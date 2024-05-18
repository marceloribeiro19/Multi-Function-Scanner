#include "mfs.h"


using namespace std;
#define MAX_MSG_RECEIVE 10000
MFS::MFS(){
    cout<<"CONSTUCTOR" << endl;
}

MFS::~MFS(){
}

MFS& MFS::getInstance() {
    static MFS instance;  // A instância é criada apenas na primeira chamada
    return instance;
}

void MFS::receive_Value(int value)
{
    MFS& mfs = MFS::getInstance(); //cria uma referência à instância única da classe MFS usando o padrão Singleton, permitindo acesso global à mesma.
    mfs.DBoperation = value;
}

/************************* SCANNER AND SENSOR OPERATIONS ***************/
const uint8_t* MFS::performScannerRead(){
    scanner.readScanner();
    return scanner.getCode();
}

void MFS::performSensorRead(){
    TempSensor.readTemperature();
}

double MFS::getSensorValue(){
    return TempSensor.getTemperature();
}



void MFS::initializeDevices(){
    //DEVICE INITIALIZATIONS
    TempSensor.init();
    scanner.init();
}


void MFS::startupSystem(){
    sqlite3_open(DB_Path, &db);
    ProductsVector = DBM.InitDB(JsonFilePath,db);
    //initializeDevices();
    createThreads();

}

void MFS::createThreads() {
    // Configuração de prioridades
    int high_priority = sched_get_priority_max(SCHED_RR);
    int mid_priority = (sched_get_priority_max(SCHED_RR) + sched_get_priority_min(SCHED_RR)) / 2;
    int low_priority = sched_get_priority_min(SCHED_RR);

    // Atributos e parâmetros de escalonamento para cada thread
    pthread_attr_t highprio_RR_attr, mediumprio_RR_attr, lowprio_RR_attr;
    struct sched_param highprio_RR_param, mediumprio_RR_param, lowprio_RR_param;

    // Configuração das threads
    SetupThread(high_priority, &highprio_RR_attr, &highprio_RR_param);
    SetupThread(mid_priority, &mediumprio_RR_attr, &mediumprio_RR_param);
    SetupThread(low_priority, &lowprio_RR_attr, &lowprio_RR_param);

    // Criação das threads
    pthread_create(&tCheckTemp_id, &highprio_RR_attr, tcheckTemperature, NULL);
    pthread_create(&tDBM_id, &mediumprio_RR_attr, tdatabaseManage, NULL);
    pthread_create(&tScan_id, &mediumprio_RR_attr, tscan, NULL);
    pthread_create(&tLED_id, &lowprio_RR_attr, tLED, NULL);

    // Aguarda o término das threads
    pthread_join(tCheckTemp_id, NULL);
    pthread_join(tDBM_id, NULL);
    pthread_join(tScan_id, NULL);
    pthread_join(tLED_id, NULL);

    // Destroi os atributos após o uso
    destroyAttributes();
}

void MFS::SetupThread(int prio, pthread_attr_t *pthread_attr, struct sched_param *pthread_param) {
    // Inicializa a estrutura de atributos da thread
    pthread_attr_init(pthread_attr);

    // Configura a política de escalonamento como SCHED_RR (Round Robin)
    pthread_attr_setschedpolicy(pthread_attr, SCHED_RR);

    // Define a prioridade da thread
    pthread_param->sched_priority = prio;
    pthread_attr_setschedparam(pthread_attr, pthread_param);
}
/************************* SHUT DOWN SYSTEM **************************/
void MFS::mutexDestroy(){
    pthread_mutex_destroy(&condMutex);
    pthread_mutex_destroy(&mtDatabaseManage);
    pthread_mutex_destroy(&mtToGUI);
    pthread_mutex_destroy(&mtFromGUI);
}

void MFS::condDestroy(){
    pthread_cond_destroy(&condToGUI);
    pthread_cond_destroy(&condFromGUI);
    pthread_cond_destroy(&condLED);
    pthread_cond_destroy(&condScan);
    pthread_cond_destroy(&condReadTemp);
    pthread_cond_destroy(&condDatabaseSearchComplete_);
    pthread_cond_destroy(&condDatabaseManage);
}

void MFS::destroyAttributes(){
    pthread_attr_destroy(&Highprio_RR_attr);
    pthread_attr_destroy(&Mediumprio_RR_attr);
    pthread_attr_destroy(&Lowprio_RR_attr);
    pthread_attr_destroy(&thread_attr);
}

void MFS::deinitializeDevices(){
    led.exit();
    TempSensor.exit();
    scanner.exit();
}

void MFS::shutdownSystem(){
    //waitforThreads(); //wait for the threads to finish the execution
    mutexDestroy();
    condDestroy();
    destroyAttributes();
    deinitializeDevices();
}




void MFS::PurshaseCompleted_signal()
{
    pthread_mutex_lock(&mtDatabaseManage);
    pthread_cond_signal(&condDatabaseManage);  // sinalize a condição para acordar a thread
    pthread_mutex_unlock(&mtDatabaseManage);
}


void MFS::VectorIncBuyed_Qty(CProduct product)
{
    for (int i = 0; i < ProductsVector.size(); ++i)
    {
        if (ProductsVector[i].getBarcode() == product.getBarcode())
        {
            ProductsVector[i].incBuyed_Qty();
            break;
        }
    }
}



//MLX90614 Temperature sensor
void* MFS::tcheckTemperature(void* arg){
    int Actual_Temp;
    for(;;)
    {
        /*----------------------Changes the Ledmode in the critical zone--------------------*/
        pthread_mutex_lock(&MFS::getInstance().mtLED);          //Tries to get the mutex's token
        cout << "Temp Thread" << endl;
        //MFS::getInstance().performSensorRead();
        //Actual_Temp = MFS::getInstance().getSensorValue();

        if(Actual_Temp >= CRITICAL_TEMP)
        {
            MFS::getInstance().LedMode = 3; //Red LED for critical temperature
            pthread_cond_signal(&MFS::getInstance().condLED);
            sleep(3);
            MFS::getInstance().shutdownSystem();
            exit(1);
        }
        else if(Actual_Temp >= MODERATE_TEMP && Actual_Temp < CRITICAL_TEMP)
        {
            MFS::getInstance().LedMode = 2; //Yellow/orange LED for not ideal temperature
            pthread_cond_signal(&MFS::getInstance().condLED);
        }
        else if(Actual_Temp > IDEAL_TEMP && Actual_Temp < MODERATE_TEMP)
        {
            MFS::getInstance().LedMode = 1; //Green LED for exellent temeperature
            pthread_cond_signal(&MFS::getInstance().condLED);
        }

        pthread_mutex_unlock(&MFS::getInstance().mtLED);        //Releases the mutex's token
        /*---------------------------------------------------------------------------------------*/
        usleep(2000000);
    }
    pthread_exit(NULL);
}




//RGB LED
void* MFS::tLED(void* arg){
    for(;;)
    {
        pthread_mutex_lock(&MFS::getInstance().mtLED);                  //Tries to get the mutex's token

        while (MFS::getInstance().LedMode == 0)                         //Stays stuck if no mode was selected
        {
            pthread_cond_wait(&MFS::getInstance().condLED, &MFS::getInstance().mtLED);
        }

        switch(MFS::getInstance().LedMode){
            case(1):
                MFS::getInstance().led.writeColor(1);       //Green LED for exellent temeperature
                break;
            case(2):
                MFS::getInstance().led.writeColor(1);       //Yellow/orange LED for not ideal temperature
                break;
            case(3):
                MFS::getInstance().led.writeColor(1);       //Red LED for critical temperature
                break;
            case(4):
                MFS::getInstance().led.writeColor(1);       //Blink Led for Scan Acknowledgement
                break;
        }
        pthread_mutex_unlock(&MFS::getInstance().mtLED);                  //Releases the mutex's token
    }
    pthread_exit(NULL);
}





//SCANNER
void* MFS::tscan(void* arg){
    MFS& inst = getInstance();

    for(;;)
    {
        /*-----------------------Scan Thread locking---------------------*/
        pthread_mutex_lock(&inst.mtScan);                       //Mutex é desbloqueado quando o user carrega no botão para fazer um scan
        /*---------------------------------------------------------------*/

        /*------------------------LedMode selection----------------------*/
        pthread_mutex_lock(&MFS::getInstance().mtLED);          //Tries to get the LED's mutex token

        MFS::getInstance().LedMode = 2;                         //Changes the Ledmode  in the critical zone (Led for Scan Acknowledgement)
        pthread_cond_signal(&MFS::getInstance().condLED);

        pthread_mutex_unlock(&MFS::getInstance().mtLED);        //Releases the mutex's token
        /*---------------------------------------------------------------*/

        cout << "Scan Thread" << endl;

        /*--------------------------Scanner code-------------------------*/

        //inst.performScannerRead();

        /*---------------------------------------------------------------*/

        /*------------------------Send MessageQueue----------------------*/
        mq_unlink(MSG_NAME);        // After unlink the previous MQ is removed from the system

        inst.Barcode_msgQueue = mq_open(MSG_NAME, O_RDWR | O_CREAT |O_EXCL,  0666,NULL);//Creates and opens a new MQ
        if(inst.Barcode_msgQueue == (mqd_t)-1){
            perror("In mq_open()");
            exit(1);
        }

        snprintf(inst.msgcontent, MAX_MSG_LEN, "A-0001-Z");                             //Produce the message using the scanned code

        mq_send(inst.Barcode_msgQueue, inst.msgcontent, strlen(inst.msgcontent)+1, 1);  //Sending the message

        mq_close(inst.Barcode_msgQueue);                                                //Closing the queue
        inst.msq_sent = true;
        /*--------------------------------------------------------------*/

        /*----------------------tdatabaseManage Unlock------------------*/
        pthread_mutex_lock(&inst.condMutex);
        pthread_cond_signal(&inst.condDatabaseManage);
        pthread_mutex_unlock(&inst.condMutex);
        /*--------------------------------------------------------------*/
    }
    pthread_exit(NULL);
}




//DATABASE
void* MFS::tdatabaseManage(void* arg){
    MFS& inst = getInstance();
    int DataBaseOp;
    int erreceive;
    unsigned int sender;
    string barcode;
    for(;;)
    {
        /*-----------------------Thread locking---------------------*/
        pthread_mutex_lock(&inst.mtDatabaseManage);
        pthread_cond_wait(&inst.condDatabaseManage, &inst.mtDatabaseManage);        //espera pelo sinal enviado no fim da tscan numa seçao critica
        pthread_mutex_unlock(&inst.mtDatabaseManage);
        /*----------------------------------------------------------*/

        cout << "Database Thread" << endl;

        /*-------------------Receive MessageQueue-------------------*/
        if(inst.msq_sent)
        {
            inst.msq_sent = false;
            inst.Barcode_msgQueue = mq_open(MSG_NAME, O_RDWR,0666);     //Open the existing queue
            if(inst.Barcode_msgQueue == (mqd_t)-1){
                perror("In mq_open()");
                exit(1);
            }

            erreceive = mq_receive(inst.Barcode_msgQueue, inst.msgcontent, MAX_MSG_RECEIVE, &sender);  //Receiving the message
            if(erreceive == -1){
                perror("In receive()");
                exit(1);
            }

            barcode = inst.msgcontent;                //Store the data in a variable

            mq_close(inst.Barcode_msgQueue);          //Closes the queue

            if(mq_unlink(MSG_NAME) == -1){            //After unlink MQ is removed from the system
                perror("Removing queue error");
                exit(1);
            }
        }

        /*----------------------------------------------------------*/

        DataBaseOp = inst.DBoperation;

        /*---------------Database Operation Selection---------------*/
        switch(DataBaseOp)
        {
            case 1:
                inst.DBM.DatabaseADD(barcode, inst.ProductsVector,inst.db,inst.JsonFilePath);   //Add to database

            case 2:
                inst.DBM.DatabaseREM(barcode, inst.ProductsVector,inst.db,inst.JsonFilePath);   //Remove from database
                break;

            case 3:
                inst.setFoundProduct(inst.DBM.DatabaseSearch(barcode, inst.db) );               //Search in database and set the foundProduct variable to the product searched/found on DB
                cout << "Produto encontrado" << endl;
                inst.DBSearchComplete = true;                               // Set the flag to indicate search completion
                break;

            case 4:
                inst.DBM.DatabaseSale(inst.ProductsVector);                                     //Register a sale in Database
                break;

            default:
                break;
        }
        /*----------------------------------------------------------*/
    }
    pthread_exit(NULL);
}



//QTCREATOR
void* MFS::tfromGUI(void* arg){
    for(;;)
    {
        //cout << "from GUI Thread" << endl;
        sleep(2);
    }
    pthread_exit(NULL);
}

//QTCREATOR
void* MFS::ttoGUI(void* arg){
    for(;;)
    {
        //cout << "to GUI Thread" << endl;
        sleep(2);
    }
    pthread_exit(NULL);
}


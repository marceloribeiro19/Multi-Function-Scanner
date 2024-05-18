#include "mfs.h"
#include <syscall.h>
using namespace std;

constexpr const char* systemCallRGB = "insmod /etc/rgbDriver.ko";
constexpr const char* systemI2CDEV = "insmod /lib/modules/5.10.92-v7l/kernel/drivers/i2c/i2c-dev.ko";
constexpr const char* systemI2CBCM2835 = "insmod /lib/modules/5.10.92-v7l/kernel/drivers/i2c/busses/i2c-bcm2835.ko";
constexpr const char* systemRemRGB = "rmmod rgbDriver";
constexpr const char* systemRemI2CDEV = "rmmod i2c-dev";


/*---------------- FUNCTIONS FOR WRAPPER ------------*/
/**
 * @brief Signals GUI from stock check.
 */
void MFS::signaltoGUIfromStockCheck() {
    pthread_mutex_lock(&condMutex);
    signalFromStockcheck=true;
    pthread_cond_signal(&condToGUI);
    pthread_mutex_unlock(&condMutex);
}

/**
 * @brief Signals for initiating a scan.
 */

void MFS::signalScan(){
    pthread_mutex_lock(&condMutex);
    pthread_cond_signal(&condScan);
    LedMode = BLUE;
    ledModeChanged=true;
    pthread_cond_signal(&condLED);
    pthread_mutex_unlock(&condMutex);
}

/**
 * @brief Gets the status of the MLX sensor.
 * @return Status of the MLX sensor.
 */
int MFS::getMLXStatus(){
    return mlxStatus;
}

/*----------------------SIGNAL----------------------*/
/**
 * @brief Signal handler function.
 */
void MFS::signalHandler(){
    pthread_mutex_lock(&condMutex);
    pthread_cond_signal(&condReadTemp);
    pthread_mutex_unlock(&condMutex);
    alarm(2);
}
/*---------------------------------------------------*/

/*-----------------------DATABASE OPERATION-----------------------*/
/**
 * @brief Receives a value for database operation.
 * @param value The value for database operation.
 */
void MFS::receive_Value(int value)
{
    MFS& mfs = MFS::getInstance(); //cria uma referência à instância única da classe MFS usando o padrão Singleton, permitindo acesso global à mesma.
    mfs.DBoperation = value;
}

/**
 * @brief Signals that purchase is completed.
 */
void MFS::PurshaseCompleted_signal()
{
    pthread_mutex_lock(&mtDatabaseManage);
    pthread_cond_signal(&condDatabaseManage);  // sinalize a condição para acordar a thread
    pthread_mutex_unlock(&mtDatabaseManage);
}

/**
 * @brief Increments the quantity of a product in the vector.
 * @param product The product to increment quantity.
 */
void MFS::IncBuyedQtyVector(CProduct product)
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

/**
 * @brief Resets the quantity of all products in the vector.
 */
void MFS::ResetQtyVector()
{
    for (int i = 0; i < ProductsVector.size(); ++i)
    {
        ProductsVector[i].setBuyed_Qty(0);
    }
}
/*--------------------------------------------------------*/

/**
 * @brief Constructor for the MFS class.
 */
MFS::MFS(){}

/**
 * @brief Destructor for the MFS class.
 */
MFS::~MFS(){}

/*---------------------------singleton--------------------*/
/**
 * @brief Gets the instance of the MFS class.
 * @return Reference to the instance of the MFS class.
 */
MFS& MFS::getInstance() {
    static MFS instance;  // A instância é criada apenas na primeira chamada
    return instance;
}


/*----------DEVICE OPERATIONS---------*/
/**
 * @brief Performs a scanner read operation.
 */
void MFS::performScannerRead(){
    scanner.readScanner();
}

/**
 * @brief Performs a sensor read operation.
 */
void MFS::performSensorRead(){
    TempSensor.readTemperature();
}

/**
 * @brief Gets the temperature value from the sensor.
 * @return The temperature value.
 */
double MFS::getSensorValue() const{
    return TempSensor.getTemperature();
}

/**
 * @brief Gets the scanner code as a string.
 * @return The scanner code as a string.
 */
string MFS::getCodeString() const{
    return scanner.getString();
}

/**
 * @brief Writes a color value to the RGB LED device.
 * @param value The color value to write.
 */
void MFS::writeColor(int value){
    led.writeColor(value);
}
/*----------------------------------------------------*/

/** ------- @brief Startup System Sequence -------  **/

/**
 * @brief Creates threads for various operations.
 */
void MFS::createThreads(){
    //pthread_create (&thread_id,     &thread_attr,        thread_routine, NULL);
    //HIGH PRIO
    pthread_create (&tCheckTemp_id, &Highprio_RR_attr,  tcheckTemperature, NULL);

    //MEDIUM PRIO
    pthread_create (&tScan_id,      &Mediumprio_RR_attr, tscan, NULL);
    pthread_create (&tDBM_id,       &Mediumprio_RR_attr, tdatabaseManage, this); //this is necessary so we can pass an object MFS as an argument

    //LOW PRIO
    pthread_create (&tToGUI_id,     &Lowprio_RR_attr,    ttoGUI, NULL);
    pthread_create (&tLED_id,       &Lowprio_RR_attr,    tLED, NULL);
}

/**
 * @brief Inserts necessary kernel drivers.
 */
void MFS::insertDrivers(){
    system(systemCallRGB);
    system(systemI2CDEV);
    //system(systemI2CBCM2835);
}

/**
 * @brief Initializes devices such as the RGB LED, temperature sensor, and scanner.
 */
void MFS::initializeDevices(){
    led.init();
    led.writeColor(ON);  //todas a 1
    mlxStatus=TempSensor.init();
    scanner.init();
}

/**
 * @brief Waits for threads to finish.
 */
void MFS::waitforThreads(){
    //pthread_join (thread_id, NULL);
    pthread_join (tCheckTemp_id, NULL);
    pthread_join (tScan_id, NULL);
    pthread_join (tDBM_id, NULL);
    pthread_join (tToGUI_id, NULL);
    pthread_join (tLED_id, NULL);
}

/**
 * @brief Sets up thread attributes.
 * @param prio Priority value for the thread.
 * @param pthread_attr Thread attributes.
 * @param pthread_param Thread parameters.
 */
void MFS::SetupThread(int prio,pthread_attr_t *pthread_attr,struct sched_param *pthread_param){
    //Assigns priority value to sched_param structure
    pthread_param->sched_priority = prio;

    // Sets the priority variable of the attribut
    pthread_attr_setschedparam (pthread_attr, pthread_param);

    // This thread attributs will be set manualy and not inherited from the calling thread
    //pthread_attr_setinheritsched (pthread_attr, PTHREAD_EXPLICIT_SCHED);

    // Sets the schedule policy for round robin
    pthread_attr_setschedpolicy (pthread_attr, SCHED_RR);
}

/**
 * @brief Initializes thread attributes.
 */
void MFS::initializeAttributes(){
    //PTHREAD INITIALIZATIONS
    // Step 1: initialize attribute object
    pthread_attr_init (&thread_attr);
    pthread_attr_getschedpolicy (&thread_attr, &thread_policy);
    pthread_attr_getschedparam (&thread_attr, &thread_param);

    //Initialize attribute object
    pthread_attr_init (&Highprio_RR_attr);
    pthread_attr_getschedpolicy (&Highprio_RR_attr, &thread_policy);
    pthread_attr_getschedparam (&Highprio_RR_attr, &Highprio_RR_param);

    pthread_attr_init (&Mediumprio_RR_attr);
    pthread_attr_getschedpolicy (&Mediumprio_RR_attr, &thread_policy);
    pthread_attr_getschedparam (&Mediumprio_RR_attr, &Mediumprio_RR_param);

    pthread_attr_init (&Lowprio_RR_attr);
    pthread_attr_getschedpolicy (&Lowprio_RR_attr, &thread_policy);
    pthread_attr_getschedparam (&Lowprio_RR_attr, &Lowprio_RR_param);

    //Setup attributes and parameters
    SetupThread(25,&Highprio_RR_attr,&Highprio_RR_param);
    SetupThread(10,&Mediumprio_RR_attr,&Mediumprio_RR_param);
    SetupThread(5,&Lowprio_RR_attr,&Lowprio_RR_param);
}


/**
 * @brief Startup procedure for the system.
 */
void MFS::startupSystem(){
    insertDrivers();
    sqlite3_open(DB_Path, &db);
    ProductsVector = DBM.InitDB(JsonFilePath,db);
    initializeDevices();
    initializeAttributes();
    createThreads();
    waitforThreads();
}


/** ------- @brief Shutdown System Sequence -------  **/

/**
 * @brief Destroys mutexes.
 */
void MFS::mutexDestroy(){
    pthread_mutex_destroy(&condMutex);
    pthread_mutex_destroy(&mtDatabaseManage);
    pthread_mutex_destroy(&mtTemperature);
}

/**
 * @brief Destroys condition variables.
 */
void MFS::condDestroy(){
    pthread_cond_destroy(&condToGUI);
    pthread_cond_destroy(&condLED);
    pthread_cond_destroy(&condScan);
    pthread_cond_destroy(&condReadTemp);
    pthread_cond_destroy(&condDatabaseManage);
}

/**
 * @brief Destroys thread attributes.
 */
void MFS::destroyAttributes(){
    pthread_attr_destroy(&Highprio_RR_attr);
    pthread_attr_destroy(&Mediumprio_RR_attr);
    pthread_attr_destroy(&Lowprio_RR_attr);
    pthread_attr_destroy(&thread_attr);
}

/**
 * @brief Deinitializes devices.
 */
void MFS::deinitializeDevices(){
    led.exit();
    TempSensor.exit();
    scanner.exit();
}

/**
 * @brief Removes kernel drivers.
 */
void MFS::removeDrivers(){
    system(systemRemRGB);
    system(systemRemI2CDEV);
}

/**
 * @brief Shuts down the system.
 */
void MFS::shutdownSystem(){
    waitforThreads();
    mutexDestroy();
    condDestroy();
    destroyAttributes();
    deinitializeDevices();
    removeDrivers();
}

//MLX90614 Temperature sensor
/**
 * @brief Thread function for checking temperature.
 * @param arg Argument for the thread function.
 * @return Thread exit status.
 */
void* MFS::tcheckTemperature(void* arg){
    MFS& inst = MFS::getInstance();
    static int currentLED=0;
    for(;;)
    {
        pthread_mutex_lock(&inst.condMutex);
        pthread_cond_wait(&inst.condReadTemp, &inst.condMutex);
        pthread_mutex_unlock(&inst.condMutex);
        /*----------------------Changes the Ledmode in the critical zone--------------------*/
        pthread_mutex_lock(&inst.mtTemperature);
        cout << "Temp Thread" << endl;
        inst.performSensorRead();
        pthread_mutex_unlock(&inst.mtTemperature);

        /*------------------------CHECK FOR TEMPERATURE THRESHOLDS----------------------*/

        if((MFS::getInstance().getSensorValue()) >= TEMP_TRESHOLD)
        {
            currentLED=RED;
            mfsWrapper::getInstance().emitWarningSignal(1);
            // sleep(3);
            // MFS::getInstance().shutdownSystem();
            // exit(1);
        }
        else if((MFS::getInstance().getSensorValue()) < TEMP_TRESHOLD)
        {
            currentLED=GREEN;
            mfsWrapper::getInstance().emitWarningSignal(0);
        }
        /*---------------------------------------------------------------------------------------*/
        // Update LED mode if changed
        if (currentLED != inst.previousLED){
            pthread_mutex_lock(&inst.mtLED);
            inst.LedMode = currentLED;
            inst.ledModeChanged = true;
            pthread_cond_signal(&MFS::getInstance().condLED);
            pthread_mutex_unlock(&inst.mtLED);
        }

        /*----------------------SIGNAL TO GUI--------------------*/
        pthread_mutex_lock(&inst.condMutex);
        inst.signalFromCheckTemp=true;
        pthread_cond_signal(&inst.condToGUI);
        pthread_mutex_unlock(&inst.condMutex);
        /*--------- ---------------------------------------------*/
    }
    pthread_exit(NULL);
}

//SCANNER
/**
 * @brief Thread function for checking temperature.
 * @param arg Argument for the thread function.
 * @return Thread exit status.
 */
void* MFS::tscan(void* arg){
    MFS& inst = MFS::getInstance();
    for(;;)
    {
        /*-----------------------Scan Thread locking---------------------*/
        pthread_mutex_lock(&inst.condMutex);
        pthread_cond_wait(&inst.condScan, &inst.condMutex);
        pthread_mutex_unlock(&inst.condMutex);

        /*-----------------------PERFORM THE READING-------------------------*/
        pthread_mutex_lock(&inst.mtScan);
        inst.performScannerRead();
        pthread_mutex_unlock(&inst.mtScan);

        /*------tToGUI and tDatabaseManage Unlock and LedMode selection--------*/
        pthread_mutex_lock(&inst.condMutex);
        pthread_cond_signal(&inst.condToGUI);
        inst.signalFromScan=true;
        pthread_cond_signal(&inst.condDatabaseManage);
        pthread_mutex_unlock(&inst.condMutex);
    }
    pthread_exit(NULL);
}

//RGB LED
/**
 * @brief Thread function for controlling the RGB LED based on system conditions.
 *
 * This thread monitors changes in the LED mode and updates the LED color accordingly.
 * It waits for a signal indicating a change in LED mode, and enforces a minimum change
 * interval to avoid rapid LED color changes.
 *
 * @param arg Unused parameter (required for thread function signature).
 */
void* MFS::tLED(void* arg){
    MFS& inst = MFS::getInstance();
    constexpr int MIN_CHANGE_INTERVAL = 2;  // 2 seconds between each change
    auto lastChangeTime = std::chrono::steady_clock::now(); // auto for detect data type
    for(;;)
    {
        pthread_mutex_lock(&inst.condMutex);
        while(inst.ledModeChanged==false){
            pthread_cond_wait(&inst.condLED, &inst.condMutex);
        }
        pthread_mutex_unlock(&inst.condMutex);
        inst.ledModeChanged=false;
        auto currentTime = std::chrono::steady_clock::now(); //gets the current time
        //calculates the elaspsed time in seconds
        auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(currentTime - lastChangeTime).count();
        //checks if the time has elasped (2 seconds)
        if (elapsedSeconds >= MIN_CHANGE_INTERVAL) {
            cout << "tLED Thread" << endl;
            pthread_mutex_lock(&inst.mtLED);
            switch(inst.LedMode){
            case(OFF):
                inst.led.writeColor(OFF); //red for critical temp
                inst.previousLED=OFF;
                break;
            case(RED):
                inst.led.writeColor(RED); //red for critical temp
                inst.previousLED=RED;
                break;
            case(GREEN):
                inst.led.writeColor(GREEN); //green for ideal tempearture
                inst.previousLED=GREEN;
                break;
            case(BLUE):
                inst.led.writeColor(BLUE); //Blink Led for Scan Acknowledgement
                inst.previousLED=BLUE;
                break;
            default:
                inst.led.writeColor(OFF); //led off
                inst.previousLED=OFF;
                break;
        }
        pthread_mutex_unlock(&inst.mtLED);
        lastChangeTime = currentTime;  //updates the last change time
        }
    }
    pthread_exit(NULL);
}


//DATABASE
/**
 * @brief Thread function for managing database operations.
 *
 * This thread waits for a signal to perform a database operation and executes the
 * corresponding action based on the operation code.
 *
 * @param arg Unused parameter (required for thread function signature).
 */
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
        pthread_cond_wait(&inst.condDatabaseManage, &inst.mtDatabaseManage);
        pthread_mutex_unlock(&inst.mtDatabaseManage);
        /*----------------------------------------------------------*/
        cout << "Database Thread" << endl;
        barcode = inst.getCodeString();
        DataBaseOp = inst.DBoperation;
        /*--------------Database Operation Selection---------------*/
        switch(DataBaseOp)
        {
        case 1:
            if(barcode[0]=='A'){
                inst.DBM.addOperation(barcode, inst.ProductsVector,inst.db);   //Add to
                mfsWrapper::getInstance().emitTableUpdateSale();
                mfsWrapper::getInstance().emitAddSignal(1);  //sucess
            }
            else mfsWrapper::getInstance().emitAddSignal(0);  //failed
            break;
        case 2:
            if(barcode[0]=='A'){
                mfsWrapper::getInstance().emitRemoveSignal(1); //sucess
                inst.DBM.remOperation(barcode, inst.ProductsVector,inst.db);   //Remove from database
            }
            else  mfsWrapper::getInstance().emitRemoveSignal(0); //failed
            break;
        case 3:
            if(barcode[0]=='A'){
                //Search in database and set the foundProduct variable to the product searched/found on DB
                inst.setFoundProduct(inst.DBM.searchOperation(barcode, inst.db) );
                inst.DBSearchComplete = true;  // Set the flag to indicate search completion
                mfsWrapper::getInstance().emitTableUpdateSale();
            }
            else {
                inst.DBSearchComplete = false;
            }
            break;
        case 4:
            //Register a sale in Database
            inst.DBM.saleOperation(inst.ProductsVector);
            break;
        default:
            break;
        }
    }
    pthread_exit(NULL);
}


//QTCREATOR
/**
 * @brief Thread function for communication with the GUI.
 *
 * This thread waits for signals related to stock checking, scanning, or temperature
 * updates. It emits corresponding signals to the GUI based on the received signals.
 *
 * @param arg Unused parameter (required for thread function signature).
 */
void* MFS::ttoGUI(void* arg){
    MFS& inst = MFS::getInstance();
    for(;;){
        /*-----------------------Thread locking from STOCKCHECK---------------------*/
        pthread_mutex_lock(&inst.condMutex); 
        pthread_cond_wait(&inst.condToGUI, &inst.condMutex);
        pthread_mutex_unlock(&inst.condMutex);
        /*------------------------------------------------------------------*/

        /*-----------------------STOCK CHECK-------------------------------*/
        if(inst.signalFromScan){
            inst.signalFromScan=false;
            mfsWrapper::getInstance().emitScanSignal(MFS::getInstance().getCodeString());
        }
        else if (inst.signalFromCheckTemp){
            inst.signalFromCheckTemp=false;
            //inst.emitUpdateSignal(MFS::getInstance().getSensorValue());
            mfsWrapper::getInstance().emitUpdateSignal(MFS::getInstance().getSensorValue());
        }
    }
    pthread_exit(NULL);
}

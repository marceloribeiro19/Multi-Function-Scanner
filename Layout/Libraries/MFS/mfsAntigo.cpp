#include "../../Pthreads/MFS/mfs.h"

using namespace std;
MFS::MFS(){
}

MFS::~MFS(){
}

void MFS::createThreads(){
    //pthread_create (&thread_id,     &thread_attr,        thread_routine, NULL);
    //HIGH PRIO
    pthread_create (&tCheckTemp_id, &Highprio_RR_attr,   tcheckTemperature, NULL);

    //MEDIUM PRIO
    pthread_create (&tScan_id,      &Mediumprio_RR_attr, tscan, NULL);
    pthread_create (&tDBM_id,       &Mediumprio_RR_attr, tdatabaseManage, NULL);

    //LOW PRIO
    pthread_create (&tToGUI_id,     &Lowprio_RR_attr,    ttoGUI, NULL);
    pthread_create (&tLED_id,       &Lowprio_RR_attr,    tLED, NULL);
    pthread_create (&tFromGUI_id,   &Lowprio_RR_attr,    tfromGUI, NULL);
}

void MFS::initializeDevices(){
    //DEVICE INITIALIZATIONS
   /* mlx90614.init();
    scanner.init();*/
}

void MFS::waitforThreads(){
    //pthread_join (thread_id, NULL);
    pthread_join (tCheckTemp_id, NULL);
    pthread_join (tDBM_id, NULL);
    pthread_join (tScan_id, NULL);
    pthread_join (tFromGUI_id, NULL);
    pthread_join (tToGUI_id, NULL);
    pthread_join (tLED_id, NULL);
}

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


void MFS::startupSystem(){	
    initializeDevices();
    initializeAttributes();
    createThreads();
    waitforThreads();
}



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



//MLX90614
void* MFS::tcheckTemperature(void* arg){
    for(;;){
        //cout << "Temp Thread" << endl;
        sleep(2);
    }
    pthread_exit(NULL);
}

//SCANNER
void* MFS::tscan(void* arg){
    for(;;){
    cout << "Scan Thread" << endl;
    sleep(2);
    }
    pthread_exit(NULL);
}

//LED
void* MFS::tLED(void* arg){
    for(;;){
    cout << "LED Thread" << endl;
    sleep(2);
    }
    pthread_exit(NULL);
}


//DATABASE
void* MFS::tdatabaseManage(void* arg){
    for(;;){
    cout << "Database Thread" << endl;
    sleep(2);
    }
    pthread_exit(NULL);
}

//QTCREATOR
void* MFS::tfromGUI(void* arg){
    for(;;){
    cout << "from GUI Thread" << endl;
    sleep(2);
    }
    pthread_exit(NULL);
}

//QTCREATOR
void* MFS::ttoGUI(void* arg){
    for(;;){
    cout << "to GUI Thread" << endl;
    sleep(2);
    }
    pthread_exit(NULL);
}


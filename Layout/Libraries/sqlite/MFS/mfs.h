#ifndef MFS_H
#define MFS_H


#include "Scanner.h"                   //Scanner module INTERFACE
#include "mlx90614.h"                  //Temperature sensore INTERFACE
#include "rgbDriver.h"
#include "CDatabaseManage.h"           //Database manager INTERFACE
#include "CProduct.h"                  //Product's class INTERFACE
#include "QObject"
#include "pininput.h"

#include <pthread.h>
#include <mqueue.h>
#include <ostream>
#include <iostream>
#include <fstream>
#include <QDialog>
#include <QTimer>
#include <QEventLoop>
#include <QMessageBox>
#include <unistd.h>

#include <QPushButton>

#define MSG_NAME    "/MyBarcode123"
#define MAX_MSG_LEN 9

#define CRITICAL_TEMP 80
#define MODERATE_TEMP 50
#define IDEAL_TEMP 20

#define LED_DEVICE_PATH "/dev/rgbDevice"

class MFS : public QDialog
{

    public:
        static MFS& getInstance();
        MFS(MFS const&) = delete;
        void operator=(MFS const&) = delete;
        ~MFS();                 //shutdown sequence
        void startupSystem();   //startup sequence
        void shutdownSystem();

        CProduct getFoundProduct(){return FoundProd;}
        void setFoundProduct(CProduct prod){FoundProd = prod;}

        const uint8_t* performScannerRead();
        void performSensorRead();
        double getSensorValue();

        bool isDBsearchComplete(){return DBSearchComplete;}
        void Reset_isDBsearchComplete(){DBSearchComplete = false;}

        void UnlockMut_tScan(){pthread_mutex_unlock(&mtScan);}
        void PurshaseCompleted_signal();
        void VectorIncBuyed_Qty(CProduct product);

    public slots:
        static void receive_Value(int value);
    //public:
        //void Set_StoreValue(int value){storedValue = value;}
    private:
        int DBoperation;    //stores the value from the signal
        int LedMode = 0;        //Can be representing either the temperature or the scan ack
    private:

        MFS();
        const char* DB_Path = "/home/marcelo/Desktop/MFS/sqlite/BaseDeDados";
        const char* JsonFilePath = "/home/marcelo/Desktop/MFS/sqlite/Products.json";
        sqlite3* db;


        //***objetos de classes - COMPOSICAO ****
        Scanner scanner;
        MLX90614 TempSensor;
        rgbDevice led;
        //CProduct Product;
        CProduct FoundProd;      //Necessary to acess the search product in others source files
        CDatabaseManage DBM;
        vector<CProduct> ProductsVector;
        bool DBSearchComplete;
        //********* FILE DESCRIPTION LED **********

        //*****************************************

        //Temperature maxima para o sensor
        double max_temperature;

        //************************PTHREADS************************
        void SetupThread(int prio,pthread_attr_t *pthread_attr,struct sched_param *pthread_param);
        void createThreads();
        void initializeAttributes();
        void initializeDevices();
        //void waitforThreads();
        int thread_policy;

        void mutexDestroy();
        void condDestroy();
        void destroyAttributes();
        void deinitializeDevices();

        //ATTRIBUTES
        pthread_attr_t thread_attr,
        Highprio_RR_attr,
        Mediumprio_RR_attr,
        Lowprio_RR_attr;

        struct sched_param thread_param,
        Highprio_RR_param,
        Mediumprio_RR_param,
        Lowprio_RR_param;

        //THREADS IDS
        pthread_t tScan_id, tFromGUI_id, I, tDBM_id, tLED_id, tCheckTemp_id, tToGUI_id;  //6

        //CONDITION VARIABLE
        pthread_cond_t condToGUI, condFromGUI,condLED, condScan, condReadTemp, condDatabaseManage, condDatabaseSearchComplete_ = PTHREAD_COND_INITIALIZER;

        //MUTEXES
        pthread_mutex_t condMutex, mtScan, mtLED, mtDatabaseManage, mtToGUI, mtFromGUI = PTHREAD_MUTEX_INITIALIZER;

        //MESSAGE QUEUES
        mqd_t Barcode_msgQueue;
        bool msq_sent;
        // struct Message_Barcode {
        char msgcontent[MAX_MSG_LEN];  // Tamanho máximo da string, ajuste conforme necessário
        //};

        // Thread entry functions
        static void* tcheckTemperature(void* arg);
        static void* tdatabaseManage(void* arg);
        static void* tscan(void* arg);
        static void* tfromGUI(void* arg);
        static void* ttoGUI(void* arg);
        static void* tLED(void* arg);
};

#endif

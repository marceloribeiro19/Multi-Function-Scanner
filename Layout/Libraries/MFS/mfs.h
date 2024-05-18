#ifndef MFS_H
#define MFS_H

#include "/home/pedro/Desktop/Pthreads/Scanner/Scanner.h"
#include "/home/pedro/Desktop/Pthreads/mlx90614/mlx90614.h"
#include "/home/pedro/Desktop/sqliteNovo/sqlite/SQLITE/sqlite.h"
#include "sqlite3.h"
#include "/home/pedro/Desktop/sqliteNovo/sqlite/CDatabaseManage.h"
#include "/home/pedro/Desktop/sqliteNovo/sqlite/CProduct.h"
#include "/home/pedro/Desktop/driverRGBLED/rgbDriver.h"
#include "mfswrapper.h"

#include <unistd.h>
#include <pthread.h>
#include <mqueue.h>
#include <ostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <signal.h>

#include <QDialog>
#include <QTimer>
#include <QEventLoop>
#include <QMessageBox>
#include <QObject>
#include <QPushButton>
#include <QMetaObject>

/* constexpr VS define. Const is handled by the compiler, defines are for preprocessing.
  Used constexpr because it has type checking, and define does not. */

// Temperature threshold
constexpr int TEMP_TRESHOLD=18;

// Constants for LED modes
constexpr int OFF=0;
constexpr int ON=1;
constexpr int RED=2;
constexpr int GREEN=3;
constexpr int BLUE=4;

// File Paths
constexpr const char* pathDB = "/etc/basedados/BaseDeDados";
constexpr const char* pathJSON = "/etc/basedados/Produtos2.json";

class MFS
{
public:
    /*-------------SINGLETON------------*/
    static MFS& getInstance();
    MFS(MFS const&) = delete;
    void operator=(MFS const&) = delete;
    ~MFS();

    void startupSystem();   //startup sequence
    void shutdownSystem();  //shutdown sequence

    /*-------------DEVICE OPERATIONS------------*/
    void performScannerRead();
    void performSensorRead();
    double getSensorValue() const;
    std::string getCodeString() const;
    void writeColor(int value);
    /*---------------------------------------*/

    CProduct getFoundProduct(){return FoundProd;}
    void setFoundProduct(CProduct prod){FoundProd = prod;}

    bool isDBsearchComplete(){return DBSearchComplete;}
    void Reset_isDBsearchComplete(){DBSearchComplete = false;}

    void PurshaseCompleted_signal();

    void IncBuyedQtyVector(CProduct product);
    void ResetQtyVector();
    /*------------- CONDITION VARIABLE ------------*/
    void signaltoGUIfromStockCheck();
    void signalScan();
    void signalHandler();

    /*------------- WRAPPER ------------*/
    int getMLXStatus();

    /*---------- DB OPERATION ---------*/
    static void receive_Value(int value);

private:
    MFS();

    int DBoperation=0;    //stores the value from the signal
    int LedMode=0;        //Can be representing either the temperature or the scan ack
    int mlxStatus=0;
    int previousLED=0;

    const char* DB_Path = pathDB;
    const char* JsonFilePath = pathJSON;
    sqlite3* db;

    //***objetos de classes - COMPOSICAO ****
    Scanner scanner;
    MLX90614 TempSensor;
    rgbDevice led;

    CProduct Product;
    CProduct FoundProd;      //Necessary to acess the search product in others source files
    CDatabaseManage DBM;
    vector<CProduct> ProductsVector;
    bool DBSearchComplete;

    bool signalFromStockcheck;
    bool signalFromCheckTemp;
    bool signalFromScan;
    bool ledModeChanged;

    //-------------- START UP SYSTEM -----------
    void SetupThread(int prio,pthread_attr_t *pthread_attr,struct sched_param *pthread_param);
    void createThreads();
    void initializeAttributes();
    void initializeDevices();
    void waitforThreads();
    void insertDrivers();


    //-------------- SHUT DOWN SYSTEM -----------
    void mutexDestroy();
    void condDestroy();
    void destroyAttributes();
    void deinitializeDevices();
    void signalThreads();
    void removeDrivers();

    int thread_policy;

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
    pthread_t tScan_id, tDBM_id, tLED_id, tCheckTemp_id, tToGUI_id;  //5

    //CONDITION VARIABLE
    pthread_cond_t condToGUI, condLED, condScan, condReadTemp, condDatabaseManage, condDatabaseSearchComplete_ = PTHREAD_COND_INITIALIZER;

    //MUTEXES
    pthread_mutex_t condMutex, mtScan, mtLED, mtDatabaseManage, mtTemperature, mtToGUI = PTHREAD_MUTEX_INITIALIZER;

    // Thread entry functions
    static void* tcheckTemperature(void* arg);
    static void* tdatabaseManage(void* arg);
    static void* tscan(void* arg);
    static void* tfromGUI(void* arg);
    static void* ttoGUI(void* arg);
    static void* tLED(void* arg);
};
#endif


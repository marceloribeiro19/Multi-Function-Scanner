#include "mainwindow.h"
#include "../../Pthreads/MFS/mfs.h"
#include <QApplication>
#include <QObject>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../../Pthreads/MFS/mfs.h"

void *startupSystemThread(void *arg) { //This thread is necessary so the main event loop and the main threads system can coexist (by placing the pthread_join() after the mainwindow is executed)
    MFS& MultiFuctionalScanner = MFS::getInstance();  //Creates a reference to the unique instance of the MFS class using the Singleton pattern, allowing global access to it.
    MultiFuctionalScanner.startupSystem();  // Obtains the unique instance and calls the method
    return nullptr;
}

void signalHandler(int signum){
    MFS::getInstance().signalHandler();
    alarm(2);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    signal(SIGALRM, signalHandler); // Register signal handler
    alarm(2);                       // Scheduled alarm after 2 seconds

    pthread_t threadId;
    int result = pthread_create(&threadId, NULL, startupSystemThread, NULL);
    if (result != 0) {
        return 1; // In case of an error occurs while creating the thread it will stop the system
    }

    int execResult = a.exec();      // Executes the main event loop
    pthread_join(threadId, NULL);   // Waits for the thread to finish

    return execResult; // Returns the main event loop result
}

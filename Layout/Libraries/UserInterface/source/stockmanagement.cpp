#include "stockmanagement.h"
#include "ui_stockmanagement.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "../../Pthreads/MFS/mfs.h"

stockManagement::stockManagement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stockManagement)
{
    ui->setupUi(this);

    connect(this,&stockManagement::Send_Signal_DB, &MFS::receive_Value); // Due to receive_Value being a static member function it doesnt need a class instance to be used
    connect(timer, &QTimer::timeout, this, &stockManagement::on_timer_timeout);
    connect(&mfsWrapper::getInstance(), &mfsWrapper::addSignal,this, &stockManagement::on_add_product);
    connect(&mfsWrapper::getInstance(), &mfsWrapper::removeSignal,this, &stockManagement::on_remove_product);
}

stockManagement::~stockManagement()
{
    delete ui;
}

void stockManagement::on_addProduct_clicked()
{
    ui->goback->setEnabled(false);
    timer->start(3000);
    MFS::getInstance().signalScan();
    this->Send_Signal_DB(1);
}

void stockManagement::on_timer_timeout(){
    timer->stop();
    ui->goback->setEnabled(true);
}

void stockManagement::on_goback_clicked()
{
    MainWindow *main;
    hide();
    main = new MainWindow(this);
    main->show();
}

void stockManagement::hideEvent(QHideEvent* event)
{
    // Disconnect the signals from mfsWrapper
    disconnect(&mfsWrapper::getInstance(), &mfsWrapper::addSignal, this, &stockManagement::on_add_product);
    disconnect(&mfsWrapper::getInstance(), &mfsWrapper::removeSignal, this, &stockManagement::on_remove_product);

    // Call the base class implementation
    QDialog::hideEvent(event);
}


void stockManagement::on_add_product(int value){
    if(value==1){
        QMessageBox::information(this, "Sucess!" , "Product added to the stock" , QMessageBox::Ok);
    }
    else  QMessageBox::warning(this, "Failed!" , "Failed to add product to the stock! Try again!" , QMessageBox::Ok);
}


void stockManagement::on_remove_product(int value){
    if(value==1){
        QMessageBox::information(this, "Sucess!" , "Product removed from the stock" , QMessageBox::Ok);
    }
    else  QMessageBox::warning(this, "Failed!" , "Failed to remove product from the stock! Try again!" , QMessageBox::Ok);
}


void stockManagement::on_removeProduct_clicked()
{
    pininput* pinInput = new pininput(this);
    connect(pinInput, &pininput::finished, this, &stockManagement::onPinInputDialogClosed);
    pinInput->exec();
}


void stockManagement::onPinInputDialogClosed(int result)
{
    //QMetaObject::invokeMethod(this, "processPinInputDialogResult", Qt::QueuedConnection, Q_ARG(int, result));
    if (result == QDialog::Accepted) {
        MFS::getInstance().signalScan();
        this->Send_Signal_DB(2);
    }
}


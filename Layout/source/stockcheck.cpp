#include "stockcheck.h"
#include "ui_stockcheck.h"
#include "mainwindow.h"
#include "stockcheck.h"
#include <QPixmap>
#include <QMetaType>
#include <QDebug>
#include "../../Pthreads/MFS/mfs.h"

stockcheck::stockcheck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stockcheck)
{
    ui->setupUi(this);

    qRegisterMetaType<std::string>("std::string");

    connect(this,&stockcheck::Send_Signal_DB, &MFS::receive_Value); // Due to receive_Value being a static member function it doesnt need a class instance to be used
    connect(timer2, &QTimer::timeout, this, &stockcheck::on_timer2_timeout);
    connect(timer, &QTimer::timeout, this, &stockcheck::Update_Table);
    this->Send_Signal_DB(3);
}

stockcheck::~stockcheck()
{
    delete ui;
}

void stockcheck::on_goback_clicked()
{
    MainWindow *main;
    hide();
    timer->stop();
    main = new MainWindow(this);
    main->show();
}


void stockcheck::on_scan_clicked()
{
    MFS::getInstance().signalScan();
   if(!timer->isActive()){  //for the table update
       timer->start(50);
   }
   if(!timer2->isActive()){  //for the go back button
       ui->goback->setEnabled(false);  //disable the go_back button
       timer2->start(3000); //timer for disable the go_back button
   }
}

void stockcheck::on_timer2_timeout(){
   timer2->stop();
   ui->goback->setEnabled(true);
}

void stockcheck::Update_Table()
{
    MFS& mfs = MFS::getInstance();
    QPixmap productImage;
    if(mfs.getFoundProduct().getBarcode()!= "" && mfs.isDBsearchComplete()) // Se nao tiver lido  nenhum produto nao atualia nada
    {
        mfs.Reset_isDBsearchComplete();
        QTableWidgetItem *Name = new QTableWidgetItem(QString::fromStdString(mfs.getFoundProduct().getName()));
        QTableWidgetItem *Barcode = new QTableWidgetItem(QString::fromStdString(mfs.getFoundProduct().getBarcode()));
        QTableWidgetItem *Price = new QTableWidgetItem(QString::fromStdString(mfs.getFoundProduct().getPrice()) + "€");
        QTableWidgetItem *Quantity = new QTableWidgetItem(QString::number(mfs.getFoundProduct().getQuantity()));
        QTableWidgetItem *Suplier = new QTableWidgetItem(QString::fromStdString(mfs.getFoundProduct().getSuplier()));
        ui->tableWidget->setItem(-1, 1, Name);
        ui->tableWidget->setItem( 0, 1, Barcode);
        ui->tableWidget->setItem( 1, 1, Price);
        ui->tableWidget->setItem( 2, 1, Quantity);
        ui->tableWidget->setItem( 3, 1, Suplier);
        cout << mfs.getFoundProduct().getName() << endl;

        std::string code = mfs.getFoundProduct().getBarcode();
        switch(code[5]){
        case '1':
            productImage=QPixmap(pathImagemTeclado);
            break;
        case '2':
            productImage=QPixmap(pathImagemRato);
            break;
        case '3':
            productImage=QPixmap(pathImagemDesktop);
            break;
        case '4':
            productImage=QPixmap(pathImagemMobile);
            break;
        default:
            productImage=QPixmap();
            break;
        }
        if(!productImage.isNull()){
            productImage = productImage.scaled(ui->produto->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->produto->setPixmap(productImage);
        }
    }
}

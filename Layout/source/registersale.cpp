#include "ui_registersale.h"
#include "mainwindow.h"
#include "registersale.h"
#include "/home/pedro/Desktop/Pthreads/MFS/mfs.h"

registersale::registersale(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registersale)
{
    ui->setupUi(this);

    connect(&mfsWrapper::getInstance(), &mfsWrapper::updateTableSale,this, &registersale::Update_Table);


    connect(this,&registersale::Send_Signal_DB, &MFS::receive_Value); // Due to receive_Value being a static member function it doesnt need a class instance to be used
    connect(timer, &QTimer::timeout, this, &registersale::on_timer_timeout);

    this->Send_Signal_DB(3);        //Emits the signal with the Database "Search" operation value
    Scanning = true;
}

registersale::~registersale()
{
    delete ui;
}

void registersale::on_goback_clicked()
{
    MainWindow *main;
    hide();
    timer->stop();
    Scanned_Products_Vector.clear();   //Cleans the vector for future purshases
    MFS::getInstance().ResetQtyVector();
    Scanning = false;
    main = new MainWindow(this);
    main->show();
}


void registersale::on_registerSale_clicked()
{
    QMessageBox::StandardButton reply;
    if(Scanned_Products_Vector.empty()){
        reply=QMessageBox::warning(this, "Warning" ,"No products scanned!", QMessageBox::Ok);
    }
    else{
    //QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", "Confirm the sale?" ,QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes)
        {
            Scanned_Products_Vector.clear();   //Cleans the vector for future purshases

            MFS& mfs = MFS::getInstance();

            emit this->Send_Signal_DB(4);
            mfs.PurshaseCompleted_signal();
            Scanning = false;
            QMessageBox::StandardButton Purshase_sucessfull;

            Purshase_sucessfull = QMessageBox::question(this, "SOLD!" , "New Purchase?" ,QMessageBox::Yes | QMessageBox::No);
            if(Purshase_sucessfull == QMessageBox::Yes)
            {
                emit this->Send_Signal_DB(3);        //Emits the signal with the Database "Search" operation value
                Scanning = true;

                for (int i = -1 ; i < ui->tableWidget->rowCount() ; i++) {
                    ui->tableWidget->removeRow(i);
                }
            }
            else
            {
                MainWindow *main;
                hide();
                Scanned_Products_Vector.clear();   //Cleans the vector for future purshases
                Scanning = false;
                main = new MainWindow(this);
                main->show();
            }
        }
        else {}
    }
}


void registersale::Update_Table()
{
    MFS& mfs = MFS::getInstance();

    if(mfs.isDBsearchComplete() && isScanning()) //The Database search is complete and it is still allowed to scan
    {
        int rowCount = ui->tableWidget->rowCount();         //Gets the last table position
        int index;
        size_t Buyed_Qty;

        auto Prod_in_Vector = std::find(Scanned_Products_Vector.begin(), Scanned_Products_Vector.end(), mfs.getFoundProduct());//Returns the iterator where a product matches, if no match occurs the iterator will be at the end of the vector

        if(Prod_in_Vector == Scanned_Products_Vector.end())  //The product hasnt been scanned yet
        {
            CProduct ScannedProduct = mfs.getFoundProduct();

            ScannedProduct.setScansAmount(1);
            Buyed_Qty = ScannedProduct.getScansAmount();
            Scanned_Products_Vector.push_back(ScannedProduct);      //Inserts on the vector the product that hasnt been scanned

            mfs.IncBuyedQtyVector(ScannedProduct);

            QTableWidgetItem *Name = new QTableWidgetItem(QString::fromStdString(ScannedProduct.getName()));
            QTableWidgetItem *Price = new QTableWidgetItem(QString::fromStdString(ScannedProduct.getPrice()));
            QTableWidgetItem *Quantity = new QTableWidgetItem(QString::number(Buyed_Qty));

            ui->tableWidget->insertRow(rowCount);                   //Inserts a new row at the end of the table
            ui->tableWidget->setVerticalHeaderItem(rowCount, Name); //Sets the row name
            ui->tableWidget->setItem(rowCount, 0, Quantity);        //Sets the Buyed quantity
            ui->tableWidget->setItem(rowCount, 1, Price);           //Sets the Price
        }
        else     //The product has been previously scanned
        {

            Prod_in_Vector->incScansAmount();         //The product

            mfs.IncBuyedQtyVector(*Prod_in_Vector);

            QTableWidgetItem *Scanned_Qty = new QTableWidgetItem(QString::number(Prod_in_Vector->getScansAmount()));

            index = std::distance(Scanned_Products_Vector.begin(), Prod_in_Vector);      //Gets the position(in scanning order) of the (repeated)scanned product

            ui->tableWidget->setItem(index, 0, Scanned_Qty);                //Sets the Buyed quantity
        }

        mfs.Reset_isDBsearchComplete(); //Resets the Database search completed flag
    }

}

void registersale::on_scan_clicked()
{
    MFS::getInstance().signalScan();
    if(!timer->isActive()){
        ui->goback->setEnabled(false);  //disable the go_back button
        timer->start(6000); //timer for disable the go_back button
    }
}

void registersale::on_timer_timeout(){
    timer->stop();
    ui->goback->setEnabled(true);   //enable the go_back button
}


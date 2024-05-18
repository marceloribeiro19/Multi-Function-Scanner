#ifndef REGISTERSALE_H
#define REGISTERSALE_H

#include <QDialog>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <fstream>
#include <QTimer>
#include "MFS/mfs.h"

namespace Ui {
class registersale;
}

class registersale : public QDialog
{
    Q_OBJECT

public:
    explicit registersale(QWidget *parent = nullptr);
    ~registersale();
    bool isScanning(){return Scanning;}
signals:
    void Send_Signal_DB(int value);
private slots:
    void on_goback_clicked();
    void on_registerSale_clicked();
    void Update_Table();
    void on_scan_clicked();
    void on_timer_timeout();
private:
    Ui::registersale *ui;
    bool Scanning;
    size_t Buyed_Qty;
    vector<CProduct> Scanned_Products_Vector;  //A vector with all the already scanned products
    QTimer* timer = new QTimer(this);
};

#endif // REGISTERSALE_H

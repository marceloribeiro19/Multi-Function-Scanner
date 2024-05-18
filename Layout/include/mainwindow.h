#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stockmanagement.h"
#include "registersale.h"
#include "stockcheck.h"
#include "info.h"
#include "pininput.h"
#include "stockmanagement.h"


#include "/home/pedro/Desktop/Pthreads/MFS/mfs.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_stockCheck_clicked();
    void on_stockManagement_clicked();
    void on_registerSale_clicked();
    void on_Info_clicked();

private:
    Ui::MainWindow *ui;
    stockManagement *stockmanagement;
    registersale *registerSale;
    stockcheck *stockCheck;
    pininput *pinInput;
    Info *information;

};
#endif // MAINWINDOW_H

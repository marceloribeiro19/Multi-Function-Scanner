#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_stockCheck_clicked()
{
    hide();
    stockCheck = new stockcheck(this);
    stockCheck->show();
}


void MainWindow::on_stockManagement_clicked()
{
    //MODELESS APPROACH
    hide();
    stockmanagement = new stockManagement(this);
    stockmanagement->show();
}


void MainWindow::on_registerSale_clicked()
{
    hide();
    registerSale = new registersale(this);
    registerSale->show();
}


void MainWindow::on_Info_clicked()
{
    hide();
    information = new Info(this);
    information->show();
}


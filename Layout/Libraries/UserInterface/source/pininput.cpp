#include "pininput.h"
#include "ui_pininput.h"
#include "QObject"
#include <QPushButton>
#include <QMessageBox>
#include <QTimer>
#include "stockmanagement.h"
#include "mfs.h"
//#include "libraries/MFS/mfs.h"
#include <QPixmap>

pininput::pininput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pininput)
{
    ui->setupUi(this);
    connect(this,&pininput::Send_Signal_DB, &MFS::receive_Value); // Due to receive_Value being a static member function it doesnt need a class instance to be used

    // Conectar os slots dos botões ao método correspondente
    connect(ui->bot0, SIGNAL(clicked()), this, SLOT(NumPress()));
    connect(ui->bot1, SIGNAL(clicked()), this, SLOT(NumPress()));
    connect(ui->bot2, SIGNAL(clicked()), this, SLOT(NumPress()));
    connect(ui->bot3, SIGNAL(clicked()), this, SLOT(NumPress()));
    connect(ui->bot4, SIGNAL(clicked()), this, SLOT(NumPress()));
    connect(ui->bot5, SIGNAL(clicked()), this, SLOT(NumPress()));
    connect(ui->bot6, SIGNAL(clicked()), this, SLOT(NumPress()));
    connect(ui->bot7, SIGNAL(clicked()), this, SLOT(NumPress()));
    connect(ui->bot8, SIGNAL(clicked()), this, SLOT(NumPress()));       //MUDAR
    connect(ui->bot9, SIGNAL(clicked()), this, SLOT(NumPress()));
    connect(ui->enter, SIGNAL(clicked()), this, SLOT(verifyPin()));
    connect(ui->clear, SIGNAL(clicked()), this, SLOT(clearPin()));
    connect(ui->hidePassword, SIGNAL(clicked()), this, SLOT(Test()));

    connect(timer, &QTimer::timeout, this, &pininput::on_timer_timeout);
    // Inicializa o número atual
    ui->display->setEchoMode(QLineEdit::Password);
}

void pininput::NumPress() {
    if(ui->display->text().length()<4){
        QPushButton *button = (QPushButton *)sender();
        if(button){
            // Obtém o texto do botão
            QString buttonText = button->text();
            ui->display->setText(ui->display->text() + buttonText);
        }
    }
}

void pininput::Test(){
    if (ui->display->echoMode() == QLineEdit::Password){
        // Se a senha estiver sendo exibida, alterne para o modo normal
        ui->display->setEchoMode(QLineEdit::Normal);
    }
    else {
        // Se a senha estiver oculta, alterne para o modo de senha
        ui->display->setEchoMode(QLineEdit::Password);
    }
}

void pininput::verifyPin(){
    QPixmap productImage;
    static int count=0;
    const int delaySeconds = 30;
    if(ui->display->text().length()>0){
        if(ui->display->text()==correctPIN){
            ui->goback->setEnabled(false);
            //timer->start(6000);
            //MFS::getInstance().signalScan();
            //this->Send_Signal_DB(2);
            count=0;
            accept();
            return;
        }
        else {
            count++;
            int remaining=3-count;
            if(remaining>0){
                QString message = QString("Incorrect Pin! Try again... Remaining attempts: %1").arg(remaining);
                QMessageBox::warning(this, "Warning", message);
                ui->display->clear();
            }
            else{
                QMessageBox countdownDialog(QMessageBox::Warning, "Warning", "Incorrect Pin! Blocked...", QMessageBox::NoButton, this);
                // Set the style sheet to use a black background
                countdownDialog.setStyleSheet("background-color: white; color: black;");
                countdownDialog.setInformativeText("Time left: " + QString::number(delaySeconds) + " seconds");
                countdownDialog.setStandardButtons(QMessageBox::NoButton);
                QTimer countdownTimer;
                connect(&countdownTimer, &QTimer::timeout, [&countdownDialog]() {
                    int remainingTime = countdownDialog.informativeText().split(" ")[2].toInt() - 1;
                    countdownDialog.setInformativeText("Time left: " + QString::number(remainingTime) + " seconds");
                    if (remainingTime == 0) {
                        countdownDialog.accept();
                    }
                });
                countdownTimer.start(1000);

                // Disable the entire pininput window
                setEnabled(false);

                // Show the countdown dialog and wait for it to be closed
                countdownDialog.exec();

                // Re-enable the entire pininput window
                setEnabled(true);
                ui->display->clear();
            }
        }
    }
    else{
        QMessageBox::warning(this,"Warning","Invalid PIN!");
    }
}

void pininput::resetAttempts(){
    setEnabled(true);
    ui->display->clear();
}

void pininput::clearPin(){
    ui->display->clear();
}

void pininput::on_timer_timeout(){
    timer->stop();
    ui->goback->setEnabled(true);
}

pininput::~pininput()
{
    delete ui;
}




void pininput::on_hidePassword_clicked()
{

}


void pininput::on_enter_clicked()
{

}


void pininput::on_goback_clicked()
{
    stockManagement *stockmanagement;
    hide();
    stockmanagement = new stockManagement(this);
    stockmanagement->show();
}


void pininput::on_confirm_clicked()
{
    stockManagement *stockmanagement;
    hide();
    stockmanagement = new stockManagement(this);
    stockmanagement->show();
}

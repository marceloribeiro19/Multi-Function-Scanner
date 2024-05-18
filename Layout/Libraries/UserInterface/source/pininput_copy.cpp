#include "pininput.h"
#include "ui_pininput.h"
#include "QObject"
#include <QPushButton>
#include <QMessageBox>

pininput::pininput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pininput)
{
    ui->setupUi(this);


    // Conectar os slots dos botões ao método correspondente
    connect(ui->bot0, SIGNAL(clicked()), this, SLOT(NumPress()));
    connect(ui->bot1, SIGNAL(clicked()), this, SLOT(NumPress()));
    connect(ui->bot2, SIGNAL(clicked()), this, SLOT(NumPress()));
    connect(ui->bot3, SIGNAL(clicked()), this, SLOT(NumPress()));
    connect(ui->bot4, SIGNAL(clicked()), this, SLOT(NumPress()));
    connect(ui->bot5, SIGNAL(clicked()), this, SLOT(NumPress()));
    connect(ui->bot6, SIGNAL(clicked()), this, SLOT(NumPress()));
    connect(ui->bot7, SIGNAL(clicked()), this, SLOT(NumPress()));
    connect(ui->bot8, SIGNAL(clicked()), this, SLOT(Test()));       //MUDAR
    connect(ui->bot9, SIGNAL(clicked()), this, SLOT(NumPress()));
    connect(ui->enter, SIGNAL(clicked()), this, SLOT(verifyPin()));
    connect(ui->clear, SIGNAL(clicked()), this, SLOT(clearPin()));

    // Inicialize o número atual
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
        if (ui->display->echoMode() == QLineEdit::Password)
        {
            // Se a senha estiver sendo exibida, alterne para o modo normal
            ui->display->setEchoMode(QLineEdit::Normal);
        }
        else
        {
            // Se a senha estiver oculta, alterne para o modo de senha
            ui->display->setEchoMode(QLineEdit::Password);
        }
        }


    void pininput::verifyPin(){
        if(ui->display->text()==corretPIN){
            QMessageBox::information(this,"Aviso","PIN Correto!");
            accept();
        }
        else {
            QMessageBox::warning(this,"Aviso","Pin Incorreto ! Tente novamente...");
            ui->display->clear();
        }
    }



    void pininput::clearPin(){
        ui->display->clear();
    }



pininput::~pininput()
{
    delete ui;
}




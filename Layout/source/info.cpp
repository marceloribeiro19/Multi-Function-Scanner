#include "info.h"
#include "ui_info.h"
#include "mainwindow.h"
#include "../../Pthreads/MFS/mfs.h"

Info::Info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Info)
{
    ui->setupUi(this);
    QObject::connect(&mfsWrapper::getInstance(), &mfsWrapper::updateValueSignal,
                     this, &Info::updateTempSlot);

    QObject::connect(&mfsWrapper::getInstance(), &mfsWrapper::updateWarningSignal,
                     this, &Info::updateWarningSlot);
}

Info::~Info()
{
    delete ui;
}

void Info::on_goback_clicked()
{
    MainWindow *main;
    hide();
    main = new MainWindow(this);
    main->show();

}

void Info::updateTempSlot(double value){
    QPixmap avisoImagem;
    switch(MFS::getInstance().getMLXStatus()){
        case 0: ui->tempValue->setText(QString::number(value, 'f', 2) + " ºC");  // Assuming 32 is the numeric value
            break;
        case 1: ui->aviso->setText("Failed to open I2C");
            avisoImagem=QPixmap(pathAviso);
            avisoImagem = avisoImagem.scaled(ui->imagemAviso->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->imagemAviso->setPixmap(avisoImagem);
            break;
        case 2: ui->aviso->setText("Failed to set Slave Address");
            avisoImagem=QPixmap(pathAviso);
            avisoImagem = avisoImagem.scaled(ui->imagemAviso->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->imagemAviso->setPixmap(avisoImagem);
            break;
        case 3: ui->aviso->setText("Failed to enable checksum");
            avisoImagem=QPixmap(pathAviso);
            avisoImagem = avisoImagem.scaled(ui->imagemAviso->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->imagemAviso->setPixmap(avisoImagem);
            break;
    }
}

void Info::updateWarningSlot(int value){
    QPixmap avisoImagem;
    switch (value) {
            case 0: ui->aviso_2->clear();
                    avisoImagem = QPixmap();  // Limpar o QPixmap
                    ui->imagemAviso->clear();  // Limpar a QLabel
                    break;

            case 1:
                    ui->aviso_2->setText("Temperature Exceeded !");
                    avisoImagem=QPixmap(pathAviso);
                    avisoImagem = avisoImagem.scaled(ui->imagemAviso->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    ui->imagemAviso->setPixmap(avisoImagem);
                    break;
            }
}

void Info::on_Info_accepted(){}



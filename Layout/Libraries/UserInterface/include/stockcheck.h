#ifndef STOCKCHECK_H
#define STOCKCHECK_H

#include <QDialog>
#include <iostream>
#include <string>
#include <fstream>
#include <QTimer>
#include  "mfswrapper.h"

constexpr const char* pathImagemTeclado = "/etc/imagens/teclado.png";
constexpr const char* pathImagemRato = "/etc/imagens/rato.png";
constexpr const char* pathImagemDesktop = "/etc/imagens/desktop.png";
constexpr const char* pathImagemMobile = "/etc/imagens/galaxyFlip.png";

namespace Ui {
class stockcheck;
}

class stockcheck : public QDialog
{
    Q_OBJECT

public:
    explicit stockcheck(QWidget *parent = nullptr);
    ~stockcheck();

private slots:
    void on_goback_clicked();
    void on_scan_clicked();
    void Update_Table();
    void on_timer2_timeout();

signals:
    void Send_Signal_DB(int value); //Database operation signal
private:
    Ui::stockcheck *ui;
    QTimer* timer2 = new QTimer(this);
    QTimer* timer = new QTimer(this);
};

#endif // STOCKCHECK_H


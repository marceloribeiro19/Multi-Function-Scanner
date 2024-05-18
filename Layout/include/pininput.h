#ifndef PININPUT_H
#define PININPUT_H

#include <QDialog>
#include <QTimer>
#include "stockmanagement.h"

namespace Ui {
class pininput;
}

class pininput : public QDialog
{
    Q_OBJECT

public:
    explicit pininput(QWidget *parent = nullptr);
    ~pininput();

private:
    Ui::pininput *ui;
    QString currentPin;
    QString correctPIN="1234";
    QTimer* timer = new QTimer(this);


signals:
    void Send_Signal_DB(int value); //Database operation signal

private slots:
    void NumPress();
    void Test();
    void verifyPin();
    void clearPin();
    void resetAttempts();
    void on_hidePassword_clicked();
    void on_enter_clicked();
    void on_goback_clicked();
    void on_confirm_clicked();
    void on_timer_timeout();
};

#endif // PININPUT_H

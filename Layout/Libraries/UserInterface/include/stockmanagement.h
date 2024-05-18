#ifndef STOCKMANAGEMENT_H
#define STOCKMANAGEMENT_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class stockManagement;
}

class stockManagement : public QDialog
{
    Q_OBJECT

public:
    explicit stockManagement(QWidget *parent = nullptr);
    ~stockManagement();

private slots:
    void on_removeProduct_clicked();
    void on_addProduct_clicked();
    void on_goback_clicked();
    void on_timer_timeout();
    void on_add_product(int value);
    void on_remove_product(int value);
    void onPinInputDialogClosed(int result);
    void hideEvent(QHideEvent* event);

signals:
    void Send_Signal_DB(int value);

private:
    Ui::stockManagement *ui;  
    QTimer* timer = new QTimer(this);
};

#endif // STOCKMANAGEMENT_H

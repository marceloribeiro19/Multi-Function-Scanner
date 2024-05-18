#ifndef INFO_H
#define INFO_H
#include <QDialog>

constexpr const char* pathAviso = "/etc/imagens/aviso.png";

namespace Ui {
class Info;
}

class Info : public QDialog
{
    Q_OBJECT

public:
    explicit Info(QWidget *parent = nullptr);
    ~Info();

public slots:
    void updateTempSlot(double value);
    void updateWarningSlot(int value);

private slots:
    void on_goback_clicked();
    void on_Info_accepted();

private:
    Ui::Info *ui;
};

#endif // INFO_H

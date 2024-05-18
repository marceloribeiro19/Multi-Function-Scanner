/********************************************************************************
** Form generated from reading UI file 'registersale.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERSALE_H
#define UI_REGISTERSALE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_registersale
{
public:
    QPushButton *goback;
    QPushButton *registerSale;
    QTableWidget *tableWidget;
    QLabel *label;
    QPushButton *scan;
    QLabel *uminho;

    void setupUi(QDialog *registersale)
    {
        if (registersale->objectName().isEmpty())
            registersale->setObjectName("registersale");
        registersale->resize(800, 480);
        registersale->setStyleSheet(QString::fromUtf8("background-color:rgb(213, 232, 212);"));
        goback = new QPushButton(registersale);
        goback->setObjectName("goback");
        goback->setGeometry(QRect(10, 10, 61, 71));
        goback->setStyleSheet(QString::fromUtf8("#goback{\n"
"background-color: transparent;\n"
"border-image:url(:turn-back.png);\n"
"background:none;\n"
"border:none;\n"
"background-repeat: none;\n"
"}"));
        registerSale = new QPushButton(registersale);
        registerSale->setObjectName("registerSale");
        registerSale->setGeometry(QRect(640, 350, 101, 91));
        registerSale->setStyleSheet(QString::fromUtf8("#registerSale{\n"
"background-color: transparent;\n"
"border-image:url(:payment.png);\n"
"background:none;\n"
"border:none;\n"
"background-repeat: none;\n"
"}"));
        tableWidget = new QTableWidget(registersale);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(60, 110, 411, 341));
        label = new QLabel(registersale);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 10, 261, 81));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: black; \n"
"background-color: none;\n"
" border: 4px solid black;\n"
" border-radius: 10px;\n"
" padding: 5px; "));
        label->setAlignment(Qt::AlignCenter);
        scan = new QPushButton(registersale);
        scan->setObjectName("scan");
        scan->setGeometry(QRect(650, 220, 101, 101));
        scan->setStyleSheet(QString::fromUtf8("#scan{\n"
"background-color: transparent;\n"
"border-image:url(:scan2.png);\n"
"background:none;\n"
"border:none;\n"
"background-repeat: none;\n"
"}"));
        uminho = new QLabel(registersale);
        uminho->setObjectName("uminho");
        uminho->setGeometry(QRect(610, 0, 191, 81));
        uminho->setStyleSheet(QString::fromUtf8("#uminho{\n"
"background-color: transparent;\n"
"border-image:url(:uminho.png);\n"
"background:none;\n"
"border:none;\n"
"background-repeat: none;\n"
"}"));
        registerSale->raise();
        tableWidget->raise();
        label->raise();
        goback->raise();
        scan->raise();
        uminho->raise();

        retranslateUi(registersale);

        QMetaObject::connectSlotsByName(registersale);
    } // setupUi

    void retranslateUi(QDialog *registersale)
    {
        registersale->setWindowTitle(QCoreApplication::translate("registersale", "Dialog", nullptr));
        goback->setText(QString());
        registerSale->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("registersale", "Quantity", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("registersale", "Price", nullptr));
        label->setText(QCoreApplication::translate("registersale", "Sale Register", nullptr));
        scan->setText(QString());
        uminho->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class registersale: public Ui_registersale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERSALE_H

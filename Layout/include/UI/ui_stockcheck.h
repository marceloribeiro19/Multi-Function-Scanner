/********************************************************************************
** Form generated from reading UI file 'stockcheck.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKCHECK_H
#define UI_STOCKCHECK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_stockcheck
{
public:
    QPushButton *goback;
    QPushButton *scan;
    QTableWidget *tableWidget;
    QLabel *produto;
    QLabel *label_2;

    void setupUi(QDialog *stockcheck)
    {
        if (stockcheck->objectName().isEmpty())
            stockcheck->setObjectName("stockcheck");
        stockcheck->resize(800, 480);
        stockcheck->setStyleSheet(QString::fromUtf8("background-color:rgb(213, 232, 212);"));
        goback = new QPushButton(stockcheck);
        goback->setObjectName("goback");
        goback->setGeometry(QRect(10, 10, 61, 71));
        goback->setStyleSheet(QString::fromUtf8("#goback{\n"
"background-color: transparent;\n"
"border-image:url(:turn-back.png);\n"
"background:none;\n"
"border:none;\n"
"background-repeat: none;\n"
"}"));
        scan = new QPushButton(stockcheck);
        scan->setObjectName("scan");
        scan->setGeometry(QRect(620, 360, 101, 91));
        scan->setStyleSheet(QString::fromUtf8("#scan{\n"
"background-color: transparent;\n"
"border-image:url(:scan2.png);\n"
"background:none;\n"
"border:none;\n"
"background-repeat: none;\n"
"}"));
        tableWidget = new QTableWidget(stockcheck);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem5);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 130, 411, 311));
        tableWidget->setTextElideMode(Qt::ElideRight);
        produto = new QLabel(stockcheck);
        produto->setObjectName("produto");
        produto->setGeometry(QRect(430, 10, 341, 291));
        label_2 = new QLabel(stockcheck);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 20, 311, 71));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: black; \n"
"background-color: none;\n"
" border: 4px solid black;\n"
" border-radius: 10px;\n"
" padding: 5px; \n"
""));
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(stockcheck);

        QMetaObject::connectSlotsByName(stockcheck);
    } // setupUi

    void retranslateUi(QDialog *stockcheck)
    {
        stockcheck->setWindowTitle(QCoreApplication::translate("stockcheck", "Dialog", nullptr));
        goback->setText(QString());
        scan->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("stockcheck", "INFO", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("stockcheck", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("stockcheck", "Barcode", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("stockcheck", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("stockcheck", "Quantity", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("stockcheck", "Supplier", nullptr));
        produto->setText(QString());
        label_2->setText(QCoreApplication::translate("stockcheck", "Stock Check", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stockcheck: public Ui_stockcheck {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKCHECK_H

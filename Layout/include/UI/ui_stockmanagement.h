/********************************************************************************
** Form generated from reading UI file 'stockmanagement.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKMANAGEMENT_H
#define UI_STOCKMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_stockManagement
{
public:
    QPushButton *goback;
    QPushButton *addProduct;
    QPushButton *removeProduct;
    QLabel *label_2;
    QLabel *uminho;

    void setupUi(QDialog *stockManagement)
    {
        if (stockManagement->objectName().isEmpty())
            stockManagement->setObjectName("stockManagement");
        stockManagement->resize(800, 480);
        stockManagement->setStyleSheet(QString::fromUtf8("background-color:rgb(213, 232, 212);"));
        goback = new QPushButton(stockManagement);
        goback->setObjectName("goback");
        goback->setGeometry(QRect(10, 10, 61, 71));
        goback->setStyleSheet(QString::fromUtf8("#goback{\n"
"background-color: transparent;\n"
"border-image:url(:turn-back.png);\n"
"background:none;\n"
"border:none;\n"
"background-repeat: none;\n"
"}"));
        addProduct = new QPushButton(stockManagement);
        addProduct->setObjectName("addProduct");
        addProduct->setGeometry(QRect(30, 290, 241, 161));
        addProduct->setStyleSheet(QString::fromUtf8("#addProduct{\n"
"background-color: transparent;\n"
"border-image:url(:stockA.png);\n"
"background:none;\n"
"border:none;\n"
"background-repeat: none;\n"
"}"));
        removeProduct = new QPushButton(stockManagement);
        removeProduct->setObjectName("removeProduct");
        removeProduct->setGeometry(QRect(520, 290, 241, 161));
        removeProduct->setStyleSheet(QString::fromUtf8("#removeProduct{\n"
"background-color: transparent;\n"
"border-image:url(:stockR.png);\n"
"background:none;\n"
"border:none;\n"
"background-repeat: none;\n"
"}"));
        label_2 = new QLabel(stockManagement);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(200, 20, 361, 61));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: black; \n"
"background-color: none;\n"
" border: 4px solid black;\n"
" border-radius: 10px;\n"
" padding: 5px; "));
        label_2->setAlignment(Qt::AlignCenter);
        uminho = new QLabel(stockManagement);
        uminho->setObjectName("uminho");
        uminho->setGeometry(QRect(610, 0, 191, 81));
        uminho->setStyleSheet(QString::fromUtf8("#uminho{\n"
"background-color: transparent;\n"
"border-image:url(:uminho.png);\n"
"background:none;\n"
"border:none;\n"
"background-repeat: none;\n"
"}"));

        retranslateUi(stockManagement);

        QMetaObject::connectSlotsByName(stockManagement);
    } // setupUi

    void retranslateUi(QDialog *stockManagement)
    {
        stockManagement->setWindowTitle(QCoreApplication::translate("stockManagement", "Dialog", nullptr));
        goback->setText(QString());
        addProduct->setText(QString());
        removeProduct->setText(QString());
        label_2->setText(QCoreApplication::translate("stockManagement", "Stock Management", nullptr));
        uminho->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class stockManagement: public Ui_stockManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKMANAGEMENT_H

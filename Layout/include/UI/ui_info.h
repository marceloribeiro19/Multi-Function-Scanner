/********************************************************************************
** Form generated from reading UI file 'info.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_H
#define UI_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Info
{
public:
    QPushButton *goback;
    QPushButton *tempLevel;
    QLabel *tempValue;
    QLabel *label_2;
    QLabel *label;
    QLabel *aviso;
    QLabel *imagemAviso;
    QLabel *aviso_2;

    void setupUi(QDialog *Info)
    {
        if (Info->objectName().isEmpty())
            Info->setObjectName("Info");
        Info->resize(800, 480);
        Info->setStyleSheet(QString::fromUtf8("background-color:rgb(213, 232, 212);"));
        goback = new QPushButton(Info);
        goback->setObjectName("goback");
        goback->setGeometry(QRect(10, 10, 71, 61));
        goback->setStyleSheet(QString::fromUtf8("#goback{\n"
"background-color: transparent;\n"
"border-image:url(:turn-back.png);\n"
"background:none;\n"
"border:none;\n"
"background-repeat: none;\n"
"}"));
        tempLevel = new QPushButton(Info);
        tempLevel->setObjectName("tempLevel");
        tempLevel->setGeometry(QRect(80, 100, 101, 71));
        tempLevel->setStyleSheet(QString::fromUtf8("#tempLevel{\n"
"background-color: transparent;\n"
"border-image:url(:niveltemperature.png);\n"
"background:none;\n"
"border:none;\n"
"background-repeat: none;\n"
"}"));
        tempValue = new QLabel(Info);
        tempValue->setObjectName("tempValue");
        tempValue->setGeometry(QRect(70, 180, 201, 101));
        QFont font;
        font.setPointSize(20);
        tempValue->setFont(font);
        tempValue->setStyleSheet(QString::fromUtf8("color: black; \n"
"background-color: none;\n"
" border: 2px solid black;\n"
" border-radius: 10px;\n"
" padding: 5px; "));
        tempValue->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Info);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 350, 771, 101));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(false);
        label_2->setFont(font1);
        label_2->setTextFormat(Qt::AutoText);
        label_2->setWordWrap(true);
        label = new QLabel(Info);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 20, 261, 51));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: black; \n"
"background-color: none;\n"
" border: 4px solid black;\n"
" border-radius: 10px;\n"
" padding: 5px; "));
        label->setAlignment(Qt::AlignCenter);
        aviso = new QLabel(Info);
        aviso->setObjectName("aviso");
        aviso->setGeometry(QRect(300, 90, 391, 41));
        aviso->setStyleSheet(QString::fromUtf8("color:red;\n"
"font-weight:bold;\n"
""));
        imagemAviso = new QLabel(Info);
        imagemAviso->setObjectName("imagemAviso");
        imagemAviso->setGeometry(QRect(200, 110, 91, 61));
        aviso_2 = new QLabel(Info);
        aviso_2->setObjectName("aviso_2");
        aviso_2->setGeometry(QRect(290, 140, 401, 41));
        aviso_2->setStyleSheet(QString::fromUtf8("color:red;\n"
"font-weight:bold;\n"
""));

        retranslateUi(Info);

        QMetaObject::connectSlotsByName(Info);
    } // setupUi

    void retranslateUi(QDialog *Info)
    {
        Info->setWindowTitle(QCoreApplication::translate("Info", "Dialog", nullptr));
        goback->setText(QString());
        tempLevel->setText(QString());
        tempValue->setText(QString());
        label_2->setText(QCoreApplication::translate("Info", "ESRG - University of Minho | Pedro Pereira PG54155 Marcelo RIbeiro PG54028", nullptr));
        label->setText(QCoreApplication::translate("Info", "Information", nullptr));
        aviso->setText(QString());
        imagemAviso->setText(QString());
        aviso_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Info: public Ui_Info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_H

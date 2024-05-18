/********************************************************************************
** Form generated from reading UI file 'pininput.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PININPUT_H
#define UI_PININPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_pininput
{
public:
    QPushButton *bot2;
    QPushButton *bot3;
    QPushButton *bot4;
    QPushButton *bot5;
    QPushButton *bot6;
    QPushButton *bot7;
    QPushButton *bot8;
    QPushButton *bot9;
    QPushButton *bot1;
    QPushButton *clear;
    QPushButton *enter;
    QPushButton *bot0;
    QLineEdit *display;
    QPushButton *hidePassword;
    QLabel *label;
    QPushButton *goback;

    void setupUi(QDialog *pininput)
    {
        if (pininput->objectName().isEmpty())
            pininput->setObjectName("pininput");
        pininput->resize(800, 480);
        pininput->setStyleSheet(QString::fromUtf8("background-color:rgb(213, 232, 212);"));
        bot2 = new QPushButton(pininput);
        bot2->setObjectName("bot2");
        bot2->setGeometry(QRect(350, 140, 71, 51));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bot2->sizePolicy().hasHeightForWidth());
        bot2->setSizePolicy(sizePolicy);
        bot2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #dae8fc;\n"
"border: 1px solid #6d8ebf;\n"
"padding: 5px;\n"
"}"));
        bot3 = new QPushButton(pininput);
        bot3->setObjectName("bot3");
        bot3->setGeometry(QRect(450, 140, 71, 51));
        bot3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #dae8fc;\n"
"border: 1px solid #6d8ebf;\n"
"padding: 5px;\n"
"}"));
        bot4 = new QPushButton(pininput);
        bot4->setObjectName("bot4");
        bot4->setGeometry(QRect(250, 210, 71, 51));
        bot4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #dae8fc;\n"
"border: 1px solid #6d8ebf;\n"
"padding: 5px;\n"
"}"));
        bot5 = new QPushButton(pininput);
        bot5->setObjectName("bot5");
        bot5->setGeometry(QRect(350, 210, 71, 51));
        bot5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #dae8fc;\n"
"border: 1px solid #6d8ebf;\n"
"padding: 5px;\n"
"}"));
        bot6 = new QPushButton(pininput);
        bot6->setObjectName("bot6");
        bot6->setGeometry(QRect(450, 210, 71, 51));
        bot6->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #dae8fc;\n"
"border: 1px solid #6d8ebf;\n"
"padding: 5px;\n"
"}"));
        bot7 = new QPushButton(pininput);
        bot7->setObjectName("bot7");
        bot7->setGeometry(QRect(250, 280, 71, 51));
        bot7->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #dae8fc;\n"
"border: 1px solid #6d8ebf;\n"
"padding: 5px;\n"
"}"));
        bot8 = new QPushButton(pininput);
        bot8->setObjectName("bot8");
        bot8->setGeometry(QRect(350, 280, 71, 51));
        bot8->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #dae8fc;\n"
"border: 1px solid #6d8ebf;\n"
"padding: 5px;\n"
"}"));
        bot9 = new QPushButton(pininput);
        bot9->setObjectName("bot9");
        bot9->setGeometry(QRect(450, 280, 71, 51));
        bot9->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #dae8fc;\n"
"border: 1px solid #6d8ebf;\n"
"padding: 5px;\n"
"}"));
        bot1 = new QPushButton(pininput);
        bot1->setObjectName("bot1");
        bot1->setGeometry(QRect(250, 140, 71, 51));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(bot1->sizePolicy().hasHeightForWidth());
        bot1->setSizePolicy(sizePolicy1);
        bot1->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #dae8fc;\n"
"border: 1px solid #6d8ebf;\n"
"padding: 5px;\n"
"}"));
        clear = new QPushButton(pininput);
        clear->setObjectName("clear");
        clear->setGeometry(QRect(120, 320, 101, 71));
        sizePolicy.setHeightForWidth(clear->sizePolicy().hasHeightForWidth());
        clear->setSizePolicy(sizePolicy);
        clear->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #b85450;\n"
"border: 2px solid #000000;\n"
"padding: 5px;\n"
"}"));
        enter = new QPushButton(pininput);
        enter->setObjectName("enter");
        enter->setGeometry(QRect(560, 320, 101, 71));
        sizePolicy.setHeightForWidth(enter->sizePolicy().hasHeightForWidth());
        enter->setSizePolicy(sizePolicy);
        enter->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #82b366;\n"
"border: 2px solid #000000;\n"
"padding: 5px;\n"
"}"));
        bot0 = new QPushButton(pininput);
        bot0->setObjectName("bot0");
        bot0->setGeometry(QRect(350, 340, 71, 51));
        sizePolicy1.setHeightForWidth(bot0->sizePolicy().hasHeightForWidth());
        bot0->setSizePolicy(sizePolicy1);
        bot0->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #dae8fc;\n"
"border: 1px solid #6d8ebf;\n"
"padding: 5px;\n"
"}"));
        display = new QLineEdit(pininput);
        display->setObjectName("display");
        display->setGeometry(QRect(320, 70, 131, 51));
        display->setEchoMode(QLineEdit::Normal);
        display->setAlignment(Qt::AlignCenter);
        hidePassword = new QPushButton(pininput);
        hidePassword->setObjectName("hidePassword");
        hidePassword->setGeometry(QRect(630, 70, 81, 61));
        hidePassword->setStyleSheet(QString::fromUtf8("#hidePassword{\n"
"background-color: transparent;\n"
"border-image:url(:passwordhide.png);\n"
"background:none;\n"
"border:none;\n"
"background-repeat: none;\n"
"}\n"
"\n"
"\n"
""));
        label = new QLabel(pininput);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 10, 331, 51));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: black; \n"
"background-color: none;\n"
" border: 4px solid black;\n"
" border-radius: 10px;\n"
" padding: 5px; "));
        label->setAlignment(Qt::AlignCenter);
        goback = new QPushButton(pininput);
        goback->setObjectName("goback");
        goback->setGeometry(QRect(10, 10, 61, 71));
        goback->setStyleSheet(QString::fromUtf8("#goback{\n"
"background-color: transparent;\n"
"border-image:url(:turn-back.png);\n"
"background:none;\n"
"border:none;\n"
"background-repeat: none;\n"
"}"));

        retranslateUi(pininput);

        QMetaObject::connectSlotsByName(pininput);
    } // setupUi

    void retranslateUi(QDialog *pininput)
    {
        pininput->setWindowTitle(QCoreApplication::translate("pininput", "Dialog", nullptr));
        bot2->setText(QCoreApplication::translate("pininput", "2", nullptr));
        bot3->setText(QCoreApplication::translate("pininput", "3", nullptr));
        bot4->setText(QCoreApplication::translate("pininput", "4", nullptr));
        bot5->setText(QCoreApplication::translate("pininput", "5", nullptr));
        bot6->setText(QCoreApplication::translate("pininput", "6", nullptr));
        bot7->setText(QCoreApplication::translate("pininput", "7", nullptr));
        bot8->setText(QCoreApplication::translate("pininput", "8", nullptr));
        bot9->setText(QCoreApplication::translate("pininput", "9", nullptr));
        bot1->setText(QCoreApplication::translate("pininput", "1", nullptr));
        clear->setText(QCoreApplication::translate("pininput", "CLEAR", nullptr));
        enter->setText(QCoreApplication::translate("pininput", "ENTER", nullptr));
        bot0->setText(QCoreApplication::translate("pininput", "0", nullptr));
        hidePassword->setText(QString());
        label->setText(QCoreApplication::translate("pininput", "Enter 4 digit pin:", nullptr));
        goback->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class pininput: public Ui_pininput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PININPUT_H

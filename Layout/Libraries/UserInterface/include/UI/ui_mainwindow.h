/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Info;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QFrame *frame;
    QPushButton *stockCheck;
    QFrame *frame_2;
    QPushButton *stockManagement;
    QFrame *frame_3;
    QPushButton *registerSale;
    QLabel *label;
    QLabel *uminho;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 480);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:rgb(213, 232, 212);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Info = new QPushButton(centralwidget);
        Info->setObjectName("Info");
        Info->setGeometry(QRect(670, 350, 81, 91));
        Info->setStyleSheet(QString::fromUtf8("#Info{\n"
"background-color: transparent;\n"
"border-image:url(:info.png);\n"
"background:none;\n"
"border:none;\n"
"background-repeat: none;\n"
"}"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(260, 340, 161, 41));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(100, 350, 81, 31));
        label_4->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(500, 350, 81, 31));
        label_5->setFont(font);
        label_5->setTextFormat(Qt::AutoText);
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(false);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(70, 180, 121, 161));
        frame->setStyleSheet(QString::fromUtf8("border: 2px solid  back;\n"
"border-width: 2px;\n"
"border-style: solid; \n"
"border-color: black; \n"
"font-weight: bold;\n"
"border-radius: 10px;\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        stockCheck = new QPushButton(frame);
        stockCheck->setObjectName("stockCheck");
        stockCheck->setGeometry(QRect(10, 10, 101, 141));
        stockCheck->setStyleSheet(QString::fromUtf8("\n"
"#stockCheck{\n"
"background-color: transparent;\n"
"border-image:url(:stockcheck.png);\n"
"background:none;\n"
"border:none;\n"
"background-repeat: none;\n"
"}"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(280, 180, 121, 161));
        frame_2->setStyleSheet(QString::fromUtf8("border: 2px solid  back;\n"
"border-width: 2px;\n"
"border-style: solid; \n"
"border-color: black; \n"
"font-weight: bold;\n"
"border-radius: 10px;\n"
"\n"
""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        stockManagement = new QPushButton(frame_2);
        stockManagement->setObjectName("stockManagement");
        stockManagement->setGeometry(QRect(10, 0, 101, 151));
        stockManagement->setStyleSheet(QString::fromUtf8("#stockManagement{\n"
"background-color: transparent;\n"
"border-image:url(:stockmanagment.png);\n"
"background:none;\n"
"border:none;\n"
"background-repeat: none;\n"
"}"));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(480, 180, 121, 161));
        frame_3->setStyleSheet(QString::fromUtf8("border: 2px solid  back;\n"
"border-width: 2px;\n"
"border-style: solid; \n"
"border-color: black; \n"
"font-weight: bold;\n"
"border-radius: 10px;\n"
""));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        registerSale = new QPushButton(frame_3);
        registerSale->setObjectName("registerSale");
        registerSale->setGeometry(QRect(20, 20, 81, 111));
        registerSale->setStyleSheet(QString::fromUtf8("#registerSale{\n"
"background-color: transparent;\n"
"border-image:url(:salesregister.png);\n"
"background:none;\n"
"border:none;\n"
"background-repeat: none;\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 10, 651, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Ubuntu")});
        font1.setPointSize(18);
        font1.setBold(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"border-width: 0px;\n"
""));
        label->setAlignment(Qt::AlignCenter);
        uminho = new QLabel(centralwidget);
        uminho->setObjectName("uminho");
        uminho->setGeometry(QRect(610, 0, 191, 81));
        uminho->setStyleSheet(QString::fromUtf8("#uminho{\n"
"background-color: transparent;\n"
"border-image:url(:uminho.png);\n"
"background:none;\n"
"border:none;\n"
"background-repeat: none;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        frame_3->raise();
        frame_2->raise();
        frame->raise();
        Info->raise();
        label_4->raise();
        label_3->raise();
        label_5->raise();
        label->raise();
        uminho->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Info->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Management", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Check", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Sale", nullptr));
        stockCheck->setText(QString());
        stockManagement->setText(QString());
        registerSale->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Multi-Functional Scanner", nullptr));
        uminho->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QLabel *labelLoginResult;
    QPushButton *btnLogin;
    QLineEdit *lineEditCard;
    QLineEdit *lineEditPIN;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *btn6;
    QPushButton *btn4;
    QPushButton *btn9;
    QPushButton *btn7;
    QPushButton *btn2;
    QPushButton *btn5;
    QPushButton *btn8;
    QPushButton *btn0;
    QPushButton *btn1;
    QPushButton *btn3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(650, 680);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        labelLoginResult = new QLabel(centralwidget);
        labelLoginResult->setObjectName(QString::fromUtf8("labelLoginResult"));
        labelLoginResult->setGeometry(QRect(210, 530, 221, 41));
        QFont font;
        font.setPointSize(14);
        labelLoginResult->setFont(font);
        btnLogin = new QPushButton(centralwidget);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(240, 470, 161, 51));
        QFont font1;
        font1.setPointSize(24);
        btnLogin->setFont(font1);
        lineEditCard = new QLineEdit(centralwidget);
        lineEditCard->setObjectName(QString::fromUtf8("lineEditCard"));
        lineEditCard->setGeometry(QRect(240, 370, 161, 41));
        lineEditCard->setFont(font1);
        lineEditPIN = new QLineEdit(centralwidget);
        lineEditPIN->setObjectName(QString::fromUtf8("lineEditPIN"));
        lineEditPIN->setGeometry(QRect(240, 420, 161, 41));
        lineEditPIN->setFont(font1);
        lineEditPIN->setReadOnly(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 420, 61, 31));
        label_2->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 370, 111, 31));
        label_3->setFont(font1);
        btn6 = new QPushButton(centralwidget);
        btn6->setObjectName(QString::fromUtf8("btn6"));
        btn6->setGeometry(QRect(360, 150, 65, 65));
        QFont font2;
        font2.setPointSize(36);
        btn6->setFont(font2);
        btn4 = new QPushButton(centralwidget);
        btn4->setObjectName(QString::fromUtf8("btn4"));
        btn4->setGeometry(QRect(220, 150, 65, 65));
        btn4->setFont(font2);
        btn9 = new QPushButton(centralwidget);
        btn9->setObjectName(QString::fromUtf8("btn9"));
        btn9->setGeometry(QRect(360, 220, 65, 65));
        btn9->setFont(font2);
        btn7 = new QPushButton(centralwidget);
        btn7->setObjectName(QString::fromUtf8("btn7"));
        btn7->setGeometry(QRect(220, 220, 65, 65));
        btn7->setFont(font2);
        btn2 = new QPushButton(centralwidget);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        btn2->setGeometry(QRect(290, 80, 65, 65));
        btn2->setFont(font2);
        btn5 = new QPushButton(centralwidget);
        btn5->setObjectName(QString::fromUtf8("btn5"));
        btn5->setGeometry(QRect(290, 150, 65, 65));
        btn5->setFont(font2);
        btn8 = new QPushButton(centralwidget);
        btn8->setObjectName(QString::fromUtf8("btn8"));
        btn8->setGeometry(QRect(290, 220, 65, 65));
        btn8->setFont(font2);
        btn0 = new QPushButton(centralwidget);
        btn0->setObjectName(QString::fromUtf8("btn0"));
        btn0->setGeometry(QRect(290, 290, 65, 65));
        btn0->setFont(font2);
        btn1 = new QPushButton(centralwidget);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        btn1->setGeometry(QRect(220, 80, 65, 65));
        btn1->setFont(font2);
        btn1->setStyleSheet(QString::fromUtf8(""));
        btn3 = new QPushButton(centralwidget);
        btn3->setObjectName(QString::fromUtf8("btn3"));
        btn3->setGeometry(QRect(360, 80, 65, 65));
        btn3->setFont(font2);
        Login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Login);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 650, 21));
        Login->setMenuBar(menubar);
        statusbar = new QStatusBar(Login);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Login->setStatusBar(statusbar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        labelLoginResult->setText(QString());
        btnLogin->setText(QCoreApplication::translate("Login", "Login", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "PIN", nullptr));
        label_3->setText(QCoreApplication::translate("Login", "Card ID", nullptr));
        btn6->setText(QCoreApplication::translate("Login", "6", nullptr));
        btn4->setText(QCoreApplication::translate("Login", "4", nullptr));
        btn9->setText(QCoreApplication::translate("Login", "9", nullptr));
        btn7->setText(QCoreApplication::translate("Login", "7", nullptr));
        btn2->setText(QCoreApplication::translate("Login", "2", nullptr));
        btn5->setText(QCoreApplication::translate("Login", "5", nullptr));
        btn8->setText(QCoreApplication::translate("Login", "8", nullptr));
        btn0->setText(QCoreApplication::translate("Login", "0", nullptr));
        btn1->setText(QCoreApplication::translate("Login", "1", nullptr));
        btn3->setText(QCoreApplication::translate("Login", "3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

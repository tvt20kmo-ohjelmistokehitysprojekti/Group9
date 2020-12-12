/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Options
{
public:
    QPushButton *btnTest;
    QLabel *labelCard2;
    QLabel *labelPassword2;
    QPushButton *btnEvents;
    QPushButton *btnBalance;
    QPushButton *btnDeposit;
    QPushButton *btnWithdraw;
    QLabel *labelCard_2;
    QLabel *labelAccType;
    QLabel *labelAccountID;
    QPushButton *btnSuljeOptions;

    void setupUi(QWidget *Options)
    {
        if (Options->objectName().isEmpty())
            Options->setObjectName(QString::fromUtf8("Options"));
        Options->resize(650, 680);
        btnTest = new QPushButton(Options);
        btnTest->setObjectName(QString::fromUtf8("btnTest"));
        btnTest->setGeometry(QRect(500, 190, 131, 91));
        labelCard2 = new QLabel(Options);
        labelCard2->setObjectName(QString::fromUtf8("labelCard2"));
        labelCard2->setGeometry(QRect(20, 170, 271, 71));
        QFont font;
        font.setPointSize(24);
        labelCard2->setFont(font);
        labelPassword2 = new QLabel(Options);
        labelPassword2->setObjectName(QString::fromUtf8("labelPassword2"));
        labelPassword2->setGeometry(QRect(20, 220, 271, 81));
        labelPassword2->setFont(font);
        btnEvents = new QPushButton(Options);
        btnEvents->setObjectName(QString::fromUtf8("btnEvents"));
        btnEvents->setGeometry(QRect(320, 470, 311, 91));
        btnEvents->setFont(font);
        btnBalance = new QPushButton(Options);
        btnBalance->setObjectName(QString::fromUtf8("btnBalance"));
        btnBalance->setGeometry(QRect(320, 380, 311, 91));
        btnBalance->setFont(font);
        btnDeposit = new QPushButton(Options);
        btnDeposit->setObjectName(QString::fromUtf8("btnDeposit"));
        btnDeposit->setGeometry(QRect(10, 470, 311, 91));
        btnDeposit->setFont(font);
        btnWithdraw = new QPushButton(Options);
        btnWithdraw->setObjectName(QString::fromUtf8("btnWithdraw"));
        btnWithdraw->setGeometry(QRect(10, 380, 311, 91));
        btnWithdraw->setFont(font);
        labelCard_2 = new QLabel(Options);
        labelCard_2->setObjectName(QString::fromUtf8("labelCard_2"));
        labelCard_2->setGeometry(QRect(10, 10, 621, 111));
        QFont font1;
        font1.setPointSize(48);
        labelCard_2->setFont(font1);
        labelAccType = new QLabel(Options);
        labelAccType->setObjectName(QString::fromUtf8("labelAccType"));
        labelAccType->setGeometry(QRect(290, 160, 191, 81));
        labelAccType->setFont(font);
        labelAccountID = new QLabel(Options);
        labelAccountID->setObjectName(QString::fromUtf8("labelAccountID"));
        labelAccountID->setGeometry(QRect(290, 220, 271, 81));
        labelAccountID->setFont(font);
        btnSuljeOptions = new QPushButton(Options);
        btnSuljeOptions->setObjectName(QString::fromUtf8("btnSuljeOptions"));
        btnSuljeOptions->setGeometry(QRect(420, 580, 211, 81));
        btnSuljeOptions->setFont(font);

        retranslateUi(Options);

        QMetaObject::connectSlotsByName(Options);
    } // setupUi

    void retranslateUi(QWidget *Options)
    {
        Options->setWindowTitle(QCoreApplication::translate("Options", "Form", nullptr));
        btnTest->setText(QCoreApplication::translate("Options", "Testinappi", nullptr));
        labelCard2->setText(QCoreApplication::translate("Options", "TextLabel", nullptr));
        labelPassword2->setText(QCoreApplication::translate("Options", "TextLabel", nullptr));
        btnEvents->setText(QCoreApplication::translate("Options", "Tapahtumat", nullptr));
        btnBalance->setText(QCoreApplication::translate("Options", "Saldo", nullptr));
        btnDeposit->setText(QCoreApplication::translate("Options", "Talletus", nullptr));
        btnWithdraw->setText(QCoreApplication::translate("Options", "Otto", nullptr));
        labelCard_2->setText(QCoreApplication::translate("Options", "Valitse", nullptr));
        labelAccType->setText(QCoreApplication::translate("Options", "TextLabel", nullptr));
        labelAccountID->setText(QCoreApplication::translate("Options", "TextLabel", nullptr));
        btnSuljeOptions->setText(QCoreApplication::translate("Options", "Sulje", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Options: public Ui_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H

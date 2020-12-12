/********************************************************************************
** Form generated from reading UI file 'acctype.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCTYPE_H
#define UI_ACCTYPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccType
{
public:
    QPushButton *btnCredit;
    QPushButton *btnDebit;
    QLabel *label;
    QLabel *labelPIN;
    QLabel *labelError;
    QPushButton *btnSuljeAcctype;

    void setupUi(QWidget *AccType)
    {
        if (AccType->objectName().isEmpty())
            AccType->setObjectName(QString::fromUtf8("AccType"));
        AccType->resize(650, 680);
        btnCredit = new QPushButton(AccType);
        btnCredit->setObjectName(QString::fromUtf8("btnCredit"));
        btnCredit->setGeometry(QRect(180, 240, 321, 91));
        QFont font;
        font.setPointSize(24);
        btnCredit->setFont(font);
        btnDebit = new QPushButton(AccType);
        btnDebit->setObjectName(QString::fromUtf8("btnDebit"));
        btnDebit->setGeometry(QRect(180, 350, 321, 91));
        btnDebit->setFont(font);
        label = new QLabel(AccType);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 611, 101));
        QFont font1;
        font1.setPointSize(48);
        label->setFont(font1);
        labelPIN = new QLabel(AccType);
        labelPIN->setObjectName(QString::fromUtf8("labelPIN"));
        labelPIN->setGeometry(QRect(30, 240, 151, 51));
        labelError = new QLabel(AccType);
        labelError->setObjectName(QString::fromUtf8("labelError"));
        labelError->setGeometry(QRect(0, 280, 651, 91));
        QFont font2;
        font2.setPointSize(31);
        labelError->setFont(font2);
        labelError->setAlignment(Qt::AlignCenter);
        btnSuljeAcctype = new QPushButton(AccType);
        btnSuljeAcctype->setObjectName(QString::fromUtf8("btnSuljeAcctype"));
        btnSuljeAcctype->setGeometry(QRect(440, 580, 171, 61));
        btnSuljeAcctype->setFont(font);

        retranslateUi(AccType);

        QMetaObject::connectSlotsByName(AccType);
    } // setupUi

    void retranslateUi(QWidget *AccType)
    {
        AccType->setWindowTitle(QCoreApplication::translate("AccType", "Form", nullptr));
        btnCredit->setText(QCoreApplication::translate("AccType", "Credit", nullptr));
        btnDebit->setText(QCoreApplication::translate("AccType", "Debit", nullptr));
        label->setText(QCoreApplication::translate("AccType", "Valitse tili", nullptr));
        labelPIN->setText(QString());
        labelError->setText(QString());
        btnSuljeAcctype->setText(QCoreApplication::translate("AccType", "Sulje", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccType: public Ui_AccType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCTYPE_H

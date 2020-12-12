/********************************************************************************
** Form generated from reading UI file 'saldoform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALDOFORM_H
#define UI_SALDOFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SaldoForm
{
public:
    QLabel *labelSaldo;
    QPushButton *btnSaldo;
    QPushButton *btnSuljeSaldo;

    void setupUi(QWidget *SaldoForm)
    {
        if (SaldoForm->objectName().isEmpty())
            SaldoForm->setObjectName(QString::fromUtf8("SaldoForm"));
        SaldoForm->resize(650, 680);
        QFont font;
        font.setPointSize(22);
        SaldoForm->setFont(font);
        labelSaldo = new QLabel(SaldoForm);
        labelSaldo->setObjectName(QString::fromUtf8("labelSaldo"));
        labelSaldo->setGeometry(QRect(200, 150, 271, 91));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        labelSaldo->setPalette(palette);
        QFont font1;
        font1.setPointSize(26);
        labelSaldo->setFont(font1);
        labelSaldo->setAutoFillBackground(true);
        btnSaldo = new QPushButton(SaldoForm);
        btnSaldo->setObjectName(QString::fromUtf8("btnSaldo"));
        btnSaldo->setGeometry(QRect(200, 30, 271, 91));
        QFont font2;
        font2.setPointSize(24);
        btnSaldo->setFont(font2);
        btnSuljeSaldo = new QPushButton(SaldoForm);
        btnSuljeSaldo->setObjectName(QString::fromUtf8("btnSuljeSaldo"));
        btnSuljeSaldo->setGeometry(QRect(440, 610, 191, 51));
        QFont font3;
        font3.setPointSize(18);
        btnSuljeSaldo->setFont(font3);

        retranslateUi(SaldoForm);

        QMetaObject::connectSlotsByName(SaldoForm);
    } // setupUi

    void retranslateUi(QWidget *SaldoForm)
    {
        SaldoForm->setWindowTitle(QCoreApplication::translate("SaldoForm", "Form", nullptr));
        labelSaldo->setText(QString());
        btnSaldo->setText(QCoreApplication::translate("SaldoForm", "N\303\244yt\303\244 saldo", nullptr));
        btnSuljeSaldo->setText(QCoreApplication::translate("SaldoForm", "Sulje", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SaldoForm: public Ui_SaldoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALDOFORM_H

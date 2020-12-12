/********************************************************************************
** Form generated from reading UI file 'accevents.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCEVENTS_H
#define UI_ACCEVENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_accEvents
{
public:
    QLabel *label;
    QTextEdit *txtEvents;
    QPushButton *btnSuljeAccevents;

    void setupUi(QWidget *accEvents)
    {
        if (accEvents->objectName().isEmpty())
            accEvents->setObjectName(QString::fromUtf8("accEvents"));
        accEvents->resize(650, 680);
        label = new QLabel(accEvents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 30, 591, 71));
        QFont font;
        font.setPointSize(48);
        label->setFont(font);
        txtEvents = new QTextEdit(accEvents);
        txtEvents->setObjectName(QString::fromUtf8("txtEvents"));
        txtEvents->setGeometry(QRect(20, 140, 611, 431));
        QFont font1;
        font1.setPointSize(14);
        txtEvents->setFont(font1);
        btnSuljeAccevents = new QPushButton(accEvents);
        btnSuljeAccevents->setObjectName(QString::fromUtf8("btnSuljeAccevents"));
        btnSuljeAccevents->setGeometry(QRect(470, 590, 161, 71));
        QFont font2;
        font2.setPointSize(24);
        btnSuljeAccevents->setFont(font2);

        retranslateUi(accEvents);

        QMetaObject::connectSlotsByName(accEvents);
    } // setupUi

    void retranslateUi(QWidget *accEvents)
    {
        accEvents->setWindowTitle(QCoreApplication::translate("accEvents", "Form", nullptr));
        label->setText(QCoreApplication::translate("accEvents", "Tilitapahtumat", nullptr));
        btnSuljeAccevents->setText(QCoreApplication::translate("accEvents", "Sulje", nullptr));
    } // retranslateUi

};

namespace Ui {
    class accEvents: public Ui_accEvents {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCEVENTS_H

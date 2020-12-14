#include "accevents.h"
#include "ui_accevents.h"

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qjsondocument.h>

accEvents::accEvents(QString events, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::accEvents)
{
    ui->setupUi(this);
    ui->txtEvents->setText(events);

    this->setStyleSheet("background-color: #0369d7;");
    ui->btnSuljeAccevents->setStyleSheet("background-color:#96a8b1;");
    ui->label->setStyleSheet("color:#f0df24;");
    ui->txtEvents->setStyleSheet("color:white;");
}

accEvents::~accEvents()
{
    delete ui;
    ui=nullptr;
}

void accEvents::on_btnSuljeAccevents_clicked()
{
    this->close();
}

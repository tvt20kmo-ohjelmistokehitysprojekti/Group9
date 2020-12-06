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
}

accEvents::~accEvents()
{
    delete ui;
    ui=nullptr;
}

#include "options.h"
#include "ui_options.h"
#include "accevents.h"
#include "varsingleton.h"

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qjsondocument.h>

Options::Options(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
}

Options::~Options()
{
    VarSingleton *var=VarSingleton::getInstance();
    delete var;
    var=nullptr;
    delete ui;
    ui=nullptr;
}

void Options::on_btnTest_clicked()
{
    VarSingleton *var=VarSingleton::getInstance();
    ui->labelCard2->setText(var->getIdClient());
    ui->labelAccType->setText(var->getAccType());
    ui->labelAccountID->setText(var->getIdAccount());
}

void Options::on_btnEvents_clicked()
{
    QString idClient, accType;

    VarSingleton *var=VarSingleton::getInstance();

    idClient=var->getIdClient();
    accType=var->getAccType();

    QNetworkRequest request(QUrl("http://localhost/Group9/RestApi-master/index.php/api/balance/events?client_id="+idClient+"&accType="+accType));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        //Authenticate
        QString username="root";
        QString password="root";
        QString concatenatedCredentials = username + ":" + password;
           QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
           QString headerData = "Basic " + data;
           request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

           QNetworkAccessManager nam;
           QNetworkReply *reply = nam.get(request);
        while (!reply->isFinished())
        {
            qApp->processEvents();
        }
        QByteArray response_data = reply->readAll();

        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonObject jsobj = json_doc.object();
        QJsonArray jsarr = json_doc.array();

        QString events;
        foreach (const QJsonValue &value, jsarr){
            QJsonObject jsob = value.toObject();
            events+=jsob["Action"].toString()+" "+jsob["Amount"].toString()+" €    Aika: "+jsob["Action_time"].toString()+"    Saldo: "+jsob["Balance"].toString()+" €"+"\r";
        }    

        accEvents *ae = new accEvents(events);
        ae->show();

        reply->deleteLater();
}

void Options::on_btnBalance_clicked()
{

}




#include "acctype.h"
#include "ui_acctype.h"
#include "options.h"
#include "varsingleton.h"

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qjsondocument.h>

AccType::AccType(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccType)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: #0369d7;");
    ui->btnCredit->setStyleSheet("background-color:white;");
    ui->btnDebit->setStyleSheet("background-color:white;");
    ui->labelValitseTilityyppi->setStyleSheet("color:white;");
    ui->btnSuljeAcctype->setStyleSheet("background-color:white;");

    delete ui;
    ui=nullptr;
}

AccType::~AccType()
{
    VarSingleton *var=VarSingleton::getInstance();
    delete var;
    var=nullptr;
    delete ui;
    ui=nullptr;
}

void AccType::on_btnCredit_clicked()
{
    QString accType, idClient, PIN;
    accType="CREDIT";

    VarSingleton *var=VarSingleton::getInstance();
    idClient=var->getIdClient();
    qDebug()<<"idClient: "+idClient;

    QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9arar00/Group9/RestApi-master/index.php/api/Client/idAccount/?idClient="+idClient+"&accType=CREDIT"));
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
        qDebug()<<response_data;
        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonObject jsobj = json_doc.object();
        QJsonArray jsarr = json_doc.array();

        QString idAccount;
        foreach (const QJsonValue &value, jsarr){
            QJsonObject jsob = value.toObject();
            idAccount+=jsob["idAccount"].toString();
            qDebug()<<"idAccount on "+idAccount;
        }

    reply->deleteLater();

    //qDebug()<<"idAccount on: "+idAccount;
    qDebug()<<idAccount.length();

    if(idAccount.length()>0){
        qDebug()<<"testi2";
        var->setIdAccount(idAccount);
        var->setAccType(accType);

        Options *opt = new Options();
        opt->show();

    }
    if(idAccount.length()==0){
        qDebug()<<"testi";
        //ui->btnCredit->setStyleSheet("QPushButton{ background-color: red }");
    }

}

void AccType::on_btnDebit_clicked()
{
    QString accType, idClient, PIN;
    accType="DEBIT";

    VarSingleton *var=VarSingleton::getInstance();
    idClient=var->getIdClient();
    qDebug()<<"idClient: "+idClient;

    QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9arar00/Group9/RestApi-master/index.php/api/client/idaccount/?idClient="+idClient+"&accType=DEBIT"));
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

        QString idAccount;

        foreach (const QJsonValue &value, jsarr){
            QJsonObject jsob = value.toObject();
            idAccount+=jsob["idAccount"].toString();
            qDebug()<<"idAccount on: "+idAccount;
        }

        reply->deleteLater();

        //qDebug()<<"idAccount on: "+idAccount;
        //qDebug()<<idAccount.length();

        if(idAccount.length()>0){
            qDebug()<<"testi2";
            var->setIdAccount(idAccount);
            var->setAccType(accType);

            Options *opt = new Options();
            opt->show();
        }
        if(idAccount.length()==0){
            //ui->btnDebit->setStyleSheet("QPushButton{ background-color: red }");
            qDebug()<<"testi";
        }
}

void AccType::on_btnCloseFrom_clicked()
{
    this->close();
}

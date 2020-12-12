#include "clientadder.h"
#include "ui_clientadder.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qjsondocument.h>

ClientAdder::ClientAdder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientAdder)
{
    ui->setupUi(this);
}

ClientAdder::~ClientAdder()
{
    delete ui;
}

void ClientAdder::on_rbtnDEBIT_clicked()
{

   ui->accTy->setText("DEBIT");
}

void ClientAdder::on_rbtnCREDIT_clicked()
{
   ui->accTy->setText("CREDIT");
}

void ClientAdder::on_btnAddClient_clicked()
{
    QString name, passw, balance, id_account, accTy;
    name=ui->addUsername->text();
    passw=ui->addPassword->text();
    qDebug()<<"tämä on salasana: " +passw;
    balance=ui->addBalance->text();
    id_account=ui->addIdAccount->text();
    accTy=ui->accTy->text();

        //QNetworkRequest request(QUrl("http://localhost/group9/RestApi-master/index.php/api/client/client/"));
        QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9arar00/Group9/RestApi-master/index.php/api/client/client/"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        //Authenticate
        QString username="root";
        QString password="root";
        QString concatenatedCredentials = username + ":" + password;
           QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
           QString headerData = "Basic " + data;
           request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

        QJsonObject json;
        json.insert("username",name);
        json.insert("passw",passw);
        json.insert("balance",balance);
        json.insert("id_account",id_account);
        json.insert("accTy",accTy);
        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.post(request, QJsonDocument(json).toJson());
        while (!reply->isFinished())
        {
            qApp->processEvents();
        }
        QByteArray response_data = reply->readAll();
        qDebug()<<response_data;
        ui->labelInfo->setText("Added : "+response_data);
        this->on_btnShowClients_clicked();
        reply->deleteLater();

}

void ClientAdder::on_btnUpdateClient_clicked()
{
        QString id, name, passw;
        id=ui->updateId->text();
        name=ui->updateName->text();
        passw=ui->updatePassword->text();

        //QNetworkRequest request(QUrl("http://localhost/group9/RestApi-master/index.php/api/client/client/"+id));
        QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9arar00/Group9/RestApi-master/index.php/api/client/client/"+id));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        //Authenticate
        QString username="root";
        QString password="root";
        QString concatenatedCredentials = username + ":" + password;
           QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
           QString headerData = "Basic " + data;
           request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

        QJsonObject json;
        json.insert("password",passw);
        json.insert("username",name);

        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.put(request, QJsonDocument(json).toJson());
        while (!reply->isFinished())
        {
            qApp->processEvents();
        }
        QByteArray response_data = reply->readAll();
        qDebug()<<response_data;
        ui->labelInfo->setText("Updated : "+response_data);
        this->on_btnShowClients_clicked();
        reply->deleteLater();

}

void ClientAdder::on_btnShowClients_clicked()
{
        //QNetworkRequest request(QUrl("http://localhost/group9/RestApi-master/index.php/api/client/client/"));
        QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9arar00/Group9/RestApi-master/index.php/api/client/client/"));
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

        QString client;
        foreach (const QJsonValue &value, jsarr) {
          QJsonObject jsob = value.toObject();
          client+=jsob["idClient"].toString()+", "+jsob["Username"].toString()+"\r";
          ui->txtClients->setText(client);
        }

        reply->deleteLater();
}

void ClientAdder::on_btnClientInfo_clicked()
{
        QString id;
        id=ui->deleteId->text();

        //QNetworkRequest request(QUrl("http://localhost/group9/RestApi-master/index.php/api/client/client/"+id));
        QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9arar00/Group9/RestApi-master/index.php/api/client/client/"+id));
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

        QString client;
        foreach (const QJsonValue &value, jsarr) {
          QJsonObject jsob = value.toObject();
          client+=jsob["idClient"].toString()+"\r";
          ui->labelDelClientID->setText(client);
         QString clientName;
          clientName+=jsob["Username"].toString()+"\r";
          ui->labelDelClientName->setText(clientName);
        }

        reply->deleteLater();
}


void ClientAdder::on_btnDeleteClient_clicked()
{


        QString id;
        id=ui->labelDelClientID->text();
        //QNetworkRequest request(QUrl("http://localhost/group9/RestApi-master/index.php/api/client/client/"+id));
        QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9arar00/Group9/RestApi-master/index.php/api/client/client/"+id));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        //Authenticate
        QString username="root";
        QString password="root";
        QString concatenatedCredentials = username + ":" + password;
           QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
           QString headerData = "Basic " + data;
           request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.deleteResource(request);
        while (!reply->isFinished())
        {
            qApp->processEvents();
        }
        QByteArray response_data = reply->readAll();
        QJsonDocument json = QJsonDocument::fromJson(response_data);
        ui->labelInfo->setText("Deleted client id="+id);
        ui->deleteId->setText("");
        ui->labelDelClientID->setText("");
        ui->labelDelClientName->setText("");
        ui->txtClients->setText("");
        this->on_btnShowClients_clicked();

        reply->deleteLater();
}

void ClientAdder::on_btnClose_clicked()
{
    this->close();
}

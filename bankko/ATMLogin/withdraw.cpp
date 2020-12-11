#include "withdraw.h"
#include "ui_withdraw.h"
#include "varsingleton.h"

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qjsondocument.h>


Withdrawal::~Withdrawal()
{
    delete ui;
}

void Withdrawal::on_btnotheramount_clicked()
{    
    QString amount, card_id;
    amount=ui->addAmount->text();
    card_id=ui->addCard->text();
    qDebug()<<card_id+" "+amount;

    QNetworkRequest request(QUrl("http://localhost/Group9/RestApi-master/index.php/api/Withdraw/Withdraw"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        //Authenticate
        QString username="root";
        QString password="root";
        QString concatenatedCredentials = username + ":" + password;
           QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
           QString headerData = "Basic " + data;
           request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

        QJsonObject json;
        json.insert("amount",amount);
        json.insert("card_id",card_id);
        qDebug()<<json;
        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.post(request, QJsonDocument(json).toJson());
        while (!reply->isFinished())
        {
            qApp->processEvents();
        }
        QByteArray response_data = reply->readAll();
        qDebug()<<response_data;
        ui->labelInfo->setText("Added : "+response_data);
        //this->on_btnotheramount_clicked();
        reply->deleteLater();

}

void Withdrawal::on_btntwenty_clicked()
{
    QString card_id, amount;
    VarSingleton *var=VarSingleton::getInstance();
    card_id= var->getIdAccount();
    amount="20";
    
    QNetworkRequest request(QUrl("http://localhost/Group9/RestApi-master/index.php/api/Withdraw/Withdraw"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        //Authenticate
        QString username="root";
        QString password="root";
        QString concatenatedCredentials = username + ":" + password;
           QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
           QString headerData = "Basic " + data;
           request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

        QJsonObject json;
        json.insert("amount",amount);
        json.insert("card_id",card_id);
        qDebug()<<json;
        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.post(request, QJsonDocument(json).toJson());
        while (!reply->isFinished())
        {
            qApp->processEvents();
        }
        QByteArray response_data = reply->readAll();
        qDebug()<<response_data;
        ui->labelInfo->setText("Added : "+response_data);
        //this->on_btnShowBooks_clicked();
        reply->deleteLater();
}

void Withdrawal::on_btnfourty_clicked()
{
    QString card_id, amount;
    VarSingleton *var=VarSingleton::getInstance();
    card_id= var->getIdAccount();
    amount="40";
    
    QNetworkRequest request(QUrl("http://localhost/Group9/RestApi-master/index.php/api/Withdraw/Withdraw"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        //Authenticate
        QString username="root";
        QString password="root";
        QString concatenatedCredentials = username + ":" + password;
           QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
           QString headerData = "Basic " + data;
           request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

        QJsonObject json;
        json.insert("amount",amount);
        json.insert("card_id",card_id);
        qDebug()<<json;
        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.post(request, QJsonDocument(json).toJson());
        while (!reply->isFinished())
        {
            qApp->processEvents();
        }
        QByteArray response_data = reply->readAll();
        qDebug()<<response_data;
        ui->labelInfo->setText("Added : "+response_data);
        //this->on_btnShowBooks_clicked();
        reply->deleteLater();
}

void Withdrawal::on_btnfifty_clicked()
{
    QString card_id, amount;
    VarSingleton *var=VarSingleton::getInstance();
    card_id= var->getIdAccount();
    amount="50";
    
    QNetworkRequest request(QUrl("http://localhost/Group9/RestApi-master/index.php/api/Withdraw/Withdraw"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        //Authenticate
        QString username="root";
        QString password="root";
        QString concatenatedCredentials = username + ":" + password;
           QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
           QString headerData = "Basic " + data;
           request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

        QJsonObject json;
        json.insert("amount",amount);
        json.insert("card_id",card_id);
        qDebug()<<json;
        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.post(request, QJsonDocument(json).toJson());
        while (!reply->isFinished())
        {
            qApp->processEvents();
        }
        QByteArray response_data = reply->readAll();
        qDebug()<<response_data;
        ui->labelInfo->setText("Added : "+response_data);
        //this->on_btnShowBooks_clicked();
        reply->deleteLater();
}

void Withdrawal::on_btnhundred_clicked()
{
    
    QString card_id, amount;
    VarSingleton *var=VarSingleton::getInstance();
    card_id= var->getIdAccount();
    amount="100";
    
    QNetworkRequest request(QUrl("http://localhost/Group9/RestApi-master/index.php/api/Withdraw/Withdraw"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        //Authenticate
        QString username="root";
        QString password="root";
        QString concatenatedCredentials = username + ":" + password;
           QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
           QString headerData = "Basic " + data;
           request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

        QJsonObject json;
        json.insert("amount",amount);
        json.insert("card_id",card_id);
        qDebug()<<json;
        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.post(request, QJsonDocument(json).toJson());
        while (!reply->isFinished())
        {
            qApp->processEvents();
        }
        QByteArray response_data = reply->readAll();
        qDebug()<<response_data;
        ui->labelInfo->setText("Added : "+response_data);
        //this->on_btnShowBooks_clicked();
        reply->deleteLater();
}

#include "withdraw2.h"
#include "ui_withdraw2.h"
#include "varsingleton.h"

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qjsondocument.h>

Withdraw2::Withdraw2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Withdraw2)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #0369d7;");
    ui->btnexit->setStyleSheet("background-color:white;");
    ui->otheramount->setStyleSheet("background-color:white;");
    ui->btnfifty->setStyleSheet("background-color:white;");
    ui->btnfourty->setStyleSheet("background-color:white;");
    ui->btnhundred->setStyleSheet("background-color:white;");
    ui->btntwenty->setStyleSheet("background-color:white;");

    ui->label_2->setStyleSheet("color:white;");
    ui->label->setStyleSheet("color:white;");
    ui->addAmount->setStyleSheet("background-color:white;");
}

Withdraw2::~Withdraw2()
{
    delete ui;
}

void Withdraw2::on_btntwenty_clicked()
{
    QString card_id, amount;
    VarSingleton *var=VarSingleton::getInstance();
    card_id= var->getIdAccount();
    amount="20";

    QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9arar00/Group9/RestApi-master/index.php/api/Withdraw/Withdraw"));
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
        //ui->labelinfo->setText("Added : "+response_data);
        //this->on_btnShowBooks_clicked();
        reply->deleteLater();
}

void Withdraw2::on_btnfourty_clicked()
{
    QString card_id, amount;
    VarSingleton *var=VarSingleton::getInstance();
    card_id= var->getIdAccount();
    amount="40";

    QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9arar00/Group9/RestApi-master/index.php/api/Withdraw/Withdraw"));
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
        //ui->labelinfo->setText("Added : "+response_data);
        //this->on_btnShowBooks_clicked();
        reply->deleteLater();
}

void Withdraw2::on_btnfifty_clicked()
{
    QString card_id, amount;
    VarSingleton *var=VarSingleton::getInstance();
    card_id= var->getIdAccount();
    amount="50";

    QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9arar00/Group9/RestApi-master/index.php/api/Withdraw/Withdraw"));
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
        //ui->labelinfo->setText("Added : "+response_data);
        //this->on_btnShowBooks_clicked();
        reply->deleteLater();
}

void Withdraw2::on_btnhundred_clicked()
{
    QString card_id, amount;
    VarSingleton *var=VarSingleton::getInstance();
    card_id= var->getIdAccount();
    amount="100";

    QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9arar00/Group9/RestApi-master/index.php/api/Withdraw/Withdraw"));
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
        //ui->labelinfo->setText("Added : "+response_data);
        //this->on_btnShowBooks_clicked();
        reply->deleteLater();
}

void Withdraw2::on_otheramount_clicked()
{
    QString card_id, amount;
    VarSingleton *var=VarSingleton::getInstance();
    card_id= var->getIdAccount();
    amount=ui->addAmount->text();
    qDebug()<<card_id+" "+amount;

    QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9arar00/Group9/RestApi-master/index.php/api/Withdraw/Withdraw"));
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
        //ui->labelinfo->setText("Added : "+response_data);
        //this->on_btnotheramount_clicked();
        reply->deleteLater();
}

void Withdraw2::on_btnexit_clicked()
{
    this->close();
}

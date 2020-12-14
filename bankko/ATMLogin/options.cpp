#include "options.h"
#include "ui_options.h"
#include "accevents.h"
#include "varsingleton.h"
#include "saldoform.h"
#include "withdraw2.h"
#include "clientadder.h"
#include "deposit.h"

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qjsondocument.h>

Options::Options(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: #0369d7;");
    ui->btnSuljeOptions->setStyleSheet("background-color:#96a8b1;");
    ui->btnBalance->setStyleSheet("background-color:white;");
    ui->btnEvents->setStyleSheet("background-color:white;");
    ui->btnWithdraw->setStyleSheet("background-color:white;");
    ui->btnDeposit->setStyleSheet("background-color:white;");
    //ui->btnTest->setStyleSheet("background-color:white;");

    ui->labelCard_2->setStyleSheet("color:#f0df24;");

    //ui->lineEditCard->setStyleSheet("color:white;");
}

Options::~Options()
{
    VarSingleton *var=VarSingleton::getInstance();
    delete var;
    var=nullptr;
    delete ui;
    ui=nullptr;

}

void Options::on_btnEvents_clicked()
{
    QString idClient, accType;

    VarSingleton *var=VarSingleton::getInstance();

    idClient=var->getIdClient();
    accType=var->getAccType();

    QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9arar00/Group9/RestApi-master/index.php/api/transactions/transactions?client_id="+idClient+"&accType="+accType));
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
        SaldoForm *sf = new SaldoForm();
        //sf-> setSaldoFromMain(response_data);
        sf->show();
}

void Options::on_btnSuljeOptions_clicked()
{
    this->close();
}

void Options::on_btnWithdraw_clicked()
{
    Withdraw2 *var=new Withdraw2();
    var->show();
    this->close();
}

void Options::on_btnDeposit_clicked()
{
    Deposit *ca=new Deposit();
    ca->show();
}

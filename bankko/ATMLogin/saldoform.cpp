#include "saldoform.h"
#include "ui_saldoform.h"
#include "varsingleton.h"

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qjsondocument.h>

SaldoForm::SaldoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SaldoForm)
{
    ui->setupUi(this);
}

SaldoForm::~SaldoForm()
{
    delete ui;
}

void SaldoForm::on_btnSaldo_clicked()
{
    QString client_id;
    VarSingleton *var=VarSingleton::getInstance();
    client_id=var->getIdClient();

    QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9arar00/Group9/RestApi-master/index.php/api/transactions/balance/?client_id="+client_id));
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

        qDebug()<<"DATA:"+response_data;

        reply->deleteLater();

      ui->labelSaldo->setText(response_data);





}

void SaldoForm::on_btnSuljeSaldo_clicked()
{
    this->close();
}

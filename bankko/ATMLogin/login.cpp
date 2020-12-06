#include "login.h"
#include "ui_login.h"
#include "acctype.h"
#include "varsingleton.h"

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qjsondocument.h>

int last=0;

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    QPushButton *nmbrButtons[10];
    for(int i=0; i<10; i++){
        QString btnName="btn"+QString::number(i);
        nmbrButtons[i]=Login::findChild<QPushButton*>(btnName);
        connect(nmbrButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }
}

Login::~Login()
{
    VarSingleton *var=VarSingleton::getInstance();
    delete var;
    var=nullptr;
    delete ui;
    ui=nullptr;
}

QString Login::getKoodi() const
{
    return koodi;
}

void Login::setKoodi(const QString &value)
{
    koodi = value;
}

void Login::NumPressed()
{
    QPushButton *btn=(QPushButton*)sender();
    QString btnVal=btn->text(); //nappien arvot tulee niiden teksteistä
    int arvo=btnVal.toInt();

    qDebug()<<"Syöttö: " +btnVal;

    if((last>=0) && (last<4)){
        PIN[last]=arvo;

        qDebug()<<PIN[last];

        ui->lineEditPIN->insert(" * ");

        if(last==3)
        {
            QString koodi;
            for(int i=0; i<4; i++){
                koodi.append(QString::number(PIN[i]));
            }
            setKoodi(koodi);
        }else{
            //ui->lineEditPIN->insert(" ");
        }
        last++;
    }
}

void Login::on_btnLogin_clicked()
{
    QString PIN=getKoodi();
    QString cardID;

    cardID=ui->lineEditCard->text();

    QNetworkRequest request(QUrl("http://localhost/Group9/RestApi-master/index.php/api/login/check_login/?idClient="+cardID+"&password="+PIN));
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

        if(response_data.compare("true")==0){
            ui->labelLoginResult->setText("Login Success YOLO!");

            VarSingleton *var = VarSingleton::getInstance();
            var->setIdClient(cardID);

            AccType *AC = new AccType();
            AC->show();
        }
        else{
            ui->labelLoginResult->setText("Wrong ID or PIN");
        }

}



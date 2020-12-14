#include "login.h"
#include "ui_login.h"
#include "acctype.h"
#include "varsingleton.h"
#include "clientadder.h"

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qjsondocument.h>
#include <QPushButton>

int last=0;
int loginTry=0;

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #0369d7;");

    ui->btnClientInterface->setStyleSheet("background-color:#f0df24;");
    ui->btn0->setStyleSheet("background-color:white;");
    ui->btn1->setStyleSheet("background-color:white;");
    ui->btn2->setStyleSheet("background-color:white;");
    ui->btn3->setStyleSheet("background-color:white;");
    ui->btn4->setStyleSheet("background-color:white;");
    ui->btn5->setStyleSheet("background-color:white;");
    ui->btn6->setStyleSheet("background-color:white;");
    ui->btn7->setStyleSheet("background-color:white;");
    ui->btn8->setStyleSheet("background-color:white;");
    ui->btn9->setStyleSheet("background-color:white;");
    ui->btnLogin->setStyleSheet("background-color:white;");
    ui->label_2->setStyleSheet("color:white;");
    ui->label_3->setStyleSheet("color:white;");
    ui->labelTervetuloa->setStyleSheet("color:#f0df24;");
    ui->labelBankkoon->setStyleSheet("color:#f0df24;");
    ui->lineEditCard->setStyleSheet("color:white;");




    QPushButton *nmbrButtons[10];
    for(int i=0; i<10; i++)
    {
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

    //qDebug()<<"Syöttö: " +btnVal;


    if((last>=0) && (last<4)){
        PIN[last]=arvo;

        qDebug()<<last;
        qDebug()<<PIN[last];


        ui->lineEditPIN->insert(" * ");
        ui->lineEditPIN->setStyleSheet("color:white;");

        ui->lineEditPIN->insert("*");


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
    qDebug()<<"idClient:"+cardID;

    QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9arar00/Group9/RestApi-master/index.php/api/login/check_login/?idClient="+cardID+"&password="+PIN));
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

            acctype *AC = new acctype();
            AC->show();
        }
        else{
            if(loginTry<2){
                ui->labelLoginResult->setText("Wrong ID or PIN");
                ui->lineEditPIN->clear();
                last=0;
                loginTry++;
            } else{
                ui->labelLoginResult->setText("Too many login attempts!");
                ui->btnLogin->setStyleSheet("QPushButton{ background-color: red }");
            }
        }
}

void Login::on_btnClientInterface_clicked()
{
    ClientAdder *AC = new ClientAdder();
    AC->show();
}

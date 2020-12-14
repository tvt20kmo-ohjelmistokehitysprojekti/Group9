#include "deposit.h"
#include "ui_deposit.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qjsondocument.h>
#include "varsingleton.h"


int cntr1c,cntr2c,cntr5c,cntr10c,cntr20c,cntr50c,cntr1e,cntr2e,cntr5e,cntr10e,cntr20e,cntr50e,cntr100e,cntr200e,cntr500e;
int selector=0;
int printer=0;
double totalAmount=0;

Deposit::Deposit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Deposit)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: #0369d7;");

    ui->btn100e->setStyleSheet("background-color:white;");
    ui->btn10c->setStyleSheet("background-color:white;");
    ui->btn10e->setStyleSheet("background-color:white;");
    ui->btn1c->setStyleSheet("background-color:white;");
    ui->btn1e->setStyleSheet("background-color:white;");
    ui->btn200e->setStyleSheet("background-color:white;");
    ui->btn20c->setStyleSheet("background-color:white;");
    ui->btn20e->setStyleSheet("background-color:white;");
    ui->btn2c->setStyleSheet("background-color:white;");
    ui->btn2e->setStyleSheet("background-color:white;");
    ui->btn500e->setStyleSheet("background-color:white;");
    ui->btn50c->setStyleSheet("background-color:white;");
    ui->btn50e->setStyleSheet("background-color:white;");
    ui->btn5c->setStyleSheet("background-color:white;");
    ui->btn5e->setStyleSheet("background-color:white;");
    ui->btnCountAgain->setStyleSheet("background-color:white;");
    ui->btnDeposit->setStyleSheet("background-color:white;");
    ui->pushButton->setStyleSheet("background-color:#96a8b1;");

    ui->labelInfo->setStyleSheet("color:#f0df24;");
    ui->label_7->setStyleSheet("color:white;");
    ui->label_8->setStyleSheet("color:#f0df24;");
    ui->lbl100e->setStyleSheet("color:white;");
    ui->lbl10c->setStyleSheet("color:white;");
    ui->lbl10e->setStyleSheet("color:white;");
    ui->lbl1c->setStyleSheet("color:white;");
    ui->lbl1e->setStyleSheet("color:white;");
    ui->lbl200e->setStyleSheet("color:white;");
    ui->lbl20c->setStyleSheet("color:white;");
    ui->lbl20e->setStyleSheet("color:white;");
    ui->lbl2c->setStyleSheet("color:white;");
    ui->lbl2e->setStyleSheet("color:white;");
    ui->lbl500e->setStyleSheet("color:white;");
    ui->lbl50c->setStyleSheet("color:white;");
    ui->lbl50e->setStyleSheet("color:white;");
    ui->lbl5c->setStyleSheet("color:white;");
    ui->lbl5e->setStyleSheet("color:white;");
    ui->lblTotalAmount->setStyleSheet("color:white;");

}

Deposit::~Deposit()
{
    delete ui;
}

void  Deposit::CountSomething()
{
    totalAmount=(cntr1c*0.01)+(cntr2c*0.02)+(cntr5c*0.05)+(cntr10c*0.1)+(cntr20c*0.2)+(cntr50c*0.5)+(cntr1e*1)+(cntr2e*2)+(cntr5e*5)+(cntr10e*10)+(cntr20e*20)+(cntr50e*50)+(cntr100e*100)+(cntr200e*200)+(cntr500e*500);

    this->PrintSomething();

}

void  Deposit::PrintSomething()

{   QString str;
    str.append(QString::number(selector));
    if (selector==cntr1c){ui->lbl1c->setText(str);};
    if (selector==cntr2c){ui->lbl2c->setText(str);};
    if (selector==cntr5c){ui->lbl5c->setText(str);};
    if (selector==cntr10c){ui->lbl10c->setText(str);};
    if (selector==cntr20c){ui->lbl20c->setText(str);};
    if (selector==cntr50c){ui->lbl50c->setText(str);};
    if (selector==cntr1e){ui->lbl1e->setText(str);};
    if (selector==cntr2e){ui->lbl2e->setText(str);};
    if (selector==cntr5e){ui->lbl5e->setText(str);};
    if (selector==cntr10e){ui->lbl10e->setText(str);};
    if (selector==cntr20e){ui->lbl20e->setText(str);};
    if (selector==cntr50e){ui->lbl50e->setText(str);};
    if (selector==cntr100e){ui->lbl100e->setText(str);};
    if (selector==cntr200e){ui->lbl200e->setText(str);};
    if (selector==cntr500e){ui->lbl500e->setText(str);};

    QString totAm;
    totAm.append(QString::number(totalAmount));
    ui->lblTotalAmount->setText(totAm);
}
void Deposit::on_btn1c_clicked()
{
    cntr1c++;
    selector=cntr1c;
     this->CountSomething();
}
void Deposit::on_btn2c_clicked()
{
    cntr2c++;
    selector=cntr2c;
     this->CountSomething();

}
void Deposit::on_btn5c_clicked()
{
    cntr5c++;
    selector=cntr5c;
     this->CountSomething();
}
void Deposit::on_btn10c_clicked()
{
    cntr10c++;
    selector=cntr10c;
     this->CountSomething();
}
void Deposit::on_btn20c_clicked()
{
    cntr20c++;
    selector=cntr20c;
     this->CountSomething();
}
void Deposit::on_btn50c_clicked()
{
    cntr50c++;
    selector=cntr50c;
     this->CountSomething();
}
void Deposit::on_btn1e_clicked()
{
    cntr1e++;
    selector=cntr1e;
     this->CountSomething();
}
void Deposit::on_btn2e_clicked()
{
    cntr2e++;
    selector=cntr2e;
     this->CountSomething();
}
void Deposit::on_btn5e_clicked()
{
    cntr5e++;
    selector=cntr5e;
     this->CountSomething();
}
void Deposit::on_btn10e_clicked()
{
    cntr10e++;
    selector=cntr10e;
     this->CountSomething();
}
void Deposit::on_btn20e_clicked()
{
    cntr20e++;
    selector=cntr20e;
     this->CountSomething();
}
void Deposit::on_btn50e_clicked()
{
    cntr50e++;
    selector=cntr50e;
     this->CountSomething();
}
void Deposit::on_btn100e_clicked()
{
    cntr100e++;
    selector=cntr100e;
     this->CountSomething();
}
void Deposit::on_btn200e_clicked()
{
    cntr200e++;
    selector=cntr200e;
     this->CountSomething();
}
void Deposit::on_btn500e_clicked()
{
    cntr500e++;
    selector=cntr500e;
     this->CountSomething();
}

void Deposit::on_btnCountAgain_clicked()
{
    cntr1c=0;cntr2c=0;cntr5c=0;cntr10c=0;cntr20c=0;cntr50c=0;cntr1e=0;cntr2e=0;cntr5e=0;cntr10e=0;cntr20e=0;cntr50e=0;cntr100e=0;cntr200e=0;cntr500e=0;
     ui->lbl1c->setText("");
     ui->lbl2c->setText("");
     ui->lbl5c->setText("");
     ui->lbl10c->setText("");
     ui->lbl20c->setText("");
     ui->lbl50c->setText("");
     ui->lbl1e->setText("");
     ui->lbl2e->setText("");
     ui->lbl5e->setText("");
     ui->lbl10e->setText("");
     ui->lbl20e->setText("");
     ui->lbl50e->setText("");
     ui->lbl100e->setText("");
     ui->lbl200e->setText("");
     ui->lbl500e->setText("");
     ui->lblTotalAmount->setText("");
}

void Deposit::on_btnDeposit_clicked()
{
     QString acc, amount;

     VarSingleton *var=VarSingleton::getInstance();
     acc=var->getIdAccount();

     amount=ui->lblTotalAmount->text();
     //QNetworkRequest request(QUrl("http://localhost/group9/RestApi-master/index.php/api/deposit/deposit/"));
     QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9arar00/Group9/RestApi-master/index.php/api/deposit/deposit/"));
         request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
         //Authenticate
         QString username="root";
         QString password="root";
         QString concatenatedCredentials = username + ":" + password;
            QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
            QString headerData = "Basic " + data;
            request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

         QJsonObject json;
         json.insert("acc",acc);
         json.insert("amount",amount);

         QNetworkAccessManager nam;
         QNetworkReply *reply = nam.put(request, QJsonDocument(json).toJson());
         while (!reply->isFinished())
         {
             qApp->processEvents();
         }
         QByteArray response_data = reply->readAll();
         qDebug()<<response_data;
         ui->labelInfo->setText("Added : "+response_data);
       this->CountSomething();
         reply->deleteLater();
}

void Deposit::on_pushButton_clicked()
{
    this->close();
    this->on_btnCountAgain_clicked();
}

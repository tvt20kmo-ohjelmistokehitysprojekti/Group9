#include "receipt.h"
#include "ui_receipt.h"

Receipt::Receipt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Receipt)
{
    ui->setupUi(this);
}

Receipt::~Receipt()
{
    delete ui;
}

void Receipt::on_btnsulje_clicked()
{
    this->close();
}

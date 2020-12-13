#ifndef CLIENTADDER_H
#define CLIENTADDER_H

#include <QWidget>

namespace Ui {
class ClientAdder;
}

class ClientAdder : public QWidget
{
    Q_OBJECT

public:
    explicit ClientAdder(QWidget *parent = nullptr);
    ~ClientAdder();

private slots:
    void on_btnShowClients_clicked();

    void on_btnAddClient_clicked();

    void on_btnDeleteClient_clicked();

    void on_btnUpdateClient_clicked();

    void on_rbtnDEBIT_clicked();

    void on_rbtnCREDIT_clicked();

    void on_btnClientInfo_clicked();

    void on_btnClose_clicked();

private:
    Ui::ClientAdder *ui;

};

#endif // CLIENTADDER_H

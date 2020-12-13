#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QWidget>

namespace Ui {
class Deposit;
}

class Deposit : public QWidget
{
    Q_OBJECT

public:
    explicit Deposit(QWidget *parent = nullptr);
    ~Deposit();
    void CountSomething();
    void PrintSomething();
private slots:


    void on_btn1c_clicked();

    void on_btn2c_clicked();

    void on_btn5c_clicked();

    void on_btn10c_clicked();

    void on_btn20c_clicked();

    void on_btn50c_clicked();

    void on_btn1e_clicked();

    void on_btn2e_clicked();

    void on_btn5e_clicked();

    void on_btn10e_clicked();

    void on_btn20e_clicked();

    void on_btn50e_clicked();

    void on_btn100e_clicked();

    void on_btn200e_clicked();

    void on_btn500e_clicked();


    void on_btnCountAgain_clicked();

    void on_btnDeposit_clicked();

    void on_pushButton_clicked();

private:
    Ui::Deposit *ui;
};

#endif // DEPOSIT_H

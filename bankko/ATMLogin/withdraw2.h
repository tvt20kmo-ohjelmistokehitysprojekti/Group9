#ifndef WITHDRAW2_H
#define WITHDRAW2_H

#include <QWidget>

namespace Ui {
class Withdraw2;
}

class Withdraw2 : public QWidget
{
    Q_OBJECT

public:
    explicit Withdraw2(QWidget *parent = nullptr);
    ~Withdraw2();

private slots:
    void on_btntwenty_clicked();

    void on_btnfourty_clicked();

    void on_btnfifty_clicked();

    void on_btnhundred_clicked();

    void on_otheramount_clicked();

    void on_btnexit_clicked();

private:
    Ui::Withdraw2 *ui;
};

#endif // WITHDRAW2_H

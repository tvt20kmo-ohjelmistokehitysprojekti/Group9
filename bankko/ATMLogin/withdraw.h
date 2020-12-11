#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Withdrawal; }
QT_END_NAMESPACE

class Withdrawal : public QWidget
{
    Q_OBJECT

public:
    explicit Withdrawal(QWidget *parent = 0);
    ~Withdrawal();

private slots:

    void on_btntwenty_clicked();
    void on_btnfourty_clicked();
    void on_btnfifty_clicked();
    void on_btnhundred_clicked();
    void on_btnotheramount_clicked();

private:
    Ui::Withdrawal *ui;
};
#endif // WITHDRAWAL_H

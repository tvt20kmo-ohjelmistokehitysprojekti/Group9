#ifndef ACCTYPE_H
#define ACCTYPE_H

#include <QWidget>

namespace Ui {
class AccType;
}

class AccType : public QWidget
{
    Q_OBJECT

public:
    explicit AccType(QWidget *parent = nullptr);
    ~AccType();

private slots:
    void on_btnCredit_clicked();

    void on_btnDebit_clicked();

private:
    Ui::AccType *ui;
};

#endif // ACCTYPE_H

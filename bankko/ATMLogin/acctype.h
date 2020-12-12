#ifndef ACCTYPE_H
#define ACCTYPE_H

#include <QWidget>

namespace Ui {
class acctype;
}

class acctype : public QWidget
{
    Q_OBJECT

public:
    explicit acctype(QWidget *parent = nullptr);
    ~acctype();
private slots:
    void on_btnCredit_clicked();

    void on_btnDebit_clicked();

private:
    Ui::acctype *ui;
};

#endif // ACCTYPE_H

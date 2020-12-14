#ifndef RECEIPT_H
#define RECEIPT_H

#include <QWidget>

namespace Ui {
class Receipt;
}

class Receipt : public QWidget
{
    Q_OBJECT

public:
    explicit Receipt(QWidget *parent = nullptr);
    ~Receipt();

private slots:
    void on_btnsulje_clicked();

    void on_label_linkActivated(const QString &link);

    void on_btnreceipt_linkActivated(const QString &link);

private:
    Ui::Receipt *ui;
};

#endif // RECEIPT_H

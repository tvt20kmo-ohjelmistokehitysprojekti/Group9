#ifndef OPTIONS_H
#define OPTIONS_H

#include <QWidget>

namespace Ui {
class Options;
}

class Options : public QWidget
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = nullptr);
    ~Options();

private slots:
    void on_btnTest_clicked();

    void on_btnEvents_clicked();

    void on_btnBalance_clicked();

    void on_btnSuljeOptions_clicked();

private:
    Ui::Options *ui;
};

#endif // OPTIONS_H

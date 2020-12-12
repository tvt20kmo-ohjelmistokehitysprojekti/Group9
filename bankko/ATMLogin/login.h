#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

    QString getKoodi() const;
    void setKoodi(const QString &value);

private slots:
    void NumPressed();
    void on_btnLogin_clicked();

private:
    Ui::Login *ui;
    int PIN[15];
    QString koodi;
};
#endif // LOGIN_H

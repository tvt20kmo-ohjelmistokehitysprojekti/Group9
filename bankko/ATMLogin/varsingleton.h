#ifndef MYSINGLETON_H
#define MYSINGLETON_H

#include <qstring.h>

class VarSingleton
{
private:
    static VarSingleton* instance;
    QString idClient;
    QString idAccount;
    QString accType;
    QString totalAmount;

public:
    static VarSingleton* getInstance();

    QString getIdClient() const;
    void setIdClient(const QString &value);

    QString getIdAccount() const;
    void setIdAccount(const QString &value);

    QString getAccType() const;
    void setAccType(const QString &value);

    QString getTotalAmount() const;
    void setTotalAmount(const double value);
};

#endif // MYSINGLETON_H

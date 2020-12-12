#include "varsingleton.h"


VarSingleton* VarSingleton::instance = nullptr;

QString VarSingleton::getIdAccount() const
{
    return idAccount;
}

QString VarSingleton::getIdClient() const
{
    return idClient;
}

void VarSingleton::setIdClient(const QString &value)
{
    idClient = value;
}

void VarSingleton::setIdAccount(const QString &value)
{
    idAccount = value;
}

QString VarSingleton::getAccType() const
{
    return accType;
}

void VarSingleton::setAccType(const QString &value)
{
    accType = value;
}

QString VarSingleton::getTotalAmount() const
{
    return totalAmount;
}

void VarSingleton::setTotalAmount(double value)
{

    totalAmount=value;
}

VarSingleton* VarSingleton::getInstance()
{
    if (instance == nullptr)
    {
        instance = new VarSingleton();
    }

    return instance;
}



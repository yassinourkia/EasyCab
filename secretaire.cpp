#include "secretaire.h"

Secretaire::Secretaire()
{

}

Secretaire::Secretaire(QString pseudo, QString password)
{
    this->psuedo = pseudo;
    this->password = password;
}

bool Secretaire::Login(){
    QSqlQuery query ;
    return query.exec("select * from 'user' where LOGIN ='"+this->psuedo+"' and PASSWORD='"+this->password+"'");
}

QString Secretaire::getPsuedo() const
{
    return psuedo;
}

void Secretaire::setPsuedo(const QString &value)
{
    psuedo = value;
}

QString Secretaire::getPassword() const
{
    return password;
}

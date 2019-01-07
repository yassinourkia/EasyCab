#include "secretaire.h"

Secretaire::Secretaire(QString psuedo, QString password) : Utilisateur ()
{
    this->psuedo = psuedo;
    this->password = password;
}

Secretaire::Secretaire(QString f_name,QString l_name,QString adresse,QString phone_number,QString pseudo, QString password)
    : Utilisateur ( f_name,l_name,adresse,phone_number )
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

QString Secretaire::toString(){
    return "["+this->getf_name()+"]"+"["+this->getl_name()+"]"+"["+this->getadresse()+"]"+"["+this->getphone_number()+"]"+"["+this->password+"]"+"["+this->psuedo+"]";
}

bool operator==(const Secretaire &a, const Secretaire &b)
{
    return (a.getPsuedo() == b.getPsuedo() && a.getPassword() == b.getPassword());
}

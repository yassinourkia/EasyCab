#include "medecin.h"

Medecin::Medecin()
{

}
Medecin::Medecin(QString psuedo, QString password,QString role) : Utilisateur ()
{
    this->psuedo = psuedo;
    this->password = password;
    this->role = role;
}

Medecin::Medecin(QString f_name,QString l_name,QString adresse,QString phone_number,QString pseudo, QString password,QString role)
    : Utilisateur ( f_name,l_name,adresse,phone_number )
{
    this->psuedo = pseudo;
    this->password = password;
    this->role = role;
}

bool Medecin::Login(){
    QSqlQuery query ;
    return query.exec("select * from 'user' where LOGIN ='"+this->psuedo+"' and PASSWORD='"+this->password+"'");
}

QString Medecin::getPsuedo() const
{
    return psuedo;
}

void Medecin::setPsuedo(const QString &value)
{
    psuedo = value;
}

QString Medecin::getPassword() const
{
    return password;
}

void Medecin::setRole(const QString &value)
{
    role = value;
}

QString Medecin::getRole() const
{
    return role;
}

QString Medecin::toString(){
    return "["+this->getf_name()+"]"+"["+this->getl_name()+"]"+"["+this->getadresse()+"]"+"["+this->getphone_number()+"]"+"["+this->password+"]"+"["+this->psuedo+"]"+"["+this->role+"]";
}

bool operator==(const Medecin &a, const Medecin &b)
{
    return (a.getPsuedo() == b.getPsuedo() && a.getPassword() == b.getPassword() && a.getRole() == b.getRole());
}

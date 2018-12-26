#include "patient.h"
#include <QtSql>
Patient::Patient()
{

}

Patient::Patient(QString f_name,QString l_name,QString adresse,QString phone_number,
                 QString allergy,QString other,QString doc,Utilisateur createdby)
: Utilisateur(f_name,l_name,adresse,phone_number)
{
    this->allergy =allergy;
    this->other=other;
    this->createdby =createdby;
    this->doc = doc;

}

QString Patient::getOther() const
{
    return other;
}

void Patient::setOther(const QString &value)
{
    other = value;
}

Utilisateur Patient::getCreatedby() const
{
    return createdby;
}

void Patient::setCreatedby(const Utilisateur &value)
{
    createdby = value;
}

QString Patient::getDoc() const
{
    return doc;
}

void Patient::setDoc(const QString &value)
{
    doc = value;
}

QString Patient::getAllergy() const
{
    return allergy;
}

void Patient::setAllergy(const QString &value)
{
    allergy = value;
}

bool Patient::addPatient()
{
    QSqlQuery query ;
    return query.exec("INSERT INTO `patient` ( `F_NAME`, `L_NAME`, `ADDRESS`, `PHONE_NUMBER`, `ALLERGY`, `OTHER`, `CREATED_BY`, `DOC`) "
               "VALUES ('"+this->getf_name()+"', '"+this->getl_name()+"', '"+this->getadresse()+
                  "', '"+this->getphone_number()+"', '"+this->allergy+"', '"+this->other+"', '"+
                  this->createdby.getf_name()+"', '"+this->doc+"')");
}

bool Patient::updatePatient(QString id)
{
    QSqlQuery query ;
    return query.exec("UPDATE  `patient` SET  "
                      "`F_NAME`='"+this->getf_name()+"', "
                      "`L_NAME`='"+this->getl_name()+"',"
                      " `ADDRESS`='"+this->getadresse()+"', "
                      "`PHONE_NUMBER`='"+this->getphone_number()+"', "
                      "`ALLERGY`='"+this->allergy+"', "
                      "`OTHER`='"+this->other+"', "
                      "`CREATED_BY`='"+this->createdby.getf_name()+"', "
                      "`DOC`='"+this->doc+"' "
               "WHERE ID_PATIENT ="+id+"");
}

bool Patient::deletePatient(QString id)
{
    QSqlQuery query ;
    return query.exec("DELETE from 'patient' where id_patient ='"+id+"'");
}



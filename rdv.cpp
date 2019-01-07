#include "rdv.h"
#include <QtSql>
RDV::RDV()
{

}
RDV:: RDV(QString date, QString patient,Utilisateur createdby,QString doc,QString description)
{
    this->date = date;
    this->patient = patient;
    this->createdby = createdby;
    this->doc = doc;
    this->description = description;
}

QString RDV::getDate() const
{
    return date;
}

void RDV::setDate(const QString &value)
{
    date = value;
}

QString RDV::getDoc() const
{
    return doc;
}

void RDV::setDoc(const QString &value)
{
    doc = value;
}

QString RDV::getPatient() const
{
    return patient;
}

void RDV::setPatient(QString value)
{
    patient = value;
}

Utilisateur RDV::getCreatedby() const
{
    return createdby;
}

void RDV::setCreatedby(const Utilisateur &value)
{
    createdby = value;
}

QString RDV::getDescription() const
{
    return description;
}

void RDV::setDescription(const QString &value)
{
    description = value;
}


bool RDV::addRDV()
{
    QSqlQuery query ;
    return query.exec("INSERT INTO `rdv` ( DATE	,PATIENT,CREATED_BY,DOC,DESCRIPTION) "
               "VALUES ('"+this->getDate()+"', '"+this->getPatient()+
                      "', '"+this->getCreatedby().getf_name()+
                  "', '"+this->getDoc()+"', '"+this->getDescription()+"')");
}

QString RDV::getIDPatientbyRdvId(QString id)
{
    QSqlQuery query;
    QString patient;

        if(query.exec("SELECT * FROM patient,rdv "
                      "where rdv.id_rdv = "+id+" and patient.f_name = (select patient from rdv where id_rdv="+id+")"))
        {
            while (query.next())
            {
                 patient = query.value(0).toString();
            }
            return patient;
        }
        else return nullptr;

}

RDV* RDV::getRdvById(QString id){
     QSqlQuery query;
     QString date,  patient, doc, description;
     Utilisateur createdby;
        if(query.exec("SELECT * FROM rdv where id_rdv = "+id+""))
        {
            while (query.next())
            {
                 date = query.value(1).toString();
                 patient = query.value(2).toString();
                 doc = query.value(4).toString();
                 description = query.value(5).toString();
                 Utilisateur(query.value(3).toString(),"","","");
            }
            return new RDV(date,patient,createdby,doc,description);
        }
        else return nullptr;

}

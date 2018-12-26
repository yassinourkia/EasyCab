#include "rdv.h"

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

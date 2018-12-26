#include "state.h"

State::State()
{

}

State::State( QString comments,QString PHARMACEUTICALS, QString date,QString FINAL, QString patient,QString rdv){
    this->comments = comments;
    this->PHARMACEUTICALS = PHARMACEUTICALS;
    this->date = date;
    this->patient = patient;
    this->rdv = rdv;
    this->FIANL = FINAL;
}


QString State::getComments() const
{
    return comments;
}

void State::setComments(const QString &value)
{
    comments = value;
}

QString State::getPHARMACEUTICALS() const
{
    return PHARMACEUTICALS;
}

void State::setPHARMACEUTICALS(const QString &value)
{
    PHARMACEUTICALS = value;
}

QString State::getPatient() const
{
    return patient;
}

void State::setPatient(const QString &value)
{
    patient = value;
}

QString State::getRdv() const
{
    return rdv;
}

void State::setRdv(const QString &value)
{
    rdv = value;
}

QString State::getDate() const
{
    return date;
}

void State::setDate(const QString &value)
{
    date = value;
}
QString State::getFIANL() const
{
    return FIANL;
}

void State::setFIANL(const QString &value)
{
    FIANL = value;
}

bool State::addState(){
    QSqlQuery query ;
    return query.exec("INSERT INTO `state` ( COMMENTS,PHARMACEUTICALS,DATE,FIANL,RDV,PATIENT) "
               "VALUES ('"+this->getComments()+"', '"+this->getPHARMACEUTICALS()+
                      "', '"+this->getDate()+
                  "', '"+this->getFIANL()+"', '"+this->getRdv()+"','"+this->getPatient()+"')");
}
bool State::deleteState(QString id){
    QSqlQuery query ;
    return query.exec("DELETE from 'state' where ID_STATE ='"+id+"'");
}
bool State::selectState(QString id){
    QSqlQuery query ;
    return query.exec("select * from 'state' where ID_STATE ='"+id+"'");
}



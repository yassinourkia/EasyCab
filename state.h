#ifndef STATE_H
#define STATE_H
#include <QString>
#include <QSqlQuery>
#include "utilisateur.h"

class State
{
public:
    State( QString comments,QString PHARMACEUTICALS, QString date,QString FINAL, QString patient,QString rdv);
    State();
    //State(QString index);
    QString getComments() const;
    void setComments(const QString &value);

    QString getPHARMACEUTICALS() const;
    void setPHARMACEUTICALS(const QString &value);

    QString getPatient() const;
    void setPatient(const QString &value);

    QString getRdv() const;
    void setRdv(const QString &value);

    QString getDate() const;
    void setDate(const QString &value);

    bool addState();
    bool deleteState(QString id);
    bool selectState(QString id);

    QString getFIANL() const;
    void setFIANL(const QString &value);

private :
    QString comments;
    QString PHARMACEUTICALS;
    QString date,FIANL;
    QString patient,rdv;


};

#endif // STATE_H

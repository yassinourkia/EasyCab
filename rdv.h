#ifndef RDV_H
#define RDV_H
#include <QString>
#include "utilisateur.h"
#include "patient.h"
#include <QSqlQuery>
/*!
 * \brief The RDV class
 * \authors MANAL BEKAOUI - OURKIA YASSIN
 */
class RDV
{
public:
    RDV();
    RDV(QString date, QString patient,Utilisateur createdby,QString doc,QString description);
    QString getDate() const;
    void setDate(const QString &value);

    QString getDoc() const;
    void setDoc(const QString &value);

    QString getPatient() const;
    void setPatient(QString value);

    Utilisateur getCreatedby() const;
    void setCreatedby(const Utilisateur &value);

    QString getDescription() const;
    void setDescription(const QString &value);

    QString getIDPatientbyRdvId(QString id);
    bool addRDV();
    bool deleteRDV(QString id);
    bool updateRDV(QString id);
    RDV* getRdvById(QString id);



private :
    QString date,doc;
    Utilisateur createdby;
    QString patient;
    QString description;
    typedef Utilisateur super;
};

#endif // RDV_H

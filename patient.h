#ifndef PATIENT_H
#define PATIENT_H
#include "utilisateur.h"
#include <QObject>

class Patient : public Utilisateur
{
public:

    Patient();
    Patient(QString f_name,QString l_name,QString adresse,QString phone_number,
            QString allergy,QString other,QString doc,Utilisateur);


    QString getOther() const;
    void setOther(const QString &value);

    Utilisateur getCreatedby() const;
    void setCreatedby(const Utilisateur &value);

    QString getDoc() const;
    void setDoc(const QString &value);

    QString getAllergy() const;
    void setAllergy(const QString &value);

    bool addPatient();
    bool deletePatient(QString id);
    bool updatePatient(QString id);
    Patient getPatient(QString f_name);

private:
    QString allergy,other;
    Utilisateur createdby;
    QString doc;
    typedef Utilisateur super;
};

#endif // PATIENT_H

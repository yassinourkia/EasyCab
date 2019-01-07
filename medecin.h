#ifndef MEDECIN_H
#define MEDECIN_H
#include "utilisateur.h"
#include "connect.h"
#include <QtSql>

class Medecin : public Utilisateur
{
    friend bool operator==(Medecin const& a, Medecin const& b);

public:
    Medecin();
    Medecin(QString f_name,QString l_name,QString adresse,QString phone_number,QString pseudo, QString password,QString role);
    Medecin(QString psuedo, QString password,QString role);
    bool Login();
    QString getPsuedo() const;
    void setPsuedo(const QString &value);

    QString getPassword() const;
    QString toString();

    QString getRole() const;
    void setRole(const QString &value);

private:
    QString psuedo, password,role;


};

#endif // MEDECIN_H

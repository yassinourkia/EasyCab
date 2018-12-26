#ifndef SECRETAIRE_H
#define SECRETAIRE_H
#include "utilisateur.h"
#include "connect.h"
class Secretaire : Utilisateur
{
public:
    Secretaire();
    Secretaire(QString pseudo, QString password);
    bool Login();
    QString getPsuedo() const;
    void setPsuedo(const QString &value);

    QString getPassword() const;

private:
    QString psuedo, password;

};

#endif // SECRETAIRE_H

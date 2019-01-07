#ifndef SECRETAIRE_H
#define SECRETAIRE_H
#include "utilisateur.h"
#include "connect.h"
/*!
 * \brief The Secretaire class
 * \authors MANAL BEKAOUI - OURKIA YASSIN
 */
class Secretaire : public Utilisateur
{
    friend bool operator==(Secretaire const& a, Secretaire const& b);

public:
    Secretaire();
    Secretaire(QString f_name,QString l_name,QString adresse,QString phone_number,QString pseudo, QString password);
    Secretaire(QString psuedo, QString password);
    bool Login();
    QString getPsuedo() const;
    void setPsuedo(const QString &value);

    QString getPassword() const;
    QString toString();

private:
    QString psuedo, password;

};

#endif // SECRETAIRE_H

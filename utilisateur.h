#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include <QString>

class Utilisateur
{

public:
    Utilisateur();
    Utilisateur(QString f_name,QString l_name,QString adresse,QString phone_number );


    // getters
    QString getf_name();
    QString getl_name();
    QString getadresse();
    QString getphone_number();
    // setters
    void setf_name(QString f_name);
    void setl_name(QString l_name);
    void setadresse(QString adresse);
    void setphone_number(QString phone_number);
    // display
    QString toString();

private :
    QString f_name, l_name, adresse, phone_number;



};

#endif // UTILISATEUR_H

#include "utilisateur.h"
//constructeurs
Utilisateur::Utilisateur(){}
Utilisateur:: Utilisateur(QString f_name,QString l_name,QString adresse,QString phone_number ){
    this->f_name = f_name;
    this->l_name = l_name;
    this->adresse= adresse;
    this->phone_number = phone_number;
}

QString Utilisateur::getf_name(){return this->f_name;}
QString Utilisateur::getl_name(){return this->l_name;}
QString Utilisateur::getadresse(){return this->adresse;}
QString Utilisateur::getphone_number(){return this->phone_number;}
// setters
void Utilisateur::setf_name(QString f_name){this->f_name =f_name;}
void Utilisateur::setl_name(QString l_name){this->l_name =l_name;}
void Utilisateur::setadresse(QString adresse){this->adresse =adresse;}
void Utilisateur::setphone_number(QString phone_number){this->phone_number =phone_number;}
// display
QString Utilisateur::toString(){return "["+this->f_name+"]"+"["+this->l_name+"]"+"["+this->adresse+"]"+"["+this->phone_number+"]";}

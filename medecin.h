#ifndef MEDECIN_H
#define MEDECIN_H
#include "utilisateur.h"
#include "connect.h"
#include <QtSql>
/*!
 * \brief The Medecin class the doctor class inherited user class
 * \authors MANAL BEKAOUI - OURKIA YASSIN
 */
class Medecin : public Utilisateur
{
    /*!
     * \brief operator == reload the operator in order to compare two doctors using their psuedo, password and role
     * \param a first doctor
     * \param b second doctor
     * \return  true if the two objects are equals ( a.psuedo =b.psuedo , a.password=b.password,a.role=b.role)
     */
    friend bool operator==(Medecin const& a, Medecin const& b);

public:
    /*!
     * \brief Medecin default constructor
     */
    Medecin();
    /*!
     * \brief Medecin  Constructor with args
     * \param f_name
     * \param l_name
     * \param adresse
     * \param phone_number
     * \param pseudo
     * \param password
     * \param role
     */
    Medecin(QString f_name,QString l_name,QString adresse,QString phone_number,QString pseudo, QString password,QString role);
    /*!
     * \brief Medecin constrcutor with 3 args
     * \param psuedo
     * \param password
     * \param role
     */
    Medecin(QString psuedo, QString password,QString role);
    /*!
     * \brief Login method to login to the system
     * \return true if he sign in
     */
    bool Login();
    /*!
     * \brief getPsuedo get the pseudo of the user
     * \return  pseudo of the doctor
     */
    QString getPsuedo() const;
    /*!
     * \brief setPsuedo set the pseudo value with the input value
     * \param value the updated balue of pseudo
     */
    void setPsuedo(const QString &value);
    /*!
     * \brief getPassword get the password value
     * \return value the updated balue of password
     */
    QString getPassword() const;
    /*!
     * \brief toString
     * \return
     */
    QString toString();
    /*!
     * \brief getRole get the Role value
     * \return  role value
     */
    QString getRole() const;
    /*!
     * \brief setRole set the role value with the input value
     * \param value the updated value of role
     */
    void setRole(const QString &value);

private:
    QString psuedo, password,role;


};

#endif // MEDECIN_H

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
    /*!
     * \brief operator == reload the operator by evaluate
     * \param a
     * \param b
     * \return
     */
    friend bool operator==(Secretaire const& a, Secretaire const& b);

public:
    /*!
     * \brief Secretaire Default constructor
     */
    Secretaire();
    /*!
     * \brief Secretaire constructor with args
     * \param f_name
     * \param l_name
     * \param adresse
     * \param phone_number
     * \param pseudo
     * \param password
     */
    Secretaire(QString f_name,QString l_name,QString adresse,QString phone_number,QString pseudo, QString password);
    /*!
     * \brief Secretaire default with two args
     * \param psuedo
     * \param password
     */
    Secretaire(QString psuedo, QString password);
    /*!
     * \brief Login method to verif if the user is logged in
     * \return true if it's logged in
     */
    bool Login();
    /*!
     * \brief getPsuedo get a psuedo value
     * \return psuedo value
     */
    QString getPsuedo() const;
    /*!
     * \brief setPsuedo set psuedo value using the input value
     * \param value the input value
     */
    void setPsuedo(const QString &value);
    /*!
     * \brief getPassword get a password value
     * \return password value
     */
    QString getPassword() const;
    /*!
     * \brief toString return the object in string fromat
     * \return  object in string format
     */
    QString toString();

private:
    QString psuedo, password;

};

#endif // SECRETAIRE_H

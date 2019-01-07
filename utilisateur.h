#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include <QString>
/*!
 * \brief The Utilisateur class the user class where the common information between the user of application are implemented
 * \authors MANAL BEKAOUI - OURKIA YASSIN
 */
class Utilisateur
{

public:
    /*!
     * \brief Utilisateur default constructor
     */
    Utilisateur();
    /*!
     * \brief Utilisateur constructor with args
     * \param f_name first name
     * \param l_name last name
     * \param adresse adresse
     * \param phone_number phone number
     */
    Utilisateur(QString f_name,QString l_name,QString adresse,QString phone_number );


    // getters
    /*!
     * \brief getf_name get the first name value
     * \return first the name value
     */
    QString getf_name();
    /*!
     * \brief getl_name get the last name value
     * \return last name value
     */
    QString getl_name();
    /*!
     * \brief getadresse get the adresse  value
     * \return addresse value
     */
    QString getadresse();
    /*!
     * \brief getphone_number get the phone number value
     * \return phone number value
     */
    QString getphone_number();
    // setters
    /*!
     * \brief setf_name set the first name value with the input value
     * \param f_name the first name input value
     */
    void setf_name(QString f_name);
    /*!
     * \brief setl_name set the last name value with the input value
     * \param l_name the last name input value
     */
    void setl_name(QString l_name);
    /*!
     * \brief setadresse set the addresse value with the input value
     * \param adresse the input value
     */
    void setadresse(QString adresse);
    /*!
     * \brief setphone_number set the phone number value with the input value
     * \param phone_number the input value
     */
    void setphone_number(QString phone_number);
    // display
    /*!
     * \brief toString the string format of the object
     * \return  string object
     */
    QString toString();

private :
    QString f_name, l_name, adresse, phone_number;



};

#endif // UTILISATEUR_H

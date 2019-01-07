#ifndef PATIENT_H
#define PATIENT_H
#include "utilisateur.h"
#include <QObject>
/*!
 * \brief The Patient class to implement all patient methods herited from user class
 * \authors MANAL BEKAOUI - OURKIA YASSIN
 */
class Patient : public Utilisateur
{
public:
    /*!
     * \brief Patient Constructors of the class
     */
    Patient();
    Patient(QString f_name,QString l_name,QString adresse,QString phone_number,
            QString allergy,QString other,QString doc,Utilisateur);

    /*!
     * \brief getOther function to get the other field
     * \return the value of other field
     */
    QString getOther() const;
    /*!
     * \brief setOther function set the other value with the input value
     * \param value
     */
    void setOther(const QString &value);

    /*!
     * \brief getCreatedby function to get the created by field
     * \return the value of created by
     */
    Utilisateur getCreatedby() const;
    /*!
     * \brief setCreatedby function set the createdby value with the input value
     * \param value
     */
    void setCreatedby(const Utilisateur &value);
    /*!
     * \brief getDoc function to get the Doc field
     * \return the value of Doc
     */
    QString getDoc() const;
    /*!
     * \brief setDoc function set the Doc value with the input value
     * \param value
     */
    void setDoc(const QString &value);
    /*!
     * \brief getAllergy function to get the allergy field
     * \return the value of allergy
     */
    QString getAllergy() const;
    /*!
     * \brief setAllergy function set the Allergy value with the input value
     * \param value
     */
    void setAllergy(const QString &value);
    /*!
     * \brief addPatient the function to add a patient to database
     * \return true if the addition is done successfully
     */
    bool addPatient();
    /*!
     * \brief deletePatient the function to delete a patient from a database
     * \param id the id of patient to be deleted
     * \return true if the delete is done successfully
     */
    bool deletePatient(QString id);
    /*!
     * \brief updatePatient the function to update a patient in database using an id as input
     * \param id the id of the patient to be updated
     * \return true if the update is done successfully
     */
    bool updatePatient(QString id);
    /*!
     * \brief getPatient function to get a Patient Object with his first name
     * \param f_name the first name of the patient
     * \return Patient object
     */
    Patient getPatient(QString f_name);
    /*!
     * \brief getPatient function to get a Patient Object with his ID
     * \param id of the patient
     * \return Patient Object
     */
    Patient* getPatientById(QString id);

private:
    QString allergy,other;
    Utilisateur createdby;
    QString doc;
    typedef Utilisateur super;
};

#endif // PATIENT_H

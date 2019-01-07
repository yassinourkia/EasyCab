#ifndef STATE_H
#define STATE_H
#include <QString>
#include <QSqlQuery>
#include "utilisateur.h"
/*!
 * \brief The State class allows to check the patient and make a historic of his treatments
 * \authors MANAL BEKAOUI - OURKIA YASSIN
 */
class State
{
public:
    /*!
     * \brief State Constructor with args
     * \param comments
     * \param PHARMACEUTICALS
     * \param date
     * \param FINAL
     * \param patient
     * \param rdv
     */
    State( QString comments,QString PHARMACEUTICALS, QString date,QString FINAL, QString patient,QString rdv);
    /*!
     * \brief State Default constructor
     */
    State();
    //State(QString index);
    /*!
     * \brief getComments get the comment field value
     * \return comment value
     */
    QString getComments() const;
    /*!
     * \brief setComments set comment field with the input value
     * \param value
     */
    void setComments(const QString &value);
    /*!
     * \brief getPHARMACEUTICALS get the PHARMACEUTICALS field value
     * \return PHARMACEUTICALS value
     */
    QString getPHARMACEUTICALS() const;
    /*!
     * \brief setPHARMACEUTICALS set Pharmaceuticals field with the input value
     * \param value
     */
    void setPHARMACEUTICALS(const QString &value);
    /*!
     * \brief getPatient get the patient id field value
     * \return  patient value
     */
    QString getPatient() const;
    /*!
     * \brief setPatient set patient id  field with the input value
     * \param value
     */
    void setPatient(const QString &value);
    /*!
     * \brief getRdv get the Rdv id field value
     * \return RDV id value
     */
    QString getRdv() const;
    /*!
     * \brief setRdv set rdv id field with the input value
     * \param value
     */
    void setRdv(const QString &value);
    /*!
     * \brief getDate get the date field value
     * \return date value
     */
    QString getDate() const;
    void setDate(const QString &value);
    /*!
     * \brief addState add a state to the database
     * \return true if it's added successfully
     */
    bool addState();
    /*!
     * \brief deleteState delete a state from the database using its index
     * \param id index of state
     * \return  true if it's deleted successefully
     */
    bool deleteState(QString id);
    /*!
     * \brief selectState select a state using its index
     * \param id index of state
     * \return false if there's no record in the database
     */
    bool selectState(QString id);
    /*!
     * \brief getFIANL
     * \return
     */
    QString getFIANL() const;
    /*!
     * \brief setFIANL
     * \param value
     */
    void setFIANL(const QString &value);

private :
    QString comments;
    QString PHARMACEUTICALS;
    QString date,FIANL;
    QString patient,rdv;


};

#endif // STATE_H

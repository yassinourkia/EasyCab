#ifndef RDV_H
#define RDV_H
#include <QString>
#include "utilisateur.h"
#include "patient.h"
#include <QSqlQuery>
/*!
 * \brief The RDV class allows to add an appointment by a user
 * \authors MANAL BEKAOUI - OURKIA YASSIN
 */
class RDV
{
public:
    /*!
     * \brief RDV default constructor
     */
    RDV();
    /*!
     * \brief RDV constructor with paramas
     * \param date
     * \param patient
     * \param createdby
     * \param doc
     * \param description
     */
    RDV(QString date, QString patient,Utilisateur createdby,QString doc,QString description);
    /*!
     * \brief getDate get the date value
     * \return
     */
    QString getDate() const;
    /*!
     * \brief setDate set the date value
     * \param value
     */
    void setDate(const QString &value);
    /*!
     * \brief getDoc get the doc value
     * \return
     */
    QString getDoc() const;
    /*!
     * \brief setDoc set the doc value
     * \param value
     */
    void setDoc(const QString &value);
    /*!
     * \brief getPatient get the patient value
     * \return
     */
    QString getPatient() const;
    /*!
     * \brief setPatient set the patient value
     * \param value
     */
    void setPatient(QString value);
    /*!
     * \brief getCreatedby get the createdby value
     * \return
     */
    Utilisateur getCreatedby() const;
    /*!
     * \brief setCreatedby set the createdby value
     * \param value
     */
    void setCreatedby(const Utilisateur &value);
    /*!
     * \brief getDescription get the descr value
     * \return
     */
    QString getDescription() const;
    /*!
     * \brief setDescription set the descr value
     * \param value
     */
    void setDescription(const QString &value);
    /*!
     * \brief getIDPatientbyRdvId get an ID patient by using the RDV id
     * \param id the rdv id
     * \return the patient id
     */
    QString getIDPatientbyRdvId(QString id);
    /*!
     * \brief addRDV add the rdv to the database
     * \return
     */
    bool addRDV();
    /*!
     * \brief deleteRDV delete a rdv from the database using its id
     * \param id of the rdv
     * \return
     */
    bool deleteRDV(QString id);
    /*!
     * \brief updateRDV update a rdv in database
     * \param id of the rdv
     * \return
     */
    bool updateRDV(QString id);
    /*!
     * \brief getRdvById get a RDV object by using its id
     * \param id of the rdv
     * \return
     */
    RDV* getRdvById(QString id);



private :
    QString date,doc;
    Utilisateur createdby;
    QString patient;
    QString description;
    typedef Utilisateur super;
};

#endif // RDV_H

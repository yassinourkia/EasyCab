#ifndef SECRETARYINTERFACE_H
#define SECRETARYINTERFACE_H
#include "listrdv.h"
#include "patientmanagement.h"
#include "rdvform.h"
#include <QWidget>

namespace Ui {
class SecretaryInterface;
}
/*!
 * \brief The SecretaryInterface class the secretary dashboard to manage his activites
 * \authors MANAL BEKAOUI - OURKIA YASSIN
 */
class SecretaryInterface : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief SecretaryInterface constructor to instanciate connection with database
     * \param parent the graphic container
     */
    explicit SecretaryInterface(QWidget *parent = nullptr);
    /*!
     * \brief SecretaryInterface contructor with user as paramater
     * \param user the current user of the application
     */
    explicit SecretaryInterface(QString user);
    ~SecretaryInterface();

private slots:
    /*!
     * \brief on_Patients_clicked to get to the patient management form
     */
    void on_Patients_clicked();
    /*!
     * \brief on_Rdvs_clicked to get to the RDV form
     */
    void on_Rdvs_clicked();
    /*!
     * \brief on_logout_clicked to loggout in the system
     */
    void on_logout_clicked();

private:
    Ui::SecretaryInterface *ui;
    QString user;
};

#endif // SECRETARYINTERFACE_H

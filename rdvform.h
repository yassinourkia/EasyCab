#ifndef RDVFORM_H
#define RDVFORM_H

#include <QWidget>
#include "connect.h"
#include <QFileDialog>
#include "utilisateur.h"
#include "rdv.h"
#include "patient.h"
#include "listrdv.h"
#include "patient.h"
namespace Ui {
class RdvForm;
}
/*!
 * \brief The RdvForm class gui to add an appointment
 * \authors MANAL BEKAOUI - OURKIA YASSIN
 */
class RdvForm : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief RdvForm constructor
     * \param parent graphic container
     * \param user the current user of the app
     */
    explicit RdvForm(QWidget *parent = nullptr,QString user=nullptr);
    ~RdvForm();
    /*!
     * \brief getPatient get a patient object by his name
     * \param fname first name of the patient
     * \return  patient object
     */
    Patient* getPatient(QString fname);

private slots:
    /*!
     * \brief on_charge_clicked to upload files links to the database
     */
    void on_charge_clicked();
    /*!
     * \brief on_add_clicked to add an appointment to the database
     */
    void on_add_clicked();
    /*!
     * \brief on_dashboard_clicked to return to the dashboard form
     */
    void on_dashboard_clicked();

    void on_listrdv_clicked();

private:
    Ui::RdvForm *ui;
    Connect *cn;
    QString fileName;
    QString user;
};

#endif // RDVFORM_H

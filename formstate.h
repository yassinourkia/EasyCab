#ifndef FORMSTATE_H
#define FORMSTATE_H

#include <QWidget>
#include "connect.h"
#include "rdv.h"
#include "state.h"
#include "patient.h"
namespace Ui {
class FormState;
}
/*!
 * \brief The FormState class the Graphic interface of the forme to manage a State of a patient
 * \authors MANAL BEKAOUI - OURKIA YASSIN
 */
class FormState : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief FormState constructor to instanciate the Form
     * \param parent the graphic Container
     */
    explicit FormState(QWidget *parent = nullptr,QString doctor = nullptr);
    /*!
     * \brief FormState distructor to kill the variables
     */
     explicit FormState(QString rdv ,QString doctor);
    ~FormState();

private slots:
    /*!
     * \brief on_add_clicked the slot to do when the button add is clicked
     */
    void on_add_clicked();
    /*!
     * \brief on_dashboard_clicked the slot to do when the button of dashbord is clicked
     */
    void on_dashboard_clicked();

    void on_charge_clicked();

private:
    Ui::FormState *ui;
    Connect *cn;
    Patient *patient;
    RDV* rdv;
    State* state;
    QString doctor;
    QString fileName;

};

#endif // FORMSTATE_H

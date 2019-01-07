#ifndef PATIENTMANAGEMENT_H
#define PATIENTMANAGEMENT_H

#include <QWidget>
#include "connect.h"
namespace Ui {
class PatientManagement;
}
/*!
 * \brief The PatientManagement class
 * \authors MANAL BEKAOUI - OURKIA YASSIN
 */
class PatientManagement : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief PatientManagement Constructor
     * \param parent graphic container
     * \param added_by the current user
     */
    explicit PatientManagement(QWidget *parent = nullptr,QString added_by = nullptr);
    ~PatientManagement();

private slots:
    /*!
     * \brief on_list_activated to manage the model list
     * \param index the id selected on the list
     */
    void on_list_activated(const QModelIndex &index);
    /*!
     * \brief on_pushButton_clicked
     */
    void on_pushButton_clicked();
    /*!
     * \brief on_delete_2_clicked to delete a patient
     */

    void on_delete_2_clicked();
    /*!
     * \brief on_toolButton_clicked
     */

    void on_toolButton_clicked();
    /*!
     * \brief on_add_clicked add a patient
     */
    void on_add_clicked();
    /*!
     * \brief RechargeModel reload the model list with the updated data from database
     */
    void RechargeModel();
    /*!
     * \brief on_dashboard_clicked to return to the dashboard form
     */
    void on_dashboard_clicked();

private:
    Ui::PatientManagement *ui;
    Connect *cn;
    QString fileName;
    QString user;
};

#endif // PATIENTMANAGEMENT_H

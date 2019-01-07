#ifndef LISTPATIENTS_H
#define LISTPATIENTS_H

#include <QWidget>
#include "connect.h"
#include <QtSql>
#include "doctordashboard.h"
namespace Ui {
class ListPatients;
}
/*!
 * \brief The ListPatients class the List of all the patients registred in the cabinent Database
 * \authors MANAL BEKAOUI - OURKIA YASSIN
 */
class ListPatients : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief ListPatients cuntructor to instanciate the model and graphics
     * \param user the name of the current user
     */
    explicit ListPatients(QString user);
    ~ListPatients();
    /*!
     * \brief RechargeModel the reload the model with the updated data from the database
     */
    void RechargeModel();

private slots:
    /*!
     * \brief on_dashboard_clicked to return to the dashboard interface
     */
    void on_dashboard_clicked();
    /*!
     * \brief on_list_activated to recharge the list with its contents from the database
     * \param index the id of the patient to be displayed
     */
    void on_list_activated(const QModelIndex &index);

private:
    Ui::ListPatients *ui;
    Connect* cn;
    QString user;
};

#endif // LISTPATIENTS_H

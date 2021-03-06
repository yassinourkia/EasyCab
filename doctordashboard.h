#ifndef DOCTORDASHBOARD_H
#define DOCTORDASHBOARD_H

#include <QWidget>

namespace Ui {
class DoctorDashboard;
}
/*!
 * \brief The DoctorDashboard class the dashboard where the doctor can manage his own tasks
 */
class DoctorDashboard : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief DoctorDashboard contrcutor to instanciate the application
     * \param user the name of the actual connected user
     */
    explicit DoctorDashboard(QString user);
    ~DoctorDashboard();

private slots:
    /*!
     * \brief on_Rdvs_clicked to manage the appointment of the current day
     */
    void on_Rdvs_clicked();
    /*!
     * \brief on_Patients_clicked to show the infos about patients
     */
    void on_Patients_clicked();
    /*!
     * \brief on_logout_clicked to logout
     */
    void on_logout_clicked();



private:
    Ui::DoctorDashboard *ui;
    QString user;
};

#endif // DOCTORDASHBOARD_H

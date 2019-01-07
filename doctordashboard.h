#ifndef DOCTORDASHBOARD_H
#define DOCTORDASHBOARD_H

#include <QWidget>

namespace Ui {
class DoctorDashboard;
}

class DoctorDashboard : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorDashboard(QString user);
    ~DoctorDashboard();

private slots:
    void on_Rdvs_clicked();

    void on_Patients_clicked();

    void on_logout_clicked();



private:
    Ui::DoctorDashboard *ui;
    QString user;
};

#endif // DOCTORDASHBOARD_H

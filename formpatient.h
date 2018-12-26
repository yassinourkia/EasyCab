#ifndef FORMPATIENT_H
#define FORMPATIENT_H
#include "connect.h"
#include "mainwindow.h"
#include "patientmanagement.h"
#include <QWidget>

namespace Ui {
class FormPatient;
}

class FormPatient : public QWidget
{
    Q_OBJECT

public:
    explicit FormPatient(QWidget *parent = nullptr);
    ~FormPatient();

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

private:
    Ui::FormPatient *ui;
    Connect *cn;
    MainWindow window;
    PatientManagement* view;
};

#endif // FORMPATIENT_H

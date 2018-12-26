#ifndef PATIENTUI_H
#define PATIENTUI_H
#include "connect.h"
#include "mainwindow.h"
#include <QWidget>

namespace Ui {
class PatientUi;
}

class PatientUi : public QWidget
{
    Q_OBJECT

public:
    explicit PatientUi(QWidget *parent = nullptr);
    ~PatientUi();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PatientUi *ui;
    Connect *cn;
    MainWindow window;
};

#endif // PATIENTUI_H

#ifndef SECRETARYINTERFACE_H
#define SECRETARYINTERFACE_H
#include "listrdv.h"
#include "patientmanagement.h"
#include "formstate.h"
#include <QWidget>

namespace Ui {
class SecretaryInterface;
}

class SecretaryInterface : public QWidget
{
    Q_OBJECT

public:
    explicit SecretaryInterface(QWidget *parent = nullptr);
    explicit SecretaryInterface(QString user);
    ~SecretaryInterface();

private slots:
    void on_Patients_clicked();

    void on_States_clicked();

    void on_Rdvs_clicked();


private:
    Ui::SecretaryInterface *ui;
};

#endif // SECRETARYINTERFACE_H

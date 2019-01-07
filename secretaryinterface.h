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
 * \brief The SecretaryInterface class
 * \authors MANAL BEKAOUI - OURKIA YASSIN
 */
class SecretaryInterface : public QWidget
{
    Q_OBJECT

public:
    explicit SecretaryInterface(QWidget *parent = nullptr);
    explicit SecretaryInterface(QString user);
    ~SecretaryInterface();

private slots:
    void on_Patients_clicked();

    void on_Rdvs_clicked();


    void on_logout_clicked();

private:
    Ui::SecretaryInterface *ui;
    QString user;
};

#endif // SECRETARYINTERFACE_H

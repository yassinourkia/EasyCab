#ifndef RDVFORM_H
#define RDVFORM_H

#include <QWidget>
#include "connect.h"
#include <QFileDialog>
#include "utilisateur.h"
#include "rdv.h"
#include "patient.h"
#include "listrdv.h"
namespace Ui {
class RdvForm;
}

class RdvForm : public QWidget
{
    Q_OBJECT

public:
    explicit RdvForm(QWidget *parent = nullptr);
    ~RdvForm();
    Patient* getPatient(QString fname);

private slots:

    void on_charge_clicked();

    void on_add_clicked();

private:
    Ui::RdvForm *ui;
    Connect *cn;
    QString fileName;
};

#endif // RDVFORM_H

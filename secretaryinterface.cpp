#include "secretaryinterface.h"
#include "ui_secretaryinterface.h"

SecretaryInterface::SecretaryInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SecretaryInterface)
{
    ui->setupUi(this);
    QPixmap patienticon ("/Users/ourkia/Desktop/Patient.png");
    QPixmap rdvicon ("/Users/ourkia/Desktop/rdv.png");
    QPixmap stateicon ("/Users/ourkia/Desktop/Patient.png");


    ui->patients->setPixmap(patienticon);
    ui->Rdv->setPixmap(rdvicon);
    ui->states->setPixmap(stateicon);

}

SecretaryInterface::~SecretaryInterface()
{
    delete ui;
}

#include "secretaryinterface.h"
#include "ui_secretaryinterface.h"
#include "patientmanagement.h"

SecretaryInterface::SecretaryInterface(QString user) :
    ui(new Ui::SecretaryInterface)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(698,459));
    ui->label->setText("Bonjour : ");
    ui->user->setText(user);
    QString date = QDate::currentDate().toString("dd/MM/yyyy");
    ui->date->setText(date);


    QIcon patienticon ("/Users/ourkia/Desktop/easycab/Patient.png");
    QIcon rdvicon ("/Users/ourkia/Desktop/easycab/rdv.png");
    QIcon stateicon ("/Users/ourkia/Desktop/easycab/state.png");

    QSize size (220,240);
    ui->Patients->setIconSize(size);
    ui->Rdvs->setIconSize(size);
    ui->States->setIconSize(size);

    ui->Patients->setIcon(patienticon);
    ui->Rdvs->setIcon(rdvicon);
    ui->States->setIcon(stateicon);

}

SecretaryInterface::~SecretaryInterface()
{
    delete ui;
}

void SecretaryInterface::on_Patients_clicked()
{
    PatientManagement *w=new PatientManagement(nullptr,ui->label->text());
    w->show();
    this->hide();
}


void SecretaryInterface::on_States_clicked()
{
    FormState *w = new FormState();
    w->show();
    this->hide();


}

void SecretaryInterface::on_Rdvs_clicked()
{
    listrdv *w=new listrdv(nullptr);
    w->show();
    this->hide();

}

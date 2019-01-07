#include "secretaryinterface.h"
#include "ui_secretaryinterface.h"
#include "patientmanagement.h"
#include "accueil.h"

SecretaryInterface::SecretaryInterface(QString user) :
    ui(new Ui::SecretaryInterface)
{
    ui->setupUi(this);
    this->user = user;
    this->setWindowTitle("Dashboard");
    this->setFixedSize(QSize(698,459));
    ui->label->setText("Bonjour : ");
    ui->user->setText(this->user);
    QString date = QDate::currentDate().toString("dd/MM/yyyy");
    ui->date->setText(date);


    QIcon patienticon (":/images/scrud.png");
    QIcon rdvicon (":/images/rdv.svg");

    QSize size (200,200);
    ui->Patients->setIconSize(size);
    ui->Rdvs->setIconSize(size);

    QIcon logout (":/images/logout.png");
    ui->logout->setIconSize(QSize (50,100));
    ui->logout->setIcon(logout);

    ui->Patients->setIcon(patienticon);
    ui->Rdvs->setIcon(rdvicon);


}

SecretaryInterface::~SecretaryInterface()
{
    delete ui;
}

void SecretaryInterface::on_Patients_clicked()
{
    PatientManagement *w=new PatientManagement(nullptr,ui->user->text());
    w->show();
    this->hide();
}




void SecretaryInterface::on_Rdvs_clicked()
{

    RdvForm *w = new RdvForm(nullptr,this->user);
    w->show();
    this->hide();
}

void SecretaryInterface::on_logout_clicked()
{
    Accueil *w= new Accueil() ;
    w->show();
    this->hide();
}

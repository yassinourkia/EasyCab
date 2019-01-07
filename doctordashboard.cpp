#include "doctordashboard.h"
#include "ui_doctordashboard.h"
#include "listrdv.h"
#include "listpatients.h"
#include "accueil.h"

DoctorDashboard::DoctorDashboard(QString user) :
    ui(new Ui::DoctorDashboard)
{
    ui->setupUi(this);
    this->user = user;
    this->setWindowTitle("Dashboard");
    this->setFixedSize(QSize(800,500));
    ui->label->setText("Bonjour : ");
    ui->user->setText(this->user);
    QString date = QDate::currentDate().toString("dd/MM/yyyy");
    ui->date->setText(date);


    QIcon patienticon (":/images/listpatient.png");
    QIcon rdvicon (":/images/suivi.svg");


    QSize size (210,230);
    ui->Patients->setIconSize(size);
    ui->Rdvs->setIconSize(size);

    QIcon logout (":/images/logout.png");
    ui->logout->setIconSize(QSize (50,100));
    ui->logout->setIcon(logout);

    ui->Patients->setIcon(patienticon);
    ui->Rdvs->setIcon(rdvicon);



}

DoctorDashboard::~DoctorDashboard()
{
    delete ui;
}

void DoctorDashboard::on_Rdvs_clicked()
{
    QString date = QDate::currentDate().toString("yyyy-MM-dd");
    listrdv *w=new listrdv(date,this->user);
    w->show();
    this->hide();
}

void DoctorDashboard::on_Patients_clicked()
{
    ListPatients *w=new ListPatients(this->user);
    w->show();
    this->hide();
}



void DoctorDashboard::on_logout_clicked()
{
    Accueil *w= new Accueil() ;
    w->show();
    this->hide();
}



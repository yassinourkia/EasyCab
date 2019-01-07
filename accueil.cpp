#include "accueil.h"
#include "ui_accueil.h"

Accueil::Accueil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Accueil)
{
    ui->setupUi(this);
    this->setWindowTitle("Accueil");
    QIcon secretaire (":/images/secretaire.svg");
    QIcon doctor (":/images/doctor.svg");
    QIcon  logo(":/images/easycab.png");

    QSize size (211,201);
    ui->secretaire->setIconSize(size);
    ui->doctor->setIconSize(size);
    ui->logo->setIconSize(QSize(331,91));

    ui->secretaire->setIcon(secretaire);
    ui->doctor->setIcon(doctor);
    ui->logo->setIcon(logo);
}

Accueil::~Accueil()
{
    delete ui;
}

void Accueil::on_secretaire_clicked()
{
    LOGIN *w= new LOGIN();
    w->show();
    this->hide();
}

void Accueil::on_doctor_clicked()
{
    LoginDoctor *w= new LoginDoctor();
    w->show();
    this->hide();
}

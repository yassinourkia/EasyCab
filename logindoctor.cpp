#include "logindoctor.h"
#include "ui_logindoctor.h"
#include <QMessageBox>
LoginDoctor::LoginDoctor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginDoctor)
{
    ui->setupUi(this);
    this->setWindowTitle("Connexion");
    this->setFixedSize(QSize(400,300));
    //cn = new Connect();
    QIcon icon (":/images/easycab.png");
    QSize size (281,81);
    ui->EasyCab->setIconSize(size);
    ui->EasyCab->setIcon(icon);

    // creation des instances de Medecin
    Medecin &sec1= *new Medecin("JeanPierre","Lelouch","Lens","09589589","choguen","zorro","ophtalmologue");
    Medecin &sec2= *new Medecin("Marlene","Monroe","New York","0849488","Marlene","monroe","dentiste");

    // ajout à la liste de Medecin
    this->users.append(sec1);
    this->users.append(sec2);
}

LoginDoctor::~LoginDoctor()
{
    delete ui;
}

void LoginDoctor::on_pushButton_clicked()
{
    QString user,password;
    user= ui->user->text();
    password = ui->password->text();
    //Login  : version QList et itterator
    try
    {
        if(this->users.empty())
        {
            throw QString("Stack Empty : aucun utilisateur dans la liste");
        }
        else
        {
            QList<Medecin>::iterator i;
            bool flag = false;
            Medecin &input = *new Medecin(user,password,ui->role->property("currentText").toString());
            for (i = this->users.begin(); i != this->users.end(); i++){
                Medecin &item = *new Medecin(i->getPsuedo(),i->getPassword(),i->getRole());

                // utilisation de surcharge d'operateur ==
                if(item == input)
                {
                    DoctorDashboard *w = new DoctorDashboard(user);
                    w->show();
                    flag = true;
                    this->hide();

                }
            }
            if(!flag)
            {
                 QMessageBox::critical(this,tr("Info"),tr("Erreur : Mot de passe ou nom utilisateur incorrecte"));
            }
        }
    }catch(QString const& chaine)
    {
        qDebug() << "Exception déclenché :" + chaine ;
    }
}

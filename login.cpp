#include "login.h"
#include "ui_login.h"
#include "connect.h"
#include <QtSql>
#include "connect.h"
#include "secretaryinterface.h"
LOGIN::LOGIN(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LOGIN)
{

    ui->setupUi(this);
    this->setWindowTitle("Connexion");
    //cn = new Connect();
    this->setFixedSize(QSize(400,300));
    //cn = new Connect();
    QIcon icon (":/images/easycab.png");
    QSize size (281,81);
    ui->EasyCab->setIconSize(size);
    ui->EasyCab->setIcon(icon);

    // creation des instances de secretaire
    Secretaire &sec1= *new Secretaire("Manal","Bourekba","Temssia","09589589","Manal","manal");
    Secretaire &sec2= *new Secretaire("Marlene","Monroe","New York","0849488","Marlene","monroe");

    // ajout à la liste de secretaire
    this->users.append(sec1);
    this->users.append(sec2);
}

LOGIN::~LOGIN()
{
    delete ui;
}



void LOGIN::on_pushButton_clicked()
{

    QString user,password;
    user= ui->user->text();
    password = ui->password->text();
    // Login : version avec la base de donnée
    /*
    this->user = new Secretaire("Manal","Bourekba","Temssia","09589589",user,password);
    try
    {
        if(!cn->isConnected())
         {
             throw QString("Echec de connexion à la base de donnée");
         }
         else
         {
             QSqlQuery query ;
             if(query.exec("select * from user where LOGIN='"+user+"' and PASSWORD='"+password+"'"))
             {
                 int count=0;
                 while(query.next())
                 {
                     count++;
                 }
                 if(count == 1)
                 {
                     cn->~Connect();
                     SecretaryInterface *w = new SecretaryInterface(user);
                     w->show();
                     this->hide();

                 }
                 else if(count < 1)
                 {
                     QMessageBox::critical(this,tr("Info"),tr("Erreur : Mot de passe ou nom utilisateur incorrecte"));
                 }
             }
             else
             {
                 throw QString("Echec d'exécution de la requête");
             }
         }
    } catch(QString const& chaine)
    {
        qDebug() << "Exception déclenché :" + chaine ;
    }
    */

    //Login  : version QList et itterator
    try
    {
        if(this->users.empty())
        {
            throw QString("Stack Empty : aucun utilisateur dans la liste");
        }
        else
        {
            QList<Secretaire>::iterator i;
            bool flag = false;
            Secretaire &input = *new Secretaire(user,password);
            for (i = this->users.begin(); i != this->users.end(); i++){
                Secretaire &item = *new Secretaire(i->getPsuedo(),i->getPassword());

                // utilisation de surcharge d'operateur ==
                if(item == input)
                {
                    SecretaryInterface *w = new SecretaryInterface(user);
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

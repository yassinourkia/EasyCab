#include "login.h"
#include "ui_login.h"
#include "connect.h"
#include <QtSql>
#include <iostream>
#include "connect.h"
#include "secretaryinterface.h"
LOGIN::LOGIN(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LOGIN)
{
    ui->setupUi(this);
    cn = new Connect();

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

    this->user = new Secretaire(user,password);
     if(!cn->isConnected())
     {
         qDebug() << "echec d'ouverture de base de donnée";
         return;
     }
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
             qDebug() <<"nom d'utilisateur ou mot de passe erroné";
         }
     }


}

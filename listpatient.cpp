#include "listpatient.h"
#include "ui_listpatient.h"
#include "patient.h"
#include <QMessageBox>
listpatient::listpatient(QString user) :
    ui(new Ui::listpatient)
{
    ui->setupUi(this);
    this->setFixedHeight(600);
    this->setFixedWidth(600);
    ui->label->setText(user);
    cn = new Connect();
    QSqlDatabase db = cn->getDb();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery* query = new QSqlQuery(db);
    if(cn->isConnected())
    {
        qDebug() << "HERE FFFFFF";
        if(cn->getDb().open())
        {
            if(query->exec("select * from patient")){
                qDebug() <<"etat KOKOKO :" <<cn->getDb().isOpen();
                model->setQuery(*query);
                ui->list->setModel(model);

            }
            else
            {
                qDebug() <<"ça marche pas etat " <<cn->getDb().isOpen();
            }
        }
        else
        {
            qDebug()<<"Not opened";
        }

        //qDebug() >> (model->rowCount());

    }
    else
    {
        qDebug() << "doesn't Arrived here";
    }
}



listpatient::~listpatient()
{
    delete ui;
}

void listpatient::on_pushButton_clicked()
{
    QString f_name,l_name,adresse,phone_number,allergy,other,doc;
    Utilisateur createdby = Utilisateur("Manal","Bekaoui","Zaio","09090");

    f_name = ui->nom->text();
    l_name = ui->prenom->text();
    adresse = ui->addresse->text();
    phone_number = ui->telephone->text();
    allergy = ui->allergies->text();
    other = ui->autres->text();
    doc ="";


    Patient patient = Patient( f_name, l_name, adresse, phone_number,
                               allergy, other, doc, createdby);


     if(!cn->isConnected())
     {
         qDebug() << "echec d'ouverture de base de donnée";
         //return;
     }
     else {
         if(patient.addPatient())
         {
            qDebug() << "Succés d'ajout de client";
            QMessageBox::critical(this,tr("ajouter"),tr("Done"));
            QSqlDatabase db = cn->getDb();
            QSqlQueryModel * model = new QSqlQueryModel();
            QSqlQuery* query = new QSqlQuery(db);
            if(cn->isConnected())
            {
                qDebug() << "Arrived here";
                if(cn->getDb().open())
                {
                    if(query->exec("select * from patient")){
                        qDebug() <<"etat :" <<cn->getDb().isOpen();
                        model->setQuery(*query);
                        ui->list->setModel(model);

                    }
                    else
                    {
                        qDebug() <<"ça marche pas etat " <<cn->getDb().isOpen();
                    }
                }
                else
                {
                    qDebug()<<"Not opened";
                }

                //qDebug() >> (model->rowCount());

            }



         }
         else
         {
             qDebug() << "Echec d'ajout";
             this->cn->~Connect();
             //view.show();
         }
     }
}

void listpatient::on_pushButton_2_clicked()
{
    QString f_name,l_name,adresse,phone_number,allergy,other,doc;
    Utilisateur createdby = Utilisateur("Manal","Bekaoui","Zaio","09090");

    f_name = ui->nom->text();
    l_name = ui->prenom->text();
    adresse = ui->addresse->text();
    phone_number = ui->telephone->text();
    allergy = ui->allergies->text();
    other = ui->autres->text();
    doc ="";


    Patient patient = Patient( f_name, l_name, adresse, phone_number,
                               allergy, other, doc, createdby);


     if(!cn->isConnected())
     {
         qDebug() << "echec d'ouverture de base de donnée";
         //return;
     }
     else {


         if(patient.deletePatient("2"))
         {
            qDebug() << "Succés de suppression de client";
            QMessageBox::critical(this,tr("Supprimer"),tr("Done"));
            this->update();
            //this->cn->~Connect();
            //this->close();

         }
         else
         {
             qDebug() << "Echec d'ajout";
             this->cn->~Connect();
             //view.show();
         }
     }
}

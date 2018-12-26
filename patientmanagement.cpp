#include "patientmanagement.h"
#include "ui_patientmanagement.h"
#include "connect.h"
#include "patient.h"
#include "formpatient.h"
#include <QFileDialog>
#include <QMessageBox>
PatientManagement::PatientManagement(QWidget *parent,QString add_by) :
    QWidget(parent),
    ui(new Ui::PatientManagement)
{
    ui->setupUi(this);
    ui->added_by->setText("Utilisateur :"+add_by);
    cn = new Connect();
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
    else
    {
        qDebug() << "doesn't Arrived here";
    }
}

PatientManagement::~PatientManagement()
{
    delete ui;
}

void PatientManagement::on_list_activated(const QModelIndex &index)
{
    QString val = ui->list->model()->data(index).toString();
    QSqlDatabase db = cn->getDb();
    QSqlQuery* query = new QSqlQuery(db);
    if(cn->isConnected())
    {
        qDebug() << "Arrived here";
        if(cn->getDb().open())
        {
            if(query->exec("select * from patient where ID_PATIENT='"+val+"'")){
                qDebug() <<"etat :" <<cn->getDb().isOpen();
                while(query->next())
                {

                    ui->id_patient->setText(query->value(0).toString());
                    ui->nom->setText(query->value(1).toString());
                    ui->prenom->setText(query->value(2).toString());
                    ui->addresse->setText(query->value(3).toString());
                    ui->telephone->setText(query->value(4).toString());
                    ui->allergies->setText(query->value(5).toString());
                    ui->autres->setText(query->value(6).toString());
                }

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

void PatientManagement::on_pushButton_clicked()
{
    QString f_name,l_name,adresse,phone_number,allergy,other,doc;

    f_name = ui->nom->text();
    l_name = ui->prenom->text();
    adresse = ui->addresse->text();
    phone_number = ui->telephone->text();
    allergy = ui->allergies->text();
    other = ui->autres->text();
    doc = fileName;


    Patient patient = Patient( f_name, l_name, adresse, phone_number,
                               allergy, other, doc, Utilisateur("","","",""));


     if(!cn->isConnected())
     {
         qDebug() << "echec d'ouverture de base de donnée";
         //return;
     }
     else {
         if(patient.updatePatient(ui->id_patient->text()))
         {
            qDebug() << "Modification réussite ";
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
            else
            {
                qDebug() << "doesn't Arrived here";
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

void PatientManagement::on_delete_2_clicked()
{

    QString f_name,l_name,adresse,phone_number,allergy,other,doc;
    Utilisateur createdby = Utilisateur("Manal","Bekaoui","Zaio","09090");

    f_name = ui->nom->text();
    l_name = ui->prenom->text();
    adresse = ui->addresse->text();
    phone_number = ui->telephone->text();
    allergy = ui->allergies->text();
    other = ui->autres->text();
    doc = fileName;


    Patient patient = Patient( f_name, l_name, adresse, phone_number,
                               allergy, other, doc, createdby);
     if(!cn->isConnected())
     {
         qDebug() << "echec d'ouverture de base de donnée";
     }
     else
     {
         QMessageBox::StandardButton reply;
           reply = QMessageBox::question(this, "Test", "Quit?",
                                         QMessageBox::Yes|QMessageBox::No);
           if (reply == QMessageBox::Yes) {
               if(patient.deletePatient(ui->id_patient->text()))
               {
                  qDebug() << ui->id_patient->text();
                  QMessageBox::critical(this,tr("Info"),tr("Suppression réussite"));
                  QSqlDatabase db = cn->getDb();
                  QSqlQueryModel * model = new QSqlQueryModel();
                  QSqlQuery* query = new QSqlQuery(db);
                  if(cn->isConnected())
                  {

                      if(cn->getDb().open())
                      {
                          if(query->exec("select * from patient")){
                              qDebug() <<"etat :" <<cn->getDb().isOpen();
                              model->setQuery(*query);
                              ui->list->setModel(model);

                              ui->nom->setText("");
                               ui->prenom->setText("");
                              ui->addresse->setText("");
                               ui->telephone->setText("");
                               ui->allergies->setText("");
                             ui->autres->setText("");
                               fileName;

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



                  }
                  else
                  {
                      qDebug() << "doesn't Arrived here";
                  }

              }
           } else {
             qDebug() << "Suppression annulée";
           }


    }
}

void PatientManagement::on_toolButton_clicked()
{
    fileName = QFileDialog::getOpenFileName(this,
           tr("Charger un document"), "",
           tr("PDF (*.pdf);;Image (*.jpg,png,bmp);;Tous les fichiers (*)"));
        if (fileName.isEmpty())
            return ;
        else
        {
           QFile file(fileName);

            if (!file.open(QIODevice::ReadOnly)) {
                QMessageBox::information(this, tr("Echec d'ouverture de fichier"),
                    file.errorString());
                return ;
            }
            else
            {
                QMessageBox::information(this, tr("Nom de fichier"),fileName);
            }

            QDataStream in(&file);
            in.setVersion(QDataStream::Qt_4_5);

        }
}

void PatientManagement::on_add_clicked()
{
    FormPatient* form = new FormPatient() ;
    form->show();
    this->hide();
}


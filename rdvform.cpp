#include "rdvform.h"
#include "ui_rdvform.h"
#include <QMessageBox>
#include "patient.h"
RdvForm::RdvForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RdvForm)
{
    ui->setupUi(this);
    cn = new Connect();
    QSqlDatabase db = cn->getDb();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery* query = new QSqlQuery(db);
    if(cn->isConnected())
    {
        qDebug() << "Arrived here";
        if(cn->getDb().open())
        {
            if(query->exec("select F_NAME from patient")){
                qDebug() <<"etat :" <<cn->getDb().isOpen();
                model->setQuery(*query);
                ui->NomPatient->setModel(model);

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

RdvForm::~RdvForm()
{
    delete ui;
}



void RdvForm::on_charge_clicked()
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

Patient* RdvForm::getPatient(QString fname)
{
     QSqlQuery query ;
     QString f_name,l_name,adresse,phone_number,allergy,other,doc;
     Utilisateur createdby = Utilisateur("Manal","Bekaoui","Zaio","09090");
     if(query.exec("select * from 'patient' where f_name='"+ fname+"')"))
     {
          while (query.next())
          {
              f_name = query.value(1).toString();
              l_name = query.value(2).toString();
              adresse= query.value(3).toString();
              phone_number = query.value(4).toString();
              allergy = query.value(5).toString();;
              other = query.value(6).toString();
              doc = query.value(7).toString();



          }
           return  new Patient(f_name,l_name,adresse,phone_number,allergy,other,doc,createdby);
     }
     else return nullptr;

}

void RdvForm::on_add_clicked()
{
    QString date,patient_name,doc,description;

    date = ui->date->selectedDate().toString("dd/MM/yy");
    patient_name = ui->NomPatient->property("currentText").toString();
    Utilisateur createdby = Utilisateur("Manal","Bekaoui","Zaio","09090");
    description = ui->desc->toPlainText();
    doc = fileName;
    qDebug() << fileName;
    //Patient *patient = this->getPatient(patient_name);
    ui->label->setText(date);
    RDV rdv = RDV(date,patient_name,createdby,description,doc);


     if(!cn->isConnected())
     {
         qDebug() << "echec d'ouverture de base de donnée";
         //return;
     }
     else {
         if(rdv.addRDV())
         {
            qDebug() << "Succés d'ajout de rdv";
            listrdv* w = new listrdv() ;
            w->show();
            this->hide();



         }
         else
         {
             qDebug() << "Echec d'ajout";
             //this->cn->~Connect();
             //view.show();
         }
     }
}

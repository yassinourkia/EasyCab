#include "rdvform.h"
#include "ui_rdvform.h"
#include "secretaryinterface.h"
#include <QMessageBox>
#include "listrdvsec.h"

RdvForm::RdvForm(QWidget *parent,QString user) :
    QWidget(parent),
    ui(new Ui::RdvForm)
{
    ui->setupUi(this);
    this->user = user;
    this->setFixedSize(733,468);
    QIcon icon (":/images/Home.png");
    QSize size (71,51);
    ui->dashboard->setIconSize(size);
    ui->dashboard->setIcon(icon);
    ui->label->setText(user);
    this->setWindowTitle("Rendez-vous");

    QIcon rdvs (":/images/state.png");

    ui->listrdv->setIconSize(size);
    ui->listrdv->setIcon(rdvs);
    cn = new Connect();
    QSqlDatabase db = cn->getDb();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery* query = new QSqlQuery(db);
    try {
        if(cn->isConnected())
        {
            if(cn->getDb().open())
            {
                if(query->exec("select F_NAME from patient"))
                {

                    model->setQuery(*query);
                    ui->NomPatient->setModel(model);

                }
                else
                {
                    throw QString("Echec d'execution de la requête");
                }
            }
        }
        else
        {
            throw QString("Echec de connexion à la base de donnée");
        }
    }catch(QString const& chaine) {
        qDebug() << "Exception déclenché :" + chaine ;
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
                QMessageBox::critical(this, tr("Echec d'ouverture de fichier"),
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

    date = ui->date->selectedDate().toString("yyyy-MM-dd");
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

     }
     else {
         if(rdv.addRDV())
         {
            QMessageBox::information(this,"Information","Vous avez bien ajouté le rendez-vous pour la date de <strong>"+date+"</strong>");

            ListRdvSec *w = new ListRdvSec(nullptr,this->user);
            w->show();
            this->hide();


         }
     }
}



void RdvForm::on_dashboard_clicked()
{
    SecretaryInterface *w = new SecretaryInterface(this->user);
    w->show();
    this->hide();
}

void RdvForm::on_listrdv_clicked()
{
    ListRdvSec *w = new ListRdvSec(nullptr,this->user);
    w->show();
    this->hide();
}

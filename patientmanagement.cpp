#include "patientmanagement.h"
#include "ui_patientmanagement.h"
#include "connect.h"
#include "patient.h"
#include "secretaryinterface.h"
#include <QFileDialog>
#include <QMessageBox>
PatientManagement::PatientManagement(QWidget *parent,QString user) :
    QWidget(parent),
    ui(new Ui::PatientManagement)
{

    ui->setupUi(this);
    this->setWindowTitle("Gestionnaire de patient");
    this->setFixedSize(QSize(944,605));
    this->user = user;
    QIcon icon (":/images/Home.png");
    QIcon add (":/images/add.png");
    QIcon del (":/images/delete.png");
    QIcon update (":/images/update.png");

    QSize size (100,50);

    ui->dashboard->setIconSize(QSize(100,70));
    ui->dashboard->setIcon(icon);
    ui->add->setIconSize(size);
    ui->add->setIcon(add);

    ui->pushButton->setIconSize(size);
    ui->pushButton->setIcon(update);

    ui->delete_2->setIconSize(size);
    ui->delete_2->setIcon(del);

    ui->added_by->setText("Utilisateur :"+ user);
    this->RechargeModel();
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
    try
    {
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
                    throw QString("Echec d'execution de la requête");
                }
            }
            else
            {
                throw QString("Echec d'ouverture de la base de donnée");
            }
        }
        else
           throw QString("Echec de connexion à la base de donnée");
    } catch(QString const& chaine)
    {
        qDebug() << "Exception déclenché :" + chaine ;
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
            this->RechargeModel();
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
           reply = QMessageBox::question(this, "Suppression", "Vous êtes sûr de supprimer ce patient ?",
                                         QMessageBox::Yes|QMessageBox::No);
           if (reply == QMessageBox::Yes) {
               if(patient.deletePatient(ui->id_patient->text()))
               {
                  qDebug() << ui->id_patient->text();
                  QMessageBox::information(this,tr("Info"),tr("Suppression réussite"));
                  this->RechargeModel();
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

void PatientManagement::on_add_clicked()
{
    QString f_name,l_name,adresse,phone_number,allergy,other,doc;
    Utilisateur createdby = Utilisateur("Manal","Bekaoui","Zaio","09090");

    f_name = ui->nom->text();
    l_name = ui->prenom->text();
    adresse = ui->addresse->text();
    phone_number = ui->telephone->text();
    allergy = ui->allergies->text();
    other = ui->autres->text();
    doc =this->fileName;



    Patient patient = Patient( f_name, l_name, adresse, phone_number,
                               allergy, other, doc, createdby);


     if(!cn->isConnected())
     {

         //return;
     }
     else {
         if(patient.addPatient())
         {

            this->cn->~Connect();
            this->RechargeModel();

         }
         else
         {
             qDebug() << "Echec d'ajout";
             this->cn->~Connect();

         }
     }
}

void PatientManagement::RechargeModel()
{
    try
    {
        cn = new Connect();
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
                }
                else
                {
                    throw QString("Echec d'execution de la requête");
                }
            }
            else
                throw QString("Echec d'ouverture de la base de donnée");
        }
        else
        {
            throw QString("Echec de connexion avec la base de donnée");
        }
    } catch(QString const& chaine)
    {
        qDebug() << "Exception déclenché :" + chaine ;
    }

}

void PatientManagement::on_dashboard_clicked()
{
    SecretaryInterface *w = new SecretaryInterface(this->user);
    w->show();
    this->hide();
}

#include "formpatient.h"
#include "ui_formpatient.h"
#include "patient.h"
#include <QFileDialog>
#include <QMessageBox>
FormPatient::FormPatient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormPatient)
{
    ui->setupUi(this);
    cn = new Connect();

}

FormPatient::~FormPatient()
{
    delete ui;
}

void FormPatient::on_pushButton_clicked()
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
            qDebug() << "Succés d'ajout de Patient";
            this->cn->~Connect();
            view = new PatientManagement();
            view->show();
            this->hide();
         }
         else
         {
             qDebug() << "Echec d'ajout";
             this->cn->~Connect();
             view->show();
         }
     }
}

void FormPatient::on_toolButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
           tr("Open Address Book"), "",
           tr("Address Book (*.pdf);;All Files (*)"));
    if (fileName.isEmpty())
            return;
        else {

            QFile file(fileName);

            if (!file.open(QIODevice::ReadOnly)) {
                QMessageBox::information(this, tr("Unable to open file"),
                    file.errorString());
                return;
            }

            QDataStream in(&file);
            in.setVersion(QDataStream::Qt_4_5);
    }

}

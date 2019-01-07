#include "formstate.h"
#include "ui_formstate.h"
#include "doctordashboard.h"
#include "doctordashboard.h"
#include "rdv.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>
FormState::FormState(QWidget *parent,QString doctor) :
    QWidget(parent),
    ui(new Ui::FormState)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(700,467));
    this->doctor = doctor;
    cn = new Connect();
    QIcon icon (":/images/Home.png");
    QSize size (71,51);
    ui->dashboard->setIconSize(size);
    ui->dashboard->setIcon(icon);

}
FormState::FormState(QString rdv, QString doctor) :
    ui(new Ui::FormState)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(700,467));
    this->doctor = doctor;
    cn = new Connect();
    QIcon icon (":/images/Home.png");
    QSize size (71,51);
    ui->dashboard->setIconSize(size);
    ui->dashboard->setIcon(icon);
    RDV r ;
    if(cn->isConnected())
    {
        ui->patient->setText(r.getIDPatientbyRdvId(rdv));
    }
    ui->rdv->setText(rdv);
    ui->rdv->setVisible(false);
    ui->patient->setVisible(false);
}
FormState::~FormState()
{

    delete ui;

}

void FormState::on_add_clicked()
{
    QString comments;
    QString PHARMACEUTICALS;
    QString date,FIANL;
    QString patient,rdv;

    comments = ui->comments->toPlainText();
    PHARMACEUTICALS = ui->PHARMACEUTICALS->toPlainText();
    date = ui->date->dateTime().toString("yyyy-MM-dd");
    patient = ui->patient->text();
    rdv = ui->rdv->text();


    State state = State(comments,PHARMACEUTICALS,date,"0",rdv,patient);
    try
    {
         if(!cn->isConnected())
         {
            throw("echec d'ouverture de base de donnée");
         }
         else
         {
             if(state.addState())
             {

               QMessageBox::critical(this,tr("Info"),tr("Status bien ajouté "));
               QString currentdate = QDate::currentDate().toString("dd/MM/yyyy");
               QString html =
               "<div align=right>"
                  "Ville : Vannes,  "+currentdate+
               "</div>"
               "<div><img src=':/images/easycab.png' />"
               "<div align=left>"
                  "EASYCAB<br>"
                  "19, Republique 34/56A<br>"
                  "Vannes 56000"
               "</div>"
               "<h1 align=center>Prescription</h1>"
               "<p align=justify>"
                  "<strong>Medicaments :</strong>  " + PHARMACEUTICALS +"<br>"
                  "<strong>Consignes d'utilisation : :</strong>  " + comments +"<br>"
                  "<strong>Prochain Rendez-vous :</strong>  " + date +"<br>"
               "</p>"
               "<div align=right>sincerly</div>";
               QTextDocument document;
               document.setHtml(html);
               QPrinter printer(QPrinter::PrinterResolution);
               printer.setOutputFormat(QPrinter::PdfFormat);
               printer.setPaperSize(QPrinter::A4);
               printer.setOutputFileName("/Users/ourkia/Desktop/easycab/Patient"+patient+"_"+date+"_"+rdv+".pdf");
               printer.setPageMargins(QMarginsF(15, 15, 15, 15));
               document.print(&printer);
               DoctorDashboard *view = new DoctorDashboard(this->doctor);
               view->show();
               this->hide();

             }
             else
             {
                 QMessageBox::critical(this,tr("Info"),tr("Erreur d'ajout de status "));
                 throw("Echec d'execution de requête");
             }
         }
    }catch(QString erreur)
    {
        qDebug() << "Exception déclenché :" + erreur;
    }
}


void FormState::on_dashboard_clicked()
{

    DoctorDashboard *w = new DoctorDashboard(this->doctor);
    w->show();
    this->hide();
}

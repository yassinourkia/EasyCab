#include "formstate.h"
#include "ui_formstate.h"
#include "secretaryinterface.h"
FormState::FormState(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormState)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(700,467));
    cn = new Connect();
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
    date = ui->date->dateTime().toString("dd MMM YYYY");
    patient = ui->patient->text();
    rdv = ui->rdv->text();




    State state = State( comments, PHARMACEUTICALS, date,"1","2","1");


     if(!cn->isConnected())
     {
         qDebug() << "echec d'ouverture de base de donnée";
         //return;
     }
     else {
         if(state.addState())
         {
            qDebug() << "Succés d'ajout de state";

            //view.show();
            //this->cn->~Connect();
            this->close();

         }
         else
         {
             qDebug() << "Echec d'ajout";
             this->cn->~Connect();
             //view.show();
         }
     }
}

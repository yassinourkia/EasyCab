#include "listpatients.h"
#include "ui_listpatients.h"
#include "doctordashboard.h"
#include <QMessageBox>
#include <QTextDocument>
ListPatients::ListPatients(QString user) :
    ui(new Ui::ListPatients)
{
    ui->setupUi(this);
    this->setWindowTitle("Visionnaire de patients");
    this->setFixedSize(QSize(944,605));
    this->user = user;
    QIcon icon (":/images/Home.png");

    QSize size (100,70);

    ui->dashboard->setIconSize(size);
    ui->dashboard->setIcon(icon);

    this->RechargeModel();

}

ListPatients::~ListPatients()
{
    delete ui;
    delete cn;
}

void ListPatients::RechargeModel()
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

void ListPatients::on_dashboard_clicked()
{
    DoctorDashboard *w = new DoctorDashboard(this->user);
    w->show();
    this->hide();
}

void ListPatients::on_list_activated(const QModelIndex &index)
{
    QString val = ui->list->model()->data(index).toString();
    QSqlDatabase db = cn->getDb();
    QSqlQuery* query = new QSqlQuery(db);
    try
    {
        if(cn->isConnected())
        {

            if(cn->getDb().open())
            {
                if(query->exec("select * from patient where ID_PATIENT='"+val+"'")){

                    while(query->next())
                    {
                        QString html =

                        "<div><img src=':/images/easycab.png' />"
                        "<div align=left>"
                           "Adresse : "+query->value(3).toString()+"<br>"
                           "Téléphone : : "+query->value(4).toString()+"<br>"
                        "</div>"
                        "<h3 align=center>Informations sur le patient : </h3>"
                        "<p align=justify>"
                           "<strong>Nom & prénom :</strong>  " + query->value(1).toString() +" "+query->value(2).toString()+"<br>"
                           "<strong>Allergies :</strong>  " +query->value(5).toString()+"<br>"
                           "<strong>Autres informations :</strong>  " +query->value(6).toString()+"<br>"
                        "</p>"
                      "<div align=right>"
                         "Créé par :   "+query->value(7).toString()+
                      "</div>"
                        ;

                        QString data = query->value(0).toString()+" "+query->value(1).toString();
                        QMessageBox::information(this,"informations de patient",html);

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

#include "listrdv.h"
#include "ui_listrdv.h"
#include "rdvform.h"
#include "staterdv.h"
#include "formstate.h"
#include "secretaryinterface.h"
#include "doctordashboard.h"

listrdv::listrdv(QWidget *parent,QString user) :
    QWidget(parent),
    ui(new Ui::listrdv)
{
    ui->setupUi(this);
    this->setWindowTitle("Listes des Rendz-vous");
    cn = new Connect();
    this->user = user;
    QIcon icon (":/images/Home.png");
    QSize size (71,51);
    ui->dashboard->setIconSize(size);
    ui->dashboard->setIcon(icon);
    QSqlDatabase db = cn->getDb();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery* query = new QSqlQuery(db);
    if(cn->isConnected())
    {

        if(cn->getDb().open())
        {
            if(query->exec("select * from rdv")){
                model->setQuery(*query);
                ui->list->setModel(model);
            }
            else
            {
                qDebug() <<"Loading issue :  " <<cn->getDb().isOpen();
            }
        }
    }

}

listrdv::listrdv(QString date,QString user) :
    ui(new Ui::listrdv)
{
    ui->setupUi(this);
    this->setWindowTitle("Listes des Rendz-vous");
    cn = new Connect();
    this->user = user;
    QIcon icon (":/images/Home.png");
    QSize size (71,51);
    ui->dashboard->setIconSize(size);
    ui->dashboard->setIcon(icon);
    QSqlDatabase db = cn->getDb();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery* query = new QSqlQuery(db);
    if(cn->isConnected())
    {

        if(cn->getDb().open())
        {
            if(query->exec("select * from rdv where DATE='"+date+"'")){
                model->setQuery(*query);
                ui->list->setModel(model);
            }
            else
            {
                qDebug() <<"Loading issue :  " <<cn->getDb().isOpen();
            }
        }
    }

}

listrdv::~listrdv()
{

    delete ui;
}

void listrdv::on_list_activated(const QModelIndex &index)
{
    QString val = ui->list->model()->data(index).toString();
    QSqlDatabase db = cn->getDb();
    QSqlQuery* query = new QSqlQuery(db);
    if(cn->isConnected())
    {
        if(cn->getDb().open())
        {
            QString patient , rdv;
            query->prepare("select * from state where PATIENT="+val+"");
            if(query->exec())
            {
                int count=0;
                while(query->next())
                {
                    count++;

                }
                if(count == 1)
                {
                   StateRdv* w = new StateRdv(val,this->user);
                   this->hide();
                   w->show();
                }
                else
                {
                   FormState* w = new FormState(val,this->user);
                   this->hide();
                   w->show();
                }
            }
        }

    }
}

void listrdv::on_dashboard_clicked()
{

        DoctorDashboard *w = new DoctorDashboard(this->user);
        w->show();
        this->hide();

}

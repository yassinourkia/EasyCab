#include "listrdv.h"
#include "ui_listrdv.h"
#include "rdvform.h"
#include "staterdv.h"
#include "formstate.h"

listrdv::listrdv(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::listrdv)
{
    ui->setupUi(this);
    cn = new Connect();
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

listrdv::listrdv(QString date) :
    ui(new Ui::listrdv)
{
    ui->setupUi(this);
    cn = new Connect();
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

            query->prepare("select * from state where RDV="+val+"");
            if(query->exec())
            {
                int count=0;
                while(query->next())
                {
                    count++;
                }

                if(count == 1)
                {
                   StateRdv* w = new StateRdv(val);
                   this->hide();
                   w->show();
                }
                else
                {
                   FormState* w = new FormState();
                   this->hide();
                   w->show();
                }
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

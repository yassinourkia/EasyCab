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
        qDebug() << "Arrived here";
        if(cn->getDb().open())
        {
            if(query->exec("select * from rdv")){
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
        qDebug() << "Arrived here";
        if(cn->getDb().open())
        {
            query->prepare("select * from rdv where ID_RDV="+val+"");
            if(query->exec())
            {
                qDebug() << "Size :" << query->size();
                if(query->next())
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

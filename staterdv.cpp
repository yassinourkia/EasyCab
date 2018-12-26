#include "staterdv.h"
#include "ui_staterdv.h"

StateRdv::StateRdv(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StateRdv)
{
    ui->setupUi(this);

}
StateRdv::StateRdv(QString id) :
    ui(new Ui::StateRdv)
{
    ui->setupUi(this);
    cn = new Connect();
    QSqlDatabase db = cn->getDb();
    QSqlQuery* query = new QSqlQuery(db);
    if(cn->isConnected())
    {

        if(cn->getDb().open())
        {
            if(query->exec("select * from state where RDV='"+id+"'")){
                qDebug() << "etat :" <<cn->getDb().isOpen();
                while(query->next())
                {

                     ui->comments->setText(query->value(1).toString());
                     ui->date->setText(query->value(2).toString());
                     ui->medic->setText(query->value(3).toString());
                     ui->patient->setText(query->value(6).toString());

                }

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

StateRdv::~StateRdv()
{
    delete ui;
}

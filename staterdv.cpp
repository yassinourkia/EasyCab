#include "staterdv.h"
#include "ui_staterdv.h"
#include "doctordashboard.h"

StateRdv::StateRdv(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StateRdv)
{
    ui->setupUi(this);

}
StateRdv::StateRdv(QString id,QString user) :
    ui(new Ui::StateRdv)
{
    ui->setupUi(this);
    this->setWindowTitle("Suivi Patient");
    QIcon icon (":/images/Home.png");
    this->user = user;
    QSize size (100,70);

    ui->dashboard->setIconSize(size);
    ui->dashboard->setIcon(icon);
    cn = new Connect();
    QSqlDatabase db = cn->getDb();
    QSqlQuery* query = new QSqlQuery(db);
    if(cn->isConnected())
    {
        if(cn->getDb().open())
        {
            if(query->exec("select * from state where PATIENT='"+id+"'")){
                while(query->next())
                {                  
                     ui->comments->setText(query->value(1).toString());
                     ui->date->setText(query->value(2).toString());
                     ui->medic->setText(query->value(3).toString());
                     Patient p ;
                     qDebug() << query->value(5).toString();
                     Patient *pp = p.getPatientById(query->value(5).toString());
                     ui->patient->setText(pp->getf_name()+" "+pp->getl_name());
                     RDV rdv;
                     ui->rdv->setText(rdv.getRdvById(id)->getDate());
                }
            }

        }

    }


}

StateRdv::~StateRdv()
{
    delete ui;
}

void StateRdv::on_dashboard_clicked()
{
    DoctorDashboard *w = new DoctorDashboard(this->user);
    w->show();
    this->hide();
}

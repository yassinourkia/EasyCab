#include "listrdvsec.h"
#include "ui_listrdvsec.h"

ListRdvSec::ListRdvSec(QWidget *parent,QString user) :
    QWidget(parent),
    ui(new Ui::ListRdvSec)
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

ListRdvSec::~ListRdvSec()
{
    delete ui;
}

void ListRdvSec::on_dashboard_clicked()
{
    SecretaryInterface *w = new SecretaryInterface(this->user);
    w->show();
    this->hide();
}

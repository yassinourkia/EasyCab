#include "formlistpatient.h"
#include "ui_formlistpatient.h"
#include "connect.h"
#include <QtSql>

FormListPatient::FormListPatient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormListPatient)
{
    ui->setupUi(this);
    /*
    cn = new Connect();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery* query = new QSqlQuery();
    if(cn->isConnected())
    {
        query->exec("select * from patient");
        model->setQuery(*query);
       // ui->list->setModel(model);
        //qDebug() >> (model->rowCount());

    }
    */


}

FormListPatient::~FormListPatient()
{
    delete ui;
}



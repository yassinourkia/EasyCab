#include "patient.h"
#include "ui_patient.h"
#include "mainwindow.h"
#include <iostream>
Patient::Patient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Patient)
{
    ui->setupUi(this);
    cn = new Connect();
}

Patient::~Patient()
{
    delete ui;
}

void Patient::on_pushButton_clicked()
{

}

#include "login.h"
#include "formpatient.h"
#include "patientmanagement.h"
#include "rdvform.h"
#include "listrdv.h"
#include "formstate.h"
#include <QApplication>
#include <QtSql>
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     //LOGIN w;
    //FormPatient w;
    //listpatient w;
    //PatientManagement w;
    //RdvForm w;
    listrdv w;
    //FormState w;
    w.show();

    return a.exec();
}

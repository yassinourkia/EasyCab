#include "logindoctor.h"
#include "patientmanagement.h"
#include "rdvform.h"
#include "listrdv.h"
#include "formstate.h"
#include "secretaryinterface.h"
#include "accueil.h"
#include <QApplication>
#include <QtSql>
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     //LoginDoctor w;
     Accueil w;
    //FormPatient w;
    //listpatient w;
    //PatientManagement w;
    //RdvForm w;
    //listrdv w;
    //FormState w;
    //SecretaryInterface w;
    w.show();

    return a.exec();
}

#ifndef LOGINDOCTOR_H
#define LOGINDOCTOR_H

#include <QWidget>
#include "connect.h"
#include "medecin.h"
#include "doctordashboard.h"
namespace Ui {
class LoginDoctor;
}

class LoginDoctor : public QWidget
{
    Q_OBJECT

public:
    explicit LoginDoctor(QWidget *parent = nullptr);
    ~LoginDoctor();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginDoctor *ui;
     QList<Medecin> users;
     Connect * cn ;
};

#endif // LOGINDOCTOR_H

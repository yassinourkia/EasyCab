#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QWidget>
#include "logindoctor.h"
#include "login.h"
namespace Ui {
class Accueil;
}

class Accueil : public QWidget
{
    Q_OBJECT

public:
    explicit Accueil(QWidget *parent = nullptr);
    ~Accueil();

private slots:
    void on_secretaire_clicked();

    void on_doctor_clicked();

private:
    Ui::Accueil *ui;
};

#endif // ACCUEIL_H

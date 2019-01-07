#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QWidget>
#include "logindoctor.h"
#include "login.h"
namespace Ui {
class Accueil;
}
/*!
 * \brief The Accueil class the Accueil page to start the application
 * \authors MANAL BEKAOUI - OURKIA YASSIN
 */
class Accueil : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Accueil Constructor
     * \param parent
     */
    explicit Accueil(QWidget *parent = nullptr);
    ~Accueil();

private slots:
    /*!
     * \brief on_secretaire_clicked to get into the secretary login form
     */
    void on_secretaire_clicked();
    /*!
     * \brief on_doctor_clicked to get into the doctor login form
     */
    void on_doctor_clicked();

private:
    Ui::Accueil *ui;
};

#endif // ACCUEIL_H

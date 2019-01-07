#ifndef LOGINDOCTOR_H
#define LOGINDOCTOR_H

#include <QWidget>
#include "connect.h"
#include "medecin.h"
#include "doctordashboard.h"
namespace Ui {
class LoginDoctor;
}
/*!
 * \brief The LoginDoctor class the login form for doctors
 * \authors MANAL BEKAOUI - OURKIA YASSIN
 */
class LoginDoctor : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief LoginDoctor constructor to instanciate the graphic and STL
     * \param parent
     */
    explicit LoginDoctor(QWidget *parent = nullptr);
    ~LoginDoctor();

private slots:
    /*!
     * \brief on_pushButton_clicked to connect to the dashboard
     */
    void on_pushButton_clicked();

private:
    Ui::LoginDoctor *ui;
     QList<Medecin> users;
     Connect * cn ;
};

#endif // LOGINDOCTOR_H

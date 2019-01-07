#ifndef LISTRDVSEC_H
#define LISTRDVSEC_H

#include <QWidget>
#include "connect.h"
#include "secretaryinterface.h"
namespace Ui {
class ListRdvSec;
}
/*!
 * \brief The ListRdvSec class the list of appointments that the secretary has created
 * \authors MANAL BEKAOUI - OURKIA YASSIN
 */
class ListRdvSec : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief ListRdvSec constructor to instanciate the graphics and connections with the database
     * \param parent the graphic container
     * \param user the name of the current user
     */
    explicit ListRdvSec(QWidget *parent = nullptr,QString user=nullptr);
    ~ListRdvSec();

private slots:
    /*!
     * \brief on_dashboard_clicked to return to the dashboard of secretary
     */
    void on_dashboard_clicked();

private:
    Ui::ListRdvSec *ui;
    Connect *cn;
    QString user;
};

#endif // LISTRDVSEC_H

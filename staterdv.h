#ifndef STATERDV_H
#define STATERDV_H

#include <QWidget>
#include "state.h"
#include "secretaryinterface.h"
#include "connect.h"
namespace Ui {
class StateRdv;
}
/*!
 * \brief The StateRdv class to display the state of an appointment after the treatment by a doctor
 * \authors MANAL BEKAOUI - OURKIA YASSIN
 */
class StateRdv : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief StateRdv constructor to instanciate graphic componnents and connect to the database
     * \param parent the graphic container
     */
    explicit StateRdv(QWidget *parent = nullptr);
    /*!
      * \brief StateRdv constructor
      * \param id of state
      * \param user the current user of the app
      */
     explicit StateRdv(QString id,QString user=nullptr );
    ~StateRdv();

private slots:
    /*!
     * \brief on_dashboard_clicked to return to the dashboard form
     */
    void on_dashboard_clicked();

private:
    Ui::StateRdv *ui;
    State* state;
    Connect *cn;
    QString user;
};

#endif // STATERDV_H

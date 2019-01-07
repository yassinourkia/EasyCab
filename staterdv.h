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
 * \brief The StateRdv class
 * \authors MANAL BEKAOUI - OURKIA YASSIN
 */
class StateRdv : public QWidget
{
    Q_OBJECT

public:
    explicit StateRdv(QWidget *parent = nullptr);
     explicit StateRdv(QString id,QString user=nullptr );
    ~StateRdv();

private slots:
    void on_dashboard_clicked();

private:
    Ui::StateRdv *ui;
    State* state;
    Connect *cn;
    QString user;
};

#endif // STATERDV_H

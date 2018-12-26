#ifndef STATERDV_H
#define STATERDV_H

#include <QWidget>
#include "state.h"
#include "connect.h"
namespace Ui {
class StateRdv;
}

class StateRdv : public QWidget
{
    Q_OBJECT

public:
    explicit StateRdv(QWidget *parent = nullptr);
     explicit StateRdv(QString id );
    ~StateRdv();

private:
    Ui::StateRdv *ui;
    State* state;
    Connect *cn;
};

#endif // STATERDV_H

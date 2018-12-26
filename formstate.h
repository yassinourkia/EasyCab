#ifndef FORMSTATE_H
#define FORMSTATE_H

#include <QWidget>
#include "connect.h"
#include "rdv.h"
#include "state.h"
#include "patient.h"
namespace Ui {
class FormState;
}

class FormState : public QWidget
{
    Q_OBJECT

public:
    explicit FormState(QWidget *parent = nullptr);
    ~FormState();

private slots:
    void on_add_clicked();

private:
    Ui::FormState *ui;
    Connect *cn;
    Patient *patient;
    RDV* rdv;
    State* state;

};

#endif // FORMSTATE_H

#ifndef FORMLISTPATIENT_H
#define FORMLISTPATIENT_H

#include <QWidget>
#include "connect.h"

namespace Ui {
class FormListPatient;
}

class FormListPatient : public QWidget
{
    Q_OBJECT

public:
    explicit FormListPatient(QWidget *parent = nullptr);
    ~FormListPatient();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FormListPatient *ui;
    Connect *cn;

};

#endif // FORMLISTPATIENT_H

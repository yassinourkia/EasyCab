#ifndef LISTPATIENT_H
#define LISTPATIENT_H

#include <QWidget>
#include "connect.h"

namespace Ui {
class listpatient;
}

class listpatient : public QWidget
{
    Q_OBJECT

public:
    explicit listpatient(QString user ="");
    ~listpatient();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::listpatient *ui;
    Connect *cn;
    QString user;

};

#endif // LISTPATIENT_H

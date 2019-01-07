#ifndef LISTRDVSEC_H
#define LISTRDVSEC_H

#include <QWidget>
#include "connect.h"
#include "secretaryinterface.h"
namespace Ui {
class ListRdvSec;
}

class ListRdvSec : public QWidget
{
    Q_OBJECT

public:
    explicit ListRdvSec(QWidget *parent = nullptr,QString user=nullptr);
    ~ListRdvSec();

private slots:
    void on_dashboard_clicked();

private:
    Ui::ListRdvSec *ui;
    Connect *cn;
    QString user;
};

#endif // LISTRDVSEC_H

#ifndef LISTPATIENTS_H
#define LISTPATIENTS_H

#include <QWidget>
#include "connect.h"
#include <QtSql>
#include "doctordashboard.h"
namespace Ui {
class ListPatients;
}

class ListPatients : public QWidget
{
    Q_OBJECT

public:
    explicit ListPatients(QString user);
    ~ListPatients();
    void RechargeModel();

private slots:
    void on_dashboard_clicked();

    void on_list_activated(const QModelIndex &index);

private:
    Ui::ListPatients *ui;
    Connect* cn;
    QString user;
};

#endif // LISTPATIENTS_H

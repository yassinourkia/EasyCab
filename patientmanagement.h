#ifndef PATIENTMANAGEMENT_H
#define PATIENTMANAGEMENT_H

#include <QWidget>
#include "connect.h"
namespace Ui {
class PatientManagement;
}

class PatientManagement : public QWidget
{
    Q_OBJECT

public:
    explicit PatientManagement(QWidget *parent = nullptr,QString added_by = nullptr);
    ~PatientManagement();

private slots:
    void on_list_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_delete_2_clicked();

    void on_toolButton_clicked();

    void on_add_clicked();



    void on_dashboard_clicked();

private:
    Ui::PatientManagement *ui;
    Connect *cn;
    QString fileName;
};

#endif // PATIENTMANAGEMENT_H

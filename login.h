#ifndef LOGIN_H
#define LOGIN_H
#include "connect.h"
#include "secretaire.h"
#include <QWidget>
#include <QtSql>
namespace Ui {
class LOGIN;
}

class LOGIN : public QWidget
{
    Q_OBJECT

public:
    explicit LOGIN(QWidget *parent = nullptr);
    ~LOGIN();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LOGIN *ui;
    Connect * cn ;
    Secretaire* user;

};

#endif // LOGIN_H

#ifndef LISTRDV_H
#define LISTRDV_H

#include <QWidget>
#include "connect.h"

namespace Ui {
class listrdv;
}

class listrdv : public QWidget
{
    Q_OBJECT

public:
    explicit listrdv(QWidget *parent = nullptr);
    ~listrdv();

private slots:
    void on_list_activated(const QModelIndex &index);

private:
    Ui::listrdv *ui;
    Connect *cn;
};

#endif // LISTRDV_H

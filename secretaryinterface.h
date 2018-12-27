#ifndef SECRETARYINTERFACE_H
#define SECRETARYINTERFACE_H

#include <QWidget>

namespace Ui {
class SecretaryInterface;
}

class SecretaryInterface : public QWidget
{
    Q_OBJECT

public:
    explicit SecretaryInterface(QWidget *parent = nullptr);
    ~SecretaryInterface();

private:
    Ui::SecretaryInterface *ui;
};

#endif // SECRETARYINTERFACE_H

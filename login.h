#ifndef LOGIN_H
#define LOGIN_H
#include "connect.h"
#include "secretaire.h"
#include <QWidget>
#include <QtSql>
#include <QMessageBox>
namespace Ui {
class LOGIN;
}
/*!
 * \brief The LOGIN class class for the graphic interface of login
 * \authors MANAL BEKAOUI - OURKIA YASSIN
 */
class LOGIN : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief LOGIN the graphic interface to login to the system functionnalities
     * \param parent the container of all graphic elements
     */
    explicit LOGIN(QWidget *parent = nullptr);
    /*!
     *  \brief distructor of the class
     */
    ~LOGIN();


private slots:
    /*!
     * \brief on_pushButton_clicked action to be done when the button of connection is clicked
     */
    void on_pushButton_clicked();

private:
    Ui::LOGIN *ui;
    Connect * cn ;
    Secretaire* user;
    QList<Secretaire> users;

};


#endif // LOGIN_H

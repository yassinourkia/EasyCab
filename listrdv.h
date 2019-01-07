#ifndef LISTRDV_H
#define LISTRDV_H

#include <QWidget>
#include "connect.h"

namespace Ui {
class listrdv;
}
/*!
 * \brief The listrdv class allows to display list of meetings reserved in the system
 * \authors MANAL BEKAOUI - OURKIA YASSIN
 */

class listrdv : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief listrdv constructor to instanciate the class
     * \param parent the Container which the list will be displayed in
     */
    explicit listrdv(QWidget *parent = nullptr,QString user=nullptr);
    /*!
     * \brief listrdv constructor to instanciate the class
     * \param date paramater of a given date to find in the list
     */
    explicit listrdv(QString date = nullptr,QString user=nullptr);
    /*!
     * \brief distructor of the class
     */
    ~listrdv();
    /*!
     * \brief setUser Set User Type
     * \param user
     */
    void setUser(QString user)
    {
        this->user = user;
    }

private slots:
    /*!
     * \brief on_list_activated action to be done when the list is activated
     * \param index the index of the item to be treated
     */
    void on_list_activated(const QModelIndex &index);
    /*!
     * \brief on_dashboard_clicked to return to the main dashboard
     */
    void on_dashboard_clicked();

private:

    Ui::listrdv *ui;
    Connect *cn;
    QString user;
};

#endif // LISTRDV_H

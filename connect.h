#ifndef CONNECT_H
#define CONNECT_H
#include <QtSql>

/*!
 * \brief The Connect class  that allows to establish a connection with the local SQLite Database
 * \authors MANAL BEKAOUI - OURKIA YASSIN
 *
 */


class Connect
{
public:
    /*!
     * \brief Connect the constructor to instanciate the connextion
     */
    Connect();
    /*!
     *  \brief Connect the distructor to kill the connextion
     */
    ~Connect();
    /*!
     * \brief isConnected to verify if the connection with the database is established
     * \return true if it's connected to the database
     */
    bool isConnected();
    /*!
     * \brief getDb Get the Database target
     * \return  database instanciated in the constructor
     */
    QSqlDatabase getDb();

private :
    /*!
      * \brief db attribute database
      */
     QSqlDatabase db ;
};

#endif // CONNECT_H

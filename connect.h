#ifndef CONNECT_H
#define CONNECT_H
#include <QtSql>

class Connect
{
public:
    Connect();
    ~Connect();
    bool isConnected();
    QSqlDatabase getDb();

private :
     QSqlDatabase db ;
};

#endif // CONNECT_H

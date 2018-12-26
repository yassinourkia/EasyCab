#include "connect.h"

Connect::Connect()
{
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName("/Users/ourkia/Desktop/easycab/database.db");
}
bool Connect::isConnected()
{

     if(db.open())
     {
          qDebug()<< "connected" ;;
          return true;
     }
     else
     {
          qDebug() << "failed to connect to database";
          return false;
     }
}

QSqlDatabase Connect::getDb(){
    return this->db;
}
Connect::~Connect()
{
    db.close();
}

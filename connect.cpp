#include "connect.h"

Connect::Connect()
{
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName("/Users/ourkia/Desktop/easycab/database4.db");
}
bool Connect::isConnected()
{
   return db.open();
}

QSqlDatabase Connect::getDb(){
    return this->db;
}
Connect::~Connect()
{
    db.close();
}

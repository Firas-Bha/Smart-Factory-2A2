#include "connection.h"
#include <QSqlDatabase>
connection::connection()
{

}
bool connection::createConnection(){

   bool test=false;
   QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
   db.setDatabaseName("test");
   db.setUserName("mahdi");
   db.setPassword("MehdiMehdi10");

   if (db.open())
      test=true;
   return test;
}

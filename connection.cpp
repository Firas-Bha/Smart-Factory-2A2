#include "connection.h"
#include <QSqlDatabase>
connection::connection()
{

}
bool connection::createConnection(){
   bool test=false;
   QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
   db.setDatabaseName("test2");
   db.setUserName("sejir");
   db.setPassword("sejir");
   if(db.open())
test=true;
return test;
}

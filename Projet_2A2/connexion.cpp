#include "connexion.h"
#include <QSqlDatabase>

Connexion::Connexion()
{

}
bool Connexion::ouvrirConnexion()
{
    bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test");//inserer le nom de la source de données ODBC
db.setUserName("firas2");//inserer nom de l'utilisateur
db.setPassword("firas2");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;

}

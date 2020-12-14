#include "ClientCo.h"
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include "connection.h"
#include "client.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connection C;
    bool test=C.createConnection();
    ClientCo w;
    if (test)  {
        w.show();         QMessageBox::information(nullptr,QObject::tr("database is open"),QObject::tr("connection succesful \n click cancel to exit")                 ,QMessageBox::Cancel);     }               else                   QMessageBox::critical(nullptr,QObject::tr("database is not open"),QObject::tr("connection failed \n click cancel to exit")                           ,QMessageBox::Cancel);


    return a.exec();

}

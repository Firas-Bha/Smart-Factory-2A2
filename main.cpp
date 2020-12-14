#include "equipements.h"
#include <QApplication>
#include <QMessageBox>
#include <QtDebug>
#include "connection.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connection C;

    bool test=C.createConnection();
    equipements w;
    if (test)
        QMessageBox::information(nullptr,QObject::tr("database is open"),
                                 QObject::tr("connexion successful!\n"
                                            "click ok to exit"),QMessageBox::Ok);
else
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                                 QObject::tr("connexion failed!\n"
                                            "click cancel to exit"),QMessageBox::Cancel);
    w.show();
    return a.exec();
}

#include "compte.h"

Compte::Compte()
{

}
QSqlQueryModel * Compte::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from compte");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("USERNAME"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("MTP"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PERMISSIONS"));

    return model;
}
Compte::Compte(int usern_,QString mtp_,QString email_,int permissions_)
{
    usern = usern_;
    mtp = mtp_;
    email = email_;
    permissions = permissions_;


}



bool Compte::supprimer(int account)
{
  QSqlQuery query;
  QString acc_ = QString::number(account);
  query.prepare("Delete from compte  where username = :account");
  query.bindValue(":account",acc_);
  return query.exec();

}

QSqlQueryModel * Compte::combobox()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    //QString acc_ = QString::number(account);
    //QString perm=  QString::number(permissions);

    model->setQuery("select username from compte" );


    return model;
}
QSqlQueryModel * Compte::chercher_compte(int account,int x)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    if ( x == 1)
    {
    QString acc_ = QString::number(account);


    model->setQuery("select * from compte where username = '"+acc_+"'" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("account"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("MTP"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PERMISSIONS"));
    }
    if(x == 2)
    {
        QString acc_ = QString::number(account);


        model->setQuery("select * from compte where permissions = '"+acc_+"'" );
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("account"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("MTP"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("EMAIL"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("PERMISSIONS"));


    }
    return model;
}
QSqlQueryModel * Compte::chercher_compte(int account,QString email,int permissions)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QString acc_ = QString::number(account);
    QString perm=  QString::number(permissions);

    model->setQuery("select * from compte where username = '"+acc_+"' and email like '"+email+"' and permissions = '"+perm+"'" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("account"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("MTP"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PERMISSIONS"));

    return model;
}
QSqlQueryModel * Compte::chercher_compte(QString email)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from compte where email like '"+email+"'" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("account"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("MTP"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PERMISSIONS"));

    return model;
}
QSqlQueryModel * Compte::chercher_compte(int account,int permissions,int z)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QString acc_ = QString::number(account);
    QString perm=  QString::number(permissions);

    model->setQuery("select * from compte where username = '"+acc_+"' and permissions = '"+perm+"' " );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("account"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("MTP"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PERMISSIONS"));

    return model;
}
QSqlQueryModel * Compte::tri_compte(int state)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    if(state == 1)
    {
    model->setQuery("select * from compte order by username ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("account"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("MTP"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PERMISSIONS"));
    }
    if(state == 2)
    {
    model->setQuery("select * from compte order by email" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("account"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("MTP"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PERMISSIONS"));
    }
    if(state == 3)
    {
    model->setQuery("select * from compte order by permissions ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("account"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("MTP"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PERMISSIONS"));
    }
    return model;
}
QSqlQueryModel * Compte::chercher_compte(int x,int state, QString email)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QString xy = QString::number(x);
    //QString perm=  QString::number(permissions);
    if (state == 2)
    {
    model->setQuery("select * from compte where username = '"+xy+"' and email like '"+email+"' " );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("account"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("MTP"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PERMISSIONS"));
    }
    if(state == 1)
    {
        model->setQuery("select * from compte where permissions = '"+xy+"' and email like '"+email+"' " );
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("account"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("MTP"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("EMAIL"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("PERMISSIONS"));

    }

    return model;
}
bool Compte::modifier_compte(int account1,QString mtp,QString email ,int permissions)
{
    QSqlQuery query;
    QString account1_ = QString::number(account1);

    QString permissions_ = QString::number(permissions);


    query.prepare("update compte   set mtp=:mtp,email=:email,permissions=:permissions where username=:account1");
    query.bindValue(":account1",account1_);

    query.bindValue(":mtp",mtp);
    query.bindValue(":email",email);
    query.bindValue(":permissions",permissions_);
    return query.exec();
}
bool Compte::ajouter_compte()
{
    QSqlQuery query;

    QString permissions_ = QString::number(permissions);


    query.prepare("insert into compte (username,mtp,email,permissions) values (seq_username.nextval,:mtp,:email,:permissions)");

    query.bindValue(":mtp",mtp);
    query.bindValue(":email",email);
    query.bindValue(":permissions",permissions_);
    return query.exec();
}

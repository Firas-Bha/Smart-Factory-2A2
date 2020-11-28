#include "departement.h"

Departement::Departement()
{

}
Departement::Departement(int id,QString nom)
{
    idd=id;
    nom_dep=nom;
}
bool Departement::ajouter_dep()
{
    QSqlQuery query;

    QString nom = nom_dep;
    query.prepare("insert into departement (idd,nom_dep) values (seq_idd.nextval,:nom)");

    query.bindValue(":nom",nom);
    return query.exec();
}
QSqlQueryModel * Departement::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from departement");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("idd"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_dep"));


    return model;
}
QSqlQueryModel * Departement::chercher_dep(int idd)
{
    QString idd_ = QString::number(idd);
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from departement where idd = '"+idd_+"'" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("idd"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom dep"));
    return model;
}
QSqlQueryModel * Departement::chercher_dep(QString nom)
{

    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from departement where nom_dep = '"+nom+"'" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("idd"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom dep"));
    return model;
}
QSqlQueryModel * Departement::chercher_dep(int idd,QString nom)
{
    QString idd_ = QString::number(idd);
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from departement where idd = '"+idd_+"' and nom_dep = '"+nom+"' " );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("idd"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom dep"));
    return model;
}
QSqlQueryModel * Departement::tri_dep(int state)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    if(state == 1)
    {
            model->setQuery("select * from departement order by idd");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("idd"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_dep"));
    }
            if(state == 2)
            {
                    model->setQuery("select * from departement order by nom_dep");
                    model->setHeaderData(0,Qt::Horizontal,QObject::tr("idd"));
                    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_dep"));
            }



    return model;
}
QSqlQueryModel * Departement::combobox()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select idd from departement");
    return model;
}
bool Departement::modifier_dep(int idd,QString nom)
{
    QSqlQuery query;
    QString idd_ = QString::number(idd);


    query.prepare("update departement set nom_dep=:nom where idd=:idd_");
    query.bindValue(":idd_",idd_);

    query.bindValue(":nom",nom);

    return query.exec();
}
bool Departement::supp_dep(int idd)
{
  QSqlQuery query;
  QString idd_ = QString::number(idd);
  query.prepare("Delete from departement  where idd =:idd");
  query.bindValue(":idd",idd_);
  return query.exec();

}

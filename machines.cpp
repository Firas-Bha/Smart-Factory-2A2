#include "machines.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
//#include "ui_equipements.h"
//#include "equipements.h"


machines::machines()
{
    id=0;
    idDepart=0;
    type="";
    etat="";
}
machines::machines(int i,int u,QString a,QString b)
{
id=i;
idDepart=u;
type=a;
etat=b;


}
bool machines::ajouter()
{
    QSqlQuery query;
    QString ids= QString::number(id);
     QString id_depart= QString::number(idDepart);
query.prepare("INSERT INTO MACHINES(id, id_Depart, type, etat)""VALUES(:id , :idDepart , :type , :etat)");
query.bindValue(":id",ids);
query.bindValue(":idDepart",id_depart);
query.bindValue(":type",type);
query.bindValue(":etat",etat);
return query.exec();
}
QSqlQueryModel * machines::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
  model->setQuery("select * from machines");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("idDepart"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("etat"));
return model;

}
bool machines::supprimer(int ide)
{
    QSqlQuery Query;
    QString ids=QString::number(ide);
    Query.prepare("Delete from machines where ID = :id"  );
    Query.bindValue(":id",ids);
    return Query.exec();


}
bool machines::modifier(int id)
{
    QSqlQuery query;

    QString ids=QString::number(id);
     QString id_depart=QString::number(idDepart);
      query.prepare("UPDATE MACHINES SET id='"+ids+"',id_Depart='"+id_depart+"',type='"+type+"',etat='"+etat+"' where id='"+ids+"'");

return query.exec();
}
QSqlQueryModel *machines::recherche_id_machine(QString txt)
{

    QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from machines where id LIKE '"+txt+"'" );
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("idDepart"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("etat"));

         return model;



}
QSqlQueryModel *machines::recherche_departement_machine(QString txt)
{

    QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from machines where id_Depart LIKE '"+txt+"'" );
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("idDepart"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("etat"));;


         return model;



}
QSqlQueryModel *machines::recherche_type_machine(QString txt)
{

    QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from machines where type LIKE '"+txt+"'" );
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("idDepart"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("etat"));

         return model;



}
QSqlQueryModel *machines::recherche_etat_machine(QString txt)
{

    QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from machines where etat LIKE '"+txt+"'" );
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("idDepart"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("etat"));


         return model;



}
QSqlQueryModel * machines::trieridDepart()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from machines order by id_Depart ");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("idDepart"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("etat"));
return model;
}
QSqlQueryModel * machines::triertype()
  {
    QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from machines order by type");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("idDepart"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("etat"));
return model;
}
QSqlQueryModel * machines::trieretat()
  {
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from machines order by etat");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("idDepart"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("etat"));
return model;
}





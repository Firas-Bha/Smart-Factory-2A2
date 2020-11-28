#include "interventions.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "ui_mainwindow.h"
#include "mainwindow.h"
interventions::interventions()
{

    code=0;
    idtech=0;
    date="";
    devis=0;
}
interventions::interventions(int i,int u,QString a,int b)
{
code=i;
idtech=u;
date=a;
devis=b;


}
bool interventions::ajouter()
{
    QSqlQuery query;
    QString codes= QString::number(code);
     QString id_tech= QString::number(idtech);
     QString devis_interv= QString::number(devis);
query.prepare("INSERT INTO interventions(code_interv, id_tech, date_interv, devis)""VALUES(:code_interv , :id_tech , :date_interv , :devis)");
query.bindValue(":code_interv",codes);
query.bindValue(":id_tech",id_tech);
query.bindValue(":date_interv",date);
query.bindValue(":devis",devis_interv);
return query.exec();
}
QSqlQueryModel * interventions::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
  model->setQuery("select * from interventions");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("code"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("idtech"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("devis"));
return model;

}
bool interventions::supprimer(int code)
{
    QSqlQuery Query;
    QString codes=QString::number(code);
    Query.prepare("Delete from interventions where code_interv = :code"  );
    Query.bindValue(":code",codes);
    return Query.exec();


}
bool interventions::modifier(int code)
{
    QSqlQuery query;

    QString codes= QString::number(code);
     QString id_tech= QString::number(idtech);
     QString devis_interv= QString::number(devis);
      query.prepare("UPDATE interventions SET code_interv='"+codes+"',id_tech='"+id_tech+"',date_interv='"+date+"',devis='"+devis_interv+"' where code_interv='"+codes+"'");

return query.exec();
}

QSqlQueryModel *interventions::recherche_code(QString txt)
{

    QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from interventions where code_interv LIKE '"+txt+"'" );
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("code"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("idtech"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("devis"));

         return model;



}
QSqlQueryModel *interventions::recherche_id_tech(QString txt)
{
    QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from interventions where id_tech LIKE '"+txt+"'" );
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("code"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("idtech"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("devis"));


         return model;



}

QSqlQueryModel *interventions::recherche_devis(QString txt)
{
    QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from interventions where devis LIKE '"+txt+"'" );
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("code"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("idtech"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("devis"));


         return model;



}
QSqlQueryModel * interventions::trieridcode()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from interventions order by id_tech ");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("code"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("idtech"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("devis"));

return model;
}
QSqlQueryModel * interventions::trierdate()
  {
    QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from interventions order by date_interv");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("code"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("idtech"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("devis"));

return model;
}
QSqlQueryModel * interventions::trierdevis()
  {
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from interventions order by devis");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("code"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("idtech"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("devis"));

return model;
}
void interventions::statistique(QVector<double>* ticks,QVector<QString> *labels)
{   QSqlQuery q;
    int i=0;
    q.exec("select code_interv from interventions");
    while (q.next()) {
        QString refer = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<refer;
}
}


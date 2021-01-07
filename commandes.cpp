#include "commandes.h"

commandes::commandes()
{
   id=0;
   lieu="";
   type="";
   nom="";
   num=0;
}
commandes::commandes(int i,QString n,QString p,QString no,int nu){

    id=i;
    type=n;
    lieu=p;
    nom=no;
    num=nu;
}
bool commandes::ajouter(){

    QSqlQuery query;
    QString ids=QString::number(id);
    QString nums=QString::number(num);

    query.prepare("INSERT INTO COMMANDESA (IDF,TYPE,LIEU,NOM,NUM)"
                  "VALUES(:id, :type, :lieu, :nom, :num)");
    query.bindValue(":id",ids);
    query.bindValue(":type",type);
    query.bindValue(":lieu",lieu);
    query.bindValue(":nom",nom);
    query.bindValue(":num",nums);

    return query.exec();


}
QSqlQueryModel * commandes::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from commandesa ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Idantifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Lieu"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Num"));

    return model;
}
bool commandes::supprimer(int ide){
    QSqlQuery query;
    QString ids=QString::number(ide);
    query.prepare("Delete from commandesa where IDF = :id");
    query.bindValue(":id",ids);
    return query.exec();
}
bool commandes::modifier()
{
    QSqlQuery query;
    QString ids=QString::number(id);
    QString nums=QString::number(num);


    query.prepare("UPDATE COMMANDESA set type=:type,lieu=:lieu,nom=:nom,num=:num where idf=:id");
    query.bindValue(":id",ids);
    query.bindValue(":type",type);
    query.bindValue(":lieu",lieu);
    query.bindValue(":nom",nom);
    query.bindValue(":num",nums);

    return query.exec();
}
QSqlQueryModel * commandes::chercher(int n,int ide,QString ch){

QSqlQuery query;
QSqlQueryModel * model1=new QSqlQueryModel();
QString ids=QString::number(ide);

if(n==1)
{
    model1->setQuery("select * from commandesa where IDF LIKE '"+ids+"' " );
    model1->setHeaderData(0,Qt::Horizontal,QObject::tr("Idantifiant"));
    model1->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
    model1->setHeaderData(2,Qt::Horizontal,QObject::tr("Lieu"));
    model1->setHeaderData(3,Qt::Horizontal,QObject::tr("Nom"));
    model1->setHeaderData(4,Qt::Horizontal,QObject::tr("Num"));

    return model1;
}
else if (n==2)
{

    model1->setQuery("select * from commandesa where LIEU LIKE '"+ch+"' " );
    model1->setHeaderData(0,Qt::Horizontal,QObject::tr("Idantifiant"));
    model1->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
    model1->setHeaderData(2,Qt::Horizontal,QObject::tr("Lieu"));
    model1->setHeaderData(3,Qt::Horizontal,QObject::tr("Nom"));
    model1->setHeaderData(4,Qt::Horizontal,QObject::tr("Num"));

    return model1;

}
else if (n==3)
{
    model1->setQuery("select * from commandesa where TYPE LIKE '"+ch+"' " );
    model1->setHeaderData(0,Qt::Horizontal,QObject::tr("Idantifiant"));
    model1->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
    model1->setHeaderData(2,Qt::Horizontal,QObject::tr("Lieu"));
    model1->setHeaderData(3,Qt::Horizontal,QObject::tr("Nom"));
    model1->setHeaderData(4,Qt::Horizontal,QObject::tr("Num"));

    return model1;

}
return model1;

}

QSqlQueryModel * commandes ::afficher_combo()
{ QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select idf from commandesa");

    return model ;

}

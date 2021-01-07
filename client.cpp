#include "client.h"

Client::Client()
{
 id=0;
 nom="";
 prenom="";
 adresse="";
 tel=0;

}

Client::Client(int i,QString n,QString p,int t,QString a){
    id=i;
    nom=n;
    prenom=p;
    adresse=a;
    tel=t;


}
bool Client::ajouter(){

    QSqlQuery query;
    QString ids=QString::number(id);
    query.prepare("INSERT INTO Client(id,nom,prenom,tel,adresse)""VALUES(:id,:nom,:prenom,:tel,:adresse)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":tel",tel);
    query.bindValue(":adresse",adresse);
    return query.exec();

}
QSqlQueryModel * Client::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from client");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Tel"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Adresse"));
    return model;
}
bool Client::supprimer(int idc)
{
    QSqlQuery query;
    QString ids=QString::number(idc);
    query.prepare("Delete from Client where ID=:id");
    query.bindValue(":id",idc);
    return query.exec();
}
bool Client::modifier()
{
   QSqlQuery query;
   QString ids= QString::number(id);
   query.prepare("UPDATE CLIENT SET Nom=:nom,Prenom=:prenom,Tel=:tel,Adresse=:adresse WHERE ID=:ids");
   query.bindValue(":nom", nom);
   query.bindValue(":prenom", prenom);
   query.bindValue(":ids",ids);
   query.bindValue(":adresse", adresse);
   query.bindValue(":tel", tel);


    return  query.exec();
}
QSqlQueryModel *Client::rechercher_client(const QString &id)
{
    QSqlQueryModel *model=new QSqlQueryModel();
   model->setQuery("select * from Client where(ID LIKE '"+id+"')");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    return model;
}
QSqlQueryModel *Client::afficher_client_trier()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from Client ORDER BY ID");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("tel"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Adresse"));
    return model;
}



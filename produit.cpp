#include "produit.h"
Produit::Produit()
{
id_Produit=0;
nom_Produit="";
prix_Produit=0;
NomStock="";
}
Produit::Produit(int i,QString n  ,int p ,QString nomS)
{
    id_Produit=i;
    nom_Produit=n;
    prix_Produit=p;
    NomStock=nomS;
}

bool Produit:: ajouter()
{
        QSqlQuery query;

        QString ids= QString::number(id_Produit);
        QString pr= QString::number(prix_Produit);
        query.prepare("insert into produit (id,nom,prix,stock) values (:ids_,:nom,:pr_,:stock)");
        query.bindValue(":ids_",ids);
        query.bindValue(":nom",nom_Produit);
        query.bindValue(":pr_",pr);
        query.bindValue(":stock",NomStock);
        return query.exec();
}
QSqlQueryModel * Produit::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from PRODUIT");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prix"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Stock"));
    return model;
}
bool Produit::supprimer(int ide)
{
QSqlQuery query;
QString ids=QString::number(ide);
query.prepare("Delete from PRODUIT where Id =:ids ");
query.bindValue(":ids",ids);
return    query.exec();
}
bool Produit::modifier( int id_Produit,QString nom_Produit,int prix_Produit,QString NomStock)
{
    QSqlQuery query;
    QString ids=QString::number(id_Produit);
    QString pr=QString::number(prix_Produit);
    query.prepare("UPDATE produit SET  id = :ids, nom = :nom_Produit, prix=:pr, Stock=:NomStock where id='"+ids+"' ");
    query.bindValue(":ids",ids);
    query.bindValue(":nom_Produit",nom_Produit);
    query.bindValue(":pr",pr);
    query.bindValue(":NomStock",NomStock);
    return  query.exec();
}
QSqlQueryModel * Produit::chercher_ID(QString txt)
{

QSqlQuery query;
QSqlQueryModel * model1=new QSqlQueryModel();
    model1->setQuery("select * from PRODUIT where Id LIKE '"+txt+"' " );
    model1->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model1->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model1->setHeaderData(2,Qt::Horizontal,QObject::tr("Prix"));
    model1->setHeaderData(3,Qt::Horizontal,QObject::tr("Nom"));
    model1->setHeaderData(4,Qt::Horizontal,QObject::tr("NomStock"));

    return model1;

}
QSqlQueryModel * Produit::chercher_Nom(QString txt)
{

QSqlQuery query;
QSqlQueryModel * model1=new QSqlQueryModel();
    model1->setQuery("select * from PRODUIT where Nom LIKE '"+txt+"' " );
    model1->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model1->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model1->setHeaderData(2,Qt::Horizontal,QObject::tr("Prix"));
    model1->setHeaderData(3,Qt::Horizontal,QObject::tr("Nom"));
    model1->setHeaderData(4,Qt::Horizontal,QObject::tr("NomStock"));

    return model1;

}
QSqlQueryModel * Produit::chercher_Prix(QString txt)
{

QSqlQuery query;
QSqlQueryModel * model1=new QSqlQueryModel();

    model1->setQuery("select * from PRODUIT where Prix LIKE '"+txt+"' " );
    model1->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model1->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model1->setHeaderData(2,Qt::Horizontal,QObject::tr("Prix"));
    model1->setHeaderData(3,Qt::Horizontal,QObject::tr("Nom"));
    model1->setHeaderData(4,Qt::Horizontal,QObject::tr("NomStock"));

    return model1;

}
QSqlQueryModel * Produit::trier_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM Produit ORDER BY NOM ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NomStock"));
    return model;

}
QSqlQueryModel * Produit::trier_Prix()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM PRODUIT ORDER BY PRIX ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NomStock"));
    return model;
}
QSqlQueryModel * Produit::trier_ID()
{

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM PRODUIT ORDER BY ID ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NomStock"));
    return model;
}

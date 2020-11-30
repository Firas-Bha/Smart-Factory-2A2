#include "stock.h"

Stock::Stock()
{
   id_Stock=0;
   Nom="";
}

Stock::Stock(int id_Stock,QString Nom)
{
    this->id_Stock=id_Stock;
    this->Nom=Nom;
}
bool Stock:: ajouterStock()
{
    QSqlQuery query;
    QString ids=QString::number(id_Stock);
   query.prepare("insert into STOCK (id,nom) values (:ids_,:nom)");
    query.bindValue(":ids_",ids);
    query.bindValue(":nom",Nom);
    return query.exec();
}
QSqlQueryModel * Stock::afficherStock()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from STOCK");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    return model;

}

bool Stock::supprimer(int ide)
{
    QSqlQuery query;
    QString ids=QString::number(ide);
    query.prepare("Delete from STOCK where Id =:ids ");
    query.bindValue(":ids",ids);
    return    query.exec();
}
bool Stock::modifier( int id_Stock,QString Nom)
{
    QSqlQuery query;
    QString res=QString::number(id_Stock);
    query.prepare("UPDATE stock SET  Id = :res, nom = :Nom ");
    query.bindValue(":res", res);
    query.bindValue(":Nom", Nom);
    return  query.exec();
}
QSqlQueryModel * Stock::trier_NomAscendant()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM STOCK ORDER BY NOM ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    return model;

}
QSqlQueryModel * Stock::trier_NomDescendant()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM STOCK ORDER BY NOM DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    return model;
}
QSqlQueryModel * Stock::trier_IDSTOCK()
{

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM STOCK ORDER BY ID ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NomStock"));
    return model;
}



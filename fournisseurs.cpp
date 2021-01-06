#include "fournisseurs.h"

fournisseurs::fournisseurs()
{
    id=0;
    type="";
    dateC="";
    nom="";
    quantite=0;
    idF=0;
}
fournisseurs::fournisseurs(int i,QString t,QString d,QString n,int q ,int id1){

    id=i;
    type=t;
    dateC=d;
    nom=n;
    quantite=q;
    idF=id1;
}
bool fournisseurs::ajouter(){

    QSqlQuery query;
    QString ids=QString::number(id);
    QString quans=QString::number(quantite);
    QString id1=QString::number(idF);


    query.prepare("INSERT INTO FOURNISSEURS (ID,TYPE,DATEC,NOM,QUANTITE,IDFO)"
                  "VALUES(:id, :type, :dateC, :nom, :quantite, :idFo)");
    query.bindValue(":id",ids);
    query.bindValue(":type",type);
    query.bindValue(":dateC",dateC);
    query.bindValue(":nom",nom);
    query.bindValue(":quantite",quans);
    query.bindValue(":idFo",id1);


    return query.exec();


}
QSqlQueryModel * fournisseurs::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from fournisseurs ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Idantifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Quantite"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("id Fournisseur"));


    return model;
}
bool fournisseurs::supprimer(int ide){
    QSqlQuery query;
    QString ids=QString::number(ide);
    query.prepare("Delete from fournisseurs where ID = :id");
    query.bindValue(":id",ids);
    return query.exec();
}
bool fournisseurs::modifier()
{
    QSqlQuery query;
    QString ids=QString::number(id);
    QString quans=QString::number(quantite);
    QString id1=QString::number(idF);



    query.prepare("UPDATE fournisseurs set type=:type,datec=:datec,nom=:nom,quantite=:quantite,idfo=:idfo where ID=:id");
    query.bindValue(":id",ids);
    query.bindValue(":type",type);
    query.bindValue(":datec",dateC);
    query.bindValue(":nom",nom);
    query.bindValue(":quantite",quans);
    query.bindValue(":idfo",id1);


    return query.exec();
}

void fournisseurs::statistique(QVector<double>* ticks,QVector<QString> *labels)
{   QSqlQuery q;
    int i=0;
    q.exec("select QUANTITE from fournisseurs");
    while (q.next()) {
        QString refer = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<refer;
}
}
QSqlQueryModel * fournisseurs::trier(int n)
{
    QSqlQueryModel * model=new QSqlQueryModel();
        if(n==1)
        {
    model->setQuery("select * from fournisseurs order by type" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Idantifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Quantite"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("id Fournisseur"));

    return model;

        }
       else if(n==2)
        {
    model->setQuery("select * from fournisseurs order by nom" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Idantifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Quantite"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("id Fournisseur"));

    return model;

        }
        else if(n==3)
         {
     model->setQuery("select * from fournisseurs order by id" );
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("Idantifiant"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("Nom"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("Quantite"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("id Fournisseur"));

     return model;

         }


        return model;


}
/*QSqlQueryModel * fournisseurs ::afficher_combo()
{ QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select id from commandes");

    return model ;

}*/

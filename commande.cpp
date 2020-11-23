#include "commande.h"

Commande::Commande()
{
  Type="";
  CodeC=0;
  Date="";
  Prix=0;
  ID=0;
}
Commande::Commande(QString T,int C,QString D,int P,int I){

    Type=T;
    CodeC=C;
    Date=D;
    Prix=P;
    ID=I;
}
bool Commande::ajouter(){

    QSqlQuery query;
    QString code=QString::number(CodeC);
    query.prepare("INSERT INTO Commande(IDCLIENT,TYPE,CODE,DATEC,PRIX)""VALUES(:ID,:Type,:CodeC,:Date,:Prix)");
    query.bindValue(":Type",Type);
    query.bindValue(":CodeC",CodeC);
    query.bindValue(":Date",Date);
    query.bindValue(":Prix",Prix);
    query.bindValue(":ID",ID);
    return query.exec();

}
QSqlQueryModel * Commande::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Commande");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CodeC"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Date"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Prix"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    return model;
}
bool Commande::supprimer(int Code)
{
    QSqlQuery query;
    QString CodeC=QString::number(Code);
    query.prepare("Delete from Commande where CODE=:CodeC");
    query.bindValue(":CodeC",Code);
    return query.exec();
}
bool Commande::modifier()
{
   QSqlQuery query;
   QString ids= QString::number(ID);
   query.prepare("UPDATE Commande SET TYPE=:Type,DATEC=:Date,CODE=:CodeC,PRIX=:Prix WHERE IDCLIENT=:ID");
   query.bindValue(":Type", Type);
   query.bindValue(":Date", Date);
   query.bindValue(":CodeC",CodeC);
   query.bindValue(":Prix", Prix);
   query.bindValue(":ID", ID);
    return  query.exec();
}
QSqlQueryModel *Commande::rechercher_commande(const QString &id)
{
    QSqlQueryModel *model=new QSqlQueryModel();
   model->setQuery("select * from Commande where(IDCLIENT LIKE '"+id+"')");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Type"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("CodeC"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("IDCLIENT"));
    return model;
}

QSqlQueryModel *Commande::afficher_commande_trier()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from Commande ORDER BY IDCLIENT");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CodeC"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Date"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Prix"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("IDCLIENT"));
    return model;
}
void Commande::statistique(QVector<double>* ticks,QVector<QString> *labels)
{   QSqlQuery q;
    int i=0;
    q.exec("select Prix from Commande");
    while (q.next()) {
        QString refer = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<refer;
}
}



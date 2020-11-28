#ifndef STOCK_H
#define STOCK_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Stock
{
public:
    Stock();
    Stock(int,QString);
    int  getidStock(){return id_Stock;}
    QString getNom(){return Nom;}
    bool ajouterStock();
    QSqlQueryModel * afficherStock();
    bool supprimer(int);
    bool modifier( int ,QString);
    QSqlQueryModel*trier_NomAscendant();
    QSqlQueryModel *trier_NomDescendant();

private:

    int id_Stock;
    QString Nom;

};

#endif // STOCK_H

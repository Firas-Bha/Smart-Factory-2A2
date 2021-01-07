#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Produit
{
public:
    Produit();
    Produit(int,QString,int,QString);
    QString getNom(){return nom_Produit;}
    QString getNomStock(){return NomStock;}
    int getid_Produit(){return id_Produit;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int ,QString ,int ,QString);
    QSqlQueryModel * chercher_ID(QString);
    QSqlQueryModel * chercher_Nom(QString);
    QSqlQueryModel * chercher_Prix(QString);
    QSqlQueryModel * trier_nom();
    QSqlQueryModel * trier_Prix();
    QSqlQueryModel *trier_ID();

private:
    int id_Produit;
    QString nom_Produit;
    int prix_Produit;
    QString NomStock;



};

#endif // PRODUIT_H

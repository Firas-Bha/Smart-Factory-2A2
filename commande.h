#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Commande
{
public:
    Commande();
    Commande(QString,int,QString,int,int);

    QString getDate(){return Date;}
    int getCodeC(){return CodeC;}
    QString getType(){return Type;}
    int getPrix(){return Prix;}
    int getID(){return ID;}
    QSqlQueryModel * afficher_commande_trier();
    QSqlQueryModel * rechercher_commande(const QString &id);
    void statistique(QVector<double>* ticks,QVector<QString> *labels);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();

private:
    QString Date,Type;
    int CodeC,Prix,ID;


};

#endif // COMMANDE_H

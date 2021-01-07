#ifndef FOURNISSEURS_H
#define FOURNISSEURS_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class fournisseurs
{
public:
    fournisseurs();
    fournisseurs(int ,QString,QString,QString,int,int);
    QString getDate(){return dateC;}
    QString getPreType(){return type;}
    QString getNom(){return nom;}
    int getID(){return id;}
    int getIDF(){return idF;}
    int getQuant(){return quantite;}


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * chercher(int);
    //QSqlQueryModel * afficher_combo();
    void statistique(QVector<double>* ticks,QVector<QString> *labels);
    QSqlQueryModel * trier(int n);
        public:
        int n=0;
        private:
        int id;
        int quantite;
        int idF;
    QString type,dateC,nom;
};

#endif // FOURNISSEURS_H

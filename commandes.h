#ifndef COMMANDES_H
#define COMMANDES_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class commandes
{
public:
    commandes();
    commandes(int ,QString,QString,QString,int);
    QString getLieu(){return lieu;}
    QString getPreType(){return type;}
    QString getNom(){return nom;}
    int getID(){return id;}
    int getNum(){return num;}


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * chercher(int,int,QString);
    QSqlQueryModel * afficher_combo();
        private:
        int id;
        int num;
        int n=0;
    QString lieu,type,nom,ch;
};
#endif // COMMANDES_H

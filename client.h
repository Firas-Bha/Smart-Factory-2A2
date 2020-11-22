#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Client
{
public:
    Client();
    Client(int,QString,QString,int,QString);
    int getID(){return id;}
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    QString getAdresse(){return adresse;}
    int getTel(){return tel;}
    QSqlQueryModel * afficher_client_trier();
    QSqlQueryModel * rechercher_client(const QString &id);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
private:
    int id,tel;
    QString nom,prenom,adresse;

};

#endif // CLIENT_H

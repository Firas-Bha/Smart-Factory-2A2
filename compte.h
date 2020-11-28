#ifndef COMPTE_H
#define COMPTE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <vector>
//
using namespace std;
class Compte
{
public:
    Compte();
    Compte(int,QString,QString,int);
    //vector <int> ComboBox();
    int getUsername(){return usern;}
    QString getMtp(){return mtp;}
    QString getEmail(){return email;}


    bool ajouter_compte();

    bool modifier_compte(int,QString,QString,int);
    QSqlQueryModel * afficher();
    QSqlQueryModel * combobox();
    bool supprimer(int);
    //account or permissions
    QSqlQueryModel *  chercher_compte(int,int);
    //email
    QSqlQueryModel *  chercher_compte(QString);
   //all
    QSqlQueryModel *  chercher_compte(int,QString,int);
    //account + permissions or account
    QSqlQueryModel *  chercher_compte(int,int,QString);
    //permissions +  account
    QSqlQueryModel *  chercher_compte(int,int,int);
     QSqlQueryModel *  tri_compte(int);


private:

    int usern;
    QString mtp;
    QString email;
    int permissions;


};

#endif // COMPTE_H

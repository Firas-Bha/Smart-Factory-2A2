#ifndef MACHINES_H
#define MACHINES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class machines
{
public:
    machines();
    machines(int,int,QString,QString);
    int getid(){return id;}
     int getidDepart(){return idDepart;}
      QString gettype(){return type;}
       QString getetat(){return etat;}
       bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier(int);
     QSqlQueryModel *recherche_id_machine(QString);
     QSqlQueryModel *recherche_departement_machine(QString);
     QSqlQueryModel *recherche_etat_machine(QString);
     QSqlQueryModel *recherche_type_machine(QString);
      QSqlQueryModel * trieridDepart();
      QSqlQueryModel * triertype();
      QSqlQueryModel * trieretat();




    private:
    int id;
    int idDepart;
    QString type;
    QString etat;



};

#endif // MACHINES_H

#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <vector>
using namespace std;
//
class Departement
{
public:
    Departement();
    Departement(int,QString);
    bool ajouter_dep();
    bool supp_dep(int);
    QSqlQueryModel * afficher();
    QSqlQueryModel * combobox();
    bool modifier_dep(int,QString);
    QSqlQueryModel * tri_dep(int);
    QSqlQueryModel * chercher_dep(int);
    QSqlQueryModel * chercher_dep(QString);
    QSqlQueryModel * chercher_dep(int,QString);
    int get_dep_index(int cin);


private:
    int idd;
    QString nom_dep;

};

#endif // DEPARTEMENT_H

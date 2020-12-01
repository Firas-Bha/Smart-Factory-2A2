#ifndef EMPLOYER_H
#define EMPLOYER_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <vector>
using namespace std;
//
class Employer
{
public:
    Employer();
    Employer(int,QString,QString,int,int,int,int,int);
    bool ajouter_emp();
    bool modifier_emp();
    bool supp_emp(int);
    QSqlQueryModel * afficher();
    QSqlQueryModel * combobox();
    QSqlQueryModel * tri_emp(int);
    QSqlQueryModel *  chercher_emp(int,int);
    QSqlQueryModel *  chercher_emp(int,int,int);
    //nom
    QSqlQueryModel *  chercher_emp(QString);
   //all
    QSqlQueryModel *  chercher_emp(int,QString,int);

    QSqlQueryModel *  chercher_emp(int,int,QString);
    int get_dep_index(int cin);


private:
    int cin;
    QString nom;
    QString prenom;
    int age;
    int salaire_j;
    int nb_presence;
    int username;
    int idd;


};

#endif // EMPLOYER_H

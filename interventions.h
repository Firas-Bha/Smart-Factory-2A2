#ifndef INTERVENTIONS_H
#define INTERVENTIONS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class interventions
{
public:
    interventions();

    interventions(int,int,QString,int);
    int getcode(){return code;}
     int getididtech(){return idtech;}
      QString getdate(){return date;}
       int getdevis(){return devis;}
       bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier(int);

     QSqlQueryModel *recherche_code(QString);
     QSqlQueryModel *recherche_id_tech(QString);
     QSqlQueryModel *recherche_date(QString);
     QSqlQueryModel *recherche_devis(QString);
      QSqlQueryModel * trieridcode();
      QSqlQueryModel * trierdate();
      QSqlQueryModel * trierdevis();
      void statistique(QVector<double>* ticks,QVector<QString> *labels);




    private:
    int code;
    int idtech;
    QString date;
    int devis;



};

#endif // INTERVENTIONS_H

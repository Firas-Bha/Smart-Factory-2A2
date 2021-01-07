#include "employer.h"
//
Employer::Employer()
{

}
Employer::Employer(int cin_,QString nom_,QString prenom_,int age_,int salaire_j_,int nb_presence_,int username_,int idd_)
{

    cin = cin_;
    nom = nom_;
    prenom = prenom_;
    age = age_;
    salaire_j = salaire_j_;
    nb_presence = nb_presence_;
    username = username_;
    idd = idd_;
}

bool Employer::supp_emp(int cin)
{
  QSqlQuery query;
  QString cin_ = QString::number(cin);
  query.prepare("Delete from employer  where cin =:cin_");
  query.bindValue(":cin_",cin_);
  return query.exec();

}
int Employer::get_dep_index(int cin)
{
  QSqlQuery query;
  QString cin_ = QString::number(cin);
  //query.prepare("select nom_dep from employer where cin = '"+cin_+"'");

   query.exec("select idd from employer where cin = '"+cin_+"'");
   query.next();
  QString idd = query.value(0).toString();
   QSqlQuery query2;
   query2.prepare("select  idd from departement ");
   int i = 0 ;
   while(query2.next())
   {

       if (query2.value(0).toString() == idd)
           return i ;
       else
           i++;
   }


}


bool Employer::modifier_emp()
{
    QSqlQuery query;
    QString cin_ = QString::number(cin);
    QString username_ = QString::number(username);
    QString idd_ = QString::number(idd);
    QString nbp = QString::number(nb_presence);
    QString age_ = QString::number(age);
    QString salaire_j_ = QString::number(salaire_j);


    query.prepare("update employer set nom=:nom_,prenom=:prenom_,age=:age_,salaire_j=:salaire_j_,nb_presence=:nb_presence_,username=:username_,idd=:idd_ where cin=:cin_");
    query.bindValue(":cin_",cin_);
    query.bindValue(":nom_",nom);
    query.bindValue(":prenom_",prenom);
    query.bindValue(":age_",age_);
    query.bindValue(":salaire_j_",salaire_j_);
    query.bindValue(":nb_presence_",nbp);
    query.bindValue(":username_",username_);
    query.bindValue(":idd_",idd_);

    return query.exec();
}
bool Employer::ajouter_emp()
{
    QSqlQuery query;
    QString cin_ = QString::number(cin);
    QString age_ = QString::number(age);
    QString salaire_j_ = QString::number(salaire_j);
    QString nb_presence_ = QString::number(nb_presence);
    QString username_ = QString::number(username);
    QString idd_ = QString::number(idd);
    query.prepare("insert into employer (cin,nom,prenom,age,salaire_j,nb_presence,username,idd) values (:cin_,:nom,:prenom,:age_,:salaire_j_,:nb_presence_,:username_,:idd_)");
    query.bindValue(":cin_",cin_);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":age_",age_);
    query.bindValue(":salaire_j_",salaire_j_);
    query.bindValue(":nb_presence_",nb_presence_);
    query.bindValue(":username_",username_);
    query.bindValue(":idd_",idd_);

    return query.exec();
}

QSqlQueryModel * Employer::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from employer");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Salaire_j"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Nb_presence"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Username"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("IDD"));
    return model;
}
QSqlQueryModel * Employer::combobox()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select cin from employer");
    return model;
}
QSqlQueryModel * Employer::tri_emp(int state)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    if(state == 1)
    {
            model->setQuery("select * from employer order by cin");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("Salaire_j"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("Nb_presence"));
            model->setHeaderData(6,Qt::Horizontal,QObject::tr("Username"));
            model->setHeaderData(7,Qt::Horizontal,QObject::tr("IDD"));

    }
    if(state == 2)
    {
            model->setQuery("select * from employer order by nom");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("Salaire_j"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("Nb_presence"));
            model->setHeaderData(6,Qt::Horizontal,QObject::tr("Username"));
            model->setHeaderData(7,Qt::Horizontal,QObject::tr("IDD"));

    }
    if(state == 3)
    {
            model->setQuery("select * from employer order by prenom");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("Salaire_j"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("Nb_presence"));
            model->setHeaderData(6,Qt::Horizontal,QObject::tr("Username"));
            model->setHeaderData(7,Qt::Horizontal,QObject::tr("IDD"));

    }
    if(state == 4)
    {
            model->setQuery("select * from employer order by salaire_j");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("Salaire_j"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("Nb_presence"));
            model->setHeaderData(6,Qt::Horizontal,QObject::tr("Username"));
            model->setHeaderData(7,Qt::Horizontal,QObject::tr("IDD"));

    }
    if(state == 5)
    {
            model->setQuery("select * from employer order by age");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("Salaire_j"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("Nb_presence"));
            model->setHeaderData(6,Qt::Horizontal,QObject::tr("Username"));
            model->setHeaderData(7,Qt::Horizontal,QObject::tr("IDD"));

    }






    return model;
}
QSqlQueryModel * Employer::chercher_emp(int y,int x)
{
    QString y_ = QString::number(y);

    QSqlQueryModel * model = new QSqlQueryModel();
    if ( x == 1)
    {



    model->setQuery("select * from employer where cin = '"+y_+"'" );

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Salaire_j"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Nb_presence"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Username"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("IDD"));
    }
    if(x == 2)
    {



        model->setQuery("select * from employer where age = '"+y_+"'" );
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("Salaire_j"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("Nb_presence"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("Username"));
        model->setHeaderData(7,Qt::Horizontal,QObject::tr("IDD"));


    }
    return model;
}
QSqlQueryModel * Employer::chercher_emp(int cin,QString nom,int age)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QString cin_ = QString::number(cin);
    QString age_=  QString::number(age);

    model->setQuery("select * from employer where cin = '"+cin_+"' and nom like '"+nom+"' and age = '"+age_+"'" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Salaire_j"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Nb_presence"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Username"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("IDD"));

    return model;
}
QSqlQueryModel * Employer::chercher_emp(int x,int state,QString nom)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QString xy = QString::number(x);
    //QString perm=  QString::number(permissions);
    if (state == 2)
    {
    model->setQuery("select * from employer where cin = '"+xy+"' and nom like '"+nom+"' " );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Salaire_j"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Nb_presence"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Username"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("IDD"));
    }
    if(state == 1)
    {
        model->setQuery("select * from employer where age = '"+xy+"' and nom like '"+nom+"' " );
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("Salaire_j"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("Nb_presence"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("Username"));
        model->setHeaderData(7,Qt::Horizontal,QObject::tr("IDD"));

    }

    return model;
}
QSqlQueryModel * Employer::chercher_emp(QString x)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from employer where nom like '"+x+"'" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Salaire_j"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Nb_presence"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Username"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("IDD"));

    return model;
}
QSqlQueryModel * Employer::chercher_emp(int cin,int age,int z)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QString cin_ = QString::number(cin);
    QString age_=  QString::number(age);

    model->setQuery("select * from employer where cin = '"+cin_+"' and age = '"+age_+"' " );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Salaire_j"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Nb_presence"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Username"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("IDD"));

    return model;
}

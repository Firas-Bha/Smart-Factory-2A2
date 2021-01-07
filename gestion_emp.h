#ifndef GESTION_EMP_H
#define GESTION_EMP_H
#include "compte.h"
#include "departement.h"
#include "employer.h"
#include <QDialog>

namespace Ui {
class gestion_emp;
}

class gestion_emp : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_emp(QWidget *parent = nullptr);
    ~gestion_emp();
    void refreshinfo();

private slots:
    void on_ajouter_emp_clicked();

    void on_modifier_emp_clicked();

    void on_supp_emp_clicked();

    void on_chercher_emp_clicked();

    void on_trier_emp_clicked();

    void on_ajouter_dep_clicked();

    void on_mod_dep_clicked();

    void on_supp_dep_clicked();

    void on_pushButton_ajout_compte_clicked();

    void on_mod_compte_clicked();

    void on_supp_compte_clicked();

    void on_chercher_dep_clicked();

    void on_trier_dep_clicked();

    void on_chercher_compte_clicked();

    void on_tri_compte_clicked();



    void on_browse_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::gestion_emp *ui;
    Compte tempCompte;
    Departement tempdep;
    Employer tempemp;
    QStringList files;
};

#endif // GESTION_EMP_H

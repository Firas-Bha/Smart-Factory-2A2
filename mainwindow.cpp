#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "compte.h"
#include <QMessageBox>
#include "employer.h"
#include "departement.h"
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QUrl>

//
using namespace std;
void MainWindow::refreshw()
{
    ui->tableView_compte->setModel(tempCompte.afficher());
    ui->comboBox_mod_compte->setModel(tempCompte.combobox());
    ui->comboBox_supp_compte->setModel(tempCompte.combobox());
    ui->tableView_dep->setModel(tempdep.afficher());
    ui->comboBox_mod_dep->setModel(tempdep.combobox());
    ui->comboBox_supp_dep->setModel(tempdep.combobox());
    ui->comboBox_emp_add_username->setModel(tempCompte.combobox());
    ui->comboBox_emp_add_dep->setModel(tempdep.combobox());
    ui->tableView_emp->setModel(tempemp.afficher());
    ui->tableView_compte->setModel(tempCompte.afficher());
    ui->comboBox_mod_emp_dep->setModel(tempdep.combobox());
    ui->comboBox_mod_emp_username->setModel(tempCompte.combobox());
    ui->comboBox_mod_emp_cin->setModel(tempemp.combobox());
    ui->comboBox_supp_emp->setModel(tempemp.combobox());
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->lineEdit_cher_cin->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_cher_age->setValidator(new QIntValidator(0,111));
    ui->lineEdit_cher_id->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_cher_username->setValidator(new QIntValidator(0,999999999));

    ui->lineEdit_emp_add_cin->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_emp_add_salaire_j->setValidator(new QIntValidator(0,99999));
    ui->lineEdit_emp_add_age->setValidator(new QIntValidator(0,111));

    ui->lineEdit_emp_mod_sal->setValidator(new QIntValidator(0,99999));
    ui->lineEdit_emp_mod_nbp->setValidator(new QIntValidator(0,99999));
    ui->lineEdit_emp_mod_age->setValidator(new QIntValidator(0,111));

    ui->lineEdit_aj_permissions->setValidator(new QIntValidator(0,111));
    ui->lineEdit_mod_permissions->setValidator(new QIntValidator(0,111));

    refreshw();

}
MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget ->setCurrentIndex(1);
}

void MainWindow::on_pushButton_28_clicked()
{
    ui->stackedWidget ->setCurrentIndex(0);
}

void MainWindow::on_pushButton_ajout_compte_clicked()
{

    QString mtp =  ui->lineEdit_aj_mtp->text();
    QString email    =  ui->lineEdit_aj_email->text();
    int permissions  =  ui->lineEdit_aj_permissions->text().toInt();
    Compte c(0,mtp,email,permissions);
    QString permissions_ = ui->lineEdit_aj_permissions->text();




    //Compte c(usern,mtp,email);
    bool test = c.ajouter_compte();
    if (test)
    {
        ui->tableView_compte->setModel(tempCompte.afficher());
        if(ui->radioButton_imp_compte->isChecked())
        {
            QPixmap logo;
            logo.load("ifactory-logo");
            logo.scaled(logo.width()*10,logo.height()*10);

            QString pdf_name= "file_compte_"+permissions_+".pdf";
            QPdfWriter pdf(pdf_name);
            QPainter painter(&pdf);
            painter.drawPixmap(3000,0,logo.width()*20,logo.height()*20,logo);



            painter.setPen(Qt::blue);
            painter.drawText(100,2000,"compte info : ");

            painter.setPen(Qt::blue);
            painter.drawText(100,2600,"mtp : ");
            painter.setPen(Qt::black);
            painter.drawText(2000,2600,mtp);
            painter.setPen(Qt::blue);
            painter.drawText(100,2900,"email : ");
            painter.setPen(Qt::black);
            painter.drawText(2000,2900,email);
            painter.setPen(Qt::blue);
            painter.drawText(100,3200,"permissions : ");
            painter.setPen(Qt::black);
            painter.drawText(2000,3200,permissions_);

            painter.end();
            QMessageBox::information(nullptr, QObject::tr("pdf  "),
                        QObject::tr("pdf terminer.\n"
                                    "Clicker sur  accept ."), QMessageBox::Accepted);

        }
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("ajout de compte refuser"),
                    QObject::tr("l ajout de compte  est refusé.\n"
                                "Clicker sur  Abort ."), QMessageBox::Abort);

refreshw();
}

void MainWindow::on_pushButton_17_clicked()
{

    int account = ui->comboBox_supp_compte->currentText().toInt();
    bool test = tempCompte.supprimer(account);
    if(!test)
    {
        QMessageBox::critical(nullptr, QObject::tr("suprr refuser"),
                    QObject::tr("la supp de compte  est refusé.\n"
                                "Clicker sur  Abort ."), QMessageBox::Abort);
    }
   refreshw();

}

void MainWindow::on_pushButton_16_clicked()
{

    int account = ui->comboBox_mod_compte->currentText().toInt();
     int permissions = ui->lineEdit_mod_permissions->text().toInt();

     QString email =  ui->lineEdit_mod_email->text();
     QString mtp =  ui->lineEdit_mod_mtp->text();
     Compte c;
     bool test = c.modifier_compte(account,mtp,email,permissions);
     if(!test)
     {
         QMessageBox::critical(nullptr, QObject::tr("modif refuser"),
                     QObject::tr("la modif de compte  est refusé.\n"
                                 "Clicker sur  Abort ."), QMessageBox::Abort);
     }
    refreshw();
}


void MainWindow::on_pushButton_12_clicked()
{
    int account = ui->lineEdit_cher_username->text().toInt() ,permissions = ui->lineEdit_cher_permissions->text().toInt();
    QString email = ui->lineEdit_cher_email->text();
        Compte c;
               /********************************  null */
        if (account== '\0' && email == '\0' && permissions == '\0' )
        {
            ui->tableView_compte->setModel(tempCompte.afficher());
        }
        /********************************  all */
        if (account !='\0' && email != '\0' && permissions != '\0' )
        {
            ui->tableView_compte->setModel(tempCompte.chercher_compte(account,email,permissions));

        }

        /********************************  account  */
        if (account !='\0' && email == '\0' && permissions == '\0' )
        {
            ui->tableView_compte->setModel(tempCompte.chercher_compte(account,1));
        }
        if (account !='\0' && email == '\0' && permissions != '\0' )
        {
            ui->tableView_compte->setModel(tempCompte.chercher_compte(account,permissions,1));
        }

         /********************************  permissions  */
        if (account =='\0' && email == '\0' && permissions != '\0' )
        {
            ui->tableView_compte->setModel(tempCompte.chercher_compte(permissions,2));
        }
        if (account =='\0' && email != '\0' && permissions != '\0' )
        {
            ui->tableView_compte->setModel(tempCompte.chercher_compte(permissions,1,email));
        }



        /********************************  email */

        if (account =='\0' && email != '\0' && permissions == '\0' )
        {
            ui->tableView_compte->setModel(tempCompte.chercher_compte(email));
        }
        if (account !='\0' && email != '\0' && permissions == '\0' )
        {
            ui->tableView_compte->setModel(tempCompte.chercher_compte(account,2,email));
        }



      ui->lineEdit_cher_username->setText("");
      ui->lineEdit_cher_permissions->setText("");
      ui->lineEdit_cher_email->setText("");
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->tableView_compte->setModel(tempCompte.afficher());
}

void MainWindow::on_pushButton_13_clicked()
{
    if (ui->radioButton_account->isChecked())
    {
         ui->tableView_compte->setModel(tempCompte.tri_compte(1));
    }
    if (ui->radioButton_email->isChecked())
    {
         ui->tableView_compte->setModel(tempCompte.tri_compte(2));
    }
    if (ui->radioButton_permissions->isChecked())
    {
         ui->tableView_compte->setModel(tempCompte.tri_compte(3));
    }
}

void MainWindow::on_pushButton_10_clicked()
{

    QString nom_dep = ui->lineEdit_aj_nomdep->text();
    Departement d(0,nom_dep);
    bool test=d.ajouter_dep();
    if(!test)
        QMessageBox::critical(nullptr, QObject::tr("ajout dep refuser"),
                    QObject::tr("l ajout  de dep  est refusé.\n"
                                "Clicker sur  Abort ."), QMessageBox::Abort);
    refreshw();


}

void MainWindow::on_pushButton_11_clicked()
{
    int idd = ui->comboBox_mod_dep->currentText().toInt();

     QString nom =  ui->lineEdit_mod_nomdep->text();
     Departement d;
     bool test = d.modifier_dep(idd,nom);
     refreshw();
}

void MainWindow::on_pushButton_14_clicked()
{
    int idd = ui->comboBox_supp_dep->currentText().toInt();
    bool test = tempdep.supp_dep(idd);
    if (test)
    {
       refreshw();
    }
    QMessageBox::critical(nullptr, QObject::tr("suprr refuser"),
                QObject::tr("la supp de dep  est refusé.\n"
                            "Clicker sur  Abort ."), QMessageBox::Abort);

}

void MainWindow::on_pushButton_7_clicked()
{

    if (ui->radioButton_iddep->isChecked())
    {
         ui->tableView_dep->setModel(tempdep.tri_dep(1));
    }
    if (ui->radioButton_nom_dep->isChecked())
    {
         ui->tableView_dep->setModel(tempdep.tri_dep(2));
    }

}

void MainWindow::on_pushButton_6_clicked()
{
    int idd = ui->lineEdit_cher_id->text().toInt() ;
    QString nom = ui->lineEdit_cher_nomdep->text();

    /********************************  null */
if (idd== '\0' && nom == '\0' )
{
 ui->tableView_dep->setModel(tempdep.afficher());
}
/********************************  all */
if (idd !='\0' && nom == '\0' )
{
 ui->tableView_dep->setModel(tempdep.chercher_dep(idd));

}
if (idd =='\0' && nom != '\0' )
{
 ui->tableView_dep->setModel(tempdep.chercher_dep(nom));

}
if (idd !='\0' && nom != '\0' )
{
 ui->tableView_dep->setModel(tempdep.chercher_dep(idd,nom));

}
}

void MainWindow::on_pushButton_4_clicked()
{

    int cin= ui->lineEdit_emp_add_cin->text().toInt();
    QString nom = ui->lineEdit_emp_add_nom->text();
    QString prenom = ui->lineEdit_emp_add_prenom->text();
    int age= ui->lineEdit_emp_add_age->text().toInt();
    int salaire_j= ui->lineEdit_emp_add_salaire_j->text().toInt();
    int username =  ui->comboBox_emp_add_username->currentText().toInt();
    int idd =ui-> comboBox_emp_add_dep->currentText().toInt();

    QString cin_p=ui->lineEdit_emp_add_cin->text();
    QString age_p= ui->lineEdit_emp_add_age->text();
    QString salaire_j_p= ui->lineEdit_emp_add_salaire_j->text();
    QString idd_p= ui->comboBox_emp_add_dep->currentText();
    QString username_p =  ui->comboBox_emp_add_username->currentText();
    //int nb_presence= ui->lineEdit_emp_add_nb_p->text().toInt();
    int nb_presence = 0;
    Employer e(cin,nom,prenom,age,salaire_j,nb_presence,username,idd);
    bool test=e.ajouter_emp();
    if(test)
    {
        refreshw();
        if(ui->radioButton_im_emp->isChecked())
        {
            QPixmap logo;
            logo.load("ifactory-logo");
            logo.scaled(logo.width()*10,logo.height()*10);

            QString pdf_name= "file_emp_"+cin_p+".pdf";
            QPdfWriter pdf(pdf_name);
            QPainter painter(&pdf);
            painter.drawPixmap(3000,0,logo.width()*20,logo.height()*20,logo);


            painter.setPen(Qt::blue);
            painter.drawText(100,2000,"votre info : ");
            painter.drawText(100,2300,"cin : ");
            painter.setPen(Qt::black);
            painter.drawText(2000,2300,cin_p);
            painter.setPen(Qt::blue);
            painter.drawText(100,2600,"nom : ");
            painter.setPen(Qt::black);
            painter.drawText(2000,2600,nom);
            painter.setPen(Qt::blue);
            painter.drawText(100,2900,"prenom : ");
            painter.setPen(Qt::black);
            painter.drawText(2000,2900,prenom);
            painter.setPen(Qt::blue);
            painter.drawText(100,3200,"age : ");
            painter.setPen(Qt::black);
            painter.drawText(2000,3200,age_p);
            painter.setPen(Qt::blue);
            painter.drawText(100,3500,"salaire par j : ");
            painter.setPen(Qt::black);
            painter.drawText(2000,3500,salaire_j_p);
            painter.setPen(Qt::blue);
            painter.drawText(100,3800,"num departement : ");
            painter.setPen(Qt::black);
            painter.drawText(2000,3800,idd_p);
            painter.setPen(Qt::blue);
            painter.drawText(100,4100,"num compte : ");
            painter.setPen(Qt::black);
            painter.drawText(2000,4100,username_p);


            painter.end();
            QMessageBox::information(nullptr, QObject::tr("pdf  "),
                        QObject::tr("pdf terminer.\n"
                                    "Clicker sur  accept ."), QMessageBox::Accepted);

        }
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("suprr refuser"),
                    QObject::tr("l ajout de compte  est refusé.\n"
                                "Clicker sur  Abort ."), QMessageBox::Abort);


}

void MainWindow::on_pushButton_8_clicked()
{
    int cin =ui-> comboBox_mod_emp_cin->currentText().toInt();
    int username =ui-> comboBox_mod_emp_username->currentText().toInt();
    int idd =ui-> comboBox_mod_emp_dep->currentText().toInt();
    QString nom = ui->lineEdit_emp_mod_nom->text();
    QString prenom = ui->lineEdit_emp_mod_prenom->text();
    int age= ui->lineEdit_emp_mod_age->text().toInt();
    int salaire = ui->lineEdit_emp_mod_sal->text().toInt();
    int nbp = ui->lineEdit_emp_mod_nbp->text().toInt();
    Employer e(cin,nom,prenom,age,salaire,nbp,username,idd);
    bool test=e.modifier_emp();
    if(test)
    {
        refreshw();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modif refuser"),
                    QObject::tr("la modf de compte  est refusé.\n"
                                "Clicker sur  Abort ."), QMessageBox::Abort);
}

void MainWindow::on_pushButton_5_clicked()
{
    if (ui->radioButton_cin->isChecked())
    {
         ui->tableView_emp->setModel(tempemp.tri_emp(1));
    }
    if (ui->radioButton_nom->isChecked())
    {
         ui->tableView_emp->setModel(tempemp.tri_emp(2));
    }
    if (ui->radioButton_prenom->isChecked())
    {
         ui->tableView_emp->setModel(tempemp.tri_emp(3));
    }
    if (ui->radioButton_salaire->isChecked())
    {
         ui->tableView_emp->setModel(tempemp.tri_emp(4));
    }
    if (ui->radioButton_age->isChecked())
    {
         ui->tableView_emp->setModel(tempemp.tri_emp(5));
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    int cin = ui->lineEdit_cher_cin->text().toInt() ,age = ui->lineEdit_cher_age->text().toInt();
    QString nom = ui->lineEdit_cher_nom->text();
        Employer e;
               /********************************  null */
        if (cin== '\0' && nom == '\0' && age == '\0' )
        {
            ui->tableView_emp->setModel(tempemp.afficher());
        }
        /********************************  all */
        if (cin !='\0' && nom != '\0' && age != '\0' )
        {
            ui->tableView_emp->setModel(tempemp.chercher_emp(cin,nom,age));

        }

        /********************************  account  */
        if (cin !='\0' && nom == '\0' && age == '\0' )
        {
            ui->tableView_emp->setModel(tempemp.chercher_emp(cin,1));
        }
        if (cin !='\0' && nom == '\0' && age != '\0' )
        {
            ui->tableView_emp->setModel(tempemp.chercher_emp(cin,age,1));
        }

         /********************************  permissions  */
        if (cin =='\0' && nom == '\0' && age != '\0' )
        {
            ui->tableView_emp->setModel(tempemp.chercher_emp(age,2));
        }
        if (cin =='\0' && nom != '\0' && age != '\0' )
        {
            ui->tableView_emp->setModel(tempemp.chercher_emp(age,1,nom));
        }



        /********************************  email */

        if (cin =='\0' && nom != '\0' && age == '\0' )
        {
            ui->tableView_emp->setModel(tempemp.chercher_emp(nom));
        }
        if (cin !='\0' && nom != '\0' && age == '\0' )
        {
            ui->tableView_emp->setModel(tempemp.chercher_emp(cin,2,nom));
        }

}

void MainWindow::on_pushButton_9_clicked()
{
    int cin = ui->comboBox_supp_emp->currentText().toInt();
        bool  test = tempemp.supp_emp(cin);
        if (test)
        {
        refreshw();
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("suprr refuser"),
                        QObject::tr("la supp de compte  est refusé.\n"
                                    "Clicker sur  Abort ."), QMessageBox::Abort);
}

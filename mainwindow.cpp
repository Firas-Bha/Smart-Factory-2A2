#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "commande.h"
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->TableView_Client->setModel(tmpClient.afficher());
    ui->tableView_Commande->setModel(tmpCommande.afficher());
    ui->lineEdit_ID->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_ID2->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_Tel->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_Tel2->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_ID_2->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_ID_3->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_ID_4->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_Commande->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_Commande_2->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_Commande_3->setValidator(new QIntValidator(0,99999999,this));

    ui->lineEdit_Prix->setValidator(new QIntValidator(0,9999,this));
    ui->lineEdit_Prix_2->setValidator(new QIntValidator(0,9999,this));
}





MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Ajouter_clicked()
{
    int id=ui->lineEdit_ID->text().toInt();
    QString nom=ui->lineEdit_Nom->text();
    QString prenom=ui->lineEdit_Prenom->text();
    int tel=ui->lineEdit_Tel->text().toInt();
    QString adresse=ui->lineEdit_Adresse->text();
    Client c(id,nom,prenom,tel,adresse);
    bool test=c.ajouter();
    if(test)
    {
        ui->TableView_Client->setModel(tmpClient.afficher());

        QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("Ajout avec succés \n click cancel to exit")                 ,QMessageBox::Cancel);
    }
    else                   QMessageBox::critical(nullptr,QObject::tr("Ajout"),QObject::tr("Ajout echoué \n click cancel to exit")                           ,QMessageBox::Cancel);
}

void MainWindow::on_pushButton_5_clicked()
{
    int id=ui->lineEdit_Supprimer->text().toInt();
    bool test=tmpClient.supprimer(id);
    if(test)
    {
        ui->TableView_Client->setModel(tmpClient.afficher());
        QMessageBox::information(nullptr,QObject::tr("Suppression"),QObject::tr("Suppression avec succés \n click cancel to exit")                 ,QMessageBox::Cancel);
    }
    else                   QMessageBox::critical(nullptr,QObject::tr("Suppression"),QObject::tr("Suppression echoué \n click cancel to exit")                           ,QMessageBox::Cancel);
}

void MainWindow::on_pushButton_2_clicked()
{


        int id = ui->lineEdit_ID2->text().toInt();
        QString nom= ui->lineEdit_NOM2->text();
        QString prenom= ui->lineEdit_Prenom2->text();
        int tel = ui->lineEdit_Tel2->text().toInt();
        QString adresse = ui->lineEdit_Adresse2->text();

        Client c(id,nom,prenom,tel,adresse);
      bool test=c.modifier();
      if(test)
    {
    ui->TableView_Client->setModel(tmpClient.afficher());
    QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                      QObject::tr("modification aves succés.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("modifier un client"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }





void MainWindow::on_pushButton_4_clicked()
{
    int ID=ui->lineEdit_ID_2->text().toInt();
    QString Type=ui->lineEdit_Type->text();
        int CodeC=ui->lineEdit_Commande->text().toInt();
    QString Date=ui->dateTimeEdit->text();

    int Prix=ui->lineEdit_Prix->text().toInt();
    Commande c(Type,CodeC,Date,Prix,ID);
    bool test=c.ajouter();
    if(test)
    {
        ui->tableView_Commande->setModel(tmpCommande.afficher());

        QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("Ajout avec succés \n click cancel to exit")                 ,QMessageBox::Cancel);
    }
    else                   QMessageBox::critical(nullptr,QObject::tr("Ajout"),QObject::tr("Ajout echoué \n click cancel to exit")  ,QMessageBox::Cancel);
}


void MainWindow::on_pushButton_8_clicked()
{
    int CodeC=ui->lineEdit_supprimer->text().toInt();
    bool test=tmpCommande.supprimer(CodeC);
    if(test)
    {
        ui->tableView_Commande->setModel(tmpCommande.afficher());
        QMessageBox::information(nullptr,QObject::tr("Suppression"),QObject::tr("Suppression avec succés \n click cancel to exit")                 ,QMessageBox::Cancel);
    }
    else                   QMessageBox::critical(nullptr,QObject::tr("Suppression"),QObject::tr("Suppression echoué \n click cancel to exit")                           ,QMessageBox::Cancel);
}



void MainWindow::on_pushButton_7_clicked()
{
    int ID = ui->lineEdit_ID_3->text().toInt();
    QString Type= ui->lineEdit_Type_2->text();
    QString Date= ui->dateTimeEdit_2->text();
    int CodeC = ui->lineEdit_Commande_2->text().toInt();
    int Prix = ui->lineEdit_Prix_2->text().toInt();

    Commande c(Type,CodeC,Date,Prix,ID);
  bool test=c.modifier();
  if(test)
{
ui->tableView_Commande->setModel(tmpCommande.afficher());
QMessageBox::information(nullptr, QObject::tr("modifier une commande"),
                  QObject::tr("modification aves succés.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier une commande"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_clicked()
{


        QString id = ui->lineEdit_ID_4->text();
        ui->TableView_Client->setModel(tmpClient.rechercher_client(id));

}


void MainWindow::on_pushButton_3_clicked()
{


        ui->TableView_Client->setModel(tmpClient.afficher_client_trier());


}


void MainWindow::on_pushButton_10_clicked()
{
    QString id = ui->lineEdit_Commande_3->text();
    ui->tableView_Commande->setModel(tmpCommande.rechercher_commande(id));
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->tableView_Commande->setModel(tmpCommande.afficher_commande_trier());
}

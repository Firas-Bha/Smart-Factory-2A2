#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_Produit->setModel(tempProduit.afficher());
    ui->tableView_AffichageStock->setModel(tempStock.afficherStock());
      ui->lineEdit_ID->setValidator(new QIntValidator(0,999999999));
      ui->lineEdit_prix->setValidator(new QIntValidator(0,999999999));
      ui->lineEdit_idStock->setValidator(new QIntValidator(0,999999999));
   sound=new QSound("C:/Users/asus/Desktop/GestionProduit_et_Stock/Projet_2A2/Click2.wav");


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    int  id_Produit=ui->lineEdit_ID->text().toInt();
    QString nom_Produit=ui->lineEdit_NomProduit->text();
    int  prix_Produit=ui->lineEdit_prix->text().toInt();
    QString NomStock=ui->lineEdit_NomStock->text();
    Produit p (id_Produit,nom_Produit,prix_Produit,NomStock);
    bool test=p.ajouter();
    if(test)
    {
         ui->tableView_Produit->setModel(tempProduit.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
                    QObject::tr("ajout avec succès.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
                    QObject::tr("ajout echoué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableView_Produit->setModel(tempProduit.afficher());

}

void MainWindow::on_pushButton_Supprimer1_clicked()
{
    int id_Produit=ui->lineEdit_IDsupprimer->text().toInt();
    bool test=tempProduit.supprimer(id_Produit);
    if (test)
    {     ui->tableView_Produit->setModel(tempProduit.afficher());
        QMessageBox::information(nullptr, QObject::tr("Suppression"),
                    QObject::tr("Suppression avec succès.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Suppression"),
                    QObject::tr("Suppression echoué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}



void MainWindow::on_pushButton_modifier1_clicked()
{
    int  id_Produit=ui->lineEdit_ID->text().toInt();
    QString nom_Produit=ui->lineEdit_NomProduit->text();
    int  prix_Produit=ui->lineEdit_prix->text().toInt();
    QString NomStock=ui->lineEdit_NomStock->text();
    bool test=tempProduit.modifier(id_Produit,nom_Produit,prix_Produit,NomStock);
    if (test)
    {     ui->tableView_Produit->setModel(tempProduit.afficher());
        QMessageBox::information(nullptr, QObject::tr("Modification"),
                    QObject::tr("Modification avec succès.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Modification"),
                    QObject::tr("Modification echoué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

}
void MainWindow::on_pushButton_Produit_clicked()
{

}
void MainWindow::on_pushButton_7_clicked()
{

            int id=ui->lineEdit_IDD->text().toInt();
            QString nom=ui->lineEdit_Nomm->text();
            int prix=ui->lineEdit_Prixx->text().toInt();


                if(id==0&&prix==0){
                QString txt=ui->lineEdit_Nomm->text();
                ui->tableView_Produit->setModel(tempProduit.chercher_Nom(txt));
                }
                else    if(id==0&&nom=="")
                {
                    QString txt=ui->lineEdit_Prixx->text();
                   ui->tableView_Produit->setModel(tempProduit.chercher_Prix(txt));}

                else    if(prix==0&&nom=="")
                {
                    QString txt=ui->lineEdit_IDD->text();
                  ui->tableView_Produit->setModel(tempProduit.chercher_ID(txt));}



              QMessageBox::information(nullptr, QObject::tr("chercher"),
                        QObject::tr("ok"), QMessageBox::Cancel);



}

void MainWindow::on_pushButton_8_clicked()
{   sound->play();
    QSqlDatabase db;
                        QTableView TableView_Produit;
                        QSqlQueryModel * Modal=new  QSqlQueryModel();

                        QSqlQuery qry;
                         qry.prepare("SELECT * FROM PRODUIT ");
                         qry.exec();
                         Modal->setQuery(qry);
                         TableView_Produit.setModel(Modal);



                         db.close();


                         QString strStream;
                         QTextStream out(&strStream);

                         const int rowCount = TableView_Produit.model()->rowCount();
                         const int columnCount = TableView_Produit.model()->columnCount();


                         const QString strTitle ="Document";


                         out <<  "<html>\n"
                             "<head>\n"
                                 "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             <<  QString("<title>%1</title>\n").arg(strTitle)
                             <<  "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"
                            << QString("<h3 style=\" font-size: 40px; font-family: Arial, Helvetica, sans-serif; color: #0894FD; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des Produits")
                            <<"<br>"
                             <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";

                         out << "<thead><tr bgcolor=#f0f0f0>";
                         for (int column = 0; column < columnCount; column++)
                             if (!TableView_Produit.isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(TableView_Produit.model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!TableView_Produit.isColumnHidden(column)) {
                                     QString data = TableView_Produit.model()->data(TableView_Produit.model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table>\n"
                                 "<br><br>"

                                 "<p align='center'> <img src='C:/Users/asus/Desktop/GestionProduit_et_Stock/aa.png' alt='aalogo'></p>"

                              <<"<br>"
                                 <<"<table border=1 cellspacing=0 cellpadding=2 >\n";


                             out << "<thead><tr bgcolor=#f0f0f0>";

                                 out <<  "</table >\n"

                             "</body>\n"

                             "</html>\n";

                         QTextDocument *document = new QTextDocument();
                         document->setHtml(strStream);

                         QPrinter printer;
                         QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                         if (dialog->exec() == QDialog::Accepted) {

                            QLabel lab;
                              QPixmap pixmap("C:/Users/asus/Desktop/GestionProduit_et_Stock/aa.png");
                             lab.setPixmap(pixmap);
                             QPainter painter(&lab);
                             QPrinter printer(QPrinter::PrinterResolution);


                             document->print(&printer);

                         }

                         printer.setOutputFormat(QPrinter::PdfFormat);
                         printer.setPaperSize(QPrinter::A4);
                         printer.setOutputFileName("/tmp/Produit.pdf");
                         printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                         delete document;


}
void MainWindow::on_pushButton_ProduitTri_clicked()
{

     if(ui->radioButton_Nom->isChecked())
     {
         ui->tableView_Produit->setModel(tempProduit.trier_nom());
     }

     if(ui->radioButton_2_Prix->isChecked())
     {
      ui->tableView_Produit->setModel(tempProduit.trier_Prix());
     }

     if(ui->radioButton_ID1->isChecked())
     {
       ui->tableView_Produit->setModel(tempProduit.trier_ID());
     }

}




//------------------------------STOCK--------------------------------------------------------------------

void MainWindow::on_pushButton_AjouterStock_clicked()
{
    int  id_Stock=ui->lineEdit_idStock->text().toInt();
    QString Nom=ui->lineEdit_NomStock_2->text();
    Stock s (id_Stock,Nom);
    bool test=s.ajouterStock();
    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("Ajout"),
                    QObject::tr("ajout avec succès.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
                    QObject::tr("ajout echoué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_AfficherStock_clicked()
{
    ui->tableView_AffichageStock->setModel(tempStock.afficherStock());
}



void MainWindow::on_pushButton_14_clicked()
{
    {
        int idStock=ui->lineEdit_SupprimerStock->text().toInt();
        bool test=tempStock.supprimer(idStock);
        if (test)
        {     ui->tableView_AffichageStock->setModel(tempStock.afficherStock());
            QMessageBox::information(nullptr, QObject::tr("Suppression"),
                        QObject::tr("Suppression avec succès.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Suppression"),
                        QObject::tr("Suppression echoué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }

}








void MainWindow::on_pushButton_5_clicked()
{
    int  id_stock=ui->lineEdit_idStock->text().toInt();
    QString nom_stock=ui->lineEdit_NomStock_2->text();
    bool test=tempStock.modifier(id_stock,nom_stock);
    if (test)
    {     ui->tableView_AffichageStock->setModel(tempStock.afficherStock());
        QMessageBox::information(nullptr, QObject::tr("Modification"),
                    QObject::tr("Modification avec succès.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Modification"),
                    QObject::tr("Modification echoué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_12_clicked()
{
    if(ui->radioButton_NOMASC->isChecked())
    {
        ui->tableView_AffichageStock->setModel(tempStock.trier_NomAscendant());
    }

    if(ui->radioButton_NOMDESC->isChecked())
    {
     ui->tableView_AffichageStock->setModel(tempStock.trier_NomDescendant());
    }

    if(ui->radioButton_IDS->isChecked())
    {
      ui->tableView_AffichageStock->setModel(tempStock.trier_IDSTOCK());
    }
}

void MainWindow::on_pushButton_10_clicked()
{   int id=ui->lineEdit_IDDD->text().toInt();
    QString nom=ui->lineEdit_NOMMMM->text();



        if(id==0)
        {
        QString txt=ui->lineEdit_NOMMMM->text();
        ui->tableView_AffichageStock->setModel(tempStock.chercher_Nomstock(txt));
        }
        else    if(nom=="")
        {
            QString txt=ui->lineEdit_IDDD->text();
           ui->tableView_AffichageStock->setModel(tempStock.chercher_IDstock(txt));
        }


      QMessageBox::information(nullptr, QObject::tr("chercher"),
                QObject::tr("ok"), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_11_clicked()
{    sound->play();
    QSqlDatabase db;
                        QTableView TableView_Affichagestock;
                        QSqlQueryModel * Modal=new  QSqlQueryModel();

                        QSqlQuery qry;
                         qry.prepare("SELECT * FROM STOCK ");
                         qry.exec();
                         Modal->setQuery(qry);
                        TableView_Affichagestock.setModel(Modal);


                         db.close();


                         QString strStream;
                         QTextStream out(&strStream);

                         const int rowCount = TableView_Affichagestock.model()->rowCount();
                         const int columnCount = TableView_Affichagestock.model()->columnCount();


                         const QString strTitle ="Document";


                         out <<  "<html>\n"
                             "<head>\n"
                                 "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             <<  QString("<title>%1</title>\n").arg(strTitle)
                             <<  "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"
                            << QString("<h3 style=\" font-size: 40px; font-family: Arial, Helvetica, sans-serif; color: #0894FD; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des Stocks")
                            <<"<br>"
                             <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";

                         out << "<thead><tr bgcolor=#f0f0f0>";
                         for (int column = 0; column < columnCount; column++)
                             if (!TableView_Affichagestock.isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(TableView_Affichagestock.model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!TableView_Affichagestock.isColumnHidden(column)) {
                                     QString data = TableView_Affichagestock.model()->data(TableView_Affichagestock.model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table>\n"
                                 "<br><br>"

                                 "<p align='center'> <img src='C:/Users/asus/Desktop/GestionProduit_et_Stock/aa.png' alt='aalogo'></p>"

                              <<"<br>"
                                 <<"<table border=1 cellspacing=0 cellpadding=2 >\n";


                             out << "<thead><tr bgcolor=#f0f0f0>";

                                 out <<  "</table >\n"

                             "</body>\n"

                             "</html>\n";

                         QTextDocument *document = new QTextDocument();
                         document->setHtml(strStream);

                         QPrinter printer;
                         QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                         if (dialog->exec() == QDialog::Accepted) {

                            QLabel lab;
                              QPixmap pixmap("C:/Users/asus/Desktop/GestionProduit_et_Stock/aa.png");
                             lab.setPixmap(pixmap);
                             QPainter painter(&lab);
                             QPrinter printer(QPrinter::PrinterResolution);


                             document->print(&printer);

                         }

                         printer.setOutputFormat(QPrinter::PdfFormat);
                         printer.setPaperSize(QPrinter::A4);
                         printer.setOutputFileName("/tmp/Produit.pdf");
                         printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                         delete document;


}

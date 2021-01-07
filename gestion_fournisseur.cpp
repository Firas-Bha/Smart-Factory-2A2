#include "gestion_fournisseur.h"
#include "ui_gestion_fournisseur.h"
#include "commandes.h"
#include "fournisseurs.h"
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QMessageBox>
#include <QFile>
gestion_fournisseur::gestion_fournisseur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_fournisseur)
{
    ui->setupUi(this);
    ui->tableView_commandes->setModel(tempCommandes.afficher());
    ui->tableView_fourn->setModel(tempFournisseurs.afficher());
    ui->comboBox->setModel(tempCommandes.afficher_combo());
    son=new QSound("C:/Users/ksaay/Documents/Main/bro.wav");

ui->comboBox_2->setModel(tempCommandes.afficher_combo());
}

gestion_fournisseur::~gestion_fournisseur()
{
    delete ui;
}

void gestion_fournisseur::on_pushButton_clicked()
{
    int id=ui->lineEdit_ID->text().toInt();
    ui->lineEdit_ID->setValidator(new QIntValidator(0,99999999,this));
    QString lieu=ui->lineEdit_Lieu->text();
    QString type=ui->lineEdit_Type->text();
    QString nom=ui->lineEdit_nom->text();
    int num=ui->lineEdit_num->text().toInt();
    ui->comboBox->setModel(tempCommandes.afficher_combo());
    commandes commandes (id,lieu,type,nom,num);
    //bool test=e.ajouter();
    bool test=commandes.ajouter();

    if(test)
    {
        ui->tableView_commandes->setModel(tempCommandes.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout"),
                    QObject::tr("ajout avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("ajout"),
                    QObject::tr("ajout impossible.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion_fournisseur::on_pushButton_modifier_clicked()
{
    int id=ui->lineEdit_mid->text().toInt();
    QString lieu=ui->lineEdit_mlieu->text();
    QString type=ui->lineEdit_mtype->text();
    QString nom=ui->lineEdit_mnom->text();
    int num=ui->lineEdit_mnum->text().toInt();
    commandes commandes (id,lieu,type,nom,num);
  ui->comboBox->setModel(tempCommandes.afficher_combo());
    bool test=commandes.modifier();

    if(test)
    {
        ui->tableView_commandes->setModel(tempCommandes.afficher());
        QMessageBox::information(nullptr, QObject::tr("modifier"),
                    QObject::tr("modification avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier"),
                    QObject::tr("modification impossible.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion_fournisseur::on_pushButton_supprimer_clicked()
{
    int id=ui->lineEdit_supprimer->text().toInt();
    bool test=tempCommandes.supprimer(id);
    ui->comboBox->setModel(tempCommandes.afficher_combo());
    if(test)
    {
        ui->tableView_commandes->setModel(tempCommandes.afficher());
        QMessageBox::information(nullptr, QObject::tr("supprimer"),
                    QObject::tr("suppression avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("supprimer"),
                    QObject::tr("suppression impossible.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void gestion_fournisseur::on_pushButton_chercher_clicked()
{
    /*if(ui->radioButton_type->isChecked())
    {
        ui->tableView_fourn->setModel(tempFournisseurs.trier(1));
    }*/
       int id=ui->lineEdit_chercher->text().toInt();
       QString lt=ui->lineEdit_chercher->text();
       if(ui->radioButton_CHid->isChecked())
       {
        ui->tableView_commandes->setModel(tempCommandes.chercher(1,id,lt));
       }
       else if (ui->radioButton_CHlieu->isChecked())
       {
           ui->tableView_commandes->setModel(tempCommandes.chercher(2,id,lt));
       }
       else if (ui->radioButton_CHtype->isChecked())
       {
           ui->tableView_commandes->setModel(tempCommandes.chercher(3,id,lt));
       }
      /*  QMessageBox::information(nullptr, QObject::tr("chercher"),
                    QObject::tr("ok"), QMessageBox::Cancel);*/
        son->play();
       QSound::play("C:/Users/Desktop/projethabib/bref.wav");
}

void gestion_fournisseur::on_pushButton_2_clicked()
{
    son->play();
    QSqlDatabase db;
                        QTableView TableView_Commande;
                        QSqlQueryModel * Modal=new  QSqlQueryModel();

                        QSqlQuery qry;
                         qry.prepare("SELECT * FROM commandes ");
                         qry.exec();
                         Modal->setQuery(qry);
                         TableView_Commande.setModel(Modal);



                         db.close();


                         QString strStream;
                         QTextStream out(&strStream);

                         const int rowCount = TableView_Commande.model()->rowCount();
                         const int columnCount =  TableView_Commande.model()->columnCount();


                         const QString strTitle ="Document";


                         out <<  "<html>\n"
                             "<head>\n"
                                 "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             <<  QString("<title>%1</title>\n").arg(strTitle)
                             <<  "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"
                            << QString("<h3 style=\" font-size: 40px; font-family: Arial, Helvetica, sans-serif; color: #0894FD; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des Commandes")
                            <<"<br>"
                             <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";

                         out << "<thead><tr bgcolor=#f0f0f0>";
                         for (int column = 0; column < columnCount; column++)
                             if (!TableView_Commande.isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(TableView_Commande.model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!TableView_Commande.isColumnHidden(column)) {
                                     QString data = TableView_Commande.model()->data(TableView_Commande.model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table>\n"
                                 "<br><br>"

                                 "<p align='center'> <img src='C:/factory.png' alt='factorylogo'></p>"

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
                              QPixmap pixmap("C:/factory.png");
                             lab.setPixmap(pixmap);
                             QPainter painter(&lab);
                             QPrinter printer(QPrinter::PrinterResolution);


                             document->print(&printer);

                         }

                         printer.setOutputFormat(QPrinter::PdfFormat);
                         printer.setPaperSize(QPrinter::A4);
                         printer.setOutputFileName("/tmp/Commandes.pdf");
                         printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                         delete document;
}

void gestion_fournisseur::on_pushButton_ajoutC_clicked()
{
    int id=ui->lineEdit_idC->text().toInt();
    QString type=ui->lineEdit_typeC->text();
    QString dateC=ui->lineEdit_dateC->text();
    QString nom=ui->lineEdit_nomC->text();
    int quant=ui->lineEdit_quaC->text().toInt();
    //int idF=ui->lineEdit_idf->text().toInt();
    int idF=ui->comboBox->currentText().toInt();
    //int idF=ui->idFF->text().toInt();

//ui->comboBox->setModel()

    fournisseurs fournisseurs (id,type,dateC,nom,quant,idF);
    //bool test=e.ajouter();
    bool test=fournisseurs.ajouter();

    if(test)
    {
        ui->tableView_fourn->setModel(tempFournisseurs.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout"),
                    QObject::tr("ajout avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("ajout"),
                    QObject::tr("ajout impossible.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion_fournisseur::on_pushButton_modifierC_clicked()
{
    int id=ui->lineEdit_idCm->text().toInt();
    QString type=ui->lineEdit_typeCm->text();
    QString dateC=ui->lineEdit_dateCm->text();
    QString nom=ui->lineEdit_nomCm->text();
    int quant=ui->lineEdit_quaCm->text().toInt();
    //int idF=ui->lineEdit_idf->text().toInt();
    int idF=ui->comboBox_2->currentText().toInt();
    //int idF=ui->idFF->text().toInt();

//ui->comboBox->setModel()

    fournisseurs fournisseurs (id,type,dateC,nom,quant,idF);
    //bool test=e.ajouter();
    bool test=fournisseurs.modifier();

    if(test)
    {
        ui->tableView_fourn->setModel(tempFournisseurs.afficher());
        QMessageBox::information(nullptr, QObject::tr("modifier"),
                    QObject::tr("modification avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("ajout"),
                    QObject::tr("modification impossible.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion_fournisseur::on_pushButton_suppC_clicked()
{
    int id=ui->lineEdit_suppC->text().toInt();
    bool test=tempFournisseurs.supprimer(id);
    if(test)
    {
        ui->tableView_fourn->setModel(tempFournisseurs.afficher());
        QMessageBox::information(nullptr, QObject::tr("supprimer"),
                    QObject::tr("suppression avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("supprimer"),
                    QObject::tr("suppression impossible.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void gestion_fournisseur::on_browse_clicked()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( """ + QFileInfo(file).fileName() + "" " );

    ui->file_2->setText( fileListString );
}

void gestion_fournisseur::on_pushButton_14_clicked()
{
    Smtp* smtp = new Smtp("anouaramine.kassaa@esprit.tn",ui->mail_pass_2->text(), "smtp.gmail.com");
      connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

      if( !files.isEmpty() )
          smtp->sendMail("anouaramine.kassaa@esprit.tn", ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->text(),files );
      else
          smtp->sendMail("anouaramine.kassaa@esprit.tn", ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->text());
}

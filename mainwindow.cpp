#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "commande.h"
#include "qcustomplot.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
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

void MainWindow::on_pushButton_11_clicked()
{
    QSqlDatabase db;
                    QTableView TableView_Client;
                    QSqlQueryModel * Modal=new  QSqlQueryModel();

                    QSqlQuery qry;
                     qry.prepare("SELECT * FROM Client ");
                     qry.exec();
                     Modal->setQuery(qry);
                     TableView_Client.setModel(Modal);



                     db.close();


                     QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = TableView_Client.model()->rowCount();
                     const int columnCount =  TableView_Client.model()->columnCount();


                     const QString strTitle ="Document";


                     out <<  "<html>\n"
                         "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg(strTitle)
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"
                        << QString("<h3 style=\" font-size: 40px; font-family: Arial, Helvetica, sans-serif; color: #0894FD; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des Clients")
                        <<"<br>"
                         <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";

                     out << "<thead><tr bgcolor=#f0f0f0>";
                     for (int column = 0; column < columnCount; column++)
                         if (!TableView_Client.isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(TableView_Client.model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!TableView_Client.isColumnHidden(column)) {
                                 QString data = TableView_Client.model()->data(TableView_Client.model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table>\n"
                             "<br><br>"

                             "<p align='center'> <img src='D:/care++.png' alt='care++logo'></p>"

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

                        /* QLabel lab;
                          QPixmap pixmap("D:/care++.png");
                         lab.setPixmap(pixmap);
                         QPainter painter(&lab);
                         QPrinter printer(QPrinter::PrinterResolution);

    */
                         document->print(&printer);

                     }

                     printer.setOutputFormat(QPrinter::PdfFormat);
                     printer.setPaperSize(QPrinter::A4);
                     printer.setOutputFileName("/tmp/Clients.pdf");
                     printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                     delete document;
}

void MainWindow::on_pushButton_12_clicked()
{
    QSqlDatabase db;
                    QTableView TableView_Commande;
                    QSqlQueryModel * Modal=new  QSqlQueryModel();

                    QSqlQuery qry;
                     qry.prepare("SELECT * FROM Commande ");
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

                             "<p align='center'> <img src='D:/care++.png' alt='care++logo'></p>"

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
                          QPixmap pixmap("D:/IFACTORY.png");
                         lab.setPixmap(pixmap);
                         QPainter painter(&lab);
                         QPrinter printer(QPrinter::PrinterResolution);


                         document->print(&printer);

                     }

                     printer.setOutputFormat(QPrinter::PdfFormat);
                     printer.setPaperSize(QPrinter::A4);
                     printer.setOutputFileName("/tmp/Clients.pdf");
                     printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                     delete document;
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    // set dark background gradient:
              QLinearGradient gradient(0, 0, 0, 400);
              gradient.setColorAt(0, QColor(90, 90, 90));
              gradient.setColorAt(0.38, QColor(105, 105, 105));
              gradient.setColorAt(1, QColor(70, 70, 70));
              ui->plot->setBackground(QBrush(gradient));


              // create empty bar chart objects:
              QCPBars *amande = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
              amande->setAntialiased(false);
              amande->setStackingGap(1);
               //set names and colors:
              amande->setName("Repartition des commandes selon le Prix de produit ");
              amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
              amande->setBrush(QColor(0, 168, 140));
              // stack bars on top of each other:


              // prepare x axis with country labels:
              QVector<double> ticks;
              QVector<QString> labels;
              tmpCommande.statistique(&ticks,&labels);



              QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
              textTicker->addTicks(ticks, labels);
              ui->plot->xAxis->setTicker(textTicker);
              ui->plot->xAxis->setTickLabelRotation(60);
              ui->plot->xAxis->setSubTicks(false);
              ui->plot->xAxis->setTickLength(0, 4);
              ui->plot->xAxis->setRange(0, 8);
              ui->plot->xAxis->setBasePen(QPen(Qt::white));
              ui->plot->xAxis->setTickPen(QPen(Qt::white));
              ui->plot->xAxis->grid()->setVisible(true);
              ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
              ui->plot->xAxis->setTickLabelColor(Qt::white);
              ui->plot->xAxis->setLabelColor(Qt::white);

              // prepare y axis:
              ui->plot->yAxis->setRange(0,10);
              ui->plot->yAxis->setPadding(5); // a bit more space to the left border
              ui->plot->yAxis->setLabel("Statistiques");
              ui->plot->yAxis->setBasePen(QPen(Qt::white));
              ui->plot->yAxis->setTickPen(QPen(Qt::white));
              ui->plot->yAxis->setSubTickPen(QPen(Qt::white));
              ui->plot->yAxis->grid()->setSubGridVisible(true);
              ui->plot->yAxis->setTickLabelColor(Qt::white);
              ui->plot->yAxis->setLabelColor(Qt::white);
              ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
              ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

              // Add data:

              QVector<double> PlaceData;
              QSqlQuery q1("select Prix from Commande");
              while (q1.next()) {
                            int  nbr_fautee = q1.value(0).toInt();
                            PlaceData<< nbr_fautee;
                              }
              amande->setData(ticks, PlaceData);
              // setup legend:
              ui->plot->legend->setVisible(true);
              ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
              ui->plot->legend->setBrush(QColor(255, 255, 255, 100));
              ui->plot->legend->setBorderPen(Qt::NoPen);
              QFont legendFont = font();
              legendFont.setPointSize(10);
              ui->plot->legend->setFont(legendFont);
              ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


}

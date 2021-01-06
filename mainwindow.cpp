#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include <src/SmtpMime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableView_commandes->setModel(tempCommandes.afficher());
    ui->tableView_fourn->setModel(tempFournisseurs.afficher());
    ui->comboBox->setModel(tempCommandes.afficher_combo());    son=new QSound("C:/Users/LENOVO/Desktop/projethabib/click.wav");

ui->comboBox_2->setModel(tempCommandes.afficher_combo());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
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

void MainWindow::on_pushButton_supprimer_clicked()
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

void MainWindow::on_pushButton_modifier_clicked()
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

void MainWindow::on_pushButton_chercher_clicked()
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

/*void MainWindow::on_pushButton_2_clicked()
{



        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
            if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }


            QTextDocument doc;
            QSqlQuery q;
            q.prepare("SELECT * FROM COMMANDES");
            q.exec();
            QString pdf="<br> <h1  style='color:red'>COMMANDES<br></h1>\n <br> <table>  <tr>  <th>ID</th> <th>TYPE</th> <th> LIEU </th> <th> NOM</th> <th>NUM</th>    </tr>" ;


            while ( q.next()) {


                pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +"  "" " "</td>   <td>"+q.value(3).toString()+"</td>   <td>"+q.value(4).toString()+" </td>" ;
            }
            doc.setHtml(pdf);
}*/
/*void MainWindow::on_pushButton_2_clicked()
{



    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

 //       QPrinter printer(QPrinter::PrinterResolution);
   //     printer.setOutputFormat(QPrinter::PdfFormat);
     //   printer.setPaperSize(QPrinter::A4);
       // printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM COMMANDES");
        q.exec();
        QString pdf="<br> <h1  style='color:red'>COMMANDES<br></h1>\n <br> <table>  <tr>  <th>ID</th> <th>NOM</th> <th> Disponibilité </th> <th> TYPE</th> <th>PRIX</th> <th>Duree</th>    </tr>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(1).toString()+" " + q.value(2).toString() +"</td>   <td>" +q.value(0).toString() +"  "" " "</td>   <td>"+q.value(3).toString()+"</td>     <td>"+q.value(4).toString()+" </td>" ;

        }
        doc.setHtml(pdf);
       // doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
      //  doc.print(&printer);


}*/
/*void MainWindow::on_pushButton_2_clicked()
{


        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
            if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

     //       QPrinter printer(QPrinter::PrinterResolution);
       //     printer.setOutputFormat(QPrinter::PdfFormat);
         //   printer.setPaperSize(QPrinter::A4);
           // printer.setOutputFileName(fileName);

            QTextDocument doc;
            QSqlQuery q;
            q.prepare("SELECT * FROM COMMANDES");
            q.exec();
            QString pdf="<br> <h1  style='color:red'>LOCAL<br></h1>\n <br> <table>  <tr>  <th>ID</th> <th>TYPE</th> <th> LIEU </th> <th> NOM</th> <th>NUM</th>    </tr>" ;


            while ( q.next()) {

   pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +"  "" " "</td>   <td>"+q.value(3).toString()+"</td>    <td>"+q.value(4).toString()+" </td>" ;
            }
            doc.setHtml(pdf);
           // doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
          //  doc.print(&printer);


}*/
void MainWindow::on_pushButton_2_clicked()
{
   /* QSqlDatabase db;
                QTableView table_commande;
                QSqlQueryModel * Modal=new  QSqlQueryModel();

                QSqlQuery qry;
                 qry.prepare("SELECT * FROM commandes ");
                 qry.exec();
                 Modal->setQuery(qry);
                 table_commande.setModel(Modal);



                 db.close();


                 QString strStream;
                 QTextStream out(&strStream);

                 const int rowCount = table_commande.model()->rowCount();
                 const int columnCount =  table_commande.model()->columnCount();


                 const QString strTitle ="Document";


                 out <<  "<html>\n"
                     "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg(strTitle)
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"
                    << QString("<h3 style=\" font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des commandes")
                    <<"<br>"
                     <<"<table border=1 cellspacing=0 cellpadding=2>\n";

                 out << "<thead><tr bgcolor=#f0f0f0>";
                 for (int column = 0; column < columnCount; column++)
                     if (!table_commande.isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(table_commande.model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!table_commande.isColumnHidden(column)) {
                             QString data = table_commande.model()->data(table_commande.model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table>\n"
                         "<br><br>"
                         << QString("<p><img src="C:/ifactory.jpg"; width="200"; height="200";\">%1</p>\n")
                         <<"<br>"
                         <<"<table border=1 cellspacing=0 cellpadding=2>\n";


                     out << "<thead><tr bgcolor=#f0f0f0>";

                         out <<  "</table>\n"

                     "</body>\n"
                     "</html>\n";

                 QTextDocument *document = new QTextDocument();
                 document->setHtml(strStream);

                 QPrinter printer;
                 QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                 if (dialog->exec() == QDialog::Accepted) {

                     QLabel lab;
                      QPixmap pixmap("C:/ifactory.jpg");
                     lab.setPixmap(pixmap);
                     QPainter painter(&lab);
                     QPrinter printer(QPrinter::PrinterResolution);

                   //  pixmap.load("aze.png");
                    // painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
                     //painter.drawPixmap(10,10,50,50, pixmap);
                     //document->print(&printer);
                 }

                 printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                 printer.setOutputFileName("/tmp/commandes.pdf");
                 printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                 delete document;
    QPixmap logo;
                logo.load("ifactory");
                logo.scaled(logo.width()10,logo.height()10);

                QString pdf_name= "fileemp"+cin_p+".pdf";
                QPdfWriter pdf(pdf_name);
                QPainter painter(&pdf);
                painter.drawPixmap(3000,0,logo.width()20,logo.height()20,logo);


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

}

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



                     delete document; */
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
void MainWindow::on_pushButton_ajoutC_clicked()
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

void MainWindow::on_pushButton_suppC_clicked()
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
              amande->setName("Repartition des commandes selon quantitées ");
              amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
              amande->setBrush(QColor(0, 168, 140));
              // stack bars on top of each other:


              // prepare x axis with country labels:
              QVector<double> ticks;
              QVector<QString> labels;
              tempFournisseurs.statistique(&ticks,&labels);

              /*QSqlQuery q;
              int i=0;
              q.exec("select reference from medicament");
              while (q.next()) {
                  QString refer = q.value(0).toString();
                  i++;
                  ticks<<i;
                  labels <<refer;
              }*/

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
              QSqlQuery q1("select QUANTITE from fournisseurs");
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

void MainWindow::on_pushButton_trier_clicked()
{
    son->play();
    if(ui->radioButton_type->isChecked())
    {
        ui->tableView_fourn->setModel(tempFournisseurs.trier(1));
    }
    else if(ui->radioButton_n->isChecked())
    {
        ui->tableView_fourn->setModel(tempFournisseurs.trier(2));

    }
    else if(ui->radioButton_id->isChecked())
    {
        ui->tableView_fourn->setModel(tempFournisseurs.trier(3));

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("tri"),
                    QObject::tr("selectionner une bouton.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pushButton_modifierC_clicked()
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

void MainWindow::on_pushButton_3_clicked()
{

    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
    smtp.setUser("habib.hg1@gmail.com");
    smtp.setPassword("93313717200030");
    MimeMessage message;
    message.setSender(new EmailAddress("habib.hg1@gmail.com", "habib hadroug"));
    QString emaiil =ui->choisi_un_email->text();
    message.addRecipient(new EmailAddress(emaiil, "habib hadroug"));
    message.setSubject("bonjour");
    MimeText text;
    QString emaill = ui->pour_envoyer_email->toPlainText();
    text.setText(emaill);
    message.addPart(&text);
    smtp.connectToHost();
    smtp.login();
    if(smtp.sendMail(message))
    {
        QMessageBox::information(this, "PAS D'ERREUR", "Envoyé");
    }
    else
    {
        QMessageBox::critical(this, "ERREUR", "Non Envoyé (probleme de connexion)");
    }
    smtp.quit();
}

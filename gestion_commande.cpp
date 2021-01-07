#include "gestion_commande.h"
#include "ui_gestion_commande.h"
#include "stmp.h"
gestion_commande::gestion_commande(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_commande)
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
    son=new QSound("C:/Users/ksaay/Documents/Main/bro.wav");
}

gestion_commande::~gestion_commande()
{
    delete ui;
}

void gestion_commande::on_pushButton_Ajouter_clicked()
{
    son->play();
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

void gestion_commande::on_pushButton_11_clicked()
{
    son->play();
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

                             "<p align='center'> <img src='D:/IFACTORY.png' alt='IFACTORYlogo'></p>"

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

void gestion_commande::on_pushButton_2_clicked()
{
    son->play();


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

void gestion_commande::on_pushButton_clicked()
{
    son->play();

            QString id = ui->lineEdit_ID_4->text();
            ui->TableView_Client->setModel(tmpClient.rechercher_client(id));
}

void gestion_commande::on_pushButton_3_clicked()
{
    son->play();
           ui->TableView_Client->setModel(tmpClient.afficher_client_trier());
}

void gestion_commande::on_pushButton_9_clicked()
{
    son->play();
   ui->TableView_Client->setModel(tmpClient.afficher());
}

void gestion_commande::on_pushButton_5_clicked()
{
    son->play();
        int id=ui->lineEdit_Supprimer->text().toInt();

        bool test=tmpClient.supprimer(id);
        if(test)
        {
            ui->TableView_Client->setModel(tmpClient.afficher());
            QMessageBox::information(nullptr,QObject::tr("Suppression"),QObject::tr("Suppression avec succés \n click cancel to exit")                 ,QMessageBox::Cancel);
        }
        else                   QMessageBox::critical(nullptr,QObject::tr("Suppression"),QObject::tr("Suppression echoué \n click cancel to exit")                           ,QMessageBox::Cancel);
}

void gestion_commande::on_pushButton_4_clicked()
{
    son->play();
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

void gestion_commande::on_pushButton_12_clicked()
{
    son->play();
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

                            "<p align='center'> <img src='D:/IFACTORY.png' alt='IFACTORYlogo'></p>"

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
                    printer.setOutputFileName("/tmp/Commandes.pdf");
                    printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                    delete document;
}

void gestion_commande::on_pushButton_7_clicked()
{
    son->play();
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

void gestion_commande::on_pushButton_10_clicked()
{
    son->play();
    QString id = ui->lineEdit_Commande_3->text();
    ui->tableView_Commande->setModel(tmpCommande.rechercher_commande(id));
}

void gestion_commande::on_pushButton_6_clicked()
{
    son->play();
     ui->tableView_Commande->setModel(tmpCommande.afficher_commande_trier());
}

void gestion_commande::on_pushButton_13_clicked()
{
    son->play();
    ui->tableView_Commande->setModel(tmpCommande.afficher());
}

void gestion_commande::on_pushButton_8_clicked()
{
    son->play();
        int CodeC=ui->lineEdit_supprimer->text().toInt();

        bool test=tmpCommande.supprimer(CodeC);
        if(test)
        {
            ui->tableView_Commande->setModel(tmpCommande.afficher());
            QMessageBox::information(nullptr,QObject::tr("Suppression"),QObject::tr("Suppression avec succés \n click cancel to exit")                 ,QMessageBox::Cancel);
        }
        else                   QMessageBox::critical(nullptr,QObject::tr("Suppression"),QObject::tr("Suppression echoué \n click cancel to exit")                           ,QMessageBox::Cancel);
}

void gestion_commande::on_browse_clicked()
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

void gestion_commande::on_pushButton_14_clicked()
{
    Smtp* smtp = new Smtp("anouaramine.kassaa@esprit.tn",ui->mail_pass_2->text(), "smtp.gmail.com");
      connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

      if( !files.isEmpty() )
          smtp->sendMail("anouaramine.kassaa@esprit.tn", ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->text(),files );
      else
          smtp->sendMail("anouaramine.kassaa@esprit.tn", ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->text());
}

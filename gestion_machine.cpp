#include "gestion_machine.h"
#include "ui_gestion_machine.h"
#include "detectiongaz.h"

gestion_machine::gestion_machine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_machine)
{
    ui->setupUi(this);
    ui->tableView_machine->setModel(tempmachine.afficher());
    ui->lineEdit_idmachine->setValidator(new QIntValidator(0,999999999));

    ui->tableView_intervention->setModel(tempinterv.afficher());
    ui->lineEdit_Idtech_ajout->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_iddepart->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_idmachine_2->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_Idtech_modif->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_idtech_recherche->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_codeinterv_ajout->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_codeinterv_modif->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_codeinterv_recherche->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_idmachine_5->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_departement_3->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_supprimer->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_interv_suppr->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_devis_ajout->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_devis_modif->setValidator(new QIntValidator(0,999999999));
    ui->lineEdit_devis_recherche->setValidator(new QIntValidator(0,999999999));

       // son=new QSound("C:/Users/Sejir/Desktop/Gestion des Equipements/bro.wav");
    //son=new QSound("C:\Users\ksaay\Documents\Main\bro.wav");
    son=new QSound("C:/Users/ksaay/Documents/Main/bro.wav");
}

gestion_machine::~gestion_machine()
{
    delete ui;
}

void gestion_machine::on_pushButton_ajoutermach_clicked()
{
    son->play();
        int id=ui->lineEdit_idmachine->text().toInt();
        int idDepart=ui->lineEdit_iddepart->text().toInt();
        QString type=ui->lineEdit_type->text();
         QString etat=ui->lineEdit_etat->text();
         machines m(id,idDepart,type,etat);
         bool test=m.ajouter();
         if(test)
         { ui->tableView_machine->setModel(tempmachine.afficher());
             QMessageBox::information(nullptr,QObject::tr("Ajout"),
                                    QObject::tr("Ajout avec succès!\n"
                                               "click ok to exit"),QMessageBox::Ok);

         }
         else
         { QMessageBox::critical(nullptr,QObject::tr("Ajout"),
                                    QObject::tr("Ajout echoué!\n"
                                               "click ok to exit"),QMessageBox::Ok);

         }
}

void gestion_machine::on_pushButton_24_clicked()
{
    int id=ui->lineEdit_supprimer->text().toInt();
    bool test=tempmachine.supprimer(id);
    if(test){ui->tableView_machine->setModel(tempmachine.afficher());
        QMessageBox::information(nullptr,QObject::tr("Suppression"),
                               QObject::tr("Suppression avec succès!\n"
                                          "click ok to exit"),QMessageBox::Ok);


    }
    else { QMessageBox::critical(nullptr,QObject::tr("Suppression"),
                               QObject::tr("Suppression echoué!\n"
                                          "click ok to exit"),QMessageBox::Ok); }
}

void gestion_machine::on_pushButton_3_clicked()
{
    if(ui->radioButton->isChecked())
      ui->tableView_machine->setModel(tempmachine.trieridDepart());
       if(ui->radioButton_3->isChecked())
          ui->tableView_machine->setModel(tempmachine.triertype());
       if(ui->radioButton_5->isChecked())
          ui->tableView_machine->setModel(tempmachine.trieretat());
}

void gestion_machine::on_pushButton_clicked()
{
    ui->tableView_machine->setModel(tempmachine.afficher());
    son->play();
}

void gestion_machine::on_pushButton_25_clicked()
{
    QSqlDatabase db;
                        QTableView TableView_machine;
                        QSqlQueryModel * Modal=new  QSqlQueryModel();

                        QSqlQuery qry;
                         qry.prepare("SELECT * FROM MACHINES ");
                         qry.exec();
                         Modal->setQuery(qry);
                         TableView_machine.setModel(Modal);



                         db.close();


                         QString strStream;
                         QTextStream out(&strStream);

                         const int rowCount = TableView_machine.model()->rowCount();
                         const int columnCount =  TableView_machine.model()->columnCount();


                         const QString strTitle ="Document";


                         out <<  "<html>\n"
                             "<head>\n"
                                 "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             <<  QString("<title>%1</title>\n").arg(strTitle)
                             <<  "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"
                            << QString("<h3 style=\" font-size: 40px; font-family: Arial, Helvetica, sans-serif; color: #0894FD; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des Machines")
                            <<"<br>"
                             <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";

                         out << "<thead><tr bgcolor=#f0f0f0>";
                         for (int column = 0; column < columnCount; column++)
                             if (!TableView_machine.isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(TableView_machine.model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!TableView_machine.isColumnHidden(column)) {
                                     QString data = TableView_machine.model()->data(TableView_machine.model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table>\n"
                                 "<br><br>"

                                 "<p align='center'> <img src='C:/Users/Sejir/Desktop/IFACTORY.png' alt='IFACTORYlogo'></p>"

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
                              QPixmap pixmap("C:/Users/Sejir/Desktop/IFACTORY.png");
                             lab.setPixmap(pixmap);
                             QPainter painter(&lab);
                             QPrinter printer(QPrinter::PrinterResolution);


                             document->print(&printer);

                         }

                         printer.setOutputFormat(QPrinter::PdfFormat);
                         printer.setPaperSize(QPrinter::A4);
                         printer.setOutputFileName("/tmp/machine.pdf");
                         printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                         delete document;


}

void gestion_machine::on_pushButton_22_clicked()
{
    int id = ui->lineEdit_idmachine_2->text().toInt();
        int departement  = ui->lineEdit->text().toInt();
        QString type=ui->lineEdit_2->text();
        QString etat = ui->lineEdit_3->text();
            if(departement==0&&type==""&&etat==""){
            QString txt=ui->lineEdit_idmachine_2->text();
            ui->tableView_machine->setModel(tempmachine.recherche_id_machine(txt));
            }
            else    if(id==0&&type==""&&etat==""){
                QString txt=ui->lineEdit->text();
               ui->tableView_machine->setModel(tempmachine.recherche_departement_machine(txt));}
            else    if(departement==0&&id==0&&etat==""){
                QString txt=ui->lineEdit_2->text();
              ui->tableView_machine->setModel(tempmachine.recherche_type_machine(txt));}
            else    if(departement==0&&type==""&&id==0){
                QString txt=ui->lineEdit_3->text();
              ui->tableView_machine->setModel(tempmachine.recherche_etat_machine(txt));}
}

void gestion_machine::on_pushButton_modifiermachine_clicked()
{
    int id=ui->lineEdit_idmachine_5->text().toInt();
    int idDepart=ui->lineEdit_departement_3->text().toInt();
    QString type=ui->lineEdit_typemach_3->text();
     QString etat=ui->lineEdit_etat_5->text();
     machines m(id,idDepart,type,etat);
     bool test=m.modifier(id);
     if(test)
     { ui->tableView_machine->setModel(tempmachine.afficher());
         QMessageBox::information(nullptr,QObject::tr("Ajout"),
                                QObject::tr("Ajout avec succès!\n"
                                           "click ok to exit"),QMessageBox::Ok);

     }
     else
     { QMessageBox::critical(nullptr,QObject::tr("Ajout"),
                                QObject::tr("Ajout echoué!\n"
                                           "click ok to exit"),QMessageBox::Ok);

     }
}

void gestion_machine::on_pushButton_ajoutinterv_clicked()
{
    int code=ui->lineEdit_codeinterv_ajout->text().toInt();
    int idtech=ui->lineEdit_Idtech_ajout->text().toInt();
    QString date=ui->dateTimeEdit_ajout->text();
     int devis=ui->lineEdit_devis_ajout->text().toInt();
     int id_Machine=ui->lineEdit_iddint_ajout->text().toInt();


     interventions i(code,idtech,date,devis,id_Machine);
     bool test=i.ajouter();
     if(test)
     { ui->tableView_intervention->setModel(tempinterv.afficher());
         QMessageBox::information(nullptr,QObject::tr("Ajout"),
                                QObject::tr("Ajout avec succès!\n"
                                           "click ok to exit"),QMessageBox::Ok);

     }
     else
     { QMessageBox::critical(nullptr,QObject::tr("Ajout"),
                                QObject::tr("Ajout echoué!\n"
                                           "click ok to exit"),QMessageBox::Ok);

     }
}

void gestion_machine::on_pushButton_interv_suppr_clicked()
{
    int code=ui->lineEdit_interv_suppr->text().toInt();
    bool test=tempinterv.supprimer(code);
    if(test){ui->tableView_intervention->setModel(tempinterv.afficher());
        QMessageBox::information(nullptr,QObject::tr("Suppression"),
                               QObject::tr("Suppression avec succès!\n"
                                          "click ok to exit"),QMessageBox::Ok);


    }
    else { QMessageBox::critical(nullptr,QObject::tr("Suppression"),
                               QObject::tr("Suppression echoué!\n"
                                          "click ok to exit"),QMessageBox::Ok); }
}

void gestion_machine::on_pushButton_trier_interv_clicked()
{
    if(ui->radioButton_idtech->isChecked())
      ui->tableView_intervention->setModel(tempinterv.trieridcode());
       if(ui->radioButton_date->isChecked())
          ui->tableView_intervention->setModel(tempinterv.trierdate());
       if(ui->radioButton_devis->isChecked())
          ui->tableView_intervention->setModel(tempinterv.trierdevis());
       son->play();
}

void gestion_machine::on_pushButton_7_clicked()
{
    ui->tableView_intervention->setModel(tempinterv.afficher());
son->play();
}

void gestion_machine::on_pushButton_intervrecherche_clicked()
{
    int code = ui->lineEdit_codeinterv_recherche->text().toInt();
        int idtech  = ui->lineEdit_idtech_recherche->text().toInt();
        int devis = ui->lineEdit_devis_recherche->text().toInt();;
            if(devis==0&&idtech==0){
            QString txt=ui->lineEdit_codeinterv_recherche->text();
            ui->tableView_intervention->setModel(tempinterv.recherche_code(txt));
            }
            else    if(code==0&&devis==0){
                QString txt=ui->lineEdit_idtech_recherche->text();
               ui->tableView_intervention->setModel(tempinterv.recherche_id_tech(txt));}

            else    if(code==0&&idtech==0){
                QString txt=ui->lineEdit_devis_recherche->text();
              ui->tableView_intervention->setModel(tempinterv.recherche_devis(txt));}
}

void gestion_machine::on_pushButton_intervmidif_clicked()
{

    int code=ui->lineEdit_codeinterv_modif->text().toInt();
    int idtech=ui->lineEdit_Idtech_modif->text().toInt();
    QString date=ui->dateTimeEdit_modif->text();
     int devis=ui->lineEdit_devis_modif->text().toInt();
     int id_Machine=ui->lineEdit_idd_int_modif->text().toInt();

     interventions i(code,idtech,date,devis,id_Machine);
     bool test=i.modifier(code);
     if(test)
     { ui->tableView_intervention->setModel(tempinterv.afficher());
         QMessageBox::information(nullptr,QObject::tr("MODIF"),
                                QObject::tr("Modification avec succès!\n"
                                           "click ok to exit"),QMessageBox::Ok);

     }
     else
     { QMessageBox::critical(nullptr,QObject::tr("Modif"),
                                QObject::tr("Modification echoué!\n"
                                           "click ok to exit"),QMessageBox::Ok);

     }

}

void gestion_machine::on_browse_clicked()
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

void gestion_machine::on_pushButton_14_clicked()
{
    Smtp* smtp = new Smtp("anouaramine.kassaa@esprit.tn",ui->mail_pass_2->text(), "smtp.gmail.com");
      connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

      if( !files.isEmpty() )
          smtp->sendMail("anouaramine.kassaa@esprit.tn", ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->text(),files );
      else
          smtp->sendMail("anouaramine.kassaa@esprit.tn", ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->text());
}

void gestion_machine::on_pushButton_4_clicked()
{
    detectiongaz x;
    x.exec();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QMessageBox>
#include <QPdfWriter>
#include "gestion_emp.h"
#include "gestion_machine.h"
#include "gestion_commande.h"
#include "gestion_fournisseur.h"
#include "gestion_stock.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=a.connect_arduino();
        switch (ret) {
        case(0):qDebug()<<"arduino is available and connected to: "<<a.getarduino_port_name();
            break;
        case(1):qDebug()<<"arduino is available but not connected to: "<<a.getarduino_port_name();
            break;
        case(-1):qDebug()<<"arduino is not available";
        }
        QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_arduino()));

    ui->lineEdit_log1->setValidator(new QIntValidator(0,111));

    ui->label_captcha->setText(generate_captcha(4));

//ui->lineEdit_log1->setFocus();
//qDebug()<<focusWidget();
    ui->lineEdit_log1->setFocus();
    qDebug()<<focusWidget();
    if (focusWidget() == ui->lineEdit_log2 )
    {
        qDebug()<<"yes";
    }
    else
        qDebug()<<"no";
     //a.write_to_arduino("0");
    //qDebug()<<QWidget::hasFocus();
    //ui->lineEdit_log1->text();
    //ui->lineEdit_log1->setText('a');


}
int MainWindow::update_arduino()
{
    int c=0;
QString test;
    test=a.read_from_arduino();

    if(test=="#")
{

        if(focusWidget() == ui->lineEdit_log1  )
        {
             ui->lineEdit_log2->setFocus();

             return 0;
        }

    if(focusWidget() == ui->lineEdit_log2  )
    {

ui->lineEdit_log3->setFocus();
        return 0;
    }
    //lineEdit_iddepart
    if(focusWidget() == ui->lineEdit_log3  )
    {



         on_pushButton_clicked();
         return 0;
    }

}
    if(test!="#" and test !='A' and test !='B' and test !='C')
{

        if(focusWidget() == ui->lineEdit_log1  )
        {
            QString c = ui->lineEdit_log1->text();
            ui->lineEdit_log1->setText(c+test);
        }
    if(focusWidget() == ui->lineEdit_log2  )
    {
        QString c = ui->lineEdit_log2->text();
        ui->lineEdit_log2->setText(c+test);

    }

    if(focusWidget() == ui->lineEdit_log3  )
    {
        QString c = ui->lineEdit_log3->text();;
        ui->lineEdit_log3->setText(c+test);

    }


}

}
QString MainWindow::generate_captcha(int n)
{
    time_t t;
     srand((unsigned)time(&t));
   //QString chartab = "abcdefghijklmnopqrstuvwxyz0123456789";
     QString chartab = "0123456789";
   QString captcha;
   int x= 0 ;
   while(n--)
   {

       captcha[x]=chartab[rand()% 36];
       x++;
   }

   return captcha;

}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int  username  = ui->lineEdit_log1->text().toInt();
    QString password = ui->lineEdit_log2->text();
    QString captcha_r = ui->label_captcha->text();
    QString captcha_input = ui->lineEdit_log3->text();
    /*
    if (captcha_r != captcha_input)
    {
        QMessageBox::critical(nullptr, QObject::tr("login failled"),
                    QObject::tr("verify your captcha please\n"
                                ""), QMessageBox::Abort);
            ui->label_captcha->setText(generate_captcha(4));

    }
    else
    {
    */
    if(tempCompte.check_compte(username,password)==1)
    {
        QMessageBox::information(nullptr, QObject::tr("login  "),
                    QObject::tr("welcome back admin ."), QMessageBox::Accepted);
        ui->stackedWidget ->setCurrentIndex(1);
    }
    else
    {
        if(tempCompte.check_compte(username,password)==2)
        {
            QMessageBox::information(nullptr, QObject::tr("login  "),
                        QObject::tr("welcome back employer ."), QMessageBox::Accepted);
            ui->stackedWidget ->setCurrentIndex(2);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("login failled"),
                        QObject::tr("verify ur username and password.\n"
                                    ""), QMessageBox::Abort);
            ui->label_captcha->setText(generate_captcha(4));
         }

     //}
    }


}

void MainWindow::on_anouer_clicked()
{
    gestion_emp x;
    //x.show();
    x.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    gestion_machine x;

    x.exec();
}

void MainWindow::on_pushButton_8_clicked()
{
    gestion_machine x;

    x.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    gestion_commande x;

    x.exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    gestion_fournisseur x;

    x.exec();
}

void MainWindow::on_pushButton_7_clicked()
{
    gestion_stock x;
    x.exec();
}



void MainWindow::on_radioButton_clicked()
{

}

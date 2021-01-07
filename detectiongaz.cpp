#include "detectiongaz.h"
#include "ui_detectiongaz.h"

detectiongaz::detectiongaz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detectiongaz)
{
    ui->setupUi(this);
    int ret=a.connect_arduino();
    switch(ret)
    {
    case(0):qDebug()<<"arduino is available and connecyed to :"<<a.getarduino_port_name();
        break;
    case(1):qDebug()<<"arduino is availble but not connected to :"<<a.getarduino_port_name();
        break;
     case(-1):qDebug()<<"arduino is not availble";
    }
    QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

}

detectiongaz::~detectiongaz()
{
    delete ui;
}
void detectiongaz::update_label()
{
    data=a.read_from_arduino();
    if(data=="B")
    {
        ui->label_etat->setText("gaz non detecte");
    }
    else if(data=="A")
        ui->label_etat->setText("gaz détecté");
}

/*
detectiongaz::detectiongaz(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::detectiongaz)
{
    ui->setupUi(this);
    int ret=a.connect_arduino();
    switch(ret)
    {
    case(0):qDebug()<<"arduino is available and connecyed to :"<<a.getarduino_port_name();
        break;
    case(1):qDebug()<<"arduino is availble but not connected to :"<<a.getarduino_port_name();
        break;
     case(-1):qDebug()<<"arduino is not availble";
    }
    QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));


}

detectiongaz::~detectiongaz()
{
    delete ui;
}
void detectiongaz::update_label()
{
   data=a.read_from_arduino();
   if(data=="2")
   {
       ui->label_etat->setText("gaz non détecté ");
   }
   else if(data=="1")
       ui->label_etat->setText("gaz détecté");
}

void detectiongaz::on_pushButton_2_clicked()
{
    a.write_to_arduino("3");

}

void detectiongaz::on_pushButton_clicked()
{

}

void detectiongaz::on_pushButton_3_clicked()
{
    a.write_to_arduino("2");

}*/

void detectiongaz::on_pushButton_3_clicked()
{
    a.write_to_arduino("B");

}

void detectiongaz::on_pushButton_2_clicked()
{
    a.write_to_arduino("C");

}

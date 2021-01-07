#ifndef DETECTIONGAZ_H
#define DETECTIONGAZ_H
#include "arduino.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class detectiongaz; }
QT_END_NAMESPACE

class detectiongaz : public QMainWindow
{
    Q_OBJECT

public:
    detectiongaz(QWidget *parent = nullptr);
    ~detectiongaz();
    //void update_label();

private:
    Ui::detectiongaz *ui;
   arduino a;
   QByteArray data;
private slots:
   void update_label();

   void on_pushButton_clicked();
   void on_pushButton_2_clicked();
   void on_pushButton_3_clicked();
};
#endif // DETECTIONGAZ_H

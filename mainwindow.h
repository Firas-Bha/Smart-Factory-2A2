#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "compte.h"
#include "departement.h"
#include "employer.h"
#include "arduino.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString generate_captcha(int);

private slots:
    void on_pushButton_clicked();

    void on_anouer_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();
    int update_arduino();

    void on_radioButton_clicked();

private:
    Ui::MainWindow *ui;
    Compte tempCompte;
    Departement tempdep;
    Employer tempemp;
    arduino a;

};
#endif // MAINWINDOW_H

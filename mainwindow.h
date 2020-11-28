#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "machines.h"
#include "interventions.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajoutermach_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_modifiermachine_clicked();

    void on_pushButton_22_clicked();



    void on_pushButton_25_clicked();

    void on_pushButton_3_clicked();


    void on_pushButton_ajoutinterv_clicked();

    void on_pushButton_interv_suppr_clicked();

    void on_pushButton_intervmidif_clicked();

    void on_pushButton_intervrecherche_clicked();

    void on_pushButton_trier_interv_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tabWidget_10_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    machines tempmachine;
    interventions tempinterv;
};
#endif // MAINWINDOW_H

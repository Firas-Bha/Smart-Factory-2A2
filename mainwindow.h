#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <commandes.h>
#include <fournisseurs.h>
#include <QSound>

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
    void on_pushButton_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_chercher_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_ajoutC_clicked();

    void on_pushButton_suppC_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_trier_clicked();

    void on_pushButton_modifierC_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    commandes tempCommandes;
    fournisseurs tempFournisseurs;
    QSound * son;

};
#endif // MAINWINDOW_H

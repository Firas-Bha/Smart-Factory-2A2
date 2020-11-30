#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "produit.h"
#include "stock.h"
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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_Supprimer1_clicked();

    void on_pushButton_modifier1_clicked();

    void on_pushButton_AjouterStock_clicked();

    void on_pushButton_AfficherStock_clicked();

    void on_pushButton_Produit_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_ProduitTri_clicked();

    void on_radioButton_Nom_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::MainWindow *ui;
    Produit tempProduit;
    Stock tempStock;

};
#endif // MAINWINDOW_H

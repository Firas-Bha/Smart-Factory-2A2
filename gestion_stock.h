#ifndef GESTION_STOCK_H
#define GESTION_STOCK_H
#include "produit.h"
#include "stock.h"
#include <QSound>
#include <QDialog>
#include <QString>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QTextStream>
#include <QDebug>
#include "stmp.h"
namespace Ui {
class gestion_stock;
}

class gestion_stock : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_stock(QWidget *parent = nullptr);
    ~gestion_stock();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_modifier1_clicked();

    void on_pushButton_AfficherStock_clicked();

    void on_pushButton_AjouterStock_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_ProduitTri_clicked();

    void on_pushButton_Supprimer1_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::gestion_stock *ui;
    Produit tempProduit;
    Stock tempStock;
    QSound *sound;
};

#endif // GESTION_STOCK_H

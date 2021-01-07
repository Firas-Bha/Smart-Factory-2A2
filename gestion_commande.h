#ifndef GESTION_COMMANDE_H
#define GESTION_COMMANDE_H
#include <QSound>
#include "client.h"
#include "commande.h"
#include <QDialog>
#include "stmp.h"
namespace Ui {
class gestion_commande;
}

class gestion_commande : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_commande(QWidget *parent = nullptr);
    ~gestion_commande();

private slots:
    void on_pushButton_Ajouter_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_8_clicked();

    void on_browse_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::gestion_commande *ui;
    QSound *son;
    Client tmpClient;
    Commande tmpCommande;
    QStringList files;
};

#endif // GESTION_COMMANDE_H

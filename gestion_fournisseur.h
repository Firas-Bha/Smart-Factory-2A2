#ifndef GESTION_FOURNISSEUR_H
#define GESTION_FOURNISSEUR_H
#include <commandes.h>
#include <fournisseurs.h>
#include <QSound>
#include <QDialog>
#include "stmp.h"
namespace Ui {
class gestion_fournisseur;
}

class gestion_fournisseur : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_fournisseur(QWidget *parent = nullptr);
    ~gestion_fournisseur();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_chercher_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_ajoutC_clicked();

    void on_pushButton_modifierC_clicked();

    void on_pushButton_suppC_clicked();

    void on_browse_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::gestion_fournisseur *ui;
    commandes tempCommandes;
    fournisseurs tempFournisseurs;
    QSound * son;
    QStringList files;
};

#endif // GESTION_FOURNISSEUR_H

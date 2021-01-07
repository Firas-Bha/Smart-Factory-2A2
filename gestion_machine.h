#ifndef GESTION_MACHINE_H
#define GESTION_MACHINE_H
#include "machines.h"
#include "interventions.h"

#include <QDialog>
#include <QSound>
#include "stmp.h"
namespace Ui {
class gestion_machine;
}

class gestion_machine : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_machine(QWidget *parent = nullptr);
    ~gestion_machine();

private slots:
    void on_pushButton_ajoutermach_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_modifiermachine_clicked();

    void on_pushButton_ajoutinterv_clicked();

    void on_pushButton_interv_suppr_clicked();

    void on_pushButton_trier_interv_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_intervrecherche_clicked();

    void on_pushButton_intervmidif_clicked();

    void on_browse_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::gestion_machine *ui;
    QSound *son;
    machines tempmachine;
    interventions tempinterv;
    QStringList files;
};

#endif // GESTION_MACHINE_H

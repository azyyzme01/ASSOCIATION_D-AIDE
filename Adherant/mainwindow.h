#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "adherant.h"

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
    void on_adherant_clicked();

    void on_famille_clicked();

    void on_finance_clicked();

    void on_logistique_clicked();

    void on_physiques_clicked();

    void on_retour_adherant_clicked();

    void on_retour_adherant_3_clicked();

    void on_retour_famille_clicked();

    void on_retour_finance_clicked();

    void on_retour_logistique_clicked();

    void on_retour_physique_clicked();

    void on_pushButton_clicked();


    void on_adherant_4_clicked();

    void on_adherant_5_clicked();

    void on_retour_adherant_2_clicked();

    void on_ajouter_adherant_clicked();

    void on_pushButton_Ajouter_2_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_2_clicked();

    void on_pushButton_afficher_clicked();

    void on_pushButton_modifier_clicked();

private:
    Ui::MainWindow *ui;
    Adherant A;

};
#endif // MAINWINDOW_H

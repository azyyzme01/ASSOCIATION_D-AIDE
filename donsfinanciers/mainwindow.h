#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"donsfinanciers.h"
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



    void on_adherant_4_clicked();

    void on_adherant_5_clicked();

    void on_retour_adherant_2_clicked();


    void on_b_ajouter_clicked();

    void on_bp_supprimer_clicked();

    void on_updatebtn_clicked();

private:
    Ui::MainWindow *ui;
    donsfinanciers df;
};
#endif // MAINWINDOW_H

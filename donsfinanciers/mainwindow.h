#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"donsfinanciers.h"
#include <QSqlQuery>
#include<QSqlQueryModel>
#include<QCompleter>
#include <QSqlQuery>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QDialog>
#include <QWidget>

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
    void on_pushButton_20_clicked();
    void on_pushButton_retour_modifier_clicked();



    void on_recherche_clicked();

    void on_Trier_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_exel_clicked();

    void on_mail_clicked();

    void on_id_recherche_textChanged(const QString &arg1);

    void on_b_email_clicked();

private:
    Ui::MainWindow *ui;
    donsfinanciers df;
    donsfinanciers tempadherant;
    donsfinanciers tempf;
    //donsfinanciers statistiques();
    QList<qreal> stat_budget();
        QList <QString> stat_bud();
        donsfinanciers statistique(stat) ; ;

};
#endif // MAINWINDOW_H

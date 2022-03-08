#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"donsfinanciers.h"
#include"mainwindow.h"
#include<QSqlQueryModel>
#include<QtDebug>
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // ui->num_operation->setValidator(new QIntValidator(0, 9999, this));
    ui->tab_dons_financiers->setModel(df.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_adherant_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_famille_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_finance_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_logistique_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_physiques_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_retour_adherant_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_retour_adherant_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_retour_famille_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_retour_finance_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_retour_logistique_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_retour_physique_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_adherant_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_adherant_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_retour_adherant_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_b_ajouter_clicked()
{
    int num_operation=ui->num_operation->text().toInt();
    float somme=ui->somme->text().toInt();
    QString nom_donneur=ui->nom_donneur->text();
    donsfinanciers df(num_operation,somme,nom_donneur);
    bool test=df.ajouter();
    if(test)
    {
        ui->tab_dons_financiers->setModel(df.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("ajout successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("ajout failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_bp_supprimer_clicked()
{
    df.setnum_operation(ui->id_supp->text().toInt());
    bool test=df.supprimer(df.getnum_operation());
    if(test)
    {
    ui->tab_dons_financiers->setModel(df.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("suppression successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("suppression failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_updatebtn_clicked()
{
   int num_operation = ui->idedit->text().toInt();
   int somme = ui->sommeedit->text().toInt();
   QString nom_donneur = ui->nomedit->text();

   donsfinanciers df(num_operation,somme,nom_donneur);
   df.modifier(num_operation);

   if(df.modifier(num_operation))
   {
       QMessageBox::information(nullptr, QObject::tr("ok"),
                   QObject::tr("update successful.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}
   else
       QMessageBox::critical(nullptr, QObject::tr("not ok"),
                   QObject::tr("update failed.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}

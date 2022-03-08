#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adherant.h"
#include "QMessageBox"
#include "QIntValidator"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //controle de saisir
    ui->le_id->setValidator(new QIntValidator(100, 9999999, this));
    ui->le_tele->setValidator(new QIntValidator(100, 9999999, this));

    ui->tableView->setModel(A.afficher());

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



void MainWindow::on_ajouter_adherant_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString fonction=ui->le_fonction->text();
    int tele=ui->le_tele->text().toInt();
    QString image=ui->le_image->text();
    Adherant A(id,nom,prenom,fonction,tele,image);

    bool test=A.ajouter();


        if (test)
        {


            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Ajout effectué\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel);
            ui->tableView->setModel(A.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Warning"),
                                  QObject::tr("Ajout non effectué\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
        }

        ui->le_id->clear();
        ui->le_tele->clear();
        ui->le_nom->clear();
        ui->le_prenom->clear();
        ui->le_fonction->clear();
        ui->le_image->clear();
}



void MainWindow::on_pushButton_supprimer_clicked()
{
    Adherant A1; A1.setid(ui->id_2->text().toInt());
         bool test=A1.supprimer(A1.getid());

         if (test)
         {


             QMessageBox::information(nullptr,QObject::tr("OK"),
                                      QObject::tr("suppression effectué\n"
                                                  "Click Cancel to exit."),QMessageBox::Cancel);
         }
         else
         {
             QMessageBox::critical(nullptr,QObject::tr("Warning"),
                                   QObject::tr("supression non effectué\n"
                                               "Click Cancel to exit."),QMessageBox::Cancel);
         }

         ui->le_id->clear();
         ui->le_tele->clear();
         ui->le_nom->clear();
         ui->le_prenom->clear();
         ui->le_fonction->clear();
         ui->le_image->clear();

}



void MainWindow::on_pushButton_modifier_clicked()
{
    int id = ui->le_id->text().toInt();
    int tele = ui->le_tele->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom = ui->le_prenom->text();
    QString fonction = ui->le_fonction->text();
    QString image = ui->le_image->text();
    Adherant A(id,nom,prenom,fonction,tele,image);
    bool test = A.modifier();
    if(test)
    {

      ui->tableView->setModel(A.afficher());
    QMessageBox::information(nullptr,QObject::tr("modifier un patient"),QObject::tr("success. \n ""click cancel to exit."),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("modifier un patient"),
                    QObject::tr("erreur.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    ui->le_id->clear();
    ui->le_tele->clear();
    ui->le_nom->clear();
    ui->le_prenom->clear();
    ui->le_fonction->clear();
    ui->le_image->clear();
}



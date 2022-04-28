#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adherant.h"
#include "QMessageBox"
#include "QIntValidator"
#include <QPdfWriter>
#include <QDesktopServices>
#include <QFileDialog>
#include <QPainter>
#include<QPrinter>
#include<QPrintDialog>
#include <QTextDocument>
#include<QTextStream>
#include <QDebug>
//****************camera******
#include<QCamera>
#include<QCameraViewfinder>
#include<QCameraImageCapture>
#include<QVBoxLayout>
#include<QMenu>
#include<QAction>
#include<QFileDialog>
 //**********************
#include "membre.h"

#define EMAIL_RX "^[_a-z0-9-]+(\\.[_a-z0-9-]+)*@[a-z0-9-]+" \
                 "(\\.[a-z0-9-]+)*(\\.[a-z]{2,4})$"
#define NAME_RX "([A-Z][a-z]*)([\\s\\\'.][A-Z][a-z]*)*"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //************************camera**********
    mCamera = new QCamera(this);
       mCameraViewfinder= new QCameraViewfinder(this);
       mCameraImageCapture = new QCameraImageCapture(mCamera , this);
       mlayout = new QVBoxLayout;
       mOptionsMenu= new QMenu("options",this);
       mEncenderAction= new QAction("Ouvrir la camera",this);
       mApagarAction= new QAction("stoper",this);
       mcapturerAction=new QAction("Capturer",this);
       mOptionsMenu->addActions({mEncenderAction,mApagarAction,mcapturerAction});
       mCamera->setViewfinder(mCameraViewfinder);
       ui->options ->setMenu(mOptionsMenu);
       mlayout->addWidget(mCameraViewfinder);
       mlayout->setMargin(0);
       ui->scrollArea->setLayout(mlayout);
       connect(mEncenderAction, &QAction::triggered ,[&](){
           mCamera->start();
       });

       connect(mApagarAction,&QAction::triggered,[&](){
           mCamera->stop();
       });

       connect(mcapturerAction,&QAction::triggered,[&](){
           auto filename = QFileDialog:: getSaveFileName(this,"capturar","/",
                                                               "imagen (.jpg;.jpeg)");
                 if(filename.isEmpty()){
                     return;
                 }
           mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
       QImageEncoderSettings imageEncoderSettings;
       imageEncoderSettings.setCodec("image/jpeg");
       imageEncoderSettings.setResolution(1600,1200);
         mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
         mCamera->setCaptureMode(QCamera::CaptureStillImage);
         mCamera->start();
         mCamera->searchAndLock();
         mCameraImageCapture->capture(filename);
         mCamera->unlock();
       });
    //*************************************



        QRegExp rxEmail(EMAIL_RX);
        QRegExpValidator *valiEmail = new QRegExpValidator(rxEmail, this);
        ui->le_image_2->setValidator(valiEmail);

        //Controle de saisie Nom
        QRegExp rxName(NAME_RX);
        QRegExpValidator *valiName = new QRegExpValidator(rxName, this);
        ui->le_nom->setValidator(valiName);




    //controle de saisir
    ui->le_id->setValidator(new QIntValidator(100, 9999999, this));
    ui->le_tele->setValidator(new QIntValidator(100, 9999999, this));

    ui->tableView_adherant_14->setModel(A.afficher());

    int ret=AR.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< AR.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<AR.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(AR.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).

}

/*MainWindow::~MainWindow()
{
    delete ui;
}*/

void MainWindow::update_label()
{
    //data=A.read_from_arduino();
    data.append(AR.read_from_arduino());
        if(data[data.size()-1]=='\n') {
            data.remove(data.size()-2,2);

           // we're full
            qDebug()<<data;
           bool test=A.rechercher_arduino(data);
           qDebug()<<test;
           // bool test=true;
            if(test==true){
                AR.write_to_arduino("1");
            }
            else
                AR.write_to_arduino("0");

            data.clear();

        }



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
            ui->tableView_adherant_14->setModel(A.afficher());
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
    int id= ui->id_2->text().toInt();
    bool test=A.supprimer(id);
    if(test)
    {
        ui->tableView_2->setModel(A.afficher());

    QMessageBox::information(nullptr,QObject::tr("supprimer un Adherant"),QObject::tr("Adherant supprimé. \n ""click cancel to exit."),QMessageBox::Cancel);
    }



         ui->le_id->clear();


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

      ui->tableView_adherant_14->setModel(A.afficher());
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



void MainWindow::on_pushButton_afficher_clicked()
{
     ui->tableView_2->setModel(A.afficher());
}

void MainWindow::on_pushButton_afficher_adherant_clicked()
{
    ui->tableView_adherant_14->setModel(A.afficher());
}

void MainWindow::on_ajouter_adherant_m_clicked()
{
    int idm=ui->le_id_2->text().toInt();
    QString nomm=ui->le_nom_2->text();
    QString prenomm=ui->le_prenom_2->text();
    QString fonctionm=ui->le_fonction_2->text();
    int telem=ui->le_tele_2->text().toInt();
    QString imagem=ui->le_image_2->text();
    Membre M(idm,nomm,prenomm,fonctionm,telem,imagem);

    bool test=M.ajouter();


        if (test)
        {


            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Ajout effectué\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel);
            ui->tableView_m1->setModel(M.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Warning"),
                                  QObject::tr("Ajout non effectué\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
        }

        ui->le_id_2->clear();
        ui->le_tele_2->clear();
        ui->le_nom_2->clear();
        ui->le_prenom_2->clear();
        ui->le_fonction_2->clear();
        ui->le_image_2->clear();
}

void MainWindow::on_pushButton_afficher_m1_clicked()
{
    ui->tableView_m1->setModel(M.afficher());

}

void MainWindow::on_pushButton_modifier_m_clicked()
{
    int idm = ui->le_id_2->text().toInt();
    int telem = ui->le_tele_2->text().toInt();
    QString nomm=ui->le_nom_2->text();
    QString prenomm = ui->le_prenom_2->text();
    QString fonctionm = ui->le_fonction_2->text();
    QString imagem = ui->le_image_2->text();
    Membre M(idm,nomm,prenomm,fonctionm,telem,imagem);
    bool test = M.modifier();
    if(test)
    {

      ui->tableView_m1->setModel(M.afficher());
    QMessageBox::information(nullptr,QObject::tr("modifier un Adherant"),QObject::tr("success. \n ""click cancel to exit."),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("modifier un patient"),
                    QObject::tr("erreur.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    ui->le_id_2->clear();
    ui->le_tele_2->clear();
    ui->le_nom_2->clear();
    ui->le_prenom_2->clear();
    ui->le_fonction_2->clear();
    ui->le_image_2->clear();
}


void MainWindow::on_pushButton_supprimer_m_clicked()
{
    int idm= ui->id_3->text().toInt();
    bool test=M.supprimer(idm);
    if(test)
    {
        ui->tableView_m2->setModel(M.afficher());

    QMessageBox::information(nullptr,QObject::tr("supprimer un Membre"),QObject::tr("Membre supprimé. \n ""click cancel to exit."),QMessageBox::Cancel);
    }



         ui->id_3->clear();

}

void MainWindow::on_pushButton_afficher_m2_clicked()
{
    ui->tableView_m2->setModel(M.afficher());

}


void MainWindow::on_pushButton_rechercherA_clicked()
{
    QString value =ui->le_id_3->text();
       ui->tableView_adherant_14->setModel(tempadherant.recherche(value));

       /*QString nom =ui->le_nom->text();
          ui->tableView_adherant_14->setModel(tempadherant.recherchen(nom));

          QString prenom =ui->le_prenom->text();
             ui->tableView_adherant_14->setModel(tempadherant.recherchep(prenom));*/

}



void MainWindow::on_pushButton_trierA_clicked()
{
    QString tri=ui->comboBox66->currentText();

            if(tri=="id"){
          ui->tableView_adherant_14->setModel(tempadherant.ordre_id_A());}
            else if(tri=="nom"){
                ui->tableView_adherant_14->setModel(tempadherant.ordre_nom_A());}
            else if(tri=="prenom"){
     ui->tableView_adherant_14->setModel(tempadherant.ordre_prenom_A());}

}

void MainWindow::on_pushButton_modifier_4_clicked()
{



    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/home/Desktop",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
          qDebug()<<dir;
          QPdfWriter pdf(dir+"/Les Adhérants.pdf");
          QPainter painter(&pdf);
          int i = 4000;
          painter.setPen(Qt::black);
          painter.setFont(QFont("Arial", 30));
          painter.drawText(1200,1200,"LA LISTE DES ADHERANTS");
          painter.setPen(Qt::black);
          painter.setFont(QFont("Arial", 50));
          painter.drawPixmap(QRect(4400,1200,918,1027),QPixmap(":/new/prefix1/save.PNG"));
          painter.drawRect(0,3000,9600,500);
          painter.setFont(QFont("Arial", 9));
          painter.setPen(Qt::blue);
          painter.drawText(300,3300,"Identifiant");
          painter.drawText(2300,3300,"Nom");
          painter.drawText(4300,3300,"prenom");
          painter.drawText(6300,3300,"fonction");
          painter.drawText(8300,3300,"numero");

          QSqlQuery query;
          query.prepare("SELECT * FROM adherant ");
          query.exec();
          while (query.next())
          {
              painter.drawText(300,i,query.value(0).toString());
              painter.drawText(2300,i,query.value(1).toString());
              painter.drawText(4300,i,query.value(2).toString());
              painter.drawText(6300,i,query.value(3).toString());
              painter.drawText(8300,i,query.value(4).toString());
              i = i +500;
          }



          int reponse = QMessageBox::question(this, "Génerer PDF", "PDF Enregistré.\nVous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
          if (reponse == QMessageBox::Yes)
          {
              QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/Les Adhérants.pdf"));
              painter.end();
          }
          else
          {
              painter.end();
          }




}



void MainWindow::on_pushButton_modifier_5_clicked()
{
    QPrinter rd;
    QPrintDialog d(&rd,this);
    d.setWindowTitle("print adherant");

    d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
    if(d.exec()!=QDialog::Accepted)
        return;
}

void MainWindow::on_pushButton_rechercherA_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"), "" , tr("image (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if ( QString::compare(filename, QString()) != 0 )
    {
        QImage image;
        bool valid =image.load(filename);
        if (valid)
        {

            image =image.scaledToWidth(ui->le_image->width(),Qt::SmoothTransformation);
            ui->le_image->setPixmap(QPixmap::fromImage(image));
        }
    }
}












































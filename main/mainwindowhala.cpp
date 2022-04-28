#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"famille.h"
#include"qrcode.h"
#include<QSqlQueryModel>
#include<QtDebug>
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>

using namespace qrcodegen;

/*MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_famille->setModel(f.afficher());
    ui->tabfam->setModel(f.afficher());


}*/

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_b_ajouter_2_clicked()
{

    int cin=ui->cina->text().toInt();
        QString nom=ui->noma->text();
        QString prenom=ui->prenoma->text();
        QString localisation=ui->locala->text();
        QString nb_enfant=ui->nbenfanta->text();
        famille f(cin,nom,prenom,localisation,nb_enfant);
        qDebug() << "MonMessage";
        bool test=f.ajouter();
        if(test)
        {

            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("ajout successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("ajout failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        ui->cina->clear();
                ui->noma->clear();
                ui->prenoma->clear();
                ui->locala->clear();
                ui->nbenfanta->clear();



}

void MainWindow::on_pushButton_39_clicked()
{

    int cin= ui->lineEdit_famille->text().toInt();
        bool test=f.supprimer(cin);
        if(test)
        {
            ui->tableView_famille->setModel(f.afficher());

        QMessageBox::information(nullptr,QObject::tr("supprimer un Membre"),QObject::tr("Membre supprimé. \n ""click cancel to exit."),QMessageBox::Cancel);


}

        ui->lineEdit_famille->clear();
      }






void MainWindow::on_pushButton_afficherfamille_clicked()
{

    ui->tableView_famille->setModel(f.afficher());
    ui->tabfam->setModel(f.afficher());



}


void MainWindow::on_tabfam_activated(const QModelIndex &index)
{    //ki tenzel ala cin f modifier le selection
    QString val=ui->tabfam ->model()->data(index).toString();
       QSqlQuery qry;
       qry.prepare("select * from FAMILLES where CIN='"+val+"'");
       if (qry.exec())
       {while (qry.next()){
               ui->m1->setText(qry.value(0).toString());
                ui->m2->setText(qry.value(1).toString());
                 ui->m3->setText(qry.value(2).toString());
                  ui->m4->setText(qry.value(3).toString());
                  ui->m5->setText(qry.value(4).toString());
           }


    }
}

void MainWindow::on_pb_modifier_clicked()
{

    int cin=ui->m1->text().toInt();
        QString nom=ui->m2->text();
        QString prenom=ui->m3->text();
        QString localisation=ui->m4->text();
         QString nb_enfant=ui->m5->text();





      famille f(cin,nom,prenom,localisation,nb_enfant);






           bool test=f.modifier(cin);
           if(test)
           {

               QMessageBox::information(nullptr,QObject::tr("OK"),
                       QObject::tr("modifier effectué\n"
                                  "click cancel to exit."), QMessageBox::Cancel);
               ui->tableView_famille->setModel(f.afficher());
               ui->tabfam->setModel(f.afficher());
              // ui->combof->setModel(f.wombo_combof());


           }
           else
               QMessageBox::critical(nullptr,QObject::tr("Not OK"),//X
                       QObject::tr("modifier non effectué\n"
                                  "click cancel to exit."), QMessageBox::Cancel);


}












void MainWindow::on_onactionOpenTriggered_clicked()
{
    int cin=ui->mc->text().toInt();
    QString x= f.calculer(cin);
    /*QString status = QString("x= :").arg(f.calculer(cin));
    QMessageBox::information(this, tr("Info"), status);*/


    QMessageBox::information(0, QObject::tr("Information récupérée"), "\n DONT : " + x+"DT");
}

void MainWindow::on_pushButton_37_clicked()
{
           int tabeq=ui->tableView_famille->currentIndex().row();

            QVariant idd=ui->tableView_famille->model()->data(ui->tableView_famille->model()->index(tabeq,0));



                     QString id= idd.toString();
                     QSqlQuery qry;
                     qry.prepare("select * from familles where CIN=:CIN");
                     qry.bindValue(":CIN",id);
                     qry.exec();
                        QString  CIN,n, p, l, nb;

                     while(qry.next()){

                         id=qry.value(0).toString();

                         n=qry.value(1).toString();
                         p=qry.value(2).toString();
                         l=qry.value(3).toString();
                         nb=qry.value(4).toString();

                     }
                     CIN=QString(CIN);
                            CIN="CIN:"+CIN+"NOM:"+n+"PRENOM:"+p,"LOCALISATION:"+l+"NB_ENFANT:"+nb;
                   QrCode   qr = QrCode::encodeText(CIN.toUtf8().constData(), QrCode::Ecc::HIGH);

                     // Read the black & white pixels
                     QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
                     for (int y = 0; y < qr.getSize(); y++) {
                         for (int x = 0; x < qr.getSize(); x++) {
                             int color = qr.getModule(x, y);  // 0 for white, 1 for black

                             // You need to modify this part
                             if(color==0)
                                 im.setPixel(x, y,qRgb(254, 254, 254));
                             else
                                 im.setPixel(x, y,qRgb(0, 0, 0));
                         }
                     }
                     im=im.scaled(200,200);
                     ui->qrcodefa->setPixmap(QPixmap::fromImage(im));

}


void MainWindow::on_rech_textChanged(const QString &arg1)
{


    famille f ;
          ui->tabfam->setModel(f.rechercher2(arg1)) ;
}

void MainWindow::on_map_clicked()
{
    m = new map;

    m->show();
}

void MainWindow::on_pushButton_43_clicked()
{
    QString tri=ui->comboBox7->currentText();

                    if(tri=="nombre enfant"){
                  ui->cal->setModel(tempfa.nbrenfT());}
                    else if(tri=="nom"){
                        ui->cal->setModel(tempfa.nomT());}
                    else if(tri=="prenom"){
             ui->cal->setModel(tempfa.prenomT());}
}

void MainWindow::on_pushButton_38_clicked()
{
     ui->cal->setModel(tempfa.trie());
}

void MainWindow::on_pushButton_40_clicked()
{
   ui->cal->setModel(tempfa.triedes());
}

void MainWindow::on_label_42_linkActivated()
{
   famille f;
    QString nbr=ui->cinn->text();
        QString prenom=ui->prenom->text();
         ui->tabfam->setModel(f.rech(prenom,nbr));
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"donsfinanciers.h"
#include<QSqlQueryModel>
#include<QtDebug>
#include <QMessageBox>
#include <QIntValidator>
#include <QDesktopServices>
#include"smtp.h"




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

void MainWindow::on_pushButton_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_retour_modifier_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}



void MainWindow::on_recherche_clicked()
{
    donsfinanciers df;
        QString sommerech=ui->sommerech->text();
            QString nom_donneurrech=ui->nom_donneurerech->text();
             ui->tab_dons_financiers->setModel(df.rech(sommerech,nom_donneurrech));

}

void MainWindow::on_Trier_clicked()
{
    QString tri=ui->comboBox7->currentText();

                if(tri=="num_operation"){
              ui->tab_dons_financiers->setModel(tempf.ordre_op());}
                else if(tri=="somme"){
                    ui->tab_dons_financiers->setModel(tempf.ordre_somme());}
                else if(tri=="nom_donneur"){
         ui->tab_dons_financiers->setModel(tempf.ordre_nom());}
}



void MainWindow::on_exel_clicked()
{
    QTableView *table;
                           table = ui->tab_dons_financiers;

                           QString filters("CSV files (.xlsx);;All files (.*)");
                           QString defaultFilter("CSV files (*.xlsx)");
                           QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                              filters, &defaultFilter);
                           QFile file(fileName);

                           QAbstractItemModel *model =  table->model();
                           if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                               QTextStream data(&file);
                               QStringList strList;
                               for (int i = 0; i < model->columnCount(); i++) {
                                   if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                                       strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                                   else
                                       strList.append("");
                               }
                               data << strList.join(";") << "\n";
                               for (int i = 0; i < model->rowCount(); i++) {
                                   strList.clear();
                                   for (int j = 0; j < model->columnCount(); j++) {

                                       if (model->data(model->index(i, j)).toString().length() > 0)
                                           strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                                       else
                                           strList.append("");
                                   }
                                   data << strList.join(";") + "\n";
                               }
                               file.close();
                               QMessageBox::information(nullptr, QObject::tr("Export excel"),
                                                         QObject::tr("Export avec succes .\n"
                                                                     "Click OK to exit."), QMessageBox::Ok);
                           }
        }
        QString currDate()
        {
            QDateTime date = QDateTime::currentDateTime();
            return date.toString("dd.MM.yyyy");
}

void MainWindow::on_mail_clicked()
{
    QString link="https://mail.google.com/mail/u/0/#inbox?compose=new";
               QDesktopServices::openUrl(link);
}

/*void MainWindow::on_id_recherche_textChanged(const QString &arg1)
{
    donsfinanciers e ;
        ui->tab_dons_financiers->setModel(e.rechercher(arg1));
}*/

void MainWindow::on_b_email_clicked()
{
    Smtp* smtp = new Smtp("anasdridi62@gmail.com","09529604anas","smtp.gmail.com",465);
            connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

            smtp->sendMail("anasdridi62@gmail.com",ui->email->text(),ui->subject->text(),ui->body->text());
}

#include "donsfinanciers.h"
#include"mainwindow.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <QPainter>
#include <QSqlQuery>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QDialog>



donsfinanciers::donsfinanciers()
{
    num_operation=0;
    somme=0;
    nom_donneur="";
}
donsfinanciers::donsfinanciers(int num_operation,float somme,QString nom_donneur)
{
    this->num_operation=num_operation;
    this->somme=somme;
    this->nom_donneur=nom_donneur;
}
int donsfinanciers:: getnum_operation()
{
    return num_operation;
}
float donsfinanciers::getsomme()
{
    return somme;
}
QString donsfinanciers::getnom_donneur()
{
    return nom_donneur;
}
// __DATE__ getdate_op;
void donsfinanciers::setnum_operation(int num_operation)
{
    this->num_operation=num_operation;
}
void donsfinanciers:: setsomme(float somme)
{
    this->somme=somme;
}
void  donsfinanciers:: setnom_donneur(QString nom_donneur)
{
    this->nom_donneur=nom_donneur;
}
//void setdate_op(__DATE__);
bool donsfinanciers:: ajouter()
{
     QSqlQuery query; // utilisé pour executer les commandes sql
    QString num_operation_string=QString::number(num_operation);
    QString somme_string=QString::number(somme);

          query.prepare("INSERT INTO DONS_FINANCIERS  (num_operation, somme, nom_donneur) "
                        "VALUES (:num_operation, :somme, :nom_donneur)");
          query.bindValue(":num_operation",num_operation_string);
          query.bindValue(":somme",somme_string);
          query.bindValue(":nom_donneur",nom_donneur);
          return query.exec();//variable booleene retourne true si l'ajout est fait avec succes


}
bool donsfinanciers::supprimer(int num_operation)
{
    QSqlQuery query;
    QString res=QString::number(num_operation);
    query.prepare(" Delete from DONS_FINANCIERS where num_operation=:num_operation" );
    query.bindValue(":num_operation",res);

    return query.exec();

}
QSqlQueryModel* donsfinanciers::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
          model->setQuery("SELECT * FROM DONS_FINANCIERS");
          model->setHeaderData(0, Qt::Horizontal, QObject ::tr("Num_operation"));
          model->setHeaderData(1, Qt::Horizontal, QObject ::tr("somme"));
          model->setHeaderData(2, Qt::Horizontal, QObject ::tr("nom_donneur"));
          return model;
}

bool donsfinanciers::modifier(int idrech){
    QSqlQuery query;
    QString res=QString::number(idrech);

    query.prepare("UPDATE DONS_FINANCIERS SET SOMME=:somme,NOM_DONNEUR=:nom_donneur WHERE num_operation=:idrech");
    query.bindValue(":idrech",res);
    query.bindValue(":somme",somme);
    query.bindValue(":nom_donneur",nom_donneur);
    return query.exec();
}

QSqlQueryModel *donsfinanciers::rech(QString sommerech,QString nom_donneurrech)
{

    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM DONS_FINANCIERS WHERE somme LIKE'%"+sommerech+"%' and nom_donneur LIKE'%"+nom_donneurrech+"%'" );
    model->setHeaderData(0, Qt::Horizontal, QObject ::tr("Num_operation"));
    model->setHeaderData(1, Qt::Horizontal, QObject ::tr("somme"));
    model->setHeaderData(2, Qt::Horizontal, QObject ::tr("nom_donneur"));
    return model;
}


QSqlQueryModel *donsfinanciers::ordre_op()
     {
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from DONS_FINANCIERS   order by num_operation " );
    model->setHeaderData(0, Qt::Horizontal, QObject ::tr("Num_operation"));
    model->setHeaderData(1, Qt::Horizontal, QObject ::tr("somme"));
    model->setHeaderData(2, Qt::Horizontal, QObject ::tr("nom_donneur"));


         return model;
     }
QSqlQueryModel *donsfinanciers::ordre_somme()
     {
         QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from DONS_FINANCIERS   order by SOMME " );
         model->setHeaderData(0, Qt::Horizontal, QObject ::tr("Num_operation"));
         model->setHeaderData(1, Qt::Horizontal, QObject ::tr("somme"));
         model->setHeaderData(2, Qt::Horizontal, QObject ::tr("nom_donneur"));


         return model;
     }
QSqlQueryModel *donsfinanciers::ordre_nom()
     {
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from DONS_FINANCIERS   order by nom_donneur " );
    model->setHeaderData(0, Qt::Horizontal, QObject ::tr("Num_operation"));
    model->setHeaderData(1, Qt::Horizontal, QObject ::tr("somme"));
    model->setHeaderData(2, Qt::Horizontal, QObject ::tr("nom_donneur"));


         return model;
     }

QSqlQueryModel* donsfinanciers::statistiques()
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("SELECT COUNT(*) FROM  DONS_FINANCIERS WHERE SOMME >50 ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("somme>seuil "));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("quantitee"));
    return model;
}

/*void donsfinanciers ::statistiques(QWidget * w)
{
    int sommea = 0,sommev=0;
                QSqlQuery query("SELECT COUNT(*) FROM DONS_FINANCIERS WHERE SOMME='100'");
                while(query.next())
                {
                    sommea = query.value(0).toInt();
                }
                QSqlQuery query2("SELECT COUNT(*) FROM DONS_FINANCIERS WHERE SOMME='100'");
                while(query2.next())
                {
                   sommev= query2.value(0).toInt();
                }

            QPieSeries *series = new QPieSeries();

            series->append("prixa=100",sommea);
            series->append("prixv=100",sommev);

            series->setHoleSize(0.8);
            series->setPieSize(1.0);

            QPieSlice * I = series->slices().at(0);
            QPieSlice * C = series->slices().at(1);

            I->setLabelVisible(true);
            C->setLabelVisible(true);

            I->setBrush(QColor::fromRgb(255, 0, 0));
            C->setBrush(QColor::fromRgb(0, 0, 255));

            QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setTitle("Types");
            chart->legend()->setVisible(true);
            chart->legend()->setAlignment(Qt::AlignBottom);
            chart->setAnimationOptions(QChart::AllAnimations);

            QChartView * chartview = new QChartView(chart);
            chartview->resize(w->width(),w->height());
            chartview->setParent(w);

}*/

QList<qreal> MainWindow::stat_budget()
{
    QList<qreal> list ;
    QSqlQuery query;
    query.prepare("SELECT*FROM DONS_FINANCIERS ;");
    query.exec();
    while(query.next())
    {list.append(query.value(1).toInt());}

    return list;
}

QList<QString> MainWindow::stat_bud()
{
    QList<QString> list ;
    QSqlQuery query;
    query.prepare("SELECT*FROM DONS_FINANCIERS ;");
    query.exec();
    while(query.next())
    {list.append(query.value(0).toString());}

    return list;
}

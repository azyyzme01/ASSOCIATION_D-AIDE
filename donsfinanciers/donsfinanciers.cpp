#include "donsfinanciers.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>

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
     QSqlQuery query;
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


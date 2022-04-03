#include "adherant.h"
#include <QObject>

Adherant::Adherant()
{
 id=0;
 nom=" ";
 prenom=" ";
 fonction=" ";
 tele=0;
 image=" ";
}

Adherant::Adherant(int id,QString nom,QString prenom,QString fonction,int tele,QString image)
{   this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->fonction=fonction;
    this->tele=tele;
    this->image=image;
}



bool Adherant::ajouter()
{bool test=false;

    QSqlQuery query;
    QString id_string= QString::number(id);
    QString tele_string= QString::number(tele);
    query.prepare("INSERT INTO adherant (ID,NOM,PRENOM,FONCTION,TELE,IMAGE)"
                  "VALUES(:id, :nom, :prenom, :fonction, :tele, :image)");
    query.bindValue(":id",id_string);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":fonction",fonction);
    query.bindValue(":tele",tele_string);
    query.bindValue(":image",image);

    return query.exec();

    return test;
}

QSqlQueryModel* Adherant::afficher()
{

    QSqlQueryModel* model=new QSqlQueryModel;


          model->setQuery("SELECT* FROM ADHERANT");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Fonction"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tele"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("Image"));




    return model;
}
bool Adherant::supprimer(int id)
{



    QSqlQuery query;
    query.prepare("delete from adherant where id = :id");
    query.bindValue(":id",id);
    return query.exec();


}
bool Adherant::modifier()
{
    QSqlQuery query;
    QString res=QString::number(id);
    QString ress=QString::number(tele);
    query.prepare("UPDATE   adherant set nom=:nom,prenom=:prenom,fonction=:fonction,tele=:tele,image=:image where id=:id");
query.bindValue(":id",res);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":fonction",fonction);
query.bindValue(":tele",ress);
query.bindValue(":image",image);
return query.exec();
}


QSqlQueryModel *Adherant::recherche(QString value)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from adherant where id LIKE '"+value+"%' or nom LIKE '"+value+"%' or prenom LIKE '"+value+"%'");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Fonction"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tele"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Image"));

 return model;
}
/*QSqlQueryModel *Adherant::recherchen(QString nom)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from adherant where nom LIKE '"+nom+"%'");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Fonction"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tele"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Image"));

 return model;
}

QSqlQueryModel *Adherant::recherchep(QString prenom)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from adherant where prenom LIKE '"+prenom+"%'");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Fonction"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tele"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Image"));

 return model;
}*/








QSqlQueryModel *Adherant::ordre_id_A()
     {
         QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from adherant  order by id" );
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Fonction"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tele"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Image"));

         return model;
     }
  QSqlQueryModel *Adherant::ordre_nom_A()
     {
         QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from adherant  order by nom" );
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Fonction"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tele"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Image"));

         return model;
     }
  QSqlQueryModel *Adherant::ordre_prenom_A()
     {
         QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from adherant  order by prenom" );
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Fonction"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tele"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Image"));

         return model;
     }


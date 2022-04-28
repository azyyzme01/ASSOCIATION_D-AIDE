#include "famille.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
famille::famille()
{
     cin=0;
     nom="";
     prenom="";
    localisation="";
     nb_enfant="";
}

famille::famille(int cin,QString nom,QString prenom,QString localisation,QString nb_enfant)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->localisation=localisation;
    this->nb_enfant=nb_enfant;

}
int famille :: getcin()
{
    return cin;
}
QString famille :: getnom()
{
    return nom;
}
QString famille :: getprenom()
{
    return prenom;
}
QString famille :: getlocalisation()
{
    return localisation;
}
QString famille :: getnombre_enfant()
{
    return nb_enfant;
}
void famille :: setcin(int cin)
{
    this->cin=cin;
}
void famille :: setnom(QString nom)
{
    this->nom=nom;
}
void famille :: setprenom(QString prenom)
{
    this->prenom=prenom;
}
void famille :: setlocalisation(QString localisation)
{
    this->localisation=localisation;
}
void famille :: setnombre_enfant(QString nb_enfant)
{
    this->nb_enfant=nb_enfant;
}
bool famille :: ajouter()
{

         QSqlQuery query;
        QString cin_string=QString::number(cin);


              query.prepare("INSERT INTO familles  (cin,nom,prenom,localisation,nb_enfant)"
                            "VALUES (:cin, :nom, :prenom, :localisation, :nb_enfant)");
              query.bindValue(":cin",cin_string);
              query.bindValue(":nom",nom);
              query.bindValue(":prenom",prenom);
              query.bindValue(":localisation",localisation);
              query.bindValue(":nb_enfant",nb_enfant);
              return query.exec();//variable booleene retourne true si l'ajout est fait avec succes

}
bool famille::supprimer(int cin)
{



    QSqlQuery query;
    query.prepare("delete from familles where cin = :cin");
    query.bindValue(":cin",cin);//permet d'associer un nom (utilisé dans la requête) à une variable.
    return query.exec();//variable booleene retourne true si l'ajout est fait avec succes


}

QSqlQueryModel* famille::afficher()
{

    QSqlQueryModel* model=new QSqlQueryModel;


          model->setQuery("SELECT* FROM familles");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("localisation"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("nombre enfant"));



    return model;
}
bool famille::modifier(int cin)
{


    QSqlQuery query;
    QString code_s_string=QString::number(cin);

    query.prepare("update familles set cin=:id,NOM=:forename ,PRENOM=:surname,LOCALISATION=:localisation,NB_ENFANT=:nb where CIN=:id");
    query.bindValue(":id", code_s_string);
    query.bindValue(":forename", nom);
    query.bindValue(":surname", prenom);
    query.bindValue(":localisation",localisation);
    query.bindValue(":nb",nb_enfant);

    return query.exec();


}
QString famille:: calculer(int cin)
{
  QSqlQuery query;QString x;
    QString code_s_string=QString::number(cin);
   query.prepare("select * from familles where CIN=:id");
    query.bindValue(":id", code_s_string);
     query.exec();

     while(query.next())
     {
       x = query.value(4).toString();
     }
     x=x+"00";
     return x;
}

QSqlQueryModel *famille::rechercher2(QString rech)
{

        QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM familles WHERE CIN LIKE'%"+rech+"%' or PRENOM LIKE'%"+rech+"%' or NOM LIKE'%"+rech+"%'" );
        return model;


}

QSqlQueryModel *famille::nomT()
     {
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from familles   order by NOM " );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("localisation"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nombre enfant"));


         return model;
     }


QSqlQueryModel *famille::prenomT()
     {
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from familles   order by PRENOM " );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("localisation"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nombre enfant"));

         return model;
     }


QSqlQueryModel *famille::nbrenfT()
     {
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from familles   order by NB_ENFANT " );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("localisation"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nombre enfant"));


         return model;
     }

 QSqlQueryModel *famille::trie()
 {QSqlQueryModel *model=new QSqlQueryModel();

 model->setQuery("SELECT* from familles   order by NB_ENFANT,PRENOM  ");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("localisation"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("nombre enfant"));


      return model;
 }
 QSqlQueryModel *famille::triedes()
 {QSqlQueryModel *model=new QSqlQueryModel();

 model->setQuery("SELECT* from familles   order by NB_ENFANT DESC,PRENOM DESC  ");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("localisation"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("nombre enfant"));


      return model;
 }
QSqlQueryModel *famille::rech(QString prenom,QString nbr)
{

    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM familles WHERE PRENOM LIKE'%"+prenom+"%' and NB_ENFANT LIKE'%"+nbr+"%'" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("localisation"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nombre enfant"));
    return model;

}


#include "membre.h"
#include <QObject>



Membre::Membre()
{
 idm=0;
 nomm=" ";
 prenomm=" ";
 fonctionm=" ";
 telem=0;
 imagem=" ";
}

Membre::Membre(int idm,QString nomm,QString prenomm,QString fonctionm,int telem,QString imagem)
{   this->idm=idm;
    this->nomm=nomm;
    this->prenomm=prenomm;
    this->fonctionm=fonctionm;
    this->telem=telem;
    this->imagem=imagem;
}



bool Membre::ajouter()
{bool test=false;

    QSqlQuery query;
    QString idm_string= QString::number(idm);
    QString telem_string= QString::number(telem);
    query.prepare("INSERT INTO MEMBRE (IDM,NOMM,PRENOMM,FONCTIONM,TELEM,IMAGEM)"
                  "VALUES(:idm, :nomm, :prenomm, :fonctionm, :telem, :imagem)");
    query.bindValue(":idm",idm_string);
    query.bindValue(":nomm",nomm);
    query.bindValue(":prenomm",prenomm);
    query.bindValue(":fonctionm",fonctionm);
    query.bindValue(":telem",telem_string);
    query.bindValue(":imagem",imagem);

    return query.exec();

    return test;
}

QSqlQueryModel* Membre::afficher()
{

    QSqlQueryModel* model=new QSqlQueryModel;


          model->setQuery("SELECT* FROM MEMBRE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Fonction"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tele"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("Image"));




    return model;
}
bool Membre::supprimer(int idm)
{



    QSqlQuery query;
    query.prepare("delete from membre where idm = :idm");
    query.bindValue(":idm",idm);
    return query.exec();


}
bool Membre::modifier()
{
    QSqlQuery query;
    QString res=QString::number(idm);
    QString ress=QString::number(telem);
    query.prepare("UPDATE   membre set nomm=:nomm,prenomm=:prenomm,fonctionm=:fonctionm,telem=:telem,imagem=:imagem where idm=:idm");
query.bindValue(":idm",res);
query.bindValue(":nomm",nomm);
query.bindValue(":prenomm",prenomm);
query.bindValue(":fonctionm",fonctionm);
query.bindValue(":telem",ress);
query.bindValue(":imagem",imagem);
return query.exec();
}

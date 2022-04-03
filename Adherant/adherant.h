#ifndef ADHERANT_H
#define ADHERANT_H

#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQueryModel>


class Adherant
{
public:
    Adherant();
        Adherant(int,QString,QString,QString,int,QString);
QString get_nom(){return nom;};
QString get_prenom(){return prenom;};
QString get_fonction(){return fonction;};
QString get_image(){return image;};
int get_id(){return id;};
int get_tele(){return tele;};
bool ajouter();
bool modifier();
bool supprimer(int);
QSqlQueryModel * afficher();
QSqlQueryModel* recherche(QString);
QSqlQueryModel* recherchen(QString);
QSqlQueryModel* recherchep(QString);
QSqlQueryModel *ordre_id_A();
 QSqlQueryModel *ordre_nom_A();
  QSqlQueryModel *ordre_prenom_A();
private:
    int id, tele;
    QString nom, prenom, fonction, image;
};

#endif // ADHERANT_H

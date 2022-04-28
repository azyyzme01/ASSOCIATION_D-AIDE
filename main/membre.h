
#ifndef MEMBRE_H
#define MEMBRE_H

#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQueryModel>


class Membre
{
public:
    Membre();
        Membre(int,QString,QString,QString,int,QString);
QString getnomm(){return nomm;};
QString getprenomm(){return prenomm;};
QString getfonctionm(){return fonctionm;};
QString getimagem(){return imagem;};
int getidm(){return idm;};
int gettelem(){return telem;};
bool ajouter();
bool modifier();
bool supprimer(int);
QSqlQueryModel * afficher();



private:
    int idm, telem;
    QString nomm, prenomm, fonctionm, imagem;
};
#endif // MEMBRE_H

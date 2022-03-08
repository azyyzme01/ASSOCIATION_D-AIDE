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
    int getid();
    QString getnom();
    QString getprenom();
    QString getfonction();
    int gettele();
    QString getimage();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setfonction(QString);
    void settele(int);
    void setimage(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();




private:
    int id, tele;
    QString nom, prenom, fonction, image;
};

#endif // ADHERANT_H

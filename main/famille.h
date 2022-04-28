#ifndef FAMILLE_H
#define FAMILLE_H

#include<QString>

#include<QSqlQueryModel>
class famille
{
public:
    famille();
    famille(int,QString,QString,QString,QString);
    int getcin();
    QString getnom();
    QString getprenom();
    QString getlocalisation();
    QString getnombre_enfant();


    void setcin(int);
    void setnom( QString);
    void setprenom( QString);
    void setlocalisation( QString);
    void setnombre_enfant( QString);


    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * afficher();
    QSqlQueryModel *nomT();
        QSqlQueryModel *prenomT();
        QSqlQueryModel *nbrenfT();

   QSqlQueryModel *trie();
  QSqlQueryModel *triedes();
                QSqlQueryModel* wombo_combof();

   QString calculer(int);
QSqlQueryModel*  rechercher2(QString);
 QSqlQueryModel *rech(QString,QString);
private:
    int cin;
    QString nom;
    QString prenom;
    QString localisation;
    QString nb_enfant;

};

#endif // FAMILLE_H

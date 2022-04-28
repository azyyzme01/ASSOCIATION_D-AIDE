#ifndef DONSFINANCIERS_H
#define DONSFINANCIERS_H
#include<QString>
#include<QSqlQueryModel>

class donsfinanciers
{
public:
    donsfinanciers();
    donsfinanciers(int,float,QString);
    int getnum_operation();
    float getsomme();
    QString getnom_donneur();
   // __DATE__ getdate_op;
    void setnum_operation(int);
    void setsomme(float);
    void setnom_donneur(QString);
    //void setdate_op(__DATE__);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int idrech);
    QSqlQueryModel* trier_nom();
    QSqlQueryModel *rechercher(QString);
    QSqlQueryModel* statistiques();
    //void statistiques(QWidget);
    QSqlQueryModel *rech(QString,QString);
    QSqlQueryModel *ordre_op();
    QSqlQueryModel *ordre_somme();
    QSqlQueryModel *ordre_nom();


private:
    int num_operation;
    int somme;
    QString nom_donneur;
   // __DATE__ date_op;

};

#endif // DONSFINANCIERS_H


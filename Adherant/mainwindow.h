#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "arduino.h"
#include <QMainWindow>
#include "adherant.h"
#include "membre.h"
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//***********camera*******
class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;
//************************


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

     void update_label();
    void on_adherant_clicked();

    void on_famille_clicked();

    void on_finance_clicked();

    void on_logistique_clicked();

    void on_physiques_clicked();

    void on_retour_adherant_clicked();

    void on_retour_adherant_3_clicked();

    void on_retour_famille_clicked();

    void on_retour_finance_clicked();

    void on_retour_logistique_clicked();

    void on_retour_physique_clicked();

    void on_pushButton_clicked();


    void on_adherant_4_clicked();

    void on_adherant_5_clicked();

    void on_retour_adherant_2_clicked();

    void on_ajouter_adherant_clicked();

    void on_pushButton_Ajouter_2_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_2_clicked();

    void on_pushButton_afficher_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_afficher_adherant_clicked();

    void on_ajouter_adherant_m_clicked();

    void on_pushButton_afficher_m1_clicked();

    void on_pushButton_modifier_m_clicked();

    void on_pushButton_supprimer_m_clicked();

    void on_pushButton_afficher_m2_clicked();

    void on_pushButton_modifier_3_clicked();

    void on_pushButton_rechercherA_clicked();

    void on_pushButton_rechercherA_2_clicked();

    void on_pushButton_trierA_clicked();

    void on_pushButton_modifier_4_clicked();

    void on_comboBox66_activated(const QString &arg1);

    void on_pushButton_modifier_5_clicked();

private:
    Ui::MainWindow *ui;
    Adherant A;
    Membre M;
    Adherant tempadherant;

    QCamera *mCamera;
        QCameraViewfinder *mCameraViewfinder;
        QCameraImageCapture *mCameraImageCapture;
        QVBoxLayout *mlayout;
        QMenu *mOptionsMenu;
        QAction *mEncenderAction;
        QAction *mApagarAction;
        QAction *mcapturerAction;
        QByteArray data; // variable contenant les données reçues

        arduino AR; // objet temporaire

};
#endif // MAINWINDOW_H
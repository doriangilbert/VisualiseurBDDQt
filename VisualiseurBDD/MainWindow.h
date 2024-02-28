#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//** Espace de nommage pour la classe MainWindow **//
namespace Ui {
class MainWindow;
}

//** Classe MainWindow héritant de QMainWindow représentant la fenêtre principale de l'application **//
class MainWindow : public QMainWindow
{
    //** Macro permettant de déclarer les slots et les signaux **//
    Q_OBJECT

public:
    //** Constructeur de la classe MainWindow **//
    explicit MainWindow(QWidget *parent = nullptr);
    //** Destructeur de la classe MainWindow **//
    ~MainWindow();

private:
    //** Interface graphique de la fenêtre principale **//
    Ui::MainWindow *ui;
    //** Page de connexion **//
    class Login *loginWidget;
    //** Page de création d'un utilisateur **//
    class CreateUser *createUserWidget;
    //** Page de gestion d'un utilisateur **//
    class ManageUser *manageUserWidget;
    //** Page de sélection d'un profil **//
    class SelectProfile *selectProfileWidget;
    //** Page de création d'un profil **//
    class CreateProfile *createProfileWidget;

public slots:
    //** Slot permettant de masquer la page de connexion et d'afficher la page de gestion d'un utilisateur **//
    void goToManageUserFromLogin();
    //** Slot permettant de masquer la page de gestion d'un utilisateur et d'afficher la page de sélection d'un profil **//
    void goToSelectProfileFromManageUser();
    //** Slot permettant de masquer la page de gestion d'un utilisateur et d'afficher la page de connexion **//
    void goToLoginFromManageUser();
    //** Slot permettant de masquer la page de sélection d'un profil et d'afficher la page de gestion d'un utilisateur **//
    void goToManageUserFromSelectProfile();
    //** Slot permettant de masquer la page de création d'un utilisateur et d'afficher la page de connexion **//
    void goToLoginFromCreateUser();
    //** Slot permettant de masquer la page de sélection d'un profil et d'afficher la page de création d'un profil **//
    void goToCreateProfileFromSelectProfile();
    //** Slot permettant de masquer la page de création d'un profil et d'afficher la page de sélection d'un profil **//
    void goToSelectProfileFromCreateProfile();
    //** Slot permettant de masquer la page de gestion d'un utilisateur et d'afficher la page de création d'un utilisateur **//
    void goToCreateUserFromManageUser();
};

#endif // MAINWINDOW_H

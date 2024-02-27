#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Login.h"
#include "CreateUser.h"
#include "ManageUser.h"
#include "SelectProfile.h"
#include "CreateProfile.h"
#include "ReadWriteJson.h"

//** Constructeur de la classe MainWindow **//
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //** Initialisation de l'interface graphique **//
    ui->setupUi(this);

    ReadWriteJson qjson;
    qjson.readJson();
    //qjson.writeJson();

    //** Initialisation de la page de connexion **//
    loginWidget = new Login(this);
    //** Masquage de la page de connexion **//
    loginWidget->hide();

    //** Initialisation de la page de création d'un utilisateur **//
    createUserWidget = new CreateUser(this);
    //** Affichage de la page de création d'un utilisateur **//
    createUserWidget->show();

    //** Initialisation de la page de gestion d'un utilisateur **//
    manageUserWidget = new ManageUser(this);
    //** Masquage de la page de gestion d'un utilisateur **//
    manageUserWidget->hide();

    //** Initialisation de la page de sélection d'un profil **//
    selectProfileWidget = new SelectProfile(this);
    //** Masquage de la page de sélection d'un profil **//
    selectProfileWidget->hide();

    createProfileWidget = new CreateProfile(this);
    createProfileWidget->hide();
    
    //** Connexion des signaux et des slots **//
    connect(loginWidget, &Login::loginButtonClicked, this, &MainWindow::goToManageUserFromLogin);
    connect(manageUserWidget, &ManageUser::selectProfileButtonClicked, this, &MainWindow::goToSelectProfileFromManageUser);
    connect(manageUserWidget, &ManageUser::disconnectButtonClicked, this, &MainWindow::goToLoginFromManageUser);
    connect(selectProfileWidget, &SelectProfile::validateButtonClicked, this, &MainWindow::goToManageUserFromSelectProfile);
    connect(createUserWidget, &CreateUser::validateButtonClicked, this, &MainWindow::goToLoginFromCreateUser);
    connect(selectProfileWidget, &SelectProfile::createProfileButtonClicked, this, &MainWindow::goToCreateProfileFromSelectProfile);
    connect(createProfileWidget, &CreateProfile::validateButtonClicked, this, &MainWindow::goToSelectProfileFromCreateProfile);
}

//** Destructeur de la classe MainWindow **//
MainWindow::~MainWindow()
{
    //** Suppression de l'interface graphique **//
    delete ui;
}

//** Slot permettant de masquer la page de connexion et d'afficher la page de gestion d'un utilisateur **//
void MainWindow::goToManageUserFromLogin() {
    loginWidget->hide();
    manageUserWidget->show();
}

//** Slot permettant de masquer la page de gestion d'un utilisateur et d'afficher la page de sélection d'un profil **//
void MainWindow::goToSelectProfileFromManageUser() {
    manageUserWidget->hide();
    selectProfileWidget->show();
    selectProfileWidget->load();
}

//** Slot permettant de masquer la page de gestion d'un utilisateur et d'afficher la page de connexion **//
void MainWindow::goToLoginFromManageUser() {
    manageUserWidget->hide();
    loginWidget->show();
}

//** Slot permettant de masquer la page de sélection d'un profil et d'afficher la page de gestion d'un utilisateur **//
void MainWindow::goToManageUserFromSelectProfile() {
    selectProfileWidget->hide();
    manageUserWidget->show();
}

//** Slot permettant de masquer la page de création d'un utilisateur et d'afficher la page de connexion **//
void MainWindow::goToLoginFromCreateUser() {
    createUserWidget->hide();
    loginWidget->show();
}

void MainWindow::goToCreateProfileFromSelectProfile() {
    selectProfileWidget->hide();
    createProfileWidget->show();
}

void MainWindow::goToSelectProfileFromCreateProfile() {
    createProfileWidget->hide();
    selectProfileWidget->show();
    selectProfileWidget->load();
}

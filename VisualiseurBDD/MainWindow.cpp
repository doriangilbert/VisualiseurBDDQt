#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Login.h"
#include "CreateUser.h"
#include "ManageUser.h"
#include "SelectProfile.h"
#include "CreateProfile.h"
#include "ReadWriteJson.h"
#include "Data.h"
#include "DatabasesList.h"
#include "ManageDatabase.h"
#include "TableViewer.h"
#include "QueryMaker.h"
#include "QueryResult.h"

//** Constructeur de la classe MainWindow **//
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //** Initialisation de l'interface graphique **//
    ui->setupUi(this);

    //** Lecture du fichier JSON **//
    ReadWriteJson qjson;
    qjson.readJson();

    //** Initialisation de la page de connexion **//
    loginWidget = new Login(this);

    //** Initialisation de la page de création d'un utilisateur **//
    createUserWidget = new CreateUser(this);

    //** Si il n'y a pas d'utilisateurs **//
    if (Data::getUsers().size() == 0)
    {
        //** Masquage de la page de connexion **//
        loginWidget->hide();
        //** Affichage de la page de création d'un utilisateur **//
        createUserWidget->show();
    }
    else
    {
        //** Masquage de la page de création d'un utilisateur **//
        createUserWidget->hide();
        //** Affichage de la page de connexion **//
        loginWidget->show();
    }

    //** Initialisation de la page de gestion d'un utilisateur **//
    manageUserWidget = new ManageUser(this);
    //** Masquage de la page de gestion d'un utilisateur **//
    manageUserWidget->hide();

    //** Initialisation de la page de sélection d'un profil **//
    selectProfileWidget = new SelectProfile(this);
    //** Masquage de la page de sélection d'un profil **//
    selectProfileWidget->hide();

    //** Initialisation de la page de création d'un profil **//
    createProfileWidget = new CreateProfile(this);
    //** Masquage de la page de création d'un profil **//
    createProfileWidget->hide();

    databasesListWidget = new DatabasesList(this);
    databasesListWidget->hide();

    manageDatabaseWidget = new ManageDatabase(this);
    manageDatabaseWidget->hide();

    tableViewerWidget = new TableViewer(this);
    tableViewerWidget->hide();

    queryMakerWidget = new QueryMaker(this);
    queryMakerWidget->hide();

    queryResultWidget = new QueryResult(this);
    queryResultWidget->hide();
    
    //** Connexion des signaux et des slots **//
    connect(loginWidget, &Login::loginButtonClicked, this, &MainWindow::goToManageUserFromLogin);
    connect(manageUserWidget, &ManageUser::selectProfileButtonClicked, this, &MainWindow::goToSelectProfileFromManageUser);
    connect(manageUserWidget, &ManageUser::disconnectButtonClicked, this, &MainWindow::goToLoginFromManageUser);
    connect(selectProfileWidget, &SelectProfile::validateButtonClicked, this, &MainWindow::goToManageUserFromSelectProfile);
    connect(createUserWidget, &CreateUser::validateButtonClicked, this, &MainWindow::goToLoginFromCreateUser);
    connect(selectProfileWidget, &SelectProfile::createProfileButtonClicked, this, &MainWindow::goToCreateProfileFromSelectProfile);
    connect(createProfileWidget, &CreateProfile::validateButtonClicked, this, &MainWindow::goToSelectProfileFromCreateProfile);
    connect(manageUserWidget, &ManageUser::createUserButtonClicked, this, &MainWindow::goToCreateUserFromManageUser);
    connect(manageUserWidget, &ManageUser::basesDeDonneesButtonClicked, this, &MainWindow::goToDatabasesListFromManageUser);
    connect(databasesListWidget, &DatabasesList::retourButtonClicked, this, &MainWindow::goToManageUserFromDatabasesList);
    connect(manageDatabaseWidget, &ManageDatabase::effectuerRequeteButtonClicked, this, &MainWindow::goToQueryMakerFromManageDatabase);
    connect(manageDatabaseWidget, &ManageDatabase::retourButtonClicked, this, &MainWindow::goToDatabasesListFromManageDatabase);
    connect(tableViewerWidget, &TableViewer::retourButtonClicked, this, &MainWindow::goToManageDatabaseFromTableViewer);
    connect(queryMakerWidget, &QueryMaker::executerRequeteButtonClicked, this, &MainWindow::goToQueryResultFromQueryMaker);
    connect(queryMakerWidget, &QueryMaker::retourButtonClicked, this, &MainWindow::goToManageDatabaseFromQueryMaker);
    connect(queryResultWidget, &QueryResult::retourButtonClicked, this, &MainWindow::goToManageDatabaseFromQueryResult);
    connect(manageDatabaseWidget, &ManageDatabase::tableViewClicked, this, &MainWindow::goToTableViewerFromManageDatabase);
    connect(databasesListWidget, &DatabasesList::tableViewClicked, this, &MainWindow::goToManageDatabaseFromDatabasesList);
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
    //** Initialisation de la page de gestion d'un utilisateur **//
    manageUserWidget->load();
}

//** Slot permettant de masquer la page de gestion d'un utilisateur et d'afficher la page de sélection d'un profil **//
void MainWindow::goToSelectProfileFromManageUser() {
    manageUserWidget->hide();
    selectProfileWidget->show();
    //** Initialisation de la page de sélection d'un profil **//
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
    //** Initialisation de la page de gestion d'un utilisateur **//
    manageUserWidget->load();
}

//** Slot permettant de masquer la page de création d'un utilisateur et d'afficher la page de connexion **//
void MainWindow::goToLoginFromCreateUser() {
    createUserWidget->hide();
    loginWidget->show();
}

//** Slot permettant de masquer la page de sélection d'un profil et d'afficher la page de création d'un profil **//
void MainWindow::goToCreateProfileFromSelectProfile() {
    selectProfileWidget->hide();
    createProfileWidget->show();
}

//** Slot permettant de masquer la page de création d'un profil et d'afficher la page de sélection d'un profil **//
void MainWindow::goToSelectProfileFromCreateProfile() {
    createProfileWidget->hide();
    selectProfileWidget->show();
    //** Initialisation de la page de sélection d'un profil **//
    selectProfileWidget->load();
}

//** Slot permettant de masquer la page de gestion d'un utilisateur et d'afficher la page de création d'un utilisateur **//
void MainWindow::goToCreateUserFromManageUser() {
    manageUserWidget->hide();
    createUserWidget->show();
}

void MainWindow::goToDatabasesListFromManageUser() {
    manageUserWidget->hide();
    databasesListWidget->show();
    databasesListWidget->load();
}

void MainWindow::goToManageUserFromDatabasesList() {
    databasesListWidget->hide();
    manageUserWidget->show();
}

void MainWindow::goToQueryMakerFromManageDatabase() {
    manageDatabaseWidget->hide();
    queryMakerWidget->show();
}

void MainWindow::goToDatabasesListFromManageDatabase() {
    manageDatabaseWidget->hide();
    databasesListWidget->show();
    databasesListWidget->load();
}

void MainWindow::goToManageDatabaseFromTableViewer() {
    tableViewerWidget->hide();
    manageDatabaseWidget->show();
    manageDatabaseWidget->load();
}

void MainWindow::goToQueryResultFromQueryMaker() {
    queryMakerWidget->hide();
    queryResultWidget->show();
    queryResultWidget->load();
}

void MainWindow::goToManageDatabaseFromQueryMaker() {
    queryMakerWidget->hide();
    manageDatabaseWidget->show();
    manageDatabaseWidget->load();
}

void MainWindow::goToManageDatabaseFromQueryResult() {
    queryResultWidget->hide();
    manageDatabaseWidget->show();
    manageDatabaseWidget->load();
}

void MainWindow::goToTableViewerFromManageDatabase() {
    manageDatabaseWidget->hide();
    tableViewerWidget->show();
    tableViewerWidget->load();
}

void MainWindow::goToManageDatabaseFromDatabasesList() {
    databasesListWidget->hide();
    manageDatabaseWidget->show();
    manageDatabaseWidget->load();
}

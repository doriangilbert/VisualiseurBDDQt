#include "Login.h"
#include "ui_Login.h"
#include <string>
#include <iostream>
#include "Data.h"
using namespace std;

//** Constructeur de la classe Login **//
Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    //** Initialisation de l'interface graphique **//
    ui->setupUi(this);
}

//** Destructeur de la classe Login **//
Login::~Login()
{
    //** Suppression de l'interface graphique **//
    delete ui;
}

//** Slot appelé lors du clic sur le bouton se connecter **//
void Login::on_seConnecterPushButton_clicked()
{
    //** Récupération des informations saisies par l'utilisateur **//
    string identifiant = ui->identifiantLineEdit->text().toStdString();
    string motDePasse = ui->motDePasseLineEdit->text().toStdString();
    cout << identifiant << " | " << motDePasse << endl;
    //** Vérification de la saisie pour connexion **//
    for (User u : Data::getUsers()) {
        if (identifiant == u.getIdentifier() && motDePasse == u.getPassword()) {
            Data::setCurrentUser(u);
            //** Réinitialisation des champs **//
            ui->identifiantLineEdit->setText(0);
            ui->motDePasseLineEdit->setText(0);
            //** Emission du signal loginButtonClicked **//
            emit loginButtonClicked();
        }
    }
}


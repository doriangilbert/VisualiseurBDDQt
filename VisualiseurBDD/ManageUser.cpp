#include "ManageUser.h"
#include "ui_ManageUser.h"
#include "Data.h"
#include <iostream>

//** Constructeur de la classe ManageUser **//
ManageUser::ManageUser(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ManageUser)
{
    //** Initialisation de l'interface graphique **//
    ui->setupUi(this);
}

//** Méthode permettant d'initialiser la page **//
void ManageUser::load() {
    ui->utilisateurCourantLabel->setText(QString::fromStdString(Data::getCurrentUser().getIdentifier()));
    ui->profilCourantLabel->setText(QString::fromStdString(Data::getCurrentProfile().getName()));
    if (Data::getCurrentUser().getAdmin() == 0) {
        ui->statutCompteLabel->setText("Utilisateur");
    } else {
        ui->statutCompteLabel->setText("Administrateur");
    }
    if (Data::getCurrentUser().getAdmin() == 0) {
        ui->creerUtilisateurPushButton->setDisabled(true);
    } else {
        ui->creerUtilisateurPushButton->setDisabled(false);
    }
    cout << Data::getCurrentUser().getIdentifier() << endl;
    cout << Data::getCurrentUser().getAdmin() << endl;
}

//** Destructeur de la classe ManageUser **//
ManageUser::~ManageUser()
{
    //** Suppression de l'interface graphique **//
    delete ui;
}

//** Slot appelé lors du clic sur le bouton sélectionner un profil **//
void ManageUser::on_selectionProfilPushButton_clicked()
{
    //** Emission du signal selectProfileButtonClicked **//
    emit selectProfileButtonClicked();
}

//** Slot appelé lors du clic sur le bouton se déconnecter **//
void ManageUser::on_seDeconnecterPushButton_clicked()
{
    //** Emission du signal disconnectButtonClicked **//
    emit disconnectButtonClicked();
}


void ManageUser::on_creerUtilisateurPushButton_clicked()
{
    //** Emission du signal createUserButtonClicked **//
    emit createUserButtonClicked();
}


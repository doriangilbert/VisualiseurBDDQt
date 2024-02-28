#include "CreateProfile.h"
#include "ui_CreateProfile.h"
#include "Profile.h"
#include "Data.h"
#include "ReadWriteJson.h"

//** Constructeur de la classe CreateProfile **//
CreateProfile::CreateProfile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreateProfile)
{
    //** Initialisation de l'interface graphique **//
    ui->setupUi(this);
}

//** Destructeur de la classe CreateProfile **//
CreateProfile::~CreateProfile()
{
    //** Suppression de l'interface graphique **//
    delete ui;
}

//** Slot appelé lors du clic sur le bouton valider **//
void CreateProfile::on_validerPushButton_clicked()
{
    //** Récupération des informations saisies par l'utilisateur **//
    string nomProfil = ui->nomProfilLineEdit->text().toStdString();
    //** Création d'un nouvel objet Profile **//
    Profile newProfile = Profile(nomProfil);
    //** Ajout du profil à l'utilisateur courant **//
    User currentUser = Data::getCurrentUser();
    currentUser.AddProfile(newProfile);
    Data::setCurrentUser(currentUser);
    Data::deleteUser(Data::getCurrentUser().getIdentifier());
    Data::addUser(currentUser);
    Data::getCurrentUser().AddProfile(newProfile);
    //** Mise à jour du fichier JSON **//
    ReadWriteJson qjson;
    qjson.writeJson();
    //** Réinitialisation des champs **//
    ui->nomProfilLineEdit->setText(0);
    //** Emission du signal validateButtonClicked **//
    emit validateButtonClicked();
}


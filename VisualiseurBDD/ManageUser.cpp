#include "ManageUser.h"
#include "ui_ManageUser.h"

//** Constructeur de la classe ManageUser **//
ManageUser::ManageUser(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ManageUser)
{
    //** Initialisation de l'interface graphique **//
    ui->setupUi(this);
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


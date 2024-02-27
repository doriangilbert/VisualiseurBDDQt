#include "SelectProfile.h"
#include "ui_SelectProfile.h"
#include "Profile.h"
#include <iostream>

//** Constructeur de la classe SelectProfile **//
SelectProfile::SelectProfile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SelectProfile)
{
    //** Initialisation de l'interface graphique **//
    ui->setupUi(this);

    Profile profil1 = Profile("Profil 1");
    Profile profil2 = Profile("Profil 2");
    Profile profil3 = Profile("Profil 3");
    ui->selectionnerProfilComboBox->addItem("Profil 1", "Profil 1");
    ui->selectionnerProfilComboBox->addItem("Profil 2", "Profil 2");
    ui->selectionnerProfilComboBox->addItem("Profil 3", "Profil 4");
}

//** Destructeur de la classe SelectProfile **//
SelectProfile::~SelectProfile()
{
    //** Suppression de l'interface graphique **//
    delete ui;
}

//** Slot appelé lors du clic sur le bouton valider **//
void SelectProfile::on_validerPushButton_clicked()
{
    string selectionProfil = ui->selectionnerProfilComboBox->currentText().toStdString();
    cout << selectionProfil << endl;
    //** Emission du signal validateButtonClicked **//
    emit validateButtonClicked();
}


void SelectProfile::on_creerProfilPushButton_clicked()
{
    emit createProfileButtonClicked();
}


#include "SelectProfile.h"
#include "ui_SelectProfile.h"
#include "Profile.h"
#include "Data.h"

//** Constructeur de la classe SelectProfile **//
SelectProfile::SelectProfile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SelectProfile)
{
    //** Initialisation de l'interface graphique **//
    ui->setupUi(this);
}

//** Méthode permettant d'initialiser la page **//
void SelectProfile::load() {
    QList<QString> listeChoix;
    //** Parcours des profils de l'utilisateur courant **//
    for (Profile p : Data::getCurrentUser().getProfiles()) {
        //** Ajout du nom du profil dans la liste **//
        listeChoix.append(QString::fromStdString(p.getName()));
    }
    //** Ajout des profils dans la liste déroulante **//
    ui->selectionnerProfilComboBox->clear();
    ui->selectionnerProfilComboBox->addItems(listeChoix);
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
    //** Récupération du profil sélectionné **//
    string selectionProfil = ui->selectionnerProfilComboBox->currentText().toStdString();
    //** Parcours des profils de l'utilisateur courant **//
    for (Profile p : Data::getCurrentUser().getProfiles()) {
        //** Si le profil correspond à celui sélectionné **//
        if(p.getName() == selectionProfil) {
            //** Mise à jour du profil courant **//
            Data::setCurrentProfile(p);
        }
    }
    //** Emission du signal validateButtonClicked **//
    emit validateButtonClicked();
}

//** Slot appelé lors du clic sur le bouton créer un profil **//
void SelectProfile::on_creerProfilPushButton_clicked()
{
    //** Emission du signal createProfileButtonClicked **//
    emit createProfileButtonClicked();
}


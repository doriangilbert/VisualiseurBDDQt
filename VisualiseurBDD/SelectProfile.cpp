#include "SelectProfile.h"
#include "ui_SelectProfile.h"
#include "Profile.h"
#include <iostream>
#include "Data.h"

//** Constructeur de la classe SelectProfile **//
SelectProfile::SelectProfile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SelectProfile)
{
    //** Initialisation de l'interface graphique **//
    ui->setupUi(this);
}

void SelectProfile::load() {
    QList<QString> listeChoix = {};
    for (Profile p : Data::getCurrentUser().getProfiles()) {
        listeChoix.append(QString::fromStdString(p.getName()));
    }
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
    string selectionProfil = ui->selectionnerProfilComboBox->currentText().toStdString();
    cout << selectionProfil << endl;
    //** Emission du signal validateButtonClicked **//
    emit validateButtonClicked();
}


void SelectProfile::on_creerProfilPushButton_clicked()
{
    emit createProfileButtonClicked();
}


#include "SelectProfile.h"
#include "ui_SelectProfile.h"

//** Constructeur de la classe SelectProfile **//
SelectProfile::SelectProfile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SelectProfile)
{
    //** Initialisation de l'interface graphique **//
    ui->setupUi(this);
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
    //** Emission du signal validateButtonClicked **//
    emit validateButtonClicked();
}


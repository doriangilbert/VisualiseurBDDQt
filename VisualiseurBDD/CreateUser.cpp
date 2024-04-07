#include "CreateUser.h"
#include "ui_CreateUser.h"
#include "User.h"
#include "Data.h"
#include "ReadWriteJson.h"
using namespace std;

//** Constructeur de la classe CreateUser **//
CreateUser::CreateUser(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreateUser)
{
    //** Initialisation de l'interface graphique **//
    ui->setupUi(this);
}

//** Destructeur de la classe CreateUser **//
CreateUser::~CreateUser()
{
    //** Suppression de l'interface graphique **//
    delete ui;
}

//** Slot appelé lors du clic sur le bouton valider **//
void CreateUser::on_validerPushButton_clicked()
{
    //** Récupération des informations saisies par l'utilisateur **//
    string nom = ui->nomLineEdit->text().toStdString();
    string prenom = ui->prenomLineEdit->text().toStdString();
    string identifiant = ui->identifiantLineEdit->text().toStdString();
    string motDePasse = ui->motDePasseLineEdit->text().toStdString();
    string confirmationMotDePasse = ui->confirmationMotDePasseLineEdit->text().toStdString();
    bool isAdmin = ui->adminCheckBox->isChecked();

    //** On accepte le nouvel utilisateur si tous les champs sont remplis et que la confirmation du mot de passe est identique au mot de passe **//
    if (motDePasse == confirmationMotDePasse && !nom.empty() && !prenom.empty() && !identifiant.empty() && !motDePasse.empty())
    {
        User newUser = User(nom, prenom, identifiant, motDePasse, isAdmin,1);
        Data::addUser(newUser);
        ReadWriteJson qjson;
        qjson.writeJson();
        //** Réinitialisation des champs **//
        ui->nomLineEdit->setText(0);
        ui->prenomLineEdit->setText(0);
        ui->identifiantLineEdit->setText(0);
        ui->motDePasseLineEdit->setText(0);
        ui->confirmationMotDePasseLineEdit->setText(0);
        ui->adminCheckBox->setChecked(0);
        //** Emission du signal validateButtonClicked **//
        emit validateButtonClicked();
    }
}


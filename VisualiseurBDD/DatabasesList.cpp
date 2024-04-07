#include "DatabasesList.h"
#include "ui_DatabasesList.h"
#include "Data.h"
#include "ReadWriteJson.h"
#include "lib/sqlite3.h"
#include <QFileDialog>


//sqlite3* db;
//int rc = sqlite3_open("ma_base_de_données.db", &db);
//if (rc != SQLITE_OK)
//{
    // Gestion des erreurs
//}


DatabasesList::DatabasesList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DatabasesList)
{
    ui->setupUi(this);
}

void DatabasesList::load()
{

}

DatabasesList::~DatabasesList()
{
    delete ui;
}

void DatabasesList::on_retourPushButton_clicked()
{
    emit retourButtonClicked();
}


void DatabasesList::on_ajouterBasePushButton_clicked()
{
    // On ouvre la boîte de dialogue pour choisir un fichier .SQLite
    QString fileName = QFileDialog::getOpenFileName(this, tr("Ouvrir fichier"), "", tr("Fichiers SQLite (*.SQLite)"));

    // On vérifie si un fichier a été sélectionné
    if (!fileName.isEmpty())
    {
        //** On crée la nouvelle BDD **//
        string nomBdd = fileName.toStdString();
        BDD newBdd(nomBdd);

        //** Récupération de l'utilisateur courant **//
        User currentUser = Data::getCurrentUser();
        //** Récupération du profil courant **//
        Profile currentProfile = Data::getCurrentProfile();

        //** Création d'un nouvel utilisateur **//
        User newUser = User(currentUser.getLastName(), currentUser.getFirstName(), currentUser.getIdentifier(), currentUser.getPassword(), currentUser.getAdmin(),0);

        //** Insertion des profils de l'utilisateur courant dans le nouvel utilisateur**//
        for (Profile profil : Data::getCurrentUser().getProfiles())
        {
            //** On ajoute la BDD au profil courant **//
            if (profil.getName() == Data::getCurrentProfile().getName())
            {
                profil.AddBDD(newBdd);
            }
            newUser.AddProfile(profil);
        }

        Data::setCurrentUser(newUser);
        Data::deleteUser(Data::getCurrentUser().getIdentifier());
        Data::addUser(newUser);

        //** Mise à jour du fichier JSON **//
        ReadWriteJson qjson;
        qjson.writeJson();
    }

}


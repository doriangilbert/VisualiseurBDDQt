#include "DatabasesList.h"
#include "ui_DatabasesList.h"
#include "Data.h"
#include "ReadWriteJson.h"
#include "lib/sqlite3.h"
#include <QFileDialog>
#include <iostream>


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
    if (!fileName.isEmpty()) {
        BDD newBdd(fileName.toStdString());
        Data::getCurrentProfile().AddBDD(newBdd);
        std::cout << "coucou";
        //** Mise à jour du fichier JSON **//
        ReadWriteJson qjson;
        qjson.writeJson();
        //std::cout << fileName.toStdString();
    }

}


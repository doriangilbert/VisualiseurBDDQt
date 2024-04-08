#include "DatabasesList.h"
#include "ui_DatabasesList.h"
#include "Data.h"
#include "ReadWriteJson.h"
#include "lib/sqlite3.h"
#include <QFileDialog>
#include <QStandardItemModel>
#include <QMessageBox>


DatabasesList::DatabasesList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DatabasesList)
{
    ui->setupUi(this);
}

void DatabasesList::load()
{
    // Création du modèle de vue
    QStandardItemModel *model = new QStandardItemModel();

    // Ajout des en-têtes de colonne
    model->setHorizontalHeaderLabels(QStringList{"Chemin absolu du fichier"});

    // Ajout des données un tableau et on ajoute les noms des fichiers dans un combobox
    QStringList data = {};
    for (auto chemin : Data::getCurrentProfile().getBDDs())
    {
        data.append(QString::fromStdString(chemin.getPath()));

        // On ne garde que le nom du fichier pour l'afficher dans la combobox
        QFileInfo fileInfoBdd(QString::fromStdString(chemin.getPath()));
        QString fileNameBdd = fileInfoBdd.fileName();
        ui->comboBox->addItem(fileNameBdd);
    }

    // On ajoute ces données dans la colonne
    for (const QString &text : data) {
        QList<QStandardItem*> items;
        items.append(new QStandardItem(text));
        model->appendRow(items);
    }

    // On insère le modèle dans la TableView
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    // Connexion du clic sur une ligne avec le slot onTableViewClicked
    QObject::connect(ui->tableView, &QTableView::clicked, [&](const QModelIndex &index)
    {
        if (index.isValid())
        {
            // On indique que la BDD courante est la ligne choisie
            QVariant value = model->data(model->index(index.row(), 0));
            for (auto dataBase : Data::getCurrentProfile().getBDDs())
            {
                if (value.toString() == QString::fromStdString(dataBase.getPath()))
                {
                    Data::setCurrentBDD(dataBase);
                }
            }

            //On ouvre la prochaine fenêtre
            emit tableViewClicked();
        }
    });

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

        emit retourButtonClicked();
    }
}

void DatabasesList::on_supprimerPushButton_clicked()
{
    //** On récupère le nom de la BDD qu'on veut retirer **//
    int selectedIndex = ui->comboBox->currentIndex();
    QString selectedText = ui->comboBox->itemText(selectedIndex);

    string nameBdd = selectedText.toStdString();

    //** Récupération de l'utilisateur courant **//
    User currentUser = Data::getCurrentUser();
    //** Récupération du profil courant **//
    Profile currentProfile = Data::getCurrentProfile();

    //** Création d'un nouvel utilisateur **//
    User newUser = User(currentUser.getLastName(), currentUser.getFirstName(), currentUser.getIdentifier(), currentUser.getPassword(), currentUser.getAdmin(),0);

    //** Insertion des profils de l'utilisateur courant dans le nouvel utilisateur**//
    for (Profile profil : Data::getCurrentUser().getProfiles())
    {
        //** On supprime la BDD au profil courant **//
        if (profil.getName() == Data::getCurrentProfile().getName())
        {
            profil.RemoveBDD(nameBdd);
        }
        newUser.AddProfile(profil);
    }

    Data::setCurrentUser(newUser);
    Data::deleteUser(Data::getCurrentUser().getIdentifier());
    Data::addUser(newUser);

    //** Mise à jour du fichier JSON **//
    ReadWriteJson qjson;
    qjson.writeJson();

    emit retourButtonClicked();
}


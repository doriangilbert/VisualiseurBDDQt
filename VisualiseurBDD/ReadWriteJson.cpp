#include "ReadWriteJson.h"
#include "Data.h"

//** Fonction pour reprendre les données du fichier Json et les transformer en données "utilisables" dans notre application: **//
//** liste des utilisateurs / utilisateurs / liste de profils **//
bool ReadWriteJson::readJson()
{
    QFile file("Users.json");
    //Si le fichier n'existe pas
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Le fichier n'existe pas";
        //On termine le programme en remontant l'erreur
        return false;
    }
    QByteArray jsonData  = file.readAll();

    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    QJsonObject AllObjects = doc.object();

    //On verifie que l'on a bien un objet et que ce dernier possède bien le mot clé "users", attestant que le fichier est bien lue et sous un bon format
    if (AllObjects.contains("users") && AllObjects["users"].isArray())
    {
        //On retrouve la liste de users
        QJsonArray all = AllObjects["users"].toArray();

        // On parcourt la liste des utilisateurs
        for (const auto &userValue : all)
        {
            QJsonObject userObject = userValue.toObject();

            // On récupère les informations de l'utilisateur
            string nom = userObject["nom"].toString().toStdString();
            string prenom = userObject["prenom"].toString().toStdString();
            string identifiant = userObject["identifiant"].toString().toStdString();
            string motDePasse = userObject["motDePasse"].toString().toStdString();
            bool admin = userObject["admin"].toString().toInt();

            // On va créer l'utilisateur sous un format "utilisable" par le programme
            User user = User(nom, prenom, identifiant, motDePasse, admin, 0);

            // On récupère la liste des profils de l'utilisateur
            QJsonArray profilesArray = userObject["profiles"].toArray();
            for (auto profileValue : profilesArray)
            {
                QJsonObject profileObject = profileValue.toObject();

                // On crée le profil
                Profile profile(profileObject["Le nom du profil"].toString().toStdString());
                //cout << profileValue.toString().toStdString();

                // On récupère la liste des BDDs du profil
                QJsonArray bddsArray = profileObject["Les BDDs"].toArray();
                for (auto bddValue : bddsArray)
                {
                    QJsonObject bddObject = bddValue.toObject();

                    // On crée la bdd
                    BDD Bdd(bddObject["chemin de la bdd"].toString().toStdString());
                    profile.AddBDD(Bdd);
                }
                //On ajoute le profil à l'utilisateur
                user.AddProfile(profile);
            }
            //Puis on ajoute l'utilisateur à la liste d'utilisateurs
            Data::addUser(user);
        }

        //Si tout s'est bien passé
        return true;
    }

    //Si le fichier n'est pas au bon format
    return false;
}

//** Fonction sauvegardant toutes les données de tous les utilisateurs dans un fichier Json **//
bool ReadWriteJson::writeJson()
{
    QJsonArray all;
    //On parcourt la liste des utilisateurs
    for(auto Util : Data::getUsers())
    {
        // On crée l'utilisateur
        QJsonObject account;
        // On enregistre les premières informations le concernant
        account["nom"] = QString::fromStdString(Util.getLastName());
        account["prenom"] = QString::fromStdString(Util.getFirstName());
        account["identifiant"] = QString::fromStdString(Util.getIdentifier());
        account["motDePasse"] = QString::fromStdString(Util.getPassword());
        account["admin"] = QString::number(Util.getAdmin());

        //On parcourt tous les profils de l'utilisateur
        QJsonArray profilesArray;
        for (auto profile : Util.getProfiles())
        {
            QJsonObject profileObject;
            profileObject["Le nom du profil"] = QString::fromStdString(profile.getName());

            //On parcourt tous les bdds du profil de l'utilisateur
            QJsonArray databasesArray;
            for (auto database : profile.getBDDs())
            {
                QJsonObject databaseObject;
                databaseObject["chemin de la bdd"] = QString::fromStdString(database.getPath());
                databasesArray.append(databaseObject);
            }

            profileObject["Les BDDs"] = databasesArray;
            profilesArray.append(profileObject);
        }

        account["profiles"] = profilesArray;
        all.append(account);
    }

    QJsonObject AllObjects;
    AllObjects["users"] = all;
    QJsonDocument doc(AllObjects);

    // Si non trouvé, le programme va créer le fichier
    QFile file("Users.json");
    // On ouvre le fichier en écriture seule
    if (file.open(QIODevice::WriteOnly))
    {
        file.write(doc.toJson());
        file.close();
    }
    else
    {
        //Si jamais il y a des problèmes avec des permissions
        qDebug() << "Impossible d'ouvrir le fichier pour l'enregistrement.";
        return false;
    }

    return true;
}

#include "ReadWriteJson.h"
#include "User.h"
#include "Data.h"
#include <iostream>

bool ReadWriteJson::readJson()
{
    QByteArray val;
    QFile file;
    file.setFileName("Users.json");
    //Si le fichier n'existe pas
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Le fichier n'existe pas";
        //On termine le programme en remontant l'erreur
        return false;
    }
    val = file.readAll();
    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(val);
    QJsonObject sett2 = doc.object();
    QJsonValue value = sett2.value(QString("appName"));
    QJsonObject item = value.toObject();

    //******* Programme Martin *******//
    // Vérifier si l'objet racine contient la clé "users"
    if (rootObject.contains("users") && rootObject["users"].isArray()) {

        // Obtenir le tableau des utilisateurs et le parcourir
        QJsonArray usersArray = rootObject["users"].toArray();
        for (const QJsonValue &userValue : usersArray) {
            QJsonObject userObject = userValue.toObject();

            // l'ajouter
            User *user = new User(userObject.value("login").toString(), userObject.value("password").toString());
            allUsers.append(user);

            // parcourir ses profiles:
            QJsonArray profilesArray = userObject["profiles"].toArray();
            for (const QJsonValue &profileValue : profilesArray) {
                QJsonObject profileObject = profileValue.toObject();

                // l'ajouter
                Profile profile(profileObject.value("name").toString());
                user->addProfile(profile);
            }
        }
    }
    //******* Programme Martin *******//

    return true;
}

bool ReadWriteJson::writeJson()
{
    //******* A effacer *******//
    // Créer un objet Utilisateur
    User Gilbert = User("Gilbert", "Dorian", "AdminG", "passwordG");
    User Beunas = User("Beunas", "Antoine", "AdminB", "passwordB");
    vector<User> Liste;
    Liste.push_back(Gilbert);
    Liste.push_back(Beunas);
    //******* A effacer *******//

    QJsonArray all;
    QJsonObject account;
    QJsonArray profiles;
    //for(unsigned int j = 0; j < Liste.size(); j++)
    for(User Util : Data::getUsers())
    {
        for (unsigned int i = 0; i < Util.getProfiles().size(); i++)
        {
            profiles.append(QString::fromStdString(Util.getProfiles()[i].getName()));
        }
        account["nom"] = QString::fromStdString(Util.getLastName());
        account["prenom"] = QString::fromStdString(Util.getFirstName());
        account["identifiant"] = QString::fromStdString(Util.getIdentifier());
        account["motDePasse"] = QString::fromStdString(Util.getPassword());
        account["profils"]=profiles;
        all.append(account);
    }

    //Pour créer le document Json accueillant les objets précédemment crées
    QByteArray ba = QJsonDocument(all).toJson();

    //******* A effacer *******//
    //Pour afficher le resultat sur la console
    QTextStream ts(stdout);
    std::cout << "rendered JSON" << std::endl;
    ts << ba;
    //******* A effacer *******//

    //Si non trouvé, le programme va créer le fichier
    QFile file("Users.json");
    //On ouvre le fichier en écriture seule
    if (file.open(QIODevice::WriteOnly))
    {
        //Puis on écrit à l'intérieur de ce fichier le contenu du document Json.
        file.write(ba);
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

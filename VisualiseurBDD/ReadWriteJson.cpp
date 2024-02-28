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

    //******* A effacer *******//
    //Pour afficher le resultat sur la console
    QTextStream ts(stdout);
    std::cout << "rendered JSON" << std::endl;
    ts << val;
    //******* A effacer *******//

    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(val);
    QJsonObject AllObjects = doc.object();

    //On verifie que l'on a bien un objet et que ce dernier possède bien le mot clé "users", attestant que le fichier est bien lue et sous un bon format
    if (AllObjects.contains("users") && AllObjects["users"].isArray())
    {
        //On retrouve la liste de users
        QJsonArray all = AllObjects["users"].toArray();
        //On parcourt chaque user dans la liste
        for (const QJsonValue &userValue : all)
        {
            //On transforme ces users sous format Json
            QJsonObject userObject = userValue.toObject();
            //Afin de les créer
            User user = User(userObject.value("nom").toString().toStdString(), userObject.value("prenom").toString().toStdString(), userObject.value("identifiant").toString().toStdString(), userObject.value("motDePasse").toString().toStdString(), false);

            //On va ensuite parcourir les profils du user venant d'être ajouté
            QJsonArray profilesArray = userObject["profils"].toArray();
            for (const QJsonValue &profileValue : profilesArray)
            {
                //On ajoute le profil
                Profile profile(profileValue.toString().toStdString());
                cout << profile.getName();
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

bool ReadWriteJson::writeJson()
{
    QJsonArray all;
    QJsonObject account;
    QJsonArray profiles;
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
    QJsonObject AllObjects;
    AllObjects["users"] = all;
    QByteArray ba = QJsonDocument(AllObjects).toJson();

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

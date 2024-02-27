#include "ReadWriteJson.h"
#include "User.h"
#include "Data.h"
#include <iostream>

int ReadWriteJson::readJson()
{
    QString val;
    QFile file;
    file.setFileName("Users.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    qWarning() << val;
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();
    QJsonValue value = sett2.value(QString("appName"));
    //qWarning() << value;
    QJsonObject item = value.toObject();
    //qWarning() << tr("QJsonObject of description: ") << item;

    /* in case of string value get value and convert into string*/
    //qWarning() << tr("QJsonObject[appName] of description: ") << item["description"];
    //QJsonValue subobj = item["description"];
    //qWarning() << subobj.toString();

    /* in case of array get array and convert into string*/
    //qWarning() << tr("QJsonObject[appName] of value: ") << item["imp"];
    //QJsonArray test = item["imp"].toArray();
    //qWarning() << test[1].toString();

    return 0;
}

int ReadWriteJson::writeJson()
{
    // Créer un objet Utilisateur
    User Gilbert = User("Gilbert", "Dorian", "AdminG", "passwordG");
    User Beunas = User("Beunas", "Antoine", "AdminB", "passwordB");
    vector<User> Liste;
    Liste.push_back(Gilbert);
    Liste.push_back(Beunas);

    QJsonArray all;
    QJsonObject account;
    QJsonArray profiles;
    for(unsigned int j = 0; j < Liste.size(); j++)
    {
        for (unsigned int i = 0; i < Liste[j].getProfiles().size(); i++)
        {
            profiles.append(QString::fromStdString(Liste[j].getProfiles()[i].getName()));
        }
        account["nom"] = QString::fromStdString(Liste[j].getLastName());
        account["prenom"] = QString::fromStdString(Liste[j].getFirstName());
        account["identifiant"] = QString::fromStdString(Liste[j].getIdentifier());
        account["motDePasse"] = QString::fromStdString(Liste[j].getPassword());
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
    }

    return 0;
}

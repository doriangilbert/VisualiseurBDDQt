#include "ReadWriteJson.h"
#include "User.h"
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

    // Créer un objet JSON pour stocker un utilisateur
    QJsonObject account1;
    QJsonObject profiles1;
    profiles1["defaut"]="Default";
    profiles1["bonjour"]="Hello";
    account1["nom"] = QString::fromStdString(Gilbert.getLastName());
    account1["prenom"] = QString::fromStdString(Gilbert.getFirstName());
    account1["identifiant"] = QString::fromStdString(Gilbert.getIdentifier());
    account1["motDePasse"] = QString::fromStdString(Gilbert.getPassword());
    account1["profils"]=profiles1;

    //On en crée un 2ème
    QJsonObject account2;
    QJsonObject profiles2;
    profiles2["defaut"]="Default";
    profiles2["bonjour"]="Hello";
    account2["nom"] = QString::fromStdString(Beunas.getLastName());
    account2["prenom"] = QString::fromStdString(Beunas.getFirstName());
    account2["identifiant"] = QString::fromStdString(Beunas.getIdentifier());
    account2["motDePasse"] = QString::fromStdString(Beunas.getPassword());
    account2["profils"]=profiles2;

    //On met les 2 objets dans une liste
    //vector<QJsonObject> qListe;
    //qListe.push_back(account1);
    //qListe.push_back(account2);

    //Pour créer le document Json accueillant les objets précédemment crées
    QByteArray ba = QJsonDocument(account1).toJson();

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

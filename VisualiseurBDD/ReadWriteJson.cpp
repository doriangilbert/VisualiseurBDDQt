#include "ReadWriteJson.h"
//#include "User.h"

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
    qWarning() << value;
    QJsonObject item = value.toObject();
    //qWarning() << tr("QJsonObject of description: ") << item;

    /* in case of string value get value and convert into string*/
    //qWarning() << tr("QJsonObject[appName] of description: ") << item["description"];
    QJsonValue subobj = item["description"];
    qWarning() << subobj.toString();

    /* in case of array get array and convert into string*/
    //qWarning() << tr("QJsonObject[appName] of value: ") << item["imp"];
    QJsonArray test = item["imp"].toArray();
    qWarning() << test[1].toString();

    return 0;
}

int ReadWriteJson::writeJson()
{
    // Créer un objet Utilisateur
    //User Gilbert = User("Gilbert", "Dorian", "AdminG", "passwordG");
    //User Beunas = User("Beunas", "Antoine", "AdminB", "passwordB");

    // Créer un objet JSON à partir de l'objet Utilisateur
    QJsonObject account;
    account["nom"] = "Gibert";
    account["prenom"] = "Dorian";
    account["identifiant"] = "AdminG";
    account["motDePasse"] = "passwordG";

    QJsonObject profiles;
    profiles["Defaut"]="Default";
    profiles["Bonjour"]="Hello";
    account["Profils"]=profiles;

    //QJsonDocument jsonDoc(account);


    QByteArray ba = QJsonDocument(account).toJson();
    QTextStream ts(stdout);
    ts << "rendered JSON" << Qt::endl;
    ts << ba;
    QFile fout("Users.json");
    if (fout.open(QIODevice::WriteOnly))
    {
        fout.write(ba);
    }
    else
    {
        qDebug() << "Impossible d'ouvrir le fichier pour l'enregistrement.";
    }

    return 0;

    // Enregistrer l'objet JSON dans un fichier
    /*QFile file("Users.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(jsonDoc.toJson());
        file.close();
        qDebug() << "L'objet Utilisateur a été enregistré avec succès dans le fichier JSON.";
    } else {
        qDebug() << "Impossible d'ouvrir le fichier pour l'enregistrement.";
    }*/



    /*QJsonDocument jsonDoc(jsonObject);
    // Enregistrer l'objet JSON dans un fichier
    QFile file("Users.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(jsonDoc.toJson());
        file.close();
        qDebug() << "L'objet Utilisateur a été enregistré avec succès dans le fichier JSON.";
    } else {
        qDebug() << "Impossible d'ouvrir le fichier pour l'enregistrement.";
    }

    return 0;
    //return a.exec();*/
}

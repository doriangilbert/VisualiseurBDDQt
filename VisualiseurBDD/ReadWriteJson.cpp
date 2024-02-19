#include "ReadWriteJson.h"

class Utilisateur {
public:
    QString nom;
    QString email;
    int age;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Créer un objet Utilisateur
    Utilisateur user;
    user.nom = "John Doe";
    user.email = "john.doe@example.com";
    user.age = 30;

    // Créer un objet JSON à partir de l'objet Utilisateur
    QJsonObject jsonObj;
    jsonObj["nom"] = user.nom;
    jsonObj["email"] = user.email;
    jsonObj["age"] = user.age;

    QJsonDocument jsonDoc(jsonObj);

    // Enregistrer l'objet JSON dans un fichier
    QFile file("utilisateur.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(jsonDoc.toJson());
        file.close();
        qDebug() << "L'objet Utilisateur a été enregistré avec succès dans le fichier JSON.";
    } else {
        qDebug() << "Impossible d'ouvrir le fichier pour l'enregistrement.";
    }

    return a.exec();
}
ReadWriteJson::ReadWriteJson()
{

}

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
    qWarning() << tr("QJsonObject of description: ") << item;

    /* in case of string value get value and convert into string*/
    qWarning() << tr("QJsonObject[appName] of description: ") << item["description"];
    QJsonValue subobj = item["description"];
    qWarning() << subobj.toString();

    /* in case of array get array and convert into string*/
    qWarning() << tr("QJsonObject[appName] of value: ") << item["imp"];
    QJsonArray test = item["imp"].toArray();
    qWarning() << test[1].toString();

    return 0;
}

int ReadWriteJson::writeJson()
{
    QJsonDocument jsonDoc(jsonObject);
    // Enregistrer l'objet JSON dans un fichier
    QFile file("utilisateur.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(jsonDoc.toJson());
        file.close();
        qDebug() << "L'objet Utilisateur a été enregistré avec succès dans le fichier JSON.";
    } else {
        qDebug() << "Impossible d'ouvrir le fichier pour l'enregistrement.";
    }

    return a.exec();
}

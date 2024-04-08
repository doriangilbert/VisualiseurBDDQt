#include "Profile.h"
#include <QFileInfo>

//** Construteur par défaut **//
Profile::Profile()
{

}

//** Le construction de confort de la classe. **//
//** Nous indiquons le nom du profil **//
Profile::Profile(string name)
{
    this->name = name;
}

//** Getter de l'attribut name **//
string Profile::getName()
{
    return this->name;
}

//** Setter de l'attribut name **//
void Profile::setName(string name)
{
    this->name = name;
}

//** Getter de l'attribut profiles **//
vector<BDD> Profile::getBDDs()
{
    return this->BDDs;
}

//** Setter de l'attribut profiles **//
void Profile::setBDDs(vector<BDD> BDDs)
{
    this->BDDs = BDDs;
}

//** Fonction ajoutant une base de données à la liste de bdds du profil utilisateur **//
/* Si une bdd identique (même chemin) existe déjà dans la liste de bdds
 * du profil, on n'ajoute pas la bdd et on renvoie true comme booleen */
/* Si aucune bdd du profil ne correspond à la nouvelle bdd que l'on veut ajouter
 * on l'ajoute et on renvoie comme booleen false */
bool Profile::AddBDD(BDD bdd)
{
    // On ne garde que le nom du fichier de la bdd à ajouter pour la comparaison
    QFileInfo fileInfoBdd(QString::fromStdString(bdd.getPath()));
    QString fileNameBdd = fileInfoBdd.fileName();

    bool found = false;
    //On cherche si une BDD identique existe déjà
    for (BDD bdds: this->BDDs)
    {
        // On ne garde que le nom du fichier à comparer
        QFileInfo fileInfo(QString::fromStdString(bdds.getPath()));
        QString fileName = fileInfo.fileName();

        //Si on en trouve une, on change le booleen
        if (fileName == fileNameBdd)
        {
            found = true;
        }
    }
    //Si on n'en a pas trouvé, on peut la rajouter
    if (found == false)
    {
        this->BDDs.push_back(bdd);
    }
    //On retourne le booleen pour connaître et afficher le résultat de cette fonction
    return found;
}

//** Fonction supprimant une bdd de la liste de bdds du profil utilisateur **//
void Profile::RemoveBDD(string fileName)
{
    for (size_t i = 0; i < this->BDDs.size(); i++)
    {
        // On ne garde que le nom du fichier que l'on veut enlever
        QFileInfo fileInfoBdd(QString::fromStdString(this->BDDs[i].getPath()));
        QString fileNameBdd = fileInfoBdd.fileName();

        if (fileNameBdd == QString::fromStdString(fileName))
        {
            this->BDDs.erase(this->BDDs.begin() + i);
        }
    }
}

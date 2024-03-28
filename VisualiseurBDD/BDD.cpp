#include "BDD.h"

//** Construteur par défaut **//
BDD::BDD()
{

}

//** Le construction de confort de la classe. **//
//** Nous indiquons le chemin de la BDD **//
BDD::BDD(string path)
{
    this->path = path;
}

//** Getter de l'attribut path **//
string BDD::getPath()
{
    return this->path;
}

//** Setter de l'attribut path **//
void BDD::setPath(string path)
{
    this->path = path;
}

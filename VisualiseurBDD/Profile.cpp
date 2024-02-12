#include "Profile.h"

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

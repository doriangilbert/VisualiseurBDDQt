#include "User.h"

//** Construteur par défaut **//
User::User()
{

}

//** Le constructeur de confort de la classe. **//
//** Nous renseignons tous les attributs nécessaires **//
User::User(string lastName, string firstName, string identifier, string password, bool news)
{
    this->lastName = lastName;
    this->firstName = firstName;
    this->identifier = identifier;
    this->password = password;
    if (news == true)
    {
        Profile defaut = Profile("Defaut");
        this->profiles = vector<Profile>{defaut};
    }
}

//** Getter de l'attribut lastName **//
string User::getLastName()
{
    return this->lastName;
}

//** Setter de l'attribut lastName **//
void User::setLastName(string lastName)
{
    this->lastName = lastName;
}

//** Getter de l'attribut firstName **//
string User::getFirstName()
{
    return this->firstName;
}

//** Setter de l'attribut firstName **//
void User::setFirstName(string firstName)
{
    this->firstName = firstName;
}

//** Getter de l'attribut identifier **//
string User::getIdentifier()
{
    return this->identifier;
}

//** Setter de l'attribut identifier **//
void User::setIdentifier(string identifier)
{
    this->identifier = identifier;
}

//** Getter de l'attribut password **//
string User::getPassword()
{
    return this->password;
}

//** Setter de l'attribut password **//
void User::setPassword(string password)
{
    this->password = password;
}

//** Getter de l'attribut profiles **//
vector<Profile> User::getProfiles()
{
    return this->profiles;
}

//** Setter de l'attribut profiles **//
void User::setProfiles(vector<Profile> profiles)
{
    this->profiles = profiles;
}


//** Fonction ajoutant un profil à la liste de profils de l'utilisateur **//
/* Si un profil identique (même nom de profil) existe déjà dans la liste de profils
 * de l'utilisateur, on n'ajoute pas le profil et on renvoie true comme booleen */
/* Si aucun profil de l'utilisateur ne correspond au nouveau profil que l'on veut ajouter
 * on l'ajoute et on renvoie comme booleen false */
bool User::AddProfile(Profile profile)
{
    bool found = false;
    //On cherche si un profil identique existe déjà
    for (Profile profil: this->profiles)
    {
        //Si on en trouve un, on change le booleen
        if (profil.getName() == profile.getName())
        {
            found = true;
        }
    }
    //Si on n'en a pas trouvé, on peut le rajouter
    if (found == false)
    {
        this->profiles.push_back(profile);
    }
    //On retourne le booleen pour connaître et afficher le résultat de cette fonction
    return found;
}

//** Fonction supprimant un profil de la liste de profils de l'utilisateur **//
void User::RemoveProfile(Profile profile)
{
    for (size_t i = 0; i < this->profiles.size(); i++)
    {
        if (this->profiles[i].getName() == profile.getName())
        {
            this->profiles.erase(this->profiles.begin() + i);
        }
    }
}

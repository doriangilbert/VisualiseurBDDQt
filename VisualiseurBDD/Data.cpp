#include "Data.h"

//** Initialisation des attributs statiques **//
vector<User> Data::users;
User Data::currentUser;
Profile Data::currentProfile;

//** Getter de l'attribut users **//
vector<User> Data::getUsers()
{
    return users;
}

//** Setter de l'attribut users **//
void Data::setUsers(vector<User> newUsers)
{
    users = newUsers;
}

//** Getter de l'attribut currentUser **//
User Data::getCurrentUser()
{
    return currentUser;
}

//** Setter de l'attribut currentUser **//
void Data::setCurrentUser(User newCurrentUser)
{
    currentUser = newCurrentUser;
}

//** Getter de l'attribut currentProfile **//
Profile Data::getCurrentProfile()
{
    return currentProfile;
}

//** Setter de l'attribut currentProfile **//
void Data::setCurrentProfile(Profile newCurrentProfile)
{
    currentProfile = newCurrentProfile;
}

//** Méthode permettant d'ajouter un utilisateur **//
void Data::addUser(User newCurrentUser)
{
    //** Ajout de l'utilisateur à la liste des utilisateurs **//
    users.push_back(newCurrentUser);
}

//** Méthode permettant de supprimer un utilisateur **//
void Data::deleteUser(string userId) {
    //** Parcours de la liste des utilisateurs **//
    for (size_t i = 0 ; i < users.size() ; i++) {
        //** Si l'utilisateur correspond à l'identifiant passé en paramètre **//
        if (users[i].getIdentifier() == userId) {
            //** Suppression de l'utilisateur **//
            users.erase(users.begin()+i);
        }
    }
}

//** Constructeur de la classe Data **//
Data::Data() {}

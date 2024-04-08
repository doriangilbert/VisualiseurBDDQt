#ifndef DATA_H
#define DATA_H

#include "User.h"
#include "Profile.h"

//** Classe Data stockant les données courantes de l'application **//
class Data
{
private:
    //** Attribut vecteur stockant les utilisateurs de l'application **//
    static vector<User> users;
    //** Attribut stockant l'utilisateur courant **//
    static User currentUser;
    //** Attribut stockant le profil courant **//
    static Profile currentProfile;
    //** Attribut stockant la BDD courante **//
    static BDD currentBDD;

public:
    //** Constructeur de la classe Data **//
    Data();
    //** Getter de l'attribut users **//
    static vector<User> getUsers();
    //** Setter de l'attribut users **//
    static void setUsers(vector<User> newUsers);
    //** Getter de l'attribut currentUser **//
    static User getCurrentUser();
    //** Setter de l'attribut currentUser **//
    static void setCurrentUser(User newCurrentUser);
    //** Getter de l'attribut currentProfile **//
    static Profile getCurrentProfile();
    //** Setter de l'attribut currentProfile **//
    static void setCurrentProfile(Profile newCurrentProfile);
    //** Getter de l'attribut currentBDD **//
    static BDD getCurrentBDD();
    //** Setter de l'attribut currentBDD **//
    static void setCurrentBDD(BDD newCurrentBDD);
    //** Méthode permettant d'ajouter un utilisateur **//
    static void addUser(User newCurrentUser);
    //** Méthode permettant de supprimer un utilisateur **//
    static void deleteUser(string userId);
};

#endif // DATA_H

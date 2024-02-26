#ifndef USER_H
#define USER_H

#include "Profile.h"
#include <vector>       // std::vector


class User
{
private:
    //** Attributs **//
    string lastName;
    string firstName;
    string identifier;
    string password;
    vector<Profile> profiles;

public:
    //** Constructeurs **//
    User();
    User(string lastName, string firstName, string identifier, string password);

    //** Getter et Setter **//
    string getLastName();
    void setLastName(string lastName);
    string getFirstName();
    void setFirstName(string firstName);
    string getIdentifier();
    void setIdentifier(string identifier);
    string getPassword();
    void setPassword(string password);
    vector<Profile> getProfiles();
    void setProfiles(vector<Profile> profiles);

    //** Methodes **//
    bool AddProfile(Profile profile);
    void RemoveProfile(Profile profile);
};

#endif // USER_H

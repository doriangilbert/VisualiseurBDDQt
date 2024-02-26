#ifndef PROFILE_H
#define PROFILE_H

#include <string>
using namespace std;

class Profile
{
private:
    //** Attributs **//
    string name;

public:
    //** Constructeurs **//
    Profile();
    Profile(string name);

    //** Getter et Setter **//
    string getName();
    void setName(string name);

    //** Methodes **//
};

#endif // PROFILE_H

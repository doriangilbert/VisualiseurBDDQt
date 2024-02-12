#ifndef PROFILE_H
#define PROFILE_H

#include <string>
using namespace std;

class Profile
{
private:
    //** Attributes **//
    string name;

public:
    //** Constructor **//
    Profile(string name);

    //** Getter and Setter **//
    string getName();
    void setName(string name);

    //** Methods **//
};

#endif // PROFILE_H

#ifndef PROFILE_H
#define PROFILE_H

#include <string>
#include <vector>       // std::vector
#include "BDD.h"
using namespace std;

class Profile
{
private:
    //** Attributs **//
    string name;
    vector<BDD> BDDs;

public:
    //** Constructeurs **//
    Profile();
    Profile(string name);

    //** Getter et Setter **//
    string getName();
    void setName(string name);
    vector<BDD> getBDDs();
    void setBDDs(vector<BDD> BDDs);

    //** Methodes **//
    bool AddBDD(BDD bdd);
    void RemoveBDD(string fileName);
};

#endif // PROFILE_H

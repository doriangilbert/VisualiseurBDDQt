#ifndef BDD_H
#define BDD_H

#include <string>
using namespace std;

class BDD
{
private:
    //** Attributs **//
    string path;

public:
    //** Constructeurs **//
    BDD();
    BDD(string path);

    //** Getter et Setter **//
    string getPath();
    void setPath(string path);

    //** Methodes **//
};

#endif // BDD_H

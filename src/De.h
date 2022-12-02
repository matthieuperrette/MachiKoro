#pragma once
#include "Carte.h"*


//********************Structures et variables nécessaires*****************//
class DeException {
private:
    string info;
public:
    DeException(const string& i) :info(i) {}
    string getInfo() const { return info; }
};
//********************Structures et variables nécessaires*****************//

//****************class De*******************//
class De {
private:
    unsigned int min;
    unsigned int max;
public:
    De(unsigned int m, unsigned int M) : min(m), max(M) {}
    unsigned int getMin() const { return min; }
    unsigned int getMax() const { return max; }
    unsigned int lancerDe() const;
};
//****************class De*******************//

//****************Fonctions supplémentaires******************//
ostream& operator<<(ostream& f, const De& d);
//****************Fonctions supplémentaires******************//
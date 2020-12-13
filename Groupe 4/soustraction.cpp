#include "soustraction.h"
#include <iostream>

using namespace std;

soustraction::soustraction()
{
    _operateur="-";
}

soustraction::soustraction(expression *x, expression *y){

    _opG = x;
    _opD = y;
}

void soustraction::afficherClassique(ostream &reference){

    _opG->afficherClassique(reference);
    reference<< "-";
    _opD->afficherClassique(reference);
}

void soustraction::afficherPolonaise(ostream &reference){

    _opG->afficherClassique(reference);
    reference<< " ";
    _opD->afficherClassique(reference);
    reference<< " -" <<endl;
}

float soustraction::calculer(){

    try {
        return _opG->calculer() - _opD->calculer();
    }  catch (...) {
        throw "undefined";
    }
}


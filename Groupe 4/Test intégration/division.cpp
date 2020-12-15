#include "division.h"
#include <iostream>

using namespace std;

division::division()
{
    _operateur="/";
}

division::division(expression *x, expression *y){
    _opG = x;
    _opD = y;
}

void division::afficherClassique(ostream &reference){

    _opG->afficherClassique(reference);
    reference<< "/";
    _opD->afficherClassique(reference);
}

void division::afficherPolonaise(ostream &reference){

    _opG->afficherClassique(reference);
    reference<< " ";
    _opD->afficherClassique(reference);
    reference<< " /" <<endl;
}

float division::calculer(){

    try {
        return _opG->calculer() / _opD->calculer();
    }  catch (...) {
        throw "undefined";
    }
}

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

void soustraction::afficher(ostream &reference){

    reference << _opG << "-" << _opD;
}

float soustraction::calculer(){

    return _opG->calculer() - _opD->calculer();
}


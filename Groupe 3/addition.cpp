#include "addition.h"
#include <iostream>

using namespace std;

addition::addition(){
    _operateur = "+";
}

addition::addition(expression *x, expression *y){

    _opG = x;
    _opD = y;
}

void addition::afficherPolonaise(ostream &reference){

    _opG->afficherPolonaise(reference);
    reference<< " ";
    _opD->afficherPolonaise(reference);
    reference<< " +";
}

void addition::afficherClassique(ostream &reference){

    _opG->afficherClassique(reference);
    reference<< "+";
    _opD->afficherClassique(reference);
}



float addition::calculer(){

    return _opG->calculer() + _opD->calculer();
}


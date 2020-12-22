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

void division::afficherPolonaise(ostream &reference){

    _opG->afficherPolonaise(reference);
    reference<< " ";
    _opD->afficherPolonaise(reference);
    reference<< " /" ;
}

void division::afficherClassique(ostream &reference){

    _opG->afficherClassique(reference);
    reference<< "/";
    _opD->afficherClassique(reference);


}



float division::calculer(){

    return _opG->calculer() / _opD->calculer();
}



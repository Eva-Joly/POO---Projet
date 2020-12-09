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

void addition::afficher(ostream &reference){

    reference<<endl;
}

float addition::calculer(){

    return _opG->calculer() + _opD->calculer();
}

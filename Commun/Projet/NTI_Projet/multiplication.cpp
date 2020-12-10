#include "multiplication.h"

#include <iostream>

using namespace std;

multiplication::multiplication(){
    _operateur = "/";
}

multiplication::multiplication(expression *x, expression *y){

    _opG = x;
    _opD = y;
}

void multiplication::afficher(ostringstream &reference){

    reference << "/" <<endl;
}

float multiplication::calculer(){

    return _opG->calculer() / _opD->calculer();
}

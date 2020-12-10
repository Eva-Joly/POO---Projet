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

void division::afficher(ostream &reference){

    reference<<endl;
}

float division::calculer(){

    return _opG->calculer() / _opD->calculer();
}

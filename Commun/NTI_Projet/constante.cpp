#include "constante.h"

#include <iostream>
using namespace std;

constante::constante(){

}

constante::constante(float x){
    _valeur = x;
}

void constante::afficherClassique(ostream &reference){
    reference<<endl;
}

void constante::afficherPolonaise(ostream &reference){
    reference<<endl;
}

float constante::calculer(){

    return _valeur;
}

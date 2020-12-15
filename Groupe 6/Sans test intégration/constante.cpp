#include "constante.h"

#include <iostream>
using namespace std;

constante::constante(){

}

constante::constante(float x){
    _valeur = x;
}

void constante::afficherClassique(ostream &reference){
    reference << _valeur;
}

void constante::afficherPolonaise(ostream &reference){
    reference << _valeur;
}

float constante::calculer() const
{

    return _valeur;
}

#include "constante.h"

#include <iostream>
using namespace std;

constante::constante(){

}

constante::constante(float x){
    _valeur = x;
}

void constante::afficherPolonaise(ostream &reference){
    reference << _valeur;
}

void constante::afficherClassique(ostream &reference){
    reference << _valeur;
}



float constante::calculer(){

    return _valeur;
}


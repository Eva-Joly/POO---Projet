#ifndef ADDITION_H
#define ADDITION_H

#include "operateur.h"
#include "expression.h"

class addition : public operateur
{
public:
    addition();
    addition(expression *x, expression *y);
    float calculer();
    void afficherPolonaise(ostream &reference);
    void afficherClassique(ostream &reference);


};

#endif // ADDITION_H

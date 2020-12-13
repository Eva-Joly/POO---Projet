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
    void afficherClassique(ostream &reference);
    void afficherPolonaise(ostream &reference);
};

#endif // ADDITION_H

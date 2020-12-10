#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "expression.h"
#include "operateur.h"

class multiplication : public operateur
{
public:
    multiplication();
    multiplication(expression *x, expression *y);
    float calculer();
    void afficherClassique(ostream &reference);
    void afficherPolonaise(ostream &reference);
};

#endif // MULTIPLICATION_H

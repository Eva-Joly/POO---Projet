#ifndef DIVISION_H
#define DIVISION_H

#include "operateur.h"
#include "expression.h"

class division : public operateur
{
public:
    division();
    division(expression *x, expression *y);
    float calculer();
    void afficher(ostream &reference);
};

#endif // DIVISION_H

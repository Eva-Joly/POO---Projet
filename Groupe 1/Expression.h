#include <iostream>
#include <stack>
#include <string>
#include "Adition.h"


#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

class Expression
{
    public:

    //Constructeur :
        Expression();

    //Destructeur :
        virtual ~Expression();

    //Méthodes :
        static Expression SaisieExpression();

    public:
        Constante fCte;
        Adition eAdition;
        Soustraction eSoustraction;
        Division eDivision;
        Multiplication eMultiplication;

};


#endif // CLASSES_H_INCLUDED

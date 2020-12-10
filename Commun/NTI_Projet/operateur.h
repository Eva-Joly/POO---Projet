#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "expression.h"
#include <string>

using namespace std;

class operateur : public expression
{

public:
    operateur();

protected:
    expression *_opG;
    expression *_opD;
    string _operateur;

};

#endif // OPERATEUR_H

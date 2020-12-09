#ifndef EXPRESSION_H
#define EXPRESSION_H


#include <ostream>
using namespace std;

class expression
{
public:
    expression();
    virtual float calculer()=0;
    virtual void afficher(ostream &reference)=0;
};
#endif // EXPRESSION_H

#ifndef EXPRESSION_H
#define EXPRESSION_H


#include <ostream>
using namespace std;

class expression
{
public:
    expression();
    virtual float calculer()=0;
    virtual void afficherClassique(ostream &reference)=0;
    virtual void afficherPolonaise(ostream &reference)=0;
    static Expression Creer();
    
    //Attributs :
};
#endif // EXPRESSION_H

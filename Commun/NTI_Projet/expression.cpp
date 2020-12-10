#include "expression.h"

expression::expression()
{

}

Expression Expression::Creer()
{
    std::string sUtilisateur;
    std::stack<Expression*> PileExpression;

    do
    {
        system("cls");
        cout << "Entrez un caractere : " << endl;
        cin >> sUtilisateur;
        if (isdigit(sUtilisateur(0)))
        {
            Constante *C = new Constante(stof(sUtilisateur));
            PileExpression.push(C);
        }
        else if (sUtilisateur(0)=='+')
        {
            Expression *E = PileExpression.top();
            PileExpression.pop();
            Expression *E1 = PileExpression.top();
            PileExpression.pop();
            Adition *A = new Adition(E,E1);
            PileExpression.push(A);
        }
        else if (sUtilisateur(0)=='*')
        {
            Expression *E = PileExpression.top();
            PileExpression.pop();
            Expression *E1 = PileExpression.top();
            PileExpression.pop();
            Multiplication *A = new Multiplication(E,E1);
            PileExpression.push(A);
        }
        else if (sUtilisateur(0)=='/')
        {
            Expression *E = PileExpression.top();
            PileExpression.pop();
            Expression *E1 = PileExpression.top();
            PileExpression.pop();
            Division *A = new Division(E,E1);
            PileExpression.push(A);
        }
        else if (sUtilisateur(0)=='-')
        {
            Expression *E = PileExpression.top();
            PileExpression.pop();
            Expression *E1 = PileExpression.top();
            PileExpression.pop();
            Soustraction *A = new Soustraction(E,E1);
            PileExpression.push(A);
        }
        cout << "Caracteres ajoutes : " << sUtilisateur << endl;
    }
    while (sUtilisateur != 'f');
    return PileExpression.top;
}

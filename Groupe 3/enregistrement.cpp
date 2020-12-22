#include "enregistrement.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <QApplication>
#include <QTextEdit>
#include <map>
#include <set>
#include <stack>

using namespace std;

struct ExpressionChargee_
{
    string expr_;
    string op_;
};

void enregistrement(operateur &a  ){
    QTextEdit *txt = new QTextEdit();

    ofstream file("test.txt");
    ostringstream ref;
    a.afficherPolonaise(ref);
    file << ref.str().c_str();
    file.close();
    txt->setText(ref.str().c_str());
   }


bool Ordonancement(const string& gauche, const string& droite, bool assoc)
{
    static const map<string, int> KNOWN({ { "+", 1 }, { "-", 1 }, { "*", 2 }, { "/", 2 }}); // En fonction de l'opérateur trouvé
    static const set<string> ASSOCIATIVE({ "+", "*" });
    return (KNOWN.count(gauche) ? KNOWN.find(gauche)->second : 0) < (KNOWN.count(droite) ? KNOWN.find(droite)->second : 0) + (assoc && !ASSOCIATIVE.count(droite) ? 1 : 0);
}
void Paretheses(ExpressionChargee_* expression, const string& token, bool assoc) //Reconstruction de l'expression avec les parenthèses pour plus de clareté
{
    if (!expression->op_.empty() && Ordonancement(expression->op_, token, assoc))
        expression->expr_ = '(' + expression->expr_ + ')';
}

void AddToken(stack<ExpressionChargee_>* expression, const string& token) //On "Pile" les éléments de la chaine
{
    if (token.find_first_of("0123456789") != string::npos)
        expression->push(ExpressionChargee_({ token, string() }));	// Nombre
    else
    {	// Operateur
        if (expression->size() < 2)
            cout<<"Stack underflow";
        auto rhs = expression->top();
        Paretheses(&rhs, token, false);
        expression->pop();
        auto lhs = expression->top();
        Paretheses(&lhs, token, true);
        expression->top().expr_ = lhs.expr_ + ' ' + token + ' ' + rhs.expr_ ;
        expression->top().op_ = token;
    }
}


string PolonaiseInverseToClassique(const string& chainePolo) //Reconstruction  de l'xpression sous la forme classique
{
    stack<ExpressionChargee_> stack;
    for (auto start = chainePolo.begin(), index = chainePolo.begin(); ; ++index)
    {
        if (index == chainePolo.end() || *index == ' ')
        {
            if (index > start)
                AddToken(&stack, string(start, index));
            if (index == chainePolo.end())
                break;
            start = index + 1;
        }
    }
    if (stack.size() != 1)
    {
        cout<<"Expression Incomplète";
    }

    return stack.top().expr_;
}


string chargement(string nomFichier)
{
    ifstream fichier(nomFichier);
    string expressionChargeePoloInv;
    string expressionChargeeClassique;
    getline(fichier, expressionChargeePoloInv);
    fichier.close();
    expressionChargeeClassique = PolonaiseInverseToClassique(expressionChargeePoloInv);
    return expressionChargeeClassique;
}

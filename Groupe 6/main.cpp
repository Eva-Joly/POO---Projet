#include "mainwindow.h"
#include "constante.h"
#include "addition.h"
#include "soustraction.h"
#include "multiplication.h"
#include "division.h"
#include "symboltable.h"
#include "grapheur2dmodel.h"
#include "grapheur2dview.h"
#include "grapheur2dcontroller.h"

#include <QApplication>
#include <sstream>
#include <QTextEdit>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextEdit *txt = new QTextEdit();

    constante c1(10);
    constante c2(20);

    addition add(&c1, &c2);
    soustraction sous(&c1, &c2);
    division div(&c1, &c2);


    ostringstream os;
    sous.afficherClassique(os);
    os<< "=" << sous.calculer();
    os << endl;
    sous.afficherPolonaise(os);

    // TEST INTEGRATION VARIABLES
    variable var("var");
    var.afficherClassique(os); // Test d'intégration : doit afficher "var"
    os << endl;
    var.afficherPolonaise(os); // Test d'intégration : doit afficher "var"
    //var.calculer(); // Test d'intégration : doit terminer le programme car execption de calcul non gérée
    constante c3(10);
    addition add_var(&c3, &var);
    //add_var.calculer(); // Test d'intégration : doit terminer le programme car execption de calcul non gérée
    soustraction sous_var(&c3, &var);
    //sous_var.calculer(); // Test d'intégration : doit terminer le programme car execption de calcul non gérée
    multiplication mult_var(&c3, &var);
    //mult_var.calculer(); // Test d'intégration : doit terminer le programme car execption de calcul non gérée
    division div_var(&c3, &var);
    //div_var.calculer(); // Test d'intégration : doit terminer le programme car execption de calcul non gérée
    // FIN TEST INTEGRATION VARIABLES

    //TEST INTEGRATION TABLE DE SYMBOLES
    SymbolTable paca;

    //Ajout de var à la table de symboles (nom: "var") par adresse
    paca.addVariable(&var);                         //<-- Utilise le MÊME objet (deleteVariable crashe dans notre cas, je (Tom Vautray) peux vous expliquer pourquoi, et quoi faire alors)
    paca.addVariable("bouchedurhone", 13.0);        //<-- Bonne pratique (créer l'objet décrit)

    //Doit terminer le programme lors des opérations car ici, l'objet est recrée (et pas passé par pointeur)
    //sym.addVariable(var);                         //<-- /!\ Copie l'objet /!\

    //Don de la valeur 83.0 à la variable nommée "var" de la table de symboles
    os << endl << endl << "Variable \"var\" bien modifiée: " << paca.setVariable("var", 83.0);

    //La table de symbole contient-elle des pointeurs nulls ?
    try {
        paca.checkConsistent();
    }  catch (...) {
        os << endl << "La table contient un pointeur vers rien.";
    }

    os << endl << "Contenu de la table de symboles: " << endl;
    paca.displayContent(os);

    //Dans le test d'intégration précédent, ces opérations auraient du terminer le processus, mais maintenant, avec la table de symboles, on a donné à "var" une valeur
    os << endl; add_var.afficherClassique(os); os << " = " << add_var.calculer(); // Test d'intégration : doit effectuer le calcul car "var" à à présent une valeur
    os << endl; sous_var.afficherClassique(os); os << " = " << sous_var.calculer(); // Test d'intégration : doit effectuer le calcul car "var" à à présent une valeur
    os << endl; mult_var.afficherClassique(os); os << " = " << mult_var.calculer(); // Test d'intégration : doit effectuer le calcul car "var" à à présent une valeur
    os << endl; div_var.afficherClassique(os); os << " = " << div_var.calculer(); // Test d'intégration : doit effectuer le calcul car "var" à à présent une valeur

    //Termine le programme: ("var" est crée en pile et non avec un new)
    //sym.deleteVariable("var");

    //Détruit le pointeur vers "var" dans la table de symbole (crée une fuite de mémoire si le pointeur est perdu en dehors aussi, c'est pas notre cas)
    paca.untrackVariable("var");

    //Par contre on peut faire çà parce que bouchedurhone est créé dynamiquement
    paca.deleteVariable("bouchedurhone");
    paca.deleteVariable("paris");   //<-- Ne fais rien car "paris" n'existait pas dans paca

    os << endl << endl << "Contenu de la table de symboles: " << endl;
    paca.displayContent(os);
    //FIN TEST SYMBOLES

    // TEST INTEGRATION GRAPHEUR 2D

    grapheur2dModel* graph2dModele = new grapheur2dModel(); // Définition du modèle à afficher dans le grapheur2d
    grapheur2dView* graph2dView = new grapheur2dView(graph2dModele); // Définition de la vue à qui permet d'afficher le modèle
    grapheur2dController* graph2dController = new grapheur2dController(graph2dModele); // Controller permettant de faire évoluer le modèle et l'affichage dans le temps

    MainWindow w; // On crée une fenêtre
    w.setCentralWidget(graph2dView); // On défini le grapheur2d comme widget principal de la fenêtre
    w.show(); // On affiche la fenêtre

    // FIN TEST INTEGRATION GRAPHEUR 2D

    txt->setText(os.str().c_str());
    txt->show();

    return a.exec();
}

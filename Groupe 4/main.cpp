#include "mainwindow.h"
#include "constante.h"
#include "addition.h"
#include "soustraction.h"
#include "multiplication.h"
#include "division.h"
#include "variable.h"
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

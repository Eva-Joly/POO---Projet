#include "grapheur2dcontroller.h"

grapheur2dController::grapheur2dController()
{

}

grapheur2dController::grapheur2dController(grapheur2dModel* model)
{
    _model = model;
    connect(this, &QTimer::timeout, this, &grapheur2dController::update);
    this->start(1000);
}

void grapheur2dController::update()
{
    static bool etat = false;

    QStringList list;

    if(etat)
    {
        _model->setTitle("Courbe de 10-x entre -20 et 80 avec 10 points");
        _model->setMin(-20);
        _model->setMax(80);
        _model->setNbPoints(10);

        // On défini l'expression font on veut afficher la courbe : 10-x
        constante* c1 = new constante(10);
        variable* v1 = new variable("x");
        soustraction* sous = new soustraction(c1, v1);
        _model->setExpression((expression*)sous);
        _model->setVariable(v1);
        _model->update();

        etat = false;
    }else{
        _model->setTitle("Courbe de 10+x entre 20 et 70 avec 25 points");
        _model->setMin(20);
        _model->setMax(70);
        _model->setNbPoints(25);

        // On défini l'expression font on veut afficher la courbe : 10+x
        constante* c1 = new constante(10);
        variable* v1 = new variable("x");
        addition* add = new addition(c1, v1);
        _model->setExpression((expression*)add);
        _model->setVariable(v1);
        _model->update();

        etat = true;
    }

    _model->update();
}

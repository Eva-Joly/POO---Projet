#ifndef GRAPHEUR2DMODEL_H
#define GRAPHEUR2DMODEL_H

#include <QLineSeries>
#include <QChart>
#include <iostream>

#include "expression.h"
#include "variable.h"

using namespace QtCharts;
using namespace std;

class grapheur2dModel
{
    public:
        // Constructeurs
        grapheur2dModel();

        // Setters
        void setExpression(expression* expression);
        void setTitle(QString title);
        void setNbPoints(int nbPoints);
        void setMin(float min);
        void setMax(float max);
        void setVariable(variable* variable);

        // Getters
        QChart* getChart();
        expression* getExpression();

        // Mise à jour du chart
        void update();
    private:

        // Stockage des points
        QLineSeries* _series;

        // Chart
        QChart* _chart;

        // Parametres du chart
        QString _title; // Titre du graph
        int _nbPoints; // Nombre de points de la courbe
        variable* _variable; // Variable qui est soumise à évolution
        float _min; // Début de l'interval d'évolution de la variable
        float _max; // Fin de l'interval d'évolution de la variable

        // Expression d'entrée
        expression* _expression;
};

#endif // GRAPHEUR2DMODEL_H

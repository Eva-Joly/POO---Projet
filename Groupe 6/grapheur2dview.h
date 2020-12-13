#ifndef GRAPHEUR2DVIEW_H
#define GRAPHEUR2DVIEW_H

#include <QChartView>

#include "grapheur2dmodel.h"

using namespace QtCharts;

class grapheur2dView : public QChartView
{
    public:
        // Constructeurs
        grapheur2dView();
        grapheur2dView(grapheur2dModel* model);
    private:
        grapheur2dModel* _model; // Adresse du modèle du grapheur2d
};

#endif // GRAPHEUR2DVIEW_H

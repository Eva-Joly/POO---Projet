#include "grapheur2dview.h"

grapheur2dView::grapheur2dView()
{
    this->setRenderHint(QPainter::Antialiasing);
}

grapheur2dView::grapheur2dView(grapheur2dModel* model) : QChartView(model->getChart())
{
    _model = model;
    this->setRenderHint(QPainter::Antialiasing);
}

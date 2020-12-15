#include "grapheur2dmodel.h"

grapheur2dModel::grapheur2dModel()
{
    _series = new QLineSeries();
    _chart = new QChart();
    _chart->addSeries(_series);
}

QChart* grapheur2dModel::getChart()
{
    return _chart;
}

void grapheur2dModel::setExpression(expression* expression)
{
    _expression = expression;
}

expression* grapheur2dModel::getExpression()
{
    return _expression;
}

void grapheur2dModel::setTitle(QString title)
{
    _title = title;
}

void grapheur2dModel::setNbPoints(int nbPoints)
{
    _nbPoints = nbPoints;
}

void grapheur2dModel::setMin(float min)
{
    _min = min;
}

void grapheur2dModel::setMax(float max)
{
    _max = max;
}

void grapheur2dModel::setVariable(variable* variable)
{
    _variable = variable;
}

void grapheur2dModel::update()
{
    delete _series;

    _series = new QLineSeries();
    _series->setPointsVisible(true);

    float step = (_max - _min)/(_nbPoints - 1);
    for(int i=0; i<_nbPoints; i++)
    {
        _variable->setValue(_min + i*step); // La valeur de la variable
        _series->append(_variable->getValue(), _expression->calculer());
        _variable->deleteValue();
    }

    _chart->legend()->hide();
    _chart->addSeries(_series);
    _chart->createDefaultAxes();
    _chart->setTitle(_title);
}

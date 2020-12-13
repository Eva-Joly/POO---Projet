#include "variable.h"

variable::variable()
{
    _title = nullptr;
    _value = 0;
    _isSet = false;
}

variable::variable(QString title)
{
    _title = title;
    _value = 0;
    _isSet = false;
}

variable::variable(QString title, float value): _title(title), _value(value), _isSet(true)
{

}

variable::~variable()
{

}

float variable::calculer() const
{
    if(!_isSet) // Si la variable n'a pas de valeur définie, le calcul est impossible
    {
        cout << "undefined variable" << endl;
        throw "undefined";
    }

    return _value; // Si la variable a une valeur définie, on renvoi cette valeur
}

void variable::afficherClassique(ostream &reference)
{
    reference << _title.toStdString();
}

void variable::afficherPolonaise(ostream &reference)
{
    reference << _title.toStdString();
}

void variable::setTitle(QString title)
{
    _title = title;
}

void variable::setValue(float value)
{
    _value = value;
    _isSet = true;
}

void variable::deleteValue()
{
    _value = 0;
    _isSet = false;
}

float variable::getValue()
{
    return _value;
}

QString variable::getTitle() const
{
    return _title;
}

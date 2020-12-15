#ifndef VARIABLE_H
#define VARIABLE_H

#include <QString>
#include <iostream>

#include "expression.h"

using namespace std;

class variable : public expression
{
public:
	variable();
	variable(QString title);
    variable(QString title, float value);
    virtual ~variable();

    float calculer();
	void afficherClassique(ostream &reference);
	void afficherPolonaise(ostream &reference);
	void setTitle(QString title);
    void setValue(float value);
    void deleteValue();
	float getValue();
    QString getTitle() const;

private:
	QString _title;
	float _value;
	bool _isSet;
};

#endif // VARIABLE_H

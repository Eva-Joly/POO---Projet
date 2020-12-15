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
	float calculer();
	void afficherClassique(ostream &reference);
	void afficherPolonaise(ostream &reference);
	void setTitle(QString title);
	void setValue(float value);
	void deleteValue();
	float getValue();

private:
	QString _title;
	float _value;
	bool _isSet;
};

#endif // VARIABLE_H

#ifndef ENREGISTREMENT_H
#define ENREGISTREMENT_H

#include <iostream>
#include <fstream>
#include <string>
#include "constante.h"
#include "addition.h"
#include "soustraction.h"
#include "division.h"
#include "expression.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <QApplication>
#include <QTextEdit>

using namespace std;

void enregistrement(operateur &a);

string chargement(string nomFichier);



#endif // ENREGISTREMENT_H

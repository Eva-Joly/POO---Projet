#include "mainwindow.h"
#include "constante.h"
#include "addition.h"
#include "soustraction.h"
#include "multiplication.h"
#include "division.h"
#include "symboltable.h"
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


    txt->setText(os.str().c_str());
    txt->show();

    return a.exec();
}

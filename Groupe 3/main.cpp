#include "mainwindow.h"
#include "constante.h"
#include "addition.h"
#include "soustraction.h"
#include "division.h"
#include "expression.h"

#include "enregistrement.h"

#include <QApplication>
#include <sstream>
#include <QTextEdit>


using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QTextEdit *txt = new QTextEdit();

    constante c1(10);
    constante c2(10.0);
    constante c3(2);
    constante c4(4);



    addition add(&c1, &c2);
    soustraction sous(&c1, &c2);
    division div(&add, &sous);
    addition add2(&div, &add);


    ostringstream os;
    string expressionChargee;

    add2.afficherPolonaise(os);


    enregistrement(add2);
    expressionChargee = chargement("test.txt");
    cout << expressionChargee << endl;

    ifstream fich("test.txt");

    txt->setText(os.str().c_str());
    txt->show();



  // MainWindow w;
  //  w.show();
    return a.exec();
}

#include "mainwindow.h"
#include "constante.h"
#include "addition.h"

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

    ostringstream os;
    add.afficher(os);
    os<< "=" << add.calculer();
    os << endl;
    add.afficher(os);

    txt->setText(os.str().c_str());
    txt->show();

    MainWindow w;
    w.show();
    return a.exec();
}

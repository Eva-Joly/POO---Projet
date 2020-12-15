#ifndef MYTIMER_H
#define MYTIMER_H

#include <QTimer>

#include "grapheur2dmodel.h"
#include "constante.h"
#include "addition.h"
#include "soustraction.h"
#include "multiplication.h"
#include "division.h"

class grapheur2dController : public QTimer
{
    Q_OBJECT // Macro nécessaire à la mise en place de signaux/slots

    public:
        // Constructeurs
        grapheur2dController();
        grapheur2dController(grapheur2dModel* model);

    private:
        grapheur2dModel* _model; // Adresse du modèle du grapheur2d

    public slots:
        void update();

};

#endif // MYTIMER_H

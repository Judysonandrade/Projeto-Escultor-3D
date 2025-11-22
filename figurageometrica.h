#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"

class FiguraGeometrica{
public:
    virtual ~FiguraGeometrica(){} // Destrutor Virtual, o
    // Metodo de desenho da classe abstrata
    virtual void draw(Sculptor &t) = 0; // Método abstrato que obriga as classes filhas a
    // definirem como se desenham na escultura t.
};

#endif // FIGURAGEOMETRICA_H

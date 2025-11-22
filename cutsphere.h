#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"

class cutSphere: public FiguraGeometrica
{
private:
    int xcenter, ycenter, zcenter;
    int raio;

public:
    cutSphere(int xcenter, int ycenter, int zcenter, int raio);
    ~cutSphere();

    virtual void draw(Sculptor &t);
};

#endif // CUTSPHERE_H

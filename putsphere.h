#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figurageometrica.h"

class putSphere: public FiguraGeometrica
{
private:
    int xcenter, ycenter, zcenter;
    int raio;
    float r, g, b;
    float a;


public:
    putSphere(int xcenter, int ycenter, int zcenter, int raio, float r, float g, float b, float a);
    ~putSphere();
    virtual void draw(Sculptor &t);
};

#endif // PUTSPHERE_H

#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"

class putBox: public FiguraGeometrica
{
private:
    int x0, y0, z0;
    int x1,y1, z1;
    float r, g, b;
    float a;

public:
    putBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
    ~putBox();
    virtual void draw(Sculptor &t);
};

#endif // PUTBOX_H

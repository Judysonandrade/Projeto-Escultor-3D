#ifndef PUTELIPSOIDE_H
#define PUTELIPSOIDE_H

#include "figurageometrica.h"

class putElipsoide: public FiguraGeometrica
{
private:
    int xcenter, ycenter, zcenter;
    int rx, ry, rz;
    float r,g,b;
    float a;

public:
    putElipsoide(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
    ~putElipsoide();

    virtual void draw(Sculptor &t);

};

#endif // PUTELIPSOIDE_H

#ifndef CUTELIPSOIDE_H
#define CUTELIPSOIDE_H

#include "figurageometrica.h"


class cutElipsoide: public FiguraGeometrica
{
private:
    int xcenter, ycenter, zcenter;
    int rx, ry, rz;
public:

    cutElipsoide(int xcemter, int ycenter, int zcenter, int rx, int ry, int rz);
    ~cutElipsoide();

    virtual void draw(Sculptor &t);

};

#endif // CUTELIPSOIDE_H

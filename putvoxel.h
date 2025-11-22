#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"

class putVoxel:public FiguraGeometrica
{
    int x, y, z;
    float r, g, b;
    float a;

public:
    putVoxel(int x, int y, int z, float r, float g, float b, float a);
    ~putVoxel();
    virtual void draw(Sculptor &t);
};

#endif // PUTVOXEL_H

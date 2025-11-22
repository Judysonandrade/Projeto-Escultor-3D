#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"

class cutVoxel: public FiguraGeometrica
{
    int x,y,z;

public:
    cutVoxel(int x, int y, int z);
    ~cutVoxel();
    virtual void draw(Sculptor &t);
};

#endif // CUTVOXEL_H

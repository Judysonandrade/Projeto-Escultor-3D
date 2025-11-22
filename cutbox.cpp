#include "cutbox.h"

cutBox::cutBox(int x0, int x1, int y0, int y1 ,int z0, int z1){
    this -> x0 = x0;
    this -> x1 = x1;
    this -> y0 = y0;
    this -> y1 = y1;
    this -> z0 = z0;
    this -> z1 = z1;

}

cutBox::~cutBox(){}

void cutBox::draw(Sculptor &t){
    for(int i=x0; i<=x1;i++){ // percorrendo os intervalos de X que é X0 e X1 (Largura)
        for(int j=y0; j<=y1;j++){ //percorrendo os intervalos de Y que é Y0 e Y1 (Altura)
            for(int k=z0; k<=z1;k++){ // percorrendo os intervalos de Z que é Z0 e Z1 (Profundidade)
                t.cutVoxel(i,j,k); // ativa o voxel com a cor atual determinada
            }
        }
    }
}


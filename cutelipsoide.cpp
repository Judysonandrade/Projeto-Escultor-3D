#include "cutelipsoide.h"
#include <math.h>

cutElipsoide::cutElipsoide(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> rx = rx;
    this -> ry = ry;
    this -> rz = rz;
}

cutElipsoide::~cutElipsoide(){}


void cutElipsoide::draw(Sculptor &t){
    for(int i=xcenter-rx;i<xcenter+rx;i++){ // Percorre as Fatias
        for(int j=ycenter-ry;j<ycenter+ry;j++){ // Percorre as Linhas (Altura)
            for(int k=zcenter-rz;k<zcenter+rz;k++){ // Percorre as colunas (Profundidade)

                // Fórmula: (distanciaX / raioX)² + (distanciaY / raioY)² + (distanciaZ / raioZ)²
                // Obs: pow(base, 2) eleva ao quadrado.
                // Em que em cada eixo ele é dividido pelo seu proprio raio

                float resultado = (pow(i-xcenter,2) / pow(rx,2) + pow(j-ycenter,2) / pow(ry,2) + pow(k-zcenter,2) / pow(rz,2));

                // Se o resultado for menor que 1.0 significa que está dentro do voxel e ele aponta para as cores
                //  Determinada
                if(resultado < 1.0){
                    t.cutVoxel(i,j,k);
                }
            }
        }
    }
}

#include "putsphere.h"
#include <math.h>

putSphere::putSphere(int xcenter, int ycenter, int zcenter, int raio, float r, float g, float b, float a){
    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> raio = raio;
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = a;

}

putSphere::~putSphere(){}


void putSphere::draw(Sculptor &t){
    for(int i=xcenter-raio;i<xcenter+raio;i++){ // Percorre todo os planos verticais
        for(int j=ycenter-raio;j<ycenter+raio;j++){ // Percorre todas as linhas (Altura)
            for(int k=zcenter-raio;k<zcenter+raio;k++){ // Percorre as colunas (Profundidade)

                // Calcula a distância ao quadrado do ponto atual (i,j,k) até o centro da esfera.
                // Fórmula: d² = (x-x0)² + (y-y0)² + (z-z0)²

                float resultado = (pow(i-xcenter,2) + pow(j-ycenter,2) + pow(k-zcenter,2));

                // Se o resultado for menor ou igual ao raio ao quadrado significa que o voxel
                // Esta dentro da esfera e ativa a função de pintar

                if(resultado <= pow(raio,2)){
                    t.setColor(r,g,b,a);
                    t.putVoxel(i,j,k);
                }
            }
        }
    }
}

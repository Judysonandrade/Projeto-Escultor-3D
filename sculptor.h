#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "voxel.h"

class Sculptor
{
private:
    Voxel ***v; // matriz em 3 dimensões para criação dos voxeis. Representado por um ponteiro em que cada ponteiro representa uma dimensão da matriz
    int nx,ny,nz; // Declaração das dimensões da minha matriz
    float r,g,b,a; // Declaração para a manipulação das cores e transparencia do desenhor que irei desenhar

public:

    Sculptor(int _nx, int _ny, int _nz); // construtor que tem como intuito reservar um espaço na memoria
    ~Sculptor(); // destrutor
    void setColor(float r, float g, float b, float a); // Define a cor do desenho
    void putVoxel(int x, int y, int z); // Adiciona um voxel em uma determinada posição x,y,z
    void cutVoxel(int x, int y, int z); // Remove um voxel em uma determinada posição x,y,z
    void putBox(int x0,int x1, int y0, int y1, int z0, int z1); // Implementa uma serie de voxels em um espaço determinado das coordenadas
    void cutBox(int x0,int x1, int y0, int y1, int z0, int z1); // Retira uma serie de voxels em um espaço determinado das coordenadas
    void putSphere(int xcenter, int ycenter, int zcenter, int raio); // Criação da Esfera
    void cutSphere(int xcenter, int ycenter, int zcenter, int raio); // Retirada da Esfera
    void putElipsoide(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); // Criação da Elipsoide
    void cutElipsoide(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); // Retirada da Elpsoide
    void writeOFF(const char* filename); //  Função que vai criar meu arquivo .off

};

#endif // SCULPTOR_H

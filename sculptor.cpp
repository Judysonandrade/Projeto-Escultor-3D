#include "sculptor.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;


// Construtor

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    // Guardas as dimensões na classe
    this -> nx = _nx;
    this -> ny = _ny;
    this -> nz = _nz;

    // Fazer a Alocação de Memoria

    v = new Voxel **[_nx]; // Alocação da Linha da matriz (Eixo X)

    for(int i=0;i<_nx;i++){

        v[i] = new Voxel *[_ny]; // Alocaçõa da coluna (Eixo Y)
        for(int j=0;j<_ny;j++){
            v[i][j] = new Voxel [_nz]; // Alocação no eixo Z
            for(int k=0;k<_nz;k++){
                v[i][j][k].r = 0;
                v[i][j][k].g = 0;
                v[i][j][k].b = 0;
                v[i][j][k].a = 0;
                v[i][j][k].show = false; // Desenho Começa Invisivel
            }
        }

    }
}

// Destrutor

Sculptor::~Sculptor(){
    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            delete[] this->v[i][j]; // Liberação de Memoria no Eixo Z
        }
        delete [] this->v[i]; // Liberação de Memoria no Eixo Y

    }
    delete[] this->v; // Liberaçõa de Memoria no Eixo X

}



void Sculptor::setColor(float r, float g, float b, float a){
    // Define a cor do projet, ou seja, ela aponta para a cor determinada
    // pelo usuario

    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = a;
}


void Sculptor::putVoxel(int x, int y, int z){

    // Ele acessa os parametros do voxel e aplica uma cor a ele, ou seja ele acessa
    // o que esta sendo apontado na matriz V[x][y][z] e aponta uma cor para ele e no .show
    // torna isso visivel

        this->v[x][y][z].r = r;
        this->v[x][y][z].g = g;
        this->v[x][y][z].b = b;
        this->v[x][y][z].a = a;
        this->v[x][y][z].show = true;

}


void Sculptor::cutVoxel(int x, int y, int z){

    //  Apaga um voxel,  a cores vão está la mas ao salvar o arquivo ele vai ser ignorado
        this->v[x][y][z].show = false;

}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){

    // Diferentemente do PutVoxel que coloca so um bloco por vez o PutBox ele
    // preenche com varios blocos de uma vez pra formar um bloco solido retangular

    x0 = max(0, x0); // garante que x0 nunca seja menor que 0
    x1 = min(nx-1, x1); // garante que x1 nunca untrapasse o tamanho da matriz no eixo X (nx)
    y0 = max(0, y0); // garante que y0 nunca seja menor que 0
    y1 = min(ny-1, y1); // garante que y1 nunca untrapasse o tamanho da matriz no eixo Y (ny)
    z0 = max(0, z0); // garante que z0 nunca seja menor que 0
    z1 = min(nz-1, z1); // garante que z1 nunca untrapasse o tamanho da matriz no eixo Z (zx)

    for(int i=x0; i<=x1;i++){ // percorrendo os intervalos de X que é X0 e X1 (Largura)
        for(int j=y0; j<=y1;j++){ //percorrendo os intervalos de Y que é Y0 e Y1 (Altura)
            for(int k=z0; k<=z1;k++){ // percorrendo os intervalos de Z que é Z0 e Z1 (Profundidade)
                this -> putVoxel(i,j,k); // ativa o voxel com a cor atual determinada
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    // Faz o inverso do PutBox, ele apaga os voxel apontado pelo usuario
    for(int i=x0; i<=x1;i++){ // percorrendo os intervalos de X que é X0 e X1 (largura)
        for(int j=y0; j<=y1;j++){ //percorrendo os intervalos de Y que é Y0 e Y1 (altura)
            for(int k=z0; k<=z1;k++){ // percorrendo os intervalos de Z que é Z0 e Z1 (profundidade)
                this -> cutVoxel(i,j,k); // deixa a cor invisivel
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int raio){

    // Essa função tem o objetivo de esculpir uma esfera solida na matriz

    int xmin = max(0, xcenter - raio); // Garantir que o indice nunca seja negativo no loop
    int xmax = min(nx - 1, xcenter + raio); // Garantir que o indice nunca ultrapasse o tamanho da matriz

    int ymin = max(0, ycenter - raio); // Garantir que o indice nunca seja negativo no loop
    int ymax = min(ny - 1, ycenter + raio); // Garantir que o indice nunca ultrapasse o tamanho da matriz

    int zmin = max(0, zcenter - raio); // Garantir que o indice nunca seja negativo no loop
    int zmax = min(nz - 1, zcenter + raio); // Garantir que o indice nunca ultrapasse o tamanho da matriz

    for(int i=xmin; i<xmax; i++){ // Percorre todo os planos verticais
        for(int j=ymin; j<ymax; j++){ // Percorre todas as linhas (Altura)
            for(int k=zmin; k<zmax; k++){ // Percorre as colunas (Profundidade)

                // Calcula a distância ao quadrado do ponto atual (i,j,k) até o centro da esfera.
                // Se o resultado for menor ou igual ao raio ao quadrado significa que o voxel
                // Esta dentro da esfera e ativa a função de pintar

                // Fórmula: d² = (x-x0)² + (y-y0)² + (z-z0)²
                float resultado = (pow(i-xcenter,2) + pow(j-ycenter,2) + pow(k-zcenter,2));

                if(resultado <= pow(raio,2)){
                    this -> putVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int raio){

    // Faz o inverso da funçõa PutShepre ele vai deletando a esfera

    int xmin = max(0, xcenter - raio); // Garantir que o indice nunca seja negativo no loop
    int xmax = min(nx - 1, xcenter + raio); // Garantir que o indice nunca ultrapasse o tamanho da matriz


    int ymin = max(0, ycenter - raio); // Garantir que o indice nunca seja negativo no loop
    int ymax = min(ny - 1, ycenter + raio); // Garantir que o indice nunca ultrapasse o tamanho da matriz


    int zmin = max(0, zcenter - raio); // Garantir que o indice nunca seja negativo no loop
    int zmax = min(nz - 1, zcenter + raio); // Garantir que o indice nunca ultrapasse o tamanho da matriz



    for(int i=xmin;i<xmax;i++){
        for(int j=ymin;j<ymax;j++){
            for(int k=zmin;k<zmax;k++){
                float resultado = (pow(i-xcenter,2) + pow(j-ycenter,2) + pow(k-zcenter,2));

                if(resultado <= pow(raio,2)){
                    this -> cutVoxel(i,j,k);
                }
            }
        }
    }
}


void Sculptor::putElipsoide(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    int xmin = max(0, xcenter - rx); // Garantir que o indice nunca seja negativo no loop
    int xmax = min(nx - 1, xcenter + rx); // Garantir que não ultrapasse a matriz

    int ymin = max(0, ycenter - ry); // Garantir que o indice nunca seja negativo no loop
    int ymax = min(ny - 1, ycenter + ry); // Garantir que não ultrapasse a matriz

    int zmin = max(0, zcenter - rz); // Garantir que o indice nunca seja negativo no loop
    int zmax = min(nz - 1, zcenter + rz); // Garantir que não ultrapasse a matriz


    for(int i=xmin;i<xmax;i++){ // Percorre as Fatias
        for(int j=ymin;j<ymax;j++){ // Percorre as Linhas (Altura)
            for(int k=zmin;k<zmax;k++){ // Percorre as colunas (Profundidade)

                // Fórmula: (distanciaX / raioX)² + (distanciaY / raioY)² + (distanciaZ / raioZ)²
                // Obs: pow(base, 2) eleva ao quadrado.
                // Em que em cada eixo ele é dividido pelo seu proprio raio

                float resultado = (pow(i-xcenter,2) / pow(rx,2) + pow(j-ycenter,2) / pow(ry,2) + pow(k-zcenter,2) / pow(rz,2));

                // Se o resultado for menor que 1.0 significa que está dentro do voxel e ele aponta para as cores
                //  Determinada
                if(resultado < 1.0){
                    this -> putVoxel(i,j,k);
                }
            }
        }
    }
}

// A cutElpsoide faz o inverso da PutElipsoide

void Sculptor::cutElipsoide(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    int xmin = max(0, xcenter - rx);
    int xmax = min(nx - 1, xcenter + rx);

    int ymin = max(0, ycenter - ry);
    int ymax = min(ny - 1, ycenter + ry);

    int zmin = max(0, zcenter - rz);
    int zmax = min(nz - 1, zcenter + rz);


    for(int i=xmin;i<xmax;i++){
        for(int j=ymin;j<ymax;j++){
            for(int k=zmin;k<zmax;k++){
                float resultado = (pow(i-xcenter,2) / pow(rx,2) + pow(j-ycenter,2) / pow(ry,2) + pow(k-zcenter,2) / pow(rz,2));

                if(resultado < 1.0){
                    this -> cutVoxel(i,j,k);
                }
            }
        }
    }
}
void Sculptor::writeOFF(const char *filename){
    ofstream myfile; // é oq permite salvar o meu projeto em formato off
    myfile.open(filename); // atriibui myfile ao meu projeto

    if (!myfile.is_open()){ //  Caso não consiga abrir o arquivo ele vai
        // Aparece um alerta avisando que não é possivel abrir e vai parar o programa
        cout << "Erro ao abrir o arquivo: " << filename << endl;
        exit(1);
    }

    // Cabeçalho
    // A primeira linha sempre precisa ta escrita .OFF
    myfile << "OFF\n";

    // Variavel para verificar a quantidade de voxel que tem
    int contVoxel = 0;

    // Conta quantos voxels existem para definir o cabeçalho
    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(this->v[i][j][k].show){ // Verificar a quanitade de voxel visiveis
                    contVoxel++;
                }
            }
        }
    }

    // Cabeçalho: N_vertices, N_faces, N_arestas
    myfile << contVoxel*8 << " " << contVoxel*6 << " 0\n";

    // Escreve as coordenadas dos vértices
    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0; k<nz;k++){
                if(this->v[i][j][k].show){
                    // O cubo padrão vai de -0.5 a +0.5 em torno do centro (i,j,k)
                    // O Voxel é considerado um cubo perfeito de lado igual a 1.
                    // A coordenada (i, j, k) representa o CENTRO geométrico desse cubo.
                    // Para encontrar os 8 cantos (vértices), precisamos nos deslocar
                    // metade do tamanho (0.5) para cada direção a partir do centro.

                    myfile << i-0.5 << " " << j+0.5 << " " << k-0.5 << "\n"; // Vértice 0: Esquerda (-0.5), Cima (+0.5), Frente (-0.5)
                    myfile << i-0.5 << " " << j-0.5 << " " << k-0.5 << "\n"; // Vértice 1: Esquerda (-0.5), Baixo (-0.5), Frente (-0.5)
                    myfile << i+0.5 << " " << j-0.5 << " " << k-0.5 << "\n"; // Vértice 2: Direita (+0.5), Baixo (-0.5), Frente (-0.5)
                    myfile << i+0.5 << " " << j+0.5 << " " << k-0.5 << "\n"; // Vértice 3: Direita (+0.5), Cima(+0.5), Frente (-0.5)
                    myfile << i-0.5 << " " << j+0.5 << " " << k+0.5 << "\n"; // Vértice 4: Esquerda (-0.5), Cima (+0.5), Fundo (+0.5)
                    myfile << i-0.5 << " " << j-0.5 << " " << k+0.5 << "\n"; // Vértice 5: Esquerda (-0.5), Baixo (-0.5), Fundo (+0.5)
                    myfile << i+0.5 << " " << j-0.5 << " " << k+0.5 << "\n"; // Vértice 6: Direita (+0.5), Baixo (-0.5), Fundo (+0.5)
                    myfile << i+0.5 << " " << j+0.5 << " " << k+0.5 << "\n"; // Vértice 7: Direita (+0.5), Cima (+0.5), Fundo (+0.5)
                }
            }
        }
    }

    // 3. Escreve as faces e as cores
    int vertice = 0; // Referência para o índice do vértice atual (incrementa de 8 em 8)

    myfile << fixed << setprecision(2); // Fixa a formatação de cor para float

    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0; k<nz;k++){
                if(this->v[i][j][k].show){

                    // Acessa as cores dos voxels
                    float r = this->v[i][j][k].r;
                    float g = this->v[i][j][k].g;
                    float b = this->v[i][j][k].b;
                    float a = this->v[i][j][k].a;


                    // My file vai ter como saida os pontos da face a esquerda, superior, inferior, topo, frente e fundo
                    // 0 (Cima-esquerda) // 3 (cima-direita) // 2(Baixo-direita) // 1(baixo-esquerda)
                    // 4( Cima-Esquerda) // 5 (baixo-esquerda) // 6(baixo-direta) // 7(cima-direta)
                    // FRENTE
                    myfile << "4 " << vertice+0 << " " << vertice+3 << " " << vertice+2 << " " << vertice+1 << " "
                           << r << " " << g << " " << b << " " << a << "\n";

                    // FUNDO
                    myfile << "4 " << vertice+4 << " " << vertice+5 << " " << vertice+6 << " " << vertice+7 << " "
                           << r << " " << g << " " << b << " " << a << "\n";

                    // ESQUERDA
                    myfile << "4 " << vertice+0 << " " << vertice+1 << " " << vertice+5 << " " << vertice+4 << " "
                           << r << " " << g << " " << b << " " << a << "\n";

                    // CIMA
                    myfile << "4 " << vertice+0 << " " << vertice+4 << " " << vertice+7 << " " << vertice+3 << " "
                           << r << " " << g << " " << b << " " << a << "\n";

                    // DIREITA
                    myfile << "4 " << vertice+3 << " " << vertice+7 << " " << vertice+6 << " " << vertice+2 << " "
                           << r << " " << g << " " << b << " " << a << "\n";

                    // BASE
                    myfile << "4 " << vertice+1 << " " << vertice+2 << " " << vertice+6 << " " << vertice+5 << " "
                           << r << " " << g << " " << b << " " << a << "\n";

                    // Como este voxel gastou 8 vértices (do índice 'face' até 'face+7'),
                    // somamos 8 para que o próximo voxel comece a usar os vértices a partir do 'face+8'.
                    vertice+= 8; // Incrementa 8 vértices para o próximo voxel
                }
            }
        }
    }
    //  FECHA O ARQUIVO
    myfile.close();
    cout << "Arquivo OFF criado com Sucesso: " << filename << endl;
}



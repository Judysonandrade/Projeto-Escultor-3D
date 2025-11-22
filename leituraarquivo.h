#ifndef LEITURAARQUIVO_H
#define LEITURAARQUIVO_H
#include <vector>

#include "figurageometrica.h"

class LeituraArquivo
{

    int nx, ny, nz;
    std::vector<FiguraGeometrica*> figs;

public:
    LeituraArquivo(const char* filename);
    ~LeituraArquivo();

    void draw(Sculptor &t);

    // GETTERS (Recuperadores de Informação)
    // Como nx, ny, nz são privados, essas funções servem para
    // "contar" para a main qual é o tamanho da escultura, sem deixar a main mexer nos valores.


    int getX();
    int getY();
    int getZ();
};

#endif // LEITURAARQUIVO_H

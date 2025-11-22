#include "leituraarquivo.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// Inclui os cabeçalhos de todas as formas geometricas

#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putelipsoide.h"
#include "cutelipsoide.h"

using namespace std;
// Recebe o caminho do arquivo
LeituraArquivo::LeituraArquivo(const char* filename){
    // Cria um objeto de fluxo de entrada de arquivo
    ifstream myfile;
    // tenta abrir o arquivo pelo caminho
    myfile.open(filename);
    // Declara uma string temporária 's' para armazenar cada palavra lida do arquivo.
    string s;

    // Se o arquivo não funcionar na sua abertura esse aparece essa mensagem e encerra o programa
    if (!myfile.is_open()){
        cout << "Erro ao abrir o arquivo: " << filename << endl;
        exit(1);
    }

    // Enquanto o arquivo estiver aberto faça a leitura dos dados dele e compare
    while(myfile.good()){
        myfile >> s;
        // Se acabou o arquivo após tentar ler, sai do loop para não repetir o último comando.
        if (!myfile.good()) break;

        if(s.compare("dim") == 0){
            int x, y, z;
            myfile >> x >> y >> z;
            nx = x; ny = y; nz = z;
            cout << "Dimensoes: " << nx << " " << ny << " " << nz << endl;
        }
        else if(s.compare("putVoxel") == 0){
            int x, y, z;
            float r, g, b, a;
            myfile >> x >> y >> z;
            myfile >> r >> g >> b >> a;
            figs.push_back(new putVoxel(x, y, z, r, g, b, a));
        }
        else if(s.compare("cutVoxel") == 0){
            int x, y, z;
            myfile >> x >> y >> z;
            figs.push_back(new cutVoxel(x, y, z));
        }
        else if(s.compare("putBox") == 0){
            int x0, y0, z0, x1, y1, z1;
            float r, g, b, a;
            myfile >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            myfile >> r >> g >> b >> a;
            figs.push_back(new putBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
        }
        else if(s.compare("cutBox") == 0){
            int x0, y0, z0, x1, y1, z1;
            myfile >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figs.push_back(new cutBox(x0, x1, y0, y1, z0, z1));
        }
        else if(s.compare("putSphere") == 0){
            int xcenter, ycenter, zcenter, raio;
            float r, g, b, a;
            myfile >> xcenter >> ycenter >> zcenter >> raio;
            myfile >> r >> g >> b >> a;
            figs.push_back(new putSphere(xcenter, ycenter, zcenter, raio, r, g, b, a));
        }
        else if(s.compare("cutSphere") == 0){
            int xcenter, ycenter, zcenter, raio;
            myfile >> xcenter >> ycenter >> zcenter >> raio;
            figs.push_back(new cutSphere(xcenter, ycenter, zcenter, raio));
        }
        else if(s.compare("putElipsoide") == 0){
            int xcenter, ycenter, zcenter, rx, ry, rz;
            float r, g, b, a;
            myfile >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
            myfile >> r >> g >> b >> a;
            figs.push_back(new putElipsoide(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
        }
        else if(s.compare("cutElipsoide") == 0){
            int xcenter, ycenter, zcenter, rx, ry, rz;
            myfile >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
            figs.push_back(new cutElipsoide(xcenter, ycenter, zcenter, rx, ry, rz));
        }
    }

    // Mensagem de sucesso ao terminar o loop while.
    cout << "Arquivo Lido" << endl;
    // Fecha o arquivo para liberar o recurso do sistema operacional.
    myfile.close();
}

// Destrutor

LeituraArquivo::~LeituraArquivo(){
    // Percorre todo o vetor de figuras do início ao fim.
    for(int i = 0; i < figs.size(); i++){
        // Deleta o objeto que está apontado na posição i.
        // Aqui o Polimorfismo + Destrutor Virtual garantem a limpeza correta.
        delete figs[i];
    }
    // Limpa o vetor em si, removendo os ponteiros (que agora apontam para nada).
    figs.clear();
}


// Recebe a referência do Escultor onde os desenhos serão aplicados.
void LeituraArquivo::draw(Sculptor &t){
    // Percorre todas as figuras armazenadas na lista.
    for(int i = 0; i < figs.size(); i++){
        // Chama o método draw de cada figura.
        // O polimorfismo decide se executa o draw de Box, Sphere, etc.
        figs[i]->draw(t);
    }
}

// Recebe as dimensões lidas e retorna
int LeituraArquivo::getX(){
    return nx;
}
int LeituraArquivo::getY(){
    return ny;
}
int LeituraArquivo::getZ(){
    return nz;
}

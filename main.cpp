#include <iostream>
#include "leituraarquivo.h"
#include "sculptor.h"

using namespace std;

int main()
{
    // Cria um ponteiro 'leitura' e aloca memória dinamicamente (new) para o objeto LeituraArquivo.
    // Passamos o caminho ABSOLUTO do arquivo para garantir que o programa o encontre.
    // Neste momento, o construtor roda, lê o arquivo todo e preenche o vetor de figuras.
    LeituraArquivo *leitura = new LeituraArquivo("C:/Users/andra/OneDrive/Documentos/Projeto_Parte2_Oficial/arquivo/arquivo.txt");

    // Cria um ponteiro 's' para o Escultor (nossa matriz 3D).
    // As dimensões (nx, ny, nz) não são fixas; elas vêm do arquivo que acabamos de ler.
    // Usamos leitura->getX(), getY() e getZ() para pegar esses valores privados.
    Sculptor *s = new Sculptor(leitura->getX(), leitura->getY(), leitura->getZ());

    // Desenha
    leitura->draw(*s);

    // Pega a matriz já pintada e a converte para um arquivo .OFF.
    // Salvamos no mesmo diretório para facilitar a localização.
    s->writeOFF("C:/Users/andra/OneDrive/Documentos/Projeto_Parte2_Oficial/arquivo/microfone.off");

    // Deleta o objeto 's'. Isso chama o destrutor do Sculptor e libera a matriz 3D da memória RAM.
    delete s;


    // Deleta o objeto 'leitura'. Isso chama o destrutor de LeituraArquivo e limpa o vetor de figuras.

    delete leitura;

    cout << "Arquivo OFF criado com sucesso!" << endl;
    return 0;
}

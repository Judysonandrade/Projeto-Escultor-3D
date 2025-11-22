# Escultor 3D - Projeto de Programacao Avancada

**Autor:** Judyson Andrade Justino
**Componente Curricular:** DCA3303 - PROGRAMACAO AVANCADA
**Linguagem:** C++ (Padrao C++11 ou superior)

## Objetivo

Desenvolver uma ferramenta em C++ baseada em Programação Orientada a Objetos (POO) capaz de interpretar arquivos de texto simples e, a partir deles, gerar esculturas tridimensionais (matrizes de voxels) exportadas no formato .off para visualização em softwares gráficos (como o MeshLab).

## Resumo do Projeto

O núcleo deste projeto é a classe Sculptor, responsável pelo gerenciamento de uma matriz 3D alocada dinamicamente. Cada elemento dessa matriz é um Voxel, uma estrutura que armazena propriedades de cor (r, g, b), transparência (a) e estado de ativação (se o bloco existe ou não).

A arquitetura do sistema utiliza conceitos avançados de POO, especificamente Herança e Polimorfismo:
* Foi criada uma classe abstrata FiguraGeometrica, que serve como molde genérico.
* Classes concretas (como PutBox, CutSphere, PutVoxel, etc.) herdam dessa base e implementam a lógica específica de desenho (draw).
* Um vetor de ponteiros do tipo FiguraGeometrica armazena a sequência de figuras lidas de um arquivo .txt.
* Durante a execução, o programa percorre esse vetor chamando o método draw() de cada objeto, que modifica a matriz de voxels.
* Por fim, o método writeOFF() traduz a matriz resultante para um arquivo geométrico legível.

## Funcionalidades Implementadas

O programa interpreta os seguintes códigos geométricos:

* putVoxel / cutVoxel: Ativa ou desativa um único voxel.
* putBox / cutBox: Cria ou remove uma região retangular (caixa).
* putSphere / cutSphere: Cria ou remove uma esfera.
* putElipsoide / cutElipsoide: Cria ou remove uma elipsoide.

## Como Compilar e Rodar

### Pre-requisitos
* Um compilador C++ (g++, clang ou MinGW).
* (Opcional) Qt Creator para facilitar a edição.

### No Linux (Terminal)

1. Abra o terminal na pasta do projeto.
2. Compile o código com o comando:
   g++ *.cpp -o escultor
3. Execute o programa:
   ./escultor

### No Windows

#### Opcao 1: Usando o Qt Creator (Recomendado)
1. Abra o arquivo .pro do projeto no Qt Creator.
2. Clique no ícone de Play (botão verde) ou pressione Ctrl + R.
3. O programa irá rodar e gerar o arquivo .off na mesma pasta do executável (ou na pasta especificada no código).

#### Opcao 2: Usando Terminal (MinGW/G++)
1. Abra o PowerShell ou CMD na pasta do projeto.
2. Compile o código:
   g++ *.cpp -o escultor.exe
3. Execute:
   ./escultor.exe

## Visualizacao

Após a execução, um arquivo (ex: escultura.off) será gerado. Para visualizar sua escultura:
1. Baixe e instale o software MeshLab.
2. Abra o arquivo .off gerado no MeshLab.
3. Use o mouse para rotacionar e visualizar seu modelo em 3D.

---
Projeto desenvolvido para fins educacionais na Universidade Federal do Rio Grande do Norte (UFRN).

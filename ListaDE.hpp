#include "Nodo.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

#ifndef _LISTADE
#define _LISTADE
//Lista recebida de uma SE, modificar quando mudar ela para duplamente encadeada
class ListaDE{
    Nodo *Inicio;
    Nodo *Fim;
    int contador, NodosAlocados; //Contador nao foi usado
public:
    ListaDE();
    string ImprimeLista(bool modo);//Imprime a lista e define o sentido da impressao //OK
    int InsereNoInicio(float x1, float y1); //Ira inserir o nodo no inicio //OK
    int Insere(float x1, float x2, int pos); // Ira inserir o dado apos a posicao que indicar //OK
    int Remove(int pos);//Remove Vertices //OK
    Nodo* AlocaNodo(float x, float y);//Cria um nodo novo e aumenta um valor no contador //OK
    void DestroiNodo(Nodo *n);//Destroi um nodo e diminui o contador //OK
    int TotalNodos(); //Retorna quantos nodos foram alocados //OK
    int Split(int pos1, int pos2, ListaDE &poligonoMemoria); //Recebe a posicao de dois polignos | Poderia usar bool // OK
    void SalvaLista(ListaDE poligono); //Ira salvar a lista em um txt //OK
    void LimparLista(); //Deleta todos elementos da lista //OK
    int InsereNoFim(float x1, float y1);//Insere o nodo no fim da lista //OK
    string ImprimeListaSemNodo(bool modo);//Imprime a lista sem os nodos
};

#endif
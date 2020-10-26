#include "Nodo.hpp"
#include <iostream>
#include <string>
#include <sstream>

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
    string ImprimeLista(bool modo);//Imprime a lista e define o sentido da impressao
    int InsereNoInicio(float x1, float y1); //Ira inserir o nodo no inicio
    int Insere(float x1, float x2, int pos); // Ira inserir o dado apos a posicao que indicar
    //float InsereNoFim(float dado); //Nao vou usa-la 
    int Remove(int pos);//Remove Vertices
    Nodo* AlocaNodo(float x, float y);//Cria um nodo novo e aumenta um valor no contador
    void DestroiNodo(Nodo *n);//Destroi um nodo e diminui o contador
    int TotalNodos(); //Retorna quantos nodos foram alocados
};

#endif
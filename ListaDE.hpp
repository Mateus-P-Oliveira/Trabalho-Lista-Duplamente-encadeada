#include "Nodo.hpp"

#ifndef _LISTADE
#define _LISTADE
//Lista recebida de uma SE, modificar quando mudar ela para duplamente encadeada
class ListaDE{
    Nodo *Inicio;
    Nodo *Fim;
    int contador;
public:
    ListaDE();
    void ImprimeLista();
    int InsereNoInicio(float x1, float y1); //Ira inserir o nodo no inicio
    int Insere(float x1, float x2, int pos); // Ira inserir o dado apos a posicao que indicar
    float InsereNoFim(float dado);
    float RemoveDoInicio(float &dado);
    float RemoveDoFim(float &dado);
    Nodo* BuscaDado(float dado);
    float RemoveDado(float dado);

};

#endif
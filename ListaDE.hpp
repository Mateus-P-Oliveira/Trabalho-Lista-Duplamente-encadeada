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
    float InsereNoInicio(float dado);
    float InsereNoFim(float dado);
    float RemoveDoInicio(float &dado);
    float RemoveDoFim(float &dado);
    Nodo* BuscaDado(float dado);
    float RemoveDado(float dado);

};

#endif
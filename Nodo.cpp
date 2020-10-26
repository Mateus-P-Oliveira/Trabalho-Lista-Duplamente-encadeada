#include "Nodo.hpp"

Nodo::Nodo(){//Inicializa o nodo com os valores zerados
    x = 0.0;
    y = 0.0;
    prox = nullptr;
    prev = nullptr;
}

Nodo::Nodo(float x1, float y1){// Seta valores para o nodo ao cria-lo
    x = x1;
    y = y1;

}

void Nodo::setInfo(float x1, float y1){//Define informacoes para o nodo
    x = x1;
    y = y1;
}

void Nodo::getInfo(float &x1, float &y1){// Faz os ponteiros apontarem para os valores daquele nodo
    x1 = x;
    y1 = y;
}

void Nodo::setProx(Nodo *p){//define o proximo nodo
    prox = p;
}

Nodo* Nodo::getProx(){ //Retorna quem sera o proximo nodo
    return prox;
}

void Nodo::setPrev(Nodo *p){ // Define o nodo anterior
    prev = p;
}

Nodo* Nodo::getPrev(){ // Retorna quem e o nodo anterior
    return prev;
}


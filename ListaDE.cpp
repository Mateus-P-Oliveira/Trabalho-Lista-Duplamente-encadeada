#include "ListaDE.hpp"

ListaDE::ListaDE(){ //Cria o construtor zerado
    Inicio = nullptr;
    Fim = nullptr;
    contador = 0;
}


int ListaDE::InsereNoInicio(float x1, float y1){
    Nodo *p;

    p = new Nodo;
    p->x = x1;
    p->y = y1;
    p->prev = nullptr;
    
    if(Inicio == nullptr){
        Inicio = p;
        Fim = p;
    }
    else{
        p->prox = Inicio;
        Inicio = p;
        p->prev = nullptr;
    }
    contador++;
    return 1;

}

int ListaDE::Insere(float x1, float y1, int pos){
    if(pos > contador) return 0; // Caso ultrapsse a ultima posicao da lista

    Nodo *ptr, *temp, *aux; // Cria os ponteiros
    ptr = Inicio; // Comeca apontando para o inicio da lista
    for(int i = 0; i < pos-1; i++){ // Percorre ate uma posicao antes da desejada e aponta para ela com o ptr->prox
        ptr = ptr->prox;
    }
    aux = new Nodo; // Cria o nodo aux
    //Associa os valores
    aux->x = x1; 
    aux->y = y1;

    aux->prox = ptr->prox;
    temp = ptr->prox;
    ptr->prox = aux;
    temp->prev = aux;
    aux->prev = ptr;

    contador++;
    return 1;

}
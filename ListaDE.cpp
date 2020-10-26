#include "ListaDE.hpp"

ListaDE::ListaDE(){ //Cria o construtor zerado
    Inicio = nullptr;
    Fim = nullptr;
    //contador = 0;
    NodosAlocados = 0;
}


int ListaDE::InsereNoInicio(float x1, float y1){//Na main quando for inserir checar se a posicao inserida e 0 ai eu uso ela de novo caso nao seja  eu so uso ela na leitura de arquivo
    Nodo *p;
    
    p = AlocaNodo(x1,y1);
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
    //contador++;
    return 1;

}

int ListaDE::Insere(float x1, float y1, int pos){ //Pode dar memory leak -- Testar depois
    if(pos > NodosAlocados) return 0; // Caso ultrapsse a ultima posicao da lista
    if(pos == 0) return 0; //Testa para ver se nao quer ser inserido na primeira posicao
    Nodo *ptr, *temp, *aux; // Cria os ponteiros
    ptr = Inicio; // Comeca apontando para o inicio da lista
    for(int i = 0; i < pos-1; i++){ // Percorre ate uma posicao antes da desejada e aponta para ela com o ptr->prox
       if(ptr->prox == nullptr) return 0; // Testa para ver se existe um nodo apos o nullptr
        ptr = ptr->prox; // o ptr aponta para o seu nodo seguinte
    }
    aux = AlocaNodo(x1,y1); // Cria o nodo aux e associa os valores
   
    if(ptr->prox == nullptr){ //Testa se o proximo valor nao e null
        aux->prox = nullptr; // O novo nodo passa a apontar para o nullptr
        ptr->prox = aux;//O nodo antigo que fica antes do aux passa a apontar para ele
        aux->prev = ptr;//O novo nodo passa a apontar para o velho
        Fim = aux; // O novo nodo vira o fim da lista
    }
    else{ //Caso o proximo valor nao seja Nullptr
        aux->prox = ptr->prox; // O aux aponta para o prox do ptr
        temp = ptr->prox; // o nodo proximo e associado a uma variavel temporaria 
        ptr->prox = aux; //O meu ptr aponta para o novo nodo inserido
        temp->prev = aux; // o nodo seguinte ao aux passa a apontar para ele
        aux->prev = ptr; // o Novo nodo aux passa a apontar para o nodo ptr pois ele e inserido em sua frente
    }
    //contador++;
    return 1;

}


int ListaDE::Remove(int pos){
    if(NodosAlocados == 3 || NodosAlocados < 3) return 0; // Teste para ver se existe menos de 3 vertices
    Nodo *ptr, *depois, *antes;
    ptr = Inicio;
    for(int i = 0; i < pos-1; i++){
        ptr = ptr->prox;

    }
    if(ptr->prev == nullptr){
        antes = nullptr;
        depois = ptr->prox;
        depois->prev = antes;
        DestroiNodo(ptr);
        Inicio = depois;
    }
    else if(ptr->prox == nullptr){
        antes = ptr->prev;
        depois = nullptr;
        antes->prox = depois;
        DestroiNodo(ptr);
        Fim = antes;
    }
    else{
        antes = ptr->prev;
        depois = ptr->prox;
        antes->prox = depois;
        depois->prev = antes;
        DestroiNodo(ptr);
    }
    return 1;

}


Nodo* ListaDE::AlocaNodo(float x, float y){ //Ira funcionar como new
    NodosAlocados ++; // Mesma funcao do contador
    return new Nodo (x,y);
}

void ListaDE::DestroiNodo(Nodo *n){ //Ira funcionar como delete
    delete n;
    NodosAlocados--;

}

string ListaDE::ImprimeLista(bool modo){ //Imprime os dados
    stringstream ss;
    Nodo *ptr;
    float x, y;
    ptr = Inicio;
    //Imprimir sentido de insercao
    if(modo == 1){
        ss << "Impressao em ordem" << endl; 
        for(int i = 0; i < NodosAlocados - 1; i++){
            ss << ptr->getInfo(x,y) << endl;
            ptr = ptr->prox;
        }
    }
    //Imprimir sentido inverso
    else if(modo == 0){
        ss << "Impressao em ordem reversa" << endl;
        for(int i = 0; i < NodosAlocados - 1; i++){
            ptr = ptr->prox;
        }
        for(int i = NodosAlocados; i >= 0; i++){
            ss << ptr->getInfo(x,y) << endl;
            ptr = ptr->prev;
        }
    }
    else
    {
        cout << "Modo Invalido" << endl;
    }
    
    ss << endl;
    
    return ss.str();

}
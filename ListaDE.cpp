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
        Inicio->prev = p;
        Inicio = p;
        p->prev = nullptr;
    }
    //contador++;
    return 1;

}

int ListaDE::InsereNoFim(float x1, float y1){//Aloca no fim os nodos
    Nodo *p;

    p = AlocaNodo(x1,y1);
    p->prox = nullptr;

    if(Fim == nullptr){
        Fim = p;
        Inicio = p;
    }
    else{
        p->prev = Fim;
        Fim->prox = p;
        Fim = p;
        p->prox = nullptr;
    }

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


int ListaDE::Remove(int pos){ // Remove o nodo que eu escolhi
    if(NodosAlocados <= 3) return 0; // Teste para ver se existe menos de 3 vertices
    Nodo *ptr, *depois, *antes;
    ptr = Inicio;
    for(int i = 0; i < pos; i++){
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
    
    //Imprimir sentido de insercao
    if(modo == 1){
        ptr = Inicio;
        cout << "Impressao em ordem" << endl; 
        ss << NodosAlocados << endl;
        for(int i = 0; i < NodosAlocados; i++){
            ptr->getInfo(x, y);
            ss << x << " " << y << endl;
            ptr = ptr->prox;
        }
    }
    //Imprimir sentido inverso
    else if(modo == 0){
        ptr = Fim;
        cout << "Impressao em ordem reversa" << endl;
        ss << NodosAlocados << endl;
        for(int i = NodosAlocados; i != 0; i--){
            ptr->getInfo(x,y);
            ss << x << " " << y << endl;
            ptr = ptr->prev;
        }
    }
    else
    {
        cout << "Nodo Invalido" << endl;
    }
    
    //ss << endl; // Caso queira um espaco no final eu coloco aqui
    
    return ss.str(); // Retorna a string que eu irei imprimir | Tambem vou usa-la para salvar

}


string ListaDE::ImprimeListaSemNodo(bool modo){ //Imprime os dados
    stringstream ss;
    Nodo *ptr;
    float x, y;
    
    //Imprimir sentido de insercao
    if(modo == 1){
        ptr = Inicio;
        cout << "Impressao em ordem" << endl; 
        
        for(int i = 0; i < NodosAlocados; i++){
            ptr->getInfo(x, y);
            ss << x << " " << y << endl;
            ptr = ptr->prox;
        }
    }
    //Imprimir sentido inverso
    else if(modo == 0){
        ptr = Fim;
        cout << "Impressao em ordem reversa" << endl;
        
        for(int i = NodosAlocados; i != 0; i--){
            ptr->getInfo(x,y);
            ss << x << " " << y << endl;
            ptr = ptr->prev;
        }
    }
    else
    {
        cout << "Nodo Invalido" << endl;
    }
    
    //ss << endl; // Caso queira um espaco no final eu coloco aqui
    
    return ss.str(); // Retorna a string que eu irei imprimir | Tambem vou usa-la para salvar

}

int ListaDE::Split(int pos1, int pos2, ListaDE &poligonoMemoria){ //Separador dos nodos
    //Testes de validade da posicao
    if(pos1 < 0 || pos2 < 0) return 0; //Checa se nao sao valores negativos
    if(abs(pos1-pos2) <= 1)  return 0; //Caso eles sejam adjacente a distancia sera ficara entre -1 e 1 e ai nao podera ser realizado o comando split
    //Mantendo a variavel mais proxima de zero sempre na frente
    if(abs(pos2) < abs(pos1)){
        int temp;
        temp = pos1;
        pos1 = pos2;
        pos2 = temp;
    }
    //Armazenando ponteiros dos vertices que serao separados
    Nodo *ptr1;
    ptr1 = Inicio;

    for(int i = 0; i < pos1; i++){
        ptr1 = ptr1->prox;
    }
    
    Nodo *ptr2;
    ptr2 = Inicio;

    for(int i = 0; i <= pos2; i++){
        ptr2 = ptr2->prox;
    }
   
    //Criar dois novos poligonos
    ListaDE polig1, polig2;
    float x, y;
    int elementos1 = 0, elementos2 = 0;
    Nodo *temp, *aux;
    temp = Inicio;
    aux = ptr1;
    while (ptr1 != ptr2)
    {
        ptr1->getInfo(x,y);
        polig1.InsereNoFim(x,y);
        ptr1 = ptr1->prox;
        elementos1++;
    }
    ptr1 = aux;
    while (temp != nullptr)
    {
        if(temp == ptr1){
            temp->getInfo(x,y);
            polig2.InsereNoFim(x,y);
            elementos2++;
            while(temp->prox != ptr2){
                temp = temp->prox;
            }
        }
        else{
            
            temp->getInfo(x,y);
            polig2.InsereNoFim(x,y);
            
            elementos2++;
            temp = temp->prox;
        }
        
    }
    
    //Testes dos poligs que saem
    //cout << polig1.ImprimeLista(1);
    //cout << polig2.ImprimeLista(1);
    //Compara qual poligono e menor e qual e maior
    if(elementos2 <= elementos1){
        poligonoMemoria = polig1;
        NodosAlocados = elementos1;
        SalvaLista(polig2);
        polig2.LimparLista();
    }
    else{
        poligonoMemoria = polig2;
        NodosAlocados = elementos2;
        SalvaLista(polig1);
        polig1.LimparLista();
    }
    
    
    return 1;
}

void ListaDE::SalvaLista(ListaDE poligono){//Salva a lista em um arquivo
    string nome;
    bool n;
    cout << "Insira nome que sera usado no arquivo de saida: " << endl;
    cin >> nome;
    cout << "Lista impressa em ordem Normal[1] ou Reversa[0]: " << endl;
    cin >> n;
    ofstream out(nome);
    out << poligono.ImprimeLista(n);
    out.close();
}

void ListaDE::LimparLista(){//Limpa a lista //Mudar mais tarde
    Nodo *temp;
    temp = AlocaNodo(0.0,0.0); //Cria um nodo vazio
    while(Inicio != nullptr){ //Enquanto o Inicio nao estiver vazio
        temp = Inicio;
        Inicio = Inicio->prox;
        free(temp);
    }
}

int ListaDE::TotalNodos(){
    return NodosAlocados;
}
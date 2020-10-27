#include "ListaDE.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    string nome, tamanho;
    ifstream poligono;
    int TAMANHO_POLIGONO = 0;
    ListaDE listaPoligono;
    float x, y;

    cout << "Insira o nome do arquivo que tera o poligono" << endl;
    cin >> nome;
    
    poligono.open(nome);
    if(!poligono){//Testa se abriu certo
        cout << "Erro" << endl;
        exit(1);
    }

    getline(poligono,tamanho);//Le o tamanho do poligono para o for
    TAMANHO_POLIGONO = atoi(tamanho.c_str()); //Converte para int o tamanho lido

    for(int i = 0; i < TAMANHO_POLIGONO; i++){
        /*Ler lista Poligono*/
        //Talvez usar o fscanf
        //Separa o espaco para ler o valor do x e do y
    }

    return 0;
}
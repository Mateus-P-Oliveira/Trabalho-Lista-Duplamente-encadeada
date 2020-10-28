#include "ListaDE.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    string nome, tamanho;
    ifstream poligono;
    int TAMANHO_POLIGONO = 0, opcao;
    ListaDE listaPoligono;
    float x, y;

    cout << "Insira o nome do arquivo que tera o poligono" << endl;
    cin >> nome;
    //Leitura dos dados
    poligono.open(nome);
    if(!poligono){//Testa se abriu certo
        cout << "Erro" << endl;
        exit(1);
    }

    getline(poligono,tamanho);//Le o tamanho do poligono para o for
    TAMANHO_POLIGONO = atoi(tamanho.c_str()); //Converte para int o tamanho lido

    for(int i = 0; i < TAMANHO_POLIGONO; i++){
        /*Le lista Poligono*/
        poligono >> x >> y;
        listaPoligono.InsereNoFim(x,y);        
    }
     poligono.close(); 
    //Fim da leitura dos daos

    //Criacao do menu
    while(1){
        cout << "Escolha uma opcao: " << endl;
        cout << "[1] Imprimir os vertices em ordem: " << endl;
        cout << "[2] Imprimir os vertices em ordem Reversa: " << endl;
        cout << "[3] Remova um vertice: " << endl;
        cout << "[4] Inserir vertice em dadas coordenadas: " << endl;
        cout << "[5] Salvar Poligono: " << endl;
        cout << "[6] Total de Nodos: " << endl;
        cout << "[7] Realizar Split: " << endl;
        cout << "[8] Sair" << endl;
        cin >> opcao;

        if(opcao == 1){
            cout << listaPoligono.ImprimeListaSemNodo(1);            
        }
        else if(opcao == 2){
            cout << listaPoligono.ImprimeListaSemNodo(0);
        }
        else if(opcao == 3){
            int pos;
            cout << "Escolha a posicao para ser removida: " << endl;
            cin >> pos;
            listaPoligono.Remove(pos);
        }
        else if(opcao == 4){
            int coorX, coorY, pos;
            cout << "X: " << endl;
            cin >> coorX;
            cout << endl << "Y:" << endl;
            cin >> coorY;
            cout << endl << "Posicao: " << endl;
            cin >> pos;
            if(pos == 0){
                listaPoligono.InsereNoInicio(coorX,coorY);
            }
            else{
                listaPoligono.Insere(coorX,coorY,pos);
            }
        }
        else if(opcao == 5){
            listaPoligono.SalvaLista(listaPoligono);
        }
        else if(opcao == 6){
            cout << listaPoligono.TotalNodos() << endl;
        }
        else if(opcao == 7){
            int pos1, pos2;
            cout << "Escolha as posicoes para realizar o split: " << endl;
            cin >> pos1 >> pos2;
            listaPoligono.Split(pos1,pos2,listaPoligono);
        }
        else if(opcao == 8){
            break;
        }
        else{
            cout << "Opcao Invalida" << endl;
            //continue;
        }
    }

    
    return 0;
}
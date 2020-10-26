#ifndef _NODO
#define _NODO
// ****************************
class Nodo{
public:
    float x,y;
    Nodo *prox;
    Nodo *prev;
   
    Nodo();
    Nodo (float x, float y);
    void setInfo(float x, float y);
    void getInfo(float &x, float &y);//Checar se esta certa
    void setProx(Nodo *p);
    Nodo* getProx();
    void setPrev(Nodo *p);
    Nodo* getPrev();
   
   
};

#endif
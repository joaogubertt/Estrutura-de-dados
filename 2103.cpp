#include <iostream>
using namespace std;
#define TAM 50

struct pilha
{
    int ultimo;
    char pilha[TAM];
};

bool inicializarPilha(pilha &p)
{
    p.ultimo = -1;
    return true;
}

bool inserirPilha(pilha &p, char elemento)
{
    if(p.ultimo == TAM - 1) return false;
    
    p.ultimo++;
    p.pilha[p.ultimo] = elemento;
    return true;
}

void mostrarPilha(pilha p, string frase)
{
    if (p.ultimo == -1) 
    {
        cout << "Lista Vazia";
        return;
    }
        
    cout << frase << ": ";    
    for( int i = 0; i <= p.ultimo; i++) cout << p.pilha[i] << " ";
    
    return;
}

bool retirarPilha(pilha &p, char &valor ){
    if( p.ultimo == -1 ) return false;

    valor = p.pilha[p.ultimo];
    p.ultimo--;
    return true;
}

void empilharEmOrdem(pilha p1, pilha p2, pilha &p3)
{
    inicializarPilha(p3);
    bool pilha1, pilha2;
    char aux1, aux2;
    pilha1 = retirarPilha(p1, aux1);
    pilha2 = retirarPilha(p2, aux2);
    while(pilha1 || pilha2)
    {
        if(pilha1 && pilha2)
        {
            if(aux1 < aux2)
            {
                inserirPilha (p3, aux1);
                pilha1 = retirarPilha(p1, aux1);
            }
            else if (aux1 == aux2)
            {
                inserirPilha(p3, aux1);
                inserirPilha(p3, aux2);
                pilha1 = retirarPilha(p1, aux1);
                pilha2 = retirarPilha(p2, aux2);
            }
            else
            {
                inserirPilha(p3, aux2);
                pilha2 = retirarPilha(p2, aux2);
            }
        }
        else if(!pilha1 && pilha2)
        {
            inserirPilha(p3, aux2);
            pilha2 = retirarPilha(p2, aux2); 
        }
        else
        {
            inserirPilha (p3, aux1);
            pilha1 = retirarPilha(p1, aux1);
        }
    }
}

int main()
{
    pilha Pilha1, Pilha2, Pilha3;
    
    inicializarPilha(Pilha1);
    inserirPilha(Pilha1, '5');
    inserirPilha(Pilha1, '4');
    inserirPilha(Pilha1, '3');
    inserirPilha(Pilha1, '2');
    inserirPilha(Pilha1, '1');
    
    inserirPilha(Pilha2, '7');
    inserirPilha(Pilha2, '6');
    inserirPilha(Pilha2, '5');
    inserirPilha(Pilha2, '4');
    inserirPilha(Pilha2, '2');
    mostrarPilha(Pilha2, "Pilha 2");
    cout << endl;
    mostrarPilha(Pilha1, "Pilha 1");
    cout << endl;
    empilharEmOrdem(Pilha1, Pilha2, Pilha3);
    mostrarPilha(Pilha3, "Pilha 3");

    return 0;
}
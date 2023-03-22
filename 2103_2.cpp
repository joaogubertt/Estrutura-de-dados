#include <iostream>
using namespace std;
#define TAM 50

struct pilha
{
    int ultimo;
    int pilha[TAM];
};

bool inicializarPilha(pilha &p)
{
    p.ultimo = -1;
    return true;
}

bool inserirPilha(pilha &p, int elemento)
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
    for( int i = p.ultimo; i >= 0; i--) cout << p.pilha[i] << " ";
    
    return;
}

bool retirarPilha(pilha &p, int &valor ){
    if( p.ultimo == -1 ) return false;

    valor = p.pilha[p.ultimo];
    p.ultimo--;
    return true;
}

void fatorarParaPilha(pilha &p1, int n)
{
    inicializarPilha(p1);
    int d = 2;
    while( d <= n) // está faltando o numero 11
    {
        if(n % d == 0)
        {
            inserirPilha(p1, d);
            n = n/d;
        } else d++;
    }
}

int main()
{
    pilha Pilha1;
    int n = 3960;
    fatorarParaPilha(Pilha1, n);
    cout << "n = " << n << endl;
    mostrarPilha(Pilha1, "Fatoração de n");
    return 0;
}
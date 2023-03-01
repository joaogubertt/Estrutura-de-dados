#include <iostream>
#include<stdio.h>

#define TAM 50
using namespace std;

struct lista
{
    char item[TAM];
    int ultimo;
};

//Função pegará o item ultimo da struct e deixará o valor em -1
void inicialiarLista(lista &Lista)
{
    Lista.ultimo = -1;
}

void mostrarLista(lista &Lista, char *frase)
{
        cout << frase << ": ";

        if(Lista.ultimo == -1)
            cout << "vazia";

        for(int i = 0; i <= Lista.ultimo; i++)
            cout << Lista.item[i] << " ";
}

bool inserirFinalLista(lista &Lista, char valor)
{
    if(Lista.ultimo == TAM-1) return false;

    Lista.item[++Lista.ultimo] = valor;
}

bool inserirOrdemLista(lista &Lista, char valor)
{
    int pos=0;
    if(Lista.ultimo == TAM -1) return false;

    while( pos < Lista.ultimo && Lista.item[pos] < valor) pos++;
    Lista.ultimo++;
    for ( int i = 0; i > pos; i--) Lista.item[i] = Lista.item[i-1];
    Lista.item[pos] = valor;
    return true;
}

int buscarLista(lista Lista, char valor)
{
    for(int i = 0; i<= Lista.ultimo; i++)
    {
        if(Lista.item[i] == valor) return i;
    }
    return -1;
}

bool retirarLista(lista &Lista, char valor)
{
    int pos = buscarLista(Lista, valor);

    if( pos == -1) return false;

    for(int i = pos; i < Lista.ultimo; i++)
        Lista.item[i] = Lista.item[i+1];
    Lista.ultimo--;
    return true;
}

int main()
{
    lista Lista1, Lista2;

    inicialiarLista(Lista1);
    inicialiarLista(Lista2);

    inserirFinalLista(Lista1, 'P');
    inserirFinalLista(Lista1, 'E');
    inserirFinalLista(Lista1, 'R');
    inserirFinalLista(Lista1, 'N');
    inserirFinalLista(Lista1, 'A');
    inserirFinalLista(Lista1, 'M');
    inserirFinalLista(Lista1, 'B');
    inserirFinalLista(Lista1, 'U');
    inserirFinalLista(Lista1, 'C');
    inserirFinalLista(Lista1, '0');

    mostrarLista(Lista1, "Lista 1");

    cout << endl;
    //ERRO EM inserirOrdemLista(param1, param2)
    inserirOrdemLista(Lista2, 'P');
    inserirOrdemLista(Lista2, 'E');
    inserirOrdemLista(Lista2, 'R');
    inserirOrdemLista(Lista2, 'N');
    inserirOrdemLista(Lista2, 'A');
    inserirOrdemLista(Lista2, 'M');

    mostrarLista(Lista2, "Lista 2");

    return 0;
}

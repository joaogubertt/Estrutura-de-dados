#include <iostream>
#include<stdio.h>

#define TAM 50
using namespace std;

struct lista
{
    char item[TAM];
    int ultimo;
};

//Fun��o pegar� o item ultimo da struct e deixar� o valor em -1
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
    if(Lista.ultimo == TAM -1) return false; //duvida


    //Enquanto lista.ultimo que recebe valor -1 for maior ou igual que pos(0 enquanto o array tiver 0 itens). O while continuará rodando e aumentado {pos} até encontrar uma posição em que ultimo seja diferente de -1 ou Lista.ultimo e que o valor a ser inserido seja menor que os que a lista já compreende
    while( pos <= Lista.ultimo && Lista.item[pos] < valor) pos++;
    Lista.ultimo++;
    for ( int i = Lista.ultimo; i > pos; i--) Lista.item[i] = Lista.item[i-1];
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

    inicialiarLista(Lista2);

    inserirOrdemLista(Lista2, 'C');
    inserirOrdemLista(Lista2, 'A');
    inserirOrdemLista(Lista2, 'B');


    mostrarLista(Lista2, "Lista 2");

    return 0;
}

#include <iostream>
#include<stdio.h>

#define TAM 50
using namespace std;

struct lista
{
    char item[TAM];
    int ultimo;
};

//Função pega o a variável ultimo da struct Lista e deixa o valor em -1
void inicialiarLista(lista &Lista)
{
    Lista.ultimo = -1;
}

//Função que percorre a lista dando cout até o char em indice lista.ultimo
void mostrarLista(lista &Lista, char *frase)
{
        cout << frase << ": ";

        if(Lista.ultimo == -1)
            cout << "vazia";

        for(int i = 0; i <= Lista.ultimo; i++)
            cout << Lista.item[i] << " ";
}

//Insere um char na ultima posição não preenchida da lista
bool inserirFinalLista(lista &Lista, char valor)
{
    if(Lista.ultimo == TAM-1) return false;

    Lista.item[++Lista.ultimo] = valor;
}

//Insere conforme ordem alfabética, ['A', 'B', 'C', 'D']
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

//Busca um char passado por parâmetro e retorna um valor booleano para mostrar ao usuário se determinado valor está no vetor. O valor retornado será o indice do resultado da busca em caso de existente
int buscarLista(lista Lista, char valor)
{
    for(int i = 0; i<= Lista.ultimo; i++)
    {
        if(Lista.item[i] == valor) return i;
    }
    return -1;
}

//retirarLista utiliza da função de busca para retornar o indice e diminuir o indice uma casa de todos os valores acima do resultado da função, por fim diminui o valor de lista.ultimo
bool retirarLista(lista &Lista, char valor)
{
    int pos = buscarLista(Lista, valor);

    if( pos == -1) return false;

    for(int i = pos; i < Lista.ultimo; i++)
        Lista.item[i] = Lista.item[i+1];
    Lista.ultimo--;
    return true;
}

//O problema da função acima é que por exemplo em uma array ['A', 'B', 'C', 'D'] para remover o C a lista ficaria assim: ['A', 'B', 'D', 'D'], fazendo uma "gambiarra" para mostrarLista rodar somente até ['A', 'B', 'D'] pois o valor de Lista.ulitmo foi diminuido na linha 73

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

    inicialiarLista(Lista2);

    inserirOrdemLista(Lista2, 'C');
    inserirOrdemLista(Lista2, 'A');
    inserirOrdemLista(Lista2, 'B');

    mostrarLista(Lista2, "Lista 2");

    char letraBusca = 'P';

    cout << endl;

    if(buscarLista(Lista1, letraBusca) == -1) 
        cout << "Nao existe " << letraBusca << " em Lista1";
    else
        cout << "Existe " << letraBusca << " em Lista1 no indice " << buscarLista(Lista1, letraBusca);

    return 0;
}

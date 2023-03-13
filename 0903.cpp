#include <iostream>
using namespace std;

struct No
{
    No *eloP;
    No *eloA;
    char info; 
};

struct LDE
{
    No *comeco, *fim;
};

bool inicializarLDE(LDE &lista)
{
    lista.comeco = NULL;
    lista.fim = NULL;
}

bool preencher(LDE &lista, char valor)
{

}

bool mostrar(LDE &lista, char frase[])
{

}

int main()
{

}
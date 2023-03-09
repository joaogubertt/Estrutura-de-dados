#include <iostream>

using namespace std;

struct No
{
    char info; // info será o valor armazenada no nó
    No *elo; //elo será o ponteiro do próximo a apontar
};

struct LUE
{
    No *comeco;
    No *fim;
};

void inicializarLUE(LUE &lista)
{
    lista.comeco = NULL;
    lista.fim = NULL;
}

No* criarPonteiro(char valor)
{
    No* novo = new No; // Esse ponteiro irá armazenar o valor passado por parâmetro
    //cout << novo << "\t"; // dando cout no endereço que o nó vai ficar armazenado
    if(novo == NULL) return novo; // se o ponteiro nao foi alocado nao acontecerá nada na execução de tal execução
    novo->info = valor;
    novo->elo = NULL; // Por agora, o ponteiro não apontará para nenhum outro nó
    //cout << endl << novo->info; // CONFERINDO VALOR DE INFO DO PONTEIRO
    return novo;
}

bool inserirLUE(LUE &lista, char valor)
{
    No *novo = criarPonteiro(valor);
    if(lista.comeco == NULL) // Insere em caso de lista sem nós(vazia)
    {
        lista.comeco = novo;//lista começo aponta para o nov nó
        lista.fim = novo;//O fim também
        return true;
    }

    if(valor < lista.comeco->info)//Inserção no inicio
    {
        novo->elo = lista.comeco; // O novo ponteiro do primeiro elemento da lista apontara para o antigo primeiro
        lista.comeco = novo; // agora o ponteiro de inicio de lista aponta para o novo valor inserido
        return true;
    }
    if(valor > lista.fim->info) //Inserção no fim
    {
        lista.fim->elo = novo;
        lista.fim = novo;
        return true;
    }

    No *aux = lista.comeco;
    while(aux->info < valor && aux->elo->info < valor) aux = aux->elo; //ENQUANTO O NO e o ponteiro do NO TIVERem VALOR MENOR DO QUE O INSERIDO
    novo->elo = aux->elo;
    aux->elo = novo;
    return true;
}

void mostrarLUE(LUE lista, char frase[])
{
    cout << frase << ": ";
    if(lista.comeco == NULL) cout << "vazio";

    No *aux = lista.comeco;
    while(aux != NULL) // VAI ANDAR ATÉ O ELO SER NULL POIS AUX VAI TOMANDO VALORES A PARTIR DOS ELOS, OU SEJA, NO ULTIMO AUX ASSUME UM VALOR QUE NAO EXISTE
    {
        cout << aux->info << " ";
        aux = aux->elo;
    }

    return;
}

No *buscarLUE(LUE &lista, char valor)
{
    No* aux;
    while (aux->info < valor && aux->elo->info > valor)
    {
        if(aux->elo->info == valor) return aux->elo;
        aux = aux->elo;
    }

     return NULL;
}


bool deletar(LUE &lista, char valor)
{
    No* ant = NULL, *pos;
    pos = lista.comeco;
    while(pos!= NULL && pos->info != valor)
    {
        ant = pos;
        pos = pos->elo;
    }

    if(pos == NULL) return false; // Em caso de lista vazia ou valor não encontrado

    //retirada no caso do primeiro item da lista1
    if( pos == lista.comeco)
    {
        lista.comeco = lista.comeco->elo;
        if (pos == lista.fim) lista.fim = NULL;
    }
    else // No meio de dois nós
    {
        ant->elo = pos->elo;
        if (pos == lista.fim) lista.fim = ant;
    }

    delete(pos);
    return true;
}

int main()
{
    LUE lista1;

    inicializarLUE(lista1);

    inserirLUE(lista1, 'P');
    inserirLUE(lista1, 'E');
    inserirLUE(lista1, 'R');
    inserirLUE(lista1, 'N');
    inserirLUE(lista1, 'A');
    inserirLUE(lista1, 'M');
    inserirLUE(lista1, 'B');
    inserirLUE(lista1, 'U');
    inserirLUE(lista1, 'C');
    inserirLUE(lista1, 'O');
    deletar(lista1, 'E');
    deletar(lista1, 'P');
    deletar(lista1, 'R');
    deletar(lista1, 'N');
    deletar(lista1, 'A');
    deletar(lista1, 'M');
    deletar(lista1, 'B');
    deletar(lista1, 'U');
    deletar(lista1, 'C');
    deletar(lista1, 'O');
    cout
    mostrarLUE(lista1, "Lista 1");


    return 0;
}

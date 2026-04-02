#include <iostream>
using namespace std;

struct cartaPokemon{
    string nomeCarta;
    int raridade;
    cartaPokemon *proximo;
    cartaPokemon *anterior;
};

struct ListaDE{
    cartaPokemon *inicio;
    cartaPokemon *fim;
};

void iniciaLista(ListaDE &lista){
    lista.inicio = NULL;
    lista.fim = NULL;
}
void insereInicio(ListaDE &lista, string nomeCarta, int raridade){
    cartaPokemon *novo = new cartaPokemon;

    if(lista.inicio == NULL){
        
    }
}

void insereFim(ListaDE &lista, string nomeCarta, int raridade){
    cartaPokemon *novo = new cartaPokemon;

    novo->nomeCarta = nomeCarta;
    novo->raridade = raridade;
    novo->proximo = NULL;
    novo->anterior = NULL;

    if(lista.inicio == NULL){
        lista.inicio = novo;
        lista.fim = novo;
        return;
    } 

    cartaPokemon *nav = lista.fim;

    lista.fim->proximo = novo;
    novo->anterior = lista.fim;
    lista.fim = novo;
}

void removeFim(ListaDE &lista){
    if(lista.inicio == NULL){
        cout<<"Lista esta vazia";
    }

    cartaPokemon *nav = lista.inicio;

    if(nav->proximo == NULL){
        delete nav;
        lista.inicio == NULL;
        lista.fim == NULL;
        cout<<"Primeiro elemento deletado";
    }

    nav = lista.fim;
    nav = nav->anterior;
    nav->proximo = NULL;
    delete nav->proximo;
}

void imprimir(ListaDE lista){
    if(lista.inicio == NULL){
        cout<<"Lista vazia";
        return;
    }

    cout<<"Cartas: "<<endl;

    cartaPokemon *nav = lista.inicio;
    while(nav != NULL){
        cout<<"Nome: "<<nav->nomeCarta<<endl;;
        cout<<"Raridade: "<<nav->raridade<<endl;
        cout<<"--------"<<endl;
        nav = nav->proximo;
    }
}
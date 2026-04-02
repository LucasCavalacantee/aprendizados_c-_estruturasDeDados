#include <iostream>
using namespace std;

struct cartaPokemon{
    string nomeCarta;
    int raridade;
    cartaPokemon *proximo;
};

struct listaPokemon{
    cartaPokemon *inicio;
};

void iniciaLista(listaPokemon &lista){
    lista.inicio = NULL;
}

void insereFim(listaPokemon &lista, string nomeCarta, int raridade){
    cartaPokemon *novo = new cartaPokemon;
    
    novo->nomeCarta = nomeCarta;
    novo->raridade = raridade;
    novo->proximo = NULL;

    if(lista.inicio == NULL){
        lista.inicio = novo;
        return;
    } 

    cartaPokemon *nav = lista.inicio;
    while(nav->proximo != NULL){
        nav = nav->proximo; //funciona como se fosse um i++, serve para avançar a lista
    }
    nav->proximo = novo;
}

void imprimir(listaPokemon lista){
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
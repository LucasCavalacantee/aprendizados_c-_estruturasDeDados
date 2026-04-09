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

//Inserir no início
void insereInicio(listaPokemon &lista, string nomeCarta, int raridade){
    cartaPokemon *novo = new cartaPokemon;

    novo->nomeCarta = nomeCarta;
    novo->raridade = raridade;
    novo->proximo = lista.inicio;

    lista.inicio = novo;
}

// Inserir no fim 
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
        nav = nav->proximo;
    }
    nav->proximo = novo;
}

//Remover do início
void removeInicio(listaPokemon &lista){
    if(lista.inicio == NULL) return;

    cartaPokemon *nav = lista.inicio;
    lista.inicio = lista.inicio->proximo;

    delete nav;
}

//Remover do fim
void removeFim(listaPokemon &lista){
    if(lista.inicio == NULL) return;

    // só um elemento
    if(lista.inicio->proximo == NULL){
        delete lista.inicio;
        lista.inicio = NULL;
        return;
    }

    cartaPokemon *nav = lista.inicio;

    while(nav->proximo->proximo != NULL){
        nav = nav->proximo;
    }

    delete nav->proximo;
    nav->proximo = NULL;
}

// Inserir em posição
void inserePosicao(listaPokemon &lista, string nomeCarta, int raridade, int posicao){
    if(posicao == 1){
        insereInicio(lista, nomeCarta, raridade);
        return;
    }

    cartaPokemon *novo = new cartaPokemon;
    novo->nomeCarta = nomeCarta;
    novo->raridade = raridade;

    cartaPokemon *nav = lista.inicio;

    for(int i = 1; i < posicao - 1; i++){
        if(nav == NULL){
            cout<<"Posição inválida\n";
            return;
        }
        nav = nav->proximo;
    }

    if(nav == NULL){
        cout<<"Posição inválida\n";
        return;
    }

    novo->proximo = nav->proximo;
    nav->proximo = novo;
}

// Remover em posição
void removePosicao(listaPokemon &lista, int posicao){
    if(lista.inicio == NULL) return;

    if(posicao == 1){
        removeInicio(lista);
        return;
    }

    cartaPokemon *nav = lista.inicio;

    for(int i = 1; i < posicao - 1; i++){
        if(nav->proximo == NULL){
            cout<<"Posição inválida\n";
            return;
        }
        nav = nav->proximo;
    }

    if(nav->proximo == NULL){
        cout<<"Posição inválida\n";
        return;
    }

    cartaPokemon *temp = nav->proximo;
    nav->proximo = temp->proximo;

    delete temp;
}

// Busca simples
cartaPokemon* buscar(listaPokemon lista, string nome){
    cartaPokemon *nav = lista.inicio;

    while(nav != NULL){
        if(nav->nomeCarta == nome){
            return nav;
        }
        nav = nav->proximo;
    }

    return NULL;
}

// Impressão 
void imprimir(listaPokemon lista){
    if(lista.inicio == NULL){
        cout<<"Lista vazia";
        return;
    }

    cout<<"Cartas: "<<endl;

    cartaPokemon *nav = lista.inicio;
    while(nav != NULL){
        cout<<"Nome: "<<nav->nomeCarta<<endl;
        cout<<"Raridade: "<<nav->raridade<<endl;
        cout<<"--------"<<endl;
        nav = nav->proximo;
    }
}
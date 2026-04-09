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
    novo->nomeCarta = nomeCarta;
    novo->raridade = raridade;
    novo->proximo = NULL;
    novo->anterior = NULL;

    if(lista.inicio == NULL){
        lista.inicio = novo;
        lista.fim = novo;
        return;
    }

    novo->proximo = lista.inicio;
    lista.inicio->anterior = novo;
    lista.inicio = novo;
}

void removeInicio(ListaDE &lista){
    // cartaPokemon *nav = new cartaPokemon; ❌ ERRADO (vazamento de memória)
    cartaPokemon *nav;

    if(lista.inicio == NULL) return; // ✅ proteção contra lista vazia

    nav = lista.inicio;

    if(lista.inicio->proximo == NULL){
        lista.inicio = NULL;
        lista.fim = NULL; // ✅ corrigido (antes não tratava fim)
    } else {
        lista.inicio = lista.inicio->proximo;
        lista.inicio->anterior = NULL; // ✅ corrigido
    }

    delete nav;
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

    lista.fim->proximo = novo;
    novo->anterior = lista.fim;
    lista.fim = novo;
}

void removeFim(ListaDE &lista){
    if(lista.inicio == NULL){
        cout<<"Lista esta vazia";
        return; // ✅ faltava return
    }

    // cartaPokemon *nav = lista.inicio; ❌ desnecessário
    cartaPokemon *nav = lista.fim; // ✅ correto

    if(lista.inicio == lista.fim){
        delete nav;
        // lista.inicio == NULL; ❌ errado (comparação)
        // lista.fim == NULL; ❌ errado (comparação)
        lista.inicio = NULL; // ✅ correto
        lista.fim = NULL;    // ✅ correto
        cout<<"Primeiro elemento deletado";
        return;
    }

    lista.fim = lista.fim->anterior;
    lista.fim->proximo = NULL;

    // delete nav->proximo; ❌ errado (já perdeu referência)
    delete nav; // ✅ correto
}

void inserePosicao(ListaDE &lista, string nomeCarta, int raridade, int posicao){
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
    
    cartaPokemon *nav = lista.inicio;
    for(int i = 1; i < posicao; i++){
        if(nav->proximo != NULL){
            nav = nav->proximo;
        }
        else{
            cout << "Posição Indisponivel!" << endl;
            return;
        }
    }

    // ⚠️ tratamento de inserção no início
    if(nav->anterior == NULL){
        novo->proximo = nav;
        nav->anterior = novo;
        lista.inicio = novo;
        return;
    }
    
    novo->anterior = nav->anterior;
    novo->proximo = nav;
    nav->anterior->proximo = novo;
    nav->anterior = novo;
}

void removePosicao(ListaDE &lista, int posicao){
    if(lista.inicio == NULL) return; // ✅ proteção

    cartaPokemon *nav = lista.inicio;

    for(int i = 1; i < posicao; i++){
        if(nav->proximo != NULL){
            nav = nav->proximo;
        }
        else{
            cout << "Posição Indisponivel!" << endl;
            return;
        }
    }

    // ⚠️ se for o primeiro
    if(nav->anterior == NULL){
        lista.inicio = nav->proximo;
        if(lista.inicio != NULL)
            lista.inicio->anterior = NULL;
        else
            lista.fim = NULL;
    }
    // ⚠️ se for o último
    else if(nav->proximo == NULL){
        lista.fim = nav->anterior;
        lista.fim->proximo = NULL;
    }
    else{
        nav->anterior->proximo = nav->proximo;
        nav->proximo->anterior = nav->anterior; // ✅ faltava isso
    }

    delete nav;
}

void imprimir(ListaDE lista){
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
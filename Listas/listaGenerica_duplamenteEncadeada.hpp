#include <iostream>
using namespace std;

template <typename TIPO>
struct No{
    TIPO dado;
    No *proximo;
    No *anterior;
};

template <typename T>
struct ListaDE{
    No<T> *inicio;
    No<T> *fim;
};

template <typename T>
void iniciaLista(ListaDE<T> &lista){
    lista.inicio = NULL;
    lista.fim = NULL;
}

template <typename T>
void insereInicio(ListaDE<T> &lista, T dado){
    No<T> *novo = new No<T>;
    novo->dado = dado;
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

template <typename T>
void removeInicio(ListaDE<T> &lista){
    if(lista.inicio == NULL) return;

    No<T> *nav = lista.inicio;

    if(lista.inicio->proximo == NULL){
        lista.inicio = NULL;
        lista.fim = NULL;
    } else {
        lista.inicio = lista.inicio->proximo;
        lista.inicio->anterior = NULL;
    }

    delete nav;
}

template <typename T>
void insereFim(ListaDE<T> &lista, T dado){
    No<T> *novo = new No<T>;
    novo->dado = dado;
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

template <typename T>
void removeFim(ListaDE<T> &lista){
    if(lista.inicio == NULL){
        cout<<"Lista esta vazia";
        return;
    }

    No<T> *nav = lista.fim;

    if(lista.inicio == lista.fim){
        delete nav;
        lista.inicio = NULL;
        lista.fim = NULL;
        return;
    }

    lista.fim = lista.fim->anterior;
    lista.fim->proximo = NULL;

    delete nav;
}

template <typename T>
void inserePosicao(ListaDE<T> &lista, T dado, int posicao){
    No<T> *novo = new No<T>;
    novo->dado = dado;
    novo->proximo = NULL;
    novo->anterior = NULL;

    if(lista.inicio == NULL){
        lista.inicio = novo;
        lista.fim = novo;
        return;
    } 
    
    No<T> *nav = lista.inicio;
    for(int i = 1; i < posicao; i++){
        if(nav->proximo != NULL){
            nav = nav->proximo;
        }
        else{
            cout << "Posição Indisponivel!" << endl;
            return;
        }
    }
    
    novo->anterior = nav->anterior;
    novo->proximo = nav;

    if(nav->anterior != NULL)
        nav->anterior->proximo = novo;

    nav->anterior = novo;

    if(nav == lista.inicio)
        lista.inicio = novo;
}

template <typename T>
void removePosicao(ListaDE<T> &lista, int posicao){
    if(lista.inicio == NULL) return;

    No<T> *nav = lista.inicio;

    for(int i = 1; i < posicao; i++){
        if(nav->proximo != NULL){
            nav = nav->proximo;
        }
        else{
            cout << "Posição Indisponivel!" << endl;
            return;
        }
    }

    if(nav->anterior != NULL)
        nav->anterior->proximo = nav->proximo;
    else
        lista.inicio = nav->proximo;

    if(nav->proximo != NULL)
        nav->proximo->anterior = nav->anterior;
    else
        lista.fim = nav->anterior;

    delete nav;
}

template <typename T>
void imprimir(ListaDE<T> lista){
    if(lista.inicio == NULL){
        cout<<"Lista vazia";
        return;
    }

    No<T> *nav = lista.inicio;
    while(nav != NULL){
        cout<<nav->dado<<endl;
        cout<<"--------"<<endl;
        nav = nav->proximo;
    }
}
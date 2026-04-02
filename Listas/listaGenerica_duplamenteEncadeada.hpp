#include <iostream>
using namespace std;

template <typename TIPO>
struct TElementoDE{
    TIPO dado;
    TElementoDE *proximo;
    TElementoDE *anterior;
};

template <typename TIPO>
struct TListaDE{
    TElementoDE<TIPO> *inicio;
    TElementoDE<TIPO> *fim;
};

template<typename TIPO>
void inicializaLista(TListaDE<TIPO> &lista){
    lista.inicio = NULL;
    lista.fim = NULL;
}

template<typename TIPO>
void insereFim(TListaDE<TIPO> &lista, TIPO dado){
    TElementoDE<TIPO> *novo = new TElementoDE<TIPO>;

    novo->dado = dado;
    novo->proximo = NULL;
    novo->anterior = NULL;

    if(lista.inicio == NULL){
        lista.inicio = novo;
        lista.fim = novo;
        return;
    }

    TElementoDE<TIPO> *nav = lista.fim;
    lista.fim->proximo = novo;
    novo->anterior = lista.fim;
    lista.fim = novo;
}

template<typename TIPO>
void imprimirItens(TListaDE<TIPO> &lista){
    if(lista.inicio == NULL){
        cout<<"Lista vazia";
        return;
    }

    cout<<"Itens: "<<endl;

    TElementoDE<TIPO> *nav = lista.inicio;
    while(nav != NULL){
        cout<<nav->dado<<endl;
        cout<<"--------"<<endl;
        nav = nav->proximo;
    }
} 

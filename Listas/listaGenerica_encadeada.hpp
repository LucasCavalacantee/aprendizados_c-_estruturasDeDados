#include <iostream>
using namespace std; 

template<typename TIPO>
struct ElementoE{
    TIPO dado;
    ElementoE *proximo;
};

template<typename TIPO>
struct ListaE{
    ElementoE<TIPO> *inicio;
};

template<typename TIPO>
void iniciaLista(ListaE<TIPO> &lista){
    lista.inicio = NULL;
}

template<typename TIPO>
void insereFim(ListaE<TIPO> &lista, TIPO dado){
    ElementoE<TIPO> *novo = new ElementoE<TIPO>;

    novo->dado = dado;
    novo->proximo = NULL;

    if(lista.inicio == NULL){
        lista.inicio = novo;
        return;
    }

    ElementoE<TIPO> *nav = lista.inicio;
    while(nav->proximo != NULL){
        nav = nav->proximo; //funciona como se fosse um i++, serve para avançar a lista
    }
    nav->proximo = novo;
}

template<typename TIPO>
void imprimirItens(ListaE<TIPO> &lista){
    if(lista.inicio == NULL){
        cout << "Lista vazia" << endl;
        return;
    }

    cout << "Itens:" << endl;
    ElementoE<TIPO> *nav = lista.inicio;
    while(nav != NULL){
        cout << nav->dado << endl;
        cout << "--------" << endl;
        nav = nav->proximo;
    }
}


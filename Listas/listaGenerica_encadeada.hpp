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

// Inserir no início
template<typename TIPO>
void insereInicio(ListaE<TIPO> &lista, TIPO dado){
    ElementoE<TIPO> *novo = new ElementoE<TIPO>;

    novo->dado = dado;
    novo->proximo = lista.inicio;

    lista.inicio = novo;
}

// Inserir no fim 
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
        nav = nav->proximo;
    }
    nav->proximo = novo;
}

// Remover início
template<typename TIPO>
void removeInicio(ListaE<TIPO> &lista){
    if(lista.inicio == NULL) return;

    ElementoE<TIPO> *nav = lista.inicio;
    lista.inicio = lista.inicio->proximo;

    delete nav;
}

//Remover fim
template<typename TIPO>
void removeFim(ListaE<TIPO> &lista){
    if(lista.inicio == NULL) return;

    // apenas um elemento
    if(lista.inicio->proximo == NULL){
        delete lista.inicio;
        lista.inicio = NULL;
        return;
    }

    ElementoE<TIPO> *nav = lista.inicio;

    while(nav->proximo->proximo != NULL){
        nav = nav->proximo;
    }

    delete nav->proximo;
    nav->proximo = NULL;
}

// Inserir em posição
template<typename TIPO>
void inserePosicao(ListaE<TIPO> &lista, TIPO dado, int posicao){
    if(posicao == 1){
        insereInicio(lista, dado);
        return;
    }

    ElementoE<TIPO> *novo = new ElementoE<TIPO>;
    novo->dado = dado;

    ElementoE<TIPO> *nav = lista.inicio;

    for(int i = 1; i < posicao - 1; i++){
        if(nav == NULL){
            cout << "Posição inválida\n";
            return;
        }
        nav = nav->proximo;
    }

    if(nav == NULL){
        cout << "Posição inválida\n";
        return;
    }

    novo->proximo = nav->proximo;
    nav->proximo = novo;
}

// Remover em posição
template<typename TIPO>
void removePosicao(ListaE<TIPO> &lista, int posicao){
    if(lista.inicio == NULL) return;

    if(posicao == 1){
        removeInicio(lista);
        return;
    }

    ElementoE<TIPO> *nav = lista.inicio;

    for(int i = 1; i < posicao - 1; i++){
        if(nav->proximo == NULL){
            cout << "Posição inválida\n";
            return;
        }
        nav = nav->proximo;
    }

    if(nav->proximo == NULL){
        cout << "Posição inválida\n";
        return;
    }

    ElementoE<TIPO> *temp = nav->proximo;
    nav->proximo = temp->proximo;

    delete temp;
}

//Impressão 
template<typename TIPO>
void imprimirItens(ListaE<TIPO> &lista){
    if(lista.inicio == NULL){
        cout << "Lista vazia" << endl;
        return;
    }

    cout << "Itens:" << endl;
    ElementoE<TIPO> *nav = lista.inicio;
    while(nav != NULL){
        cout << nav->dado << endl; // exige operador <<
        cout << "--------" << endl;
        nav = nav->proximo;
    }
}
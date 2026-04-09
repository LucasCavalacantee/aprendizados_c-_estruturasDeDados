#include <iostream>
using namespace std;

#define TAM 52

template<typename T>
struct Lista{
    T elementos[TAM];
    int tamanho;
};


template<typename T>
int qtd_elementos(Lista<T> &lista){
    return lista.tamanho;
}

template<typename T>
bool inicializa_lista(Lista<T> &lista){
    lista.tamanho = 0;
    return true;
}

template<typename T>
bool insereFim(Lista<T> &lista, T &elem){
    if(lista.tamanho < TAM){
        lista.elementos[lista.tamanho] = elem;
        lista.tamanho++;
        return true;
    }
    return false;
}

template<typename T>
bool removeFim(Lista<T> &lista){
    if(lista.tamanho > 0){
        lista.tamanho--;
        return true;
    }
    return false;
}

template<typename T>
bool insereInicio(Lista<T> &lista, T &elem){
    if(lista.tamanho < TAM){
        for(int i = lista.tamanho; i > 0; i--){
            lista.elementos[i] = lista.elementos[i - 1];
        }
        lista.elementos[0] = elem;
        lista.tamanho++;
        return true;
    }
    return false;
}

template<typename T>
bool removeInicio(Lista<T> &lista){
    if(lista.tamanho > 0){
        for(int i = 0; i < lista.tamanho - 1; i++){
            lista.elementos[i] = lista.elementos[i+1];
        }
        lista.tamanho--;
        return true;
    }
    return false;
}

template<typename T>
bool inserePosicao(Lista<T> &lista, T &elem, int posicao){
    if(lista.tamanho < TAM && posicao >= 0 && posicao <= lista.tamanho){
        for(int i = lista.tamanho; i > posicao; i--){
            lista.elementos[i] = lista.elementos[i-1];
        }
        lista.elementos[posicao] = elem;
        lista.tamanho++;
        return true;
    }
    return false;
}

template<typename T>
bool removePosicao(Lista<T> &lista, int posicao){
    if(lista.tamanho > 0 && posicao >= 0 && posicao < lista.tamanho){
        for(int i = posicao; i < lista.tamanho - 1; i++){
            lista.elementos[i] = lista.elementos[i+1];
        }
        lista.tamanho--;
        return true;
    }
    return false;
}

template<typename T>
void bubbleSort(Lista<T> &lista, bool (*comp)(T, T)){
    bool trocou;

    for(int i = lista.tamanho - 1; i > 0; i--){
        trocou = false;

        for(int j = 0; j < i; j++){
            if(comp(lista.elementos[j+1], lista.elementos[j])){
                T temp = lista.elementos[j];
                lista.elementos[j] = lista.elementos[j+1];
                lista.elementos[j+1] = temp;
                trocou = true;
            }
        }

        if(!trocou) break;
    }
}

// ================= QUICK SORT =================
template<typename T>
int particiona(Lista<T> &lista, int inicio, int fim, bool (*comp)(T, T)){
    T pivo = lista.elementos[fim];
    int i = inicio - 1;

    for(int j = inicio; j < fim; j++){
        if(comp(lista.elementos[j], pivo)){
            i++;
            T temp = lista.elementos[i];
            lista.elementos[i] = lista.elementos[j];
            lista.elementos[j] = temp;
        }
    }

    T temp = lista.elementos[i+1];
    lista.elementos[i+1] = lista.elementos[fim];
    lista.elementos[fim] = temp;

    return i + 1;
}

template<typename T>
void quickSort(Lista<T> &lista, int inicio, int fim, bool (*comp)(T, T)){
    if(inicio < fim){
        int p = particiona(lista, inicio, fim, comp);
        quickSort(lista, inicio, p - 1, comp);
        quickSort(lista, p + 1, fim, comp);
    }
}

template<typename T>
void ordenarQuick(Lista<T> &lista){
    quickSort(lista, 0, lista.tamanho - 1);
}

template<typename T>
void imprimir(Lista<T> &lista){
    if(lista.tamanho == 0){
        cout << "Lista vazia\n";
        return;
    }

    for(int i = 0; i < lista.tamanho; i++){
        cout << lista.elementos[i] << endl;
    }
}
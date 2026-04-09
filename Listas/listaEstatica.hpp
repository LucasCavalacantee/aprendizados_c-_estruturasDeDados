#include <iostream>
#include "TAD_POKEMON.hpp"
using namespace std;

#define TAM 52

struct Lista{
    cartaPokemon cartas[TAM];
    int tamanho;
};

// ================= BASICO =================

int qtd_cartas(Lista &lista){
    return lista.tamanho;
}

bool inicializa_baralho(Lista &lista){
    lista.tamanho = 0;
    return true;
}
    
bool insereFim(Lista &lista, cartaPokemon &carta){
    if(lista.tamanho < TAM){
        lista.cartas[lista.tamanho] = carta;
        lista.tamanho++;
        return true;
    }
    return false;
}

bool removeFim(Lista &lista){
    if(lista.tamanho > 0){
        lista.tamanho--;
        return true;
    }
    return false;
}

bool insereInicio(Lista &lista, cartaPokemon &carta){
    if(lista.tamanho < TAM){
        for(int i = lista.tamanho; i > 0; i--){
            lista.cartas[i] = lista.cartas[i - 1];
        }
        lista.cartas[0] = carta;
        lista.tamanho++;
        return true;
    }
    return false;
}

bool removeInicio(Lista &lista){
    if(lista.tamanho > 0){
        for(int i = 0; i < lista.tamanho - 1 ; i++){
           lista.cartas[i] = lista.cartas[i+1];  
        }
        lista.tamanho--;
        return true;
    }
    return false;
}

bool inserePosicao(Lista &lista, cartaPokemon &carta, int posicao){
    if(lista.tamanho < TAM && posicao >= 0 && posicao <= lista.tamanho){
        for(int i = lista.tamanho; i > posicao; i--){
            lista.cartas[i] = lista.cartas[i-1];
        }
        lista.cartas[posicao] = carta;
        lista.tamanho++;
        return true;
    }
    return false;
}

bool removePosicao(Lista &lista, int posicao){
    if(lista.tamanho > 0 && posicao >= 0 && posicao < lista.tamanho){
        for(int i = posicao; i < lista.tamanho - 1; i++){
            lista.cartas[i] = lista.cartas[i+1];
        }
        lista.tamanho--;
        return true;
    }
    return false;
}

// ================= BUBBLE SORT (CORRIGIDO) =================

void ordenaCartas(Lista &lista){
    bool trocou;

    for(int i = lista.tamanho - 1; i > 0; i--){
        trocou = false;

        for(int j = 0; j < i; j++){
            if(lista.cartas[j+1] < lista.cartas[j]){
                cartaPokemon temp = lista.cartas[j];
                lista.cartas[j] = lista.cartas[j+1];
                lista.cartas[j+1] = temp;
                trocou = true;
            }
        }

        if(!trocou) break; // otimização
    }
}

// ================= QUICK SORT =================

// função de partição
int particiona(Lista &lista, int inicio, int fim){
    cartaPokemon pivo = lista.cartas[fim];
    int i = inicio - 1;

    for(int j = inicio; j < fim; j++){
        if(lista.cartas[j] < pivo){
            i++;
            cartaPokemon temp = lista.cartas[i];
            lista.cartas[i] = lista.cartas[j];
            lista.cartas[j] = temp;
        }
    }

    cartaPokemon temp = lista.cartas[i+1];
    lista.cartas[i+1] = lista.cartas[fim];
    lista.cartas[fim] = temp;

    return i + 1;
}

// quicksort recursivo
void quickSort(Lista &lista, int inicio, int fim){
    if(inicio < fim){
        int p = particiona(lista, inicio, fim);

        quickSort(lista, inicio, p - 1);
        quickSort(lista, p + 1, fim);
    }
}

// função para chamar
void ordenarQuick(Lista &lista){
    quickSort(lista, 0, lista.tamanho - 1);
}

void imprimir(Lista lista){
    if(lista.tamanho > 0){
        for(int i = 0; i < lista.tamanho; i++){
            cout << lista.cartas[i] << endl; 
        }
    }
}
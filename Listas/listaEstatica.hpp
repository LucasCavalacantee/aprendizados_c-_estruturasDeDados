#include <iostream>
#include "TAD_POKEMON.hpp"
using namespace std;
#define TAM 52

struct Lista{
    cartaPokemon cartas[TAM];
    int tamanho;
};

int qtd_cartas(Lista &lista){
    return lista.tamanho;
}

bool inicializa_baralho(Lista &lista){
    lista.tamanho = 0;
    return true;
}
    
bool insere_carta_final(Lista &lista, cartaPokemon carta){
    if(lista.tamanho < TAM){ //se o tamanho for menor que TAM, ou seja, se a lista não estiver cheia
        lista.cartas[lista.tamanho] = carta; //recebe a carta escolhida pelo usuário e armazena na lista
        lista.tamanho++;
        return true;
    } else {
        return false;
    }
}

bool remove_cartas_final(Lista &lista){
    if(lista.tamanho > 0){
        lista.tamanho--; //tamanho-- pois quando diminui a quatidade a lista perde um item
        return true;
    } else {
        return false;
    }
}

bool remove_inicio(Lista &lista){
    int atual;
    if(lista.tamanho > 0){ // se o tamanho for maior que zero, ou seja, se houver elementos;
        for(int i = 0; i < lista.tamanho - 1 ; i++){ //lista.tamanho - 1 pois o i começa em 0 (ou seja se tamanho fosse 40 ele ia ficar com 41 posições, por isso tamanaho - 1)
           lista.cartas[i] = lista.cartas[i+1];  
        }
        lista.tamanho--;
        return true;
    } else {
        return false;
    }
}

bool insere_inicio(Lista &lista, cartaPokemon carta){
    if(lista.tamanho < TAM){ //se o tamanho for menor que TAM, ou seja, se a lista não estiver cheia
        for(int i = lista.tamanho; i > 0; i--){  //posição começa no inicio da lista
            lista.cartas[i] = lista.cartas[i - 1]; // a posição atual recebe a próxima de baixo
        }
        lista.cartas[0] = carta; //armazena a carta na posição inicial
        lista.tamanho++; //aumenta tamanho
        return true;
    } else{
        return false;
    }
}

bool remove_posicao(Lista &lista, int posicao){
    if(lista.tamanho > 0 and posicao < lista.tamanho and posicao > 0){
        for(int i = posicao; i < lista.tamanho - 1; i++)
            lista.cartas[i] = lista.cartas[i+1]; //copia o próximo elemento para a pos
        lista.tamanho--;
        return true;
    } else {
        return false;
    }
}

bool insere_posicao(Lista &lista, cartaPokemon carta, int posicao){
    if(lista.tamanho > 0 and posicao <= lista.tamanho and posicao > 0){
        for(int i = lista.tamanho-1; i+1 > posicao; i--)
            lista.cartas[i+1] = lista.cartas[i];
        lista.cartas[posicao] = carta;
        lista.tamanho++;
        return true;
    } else {
        return false;
    }
}

void monta_baralho(Lista &lista){
    cartaPokemon carta;
    for(int i = 0; i < 7; i += 2){ //naipe
        for(int j = 1; j < 14; j++){ //numero
            carta.nomeCarta = i;
            carta.nivel = j;
            insere_inicio(lista, carta); //ou insere_fim
        }
    }
}

void embaralha(Lista &lista){
    cartaPokemon carta;
    
    srand(time(NULL));
    for(int i = 0;i < TAM;i++){
        int p;
        p = rand() % TAM;
        
        carta = lista.cartas[i];
        lista.cartas[i] = lista.cartas[p];
        lista.cartas[p] = carta;
    }
}
    
void distribuir_cartas(Lista &baralho, Lista &lista, int tamanho){
    for(int i = 0; i < tamanho; i++){
        insere_inicio(lista, baralho.cartas[0]);
        remove_inicio(baralho);
    }
}

/*
void imprime_baralho(Lista lista){
    for(int i = 0;i < lista.tamanho;i++){
        montaCarta(lista.cartas[i]);
    }
}


bool operator < (cartaPokemon &a, cartaPokemon &b){
   return (a.nivel * 10) + a.nomeCarta < (b.nivel * 10) + b.nomeCarta;
}

void ordenaCartas(Lista &lista){ //Utilizando ordenação bubblesort
    for(int i = 0; i < lista.tamanho - 1; i++){
        for(int j = 0; j < lista.tamanho - i - 1; j++){
            if (lista.cartas[j+1] < lista.cartas[j]){
                Tcartas temp = lista.cartas[j];
                lista.cartas[j] = lista.cartas[j+1];
                lista.cartas[j+1] = temp;
            }
        }
    }
} 
*/




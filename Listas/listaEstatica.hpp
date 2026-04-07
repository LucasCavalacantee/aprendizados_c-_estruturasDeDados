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
    
bool insereFim(Lista &lista, cartaPokemon &carta){
    if(lista.tamanho < TAM){ //se o tamanho for menor que TAM, ou seja, se a lista não estiver cheia
        lista.cartas[lista.tamanho] = carta; //recebe a carta escolhida pelo usuário e armazena na lista
        lista.tamanho++;
        return true;
    } else {
        return false;
    }
}

bool removeFim(Lista &lista){
    if(lista.tamanho > 0){
        lista.tamanho--; //tamanho-- pois quando diminui a quatidade a lista perde um item
        return true;
    } else {
        return false;
    }
}

bool insereInicio(Lista &lista, cartaPokemon &carta){
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

bool removeInicio(Lista &lista){
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

bool inserePosicao(Lista &lista, cartaPokemon &carta, int posicao){
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

bool removePosicao(Lista &lista, int posicao){
    if(lista.tamanho > 0 and posicao < lista.tamanho and posicao > 0){
        for(int i = posicao; i < lista.tamanho - 1; i++)
            lista.cartas[i] = lista.cartas[i+1]; //copia o próximo elemento 
        lista.tamanho--;
        return true;
    } else {
        return false;
    }
}


void ordenaCartas(Lista &lista){ //Utilizando ordenação bubblesort
    int cond;
    cartaPokemon temp;
    cond = 1;
    for(int i = lista.tamanho - 1; (i >= 1) && (cond == 1); i--){
        cond = 0;
        for(int j = 0; j < i; j++){
            if (lista.cartas[j+1] < lista.cartas[j]){
                cartaPokemon temp = lista.cartas[j]; //armazena em temp para não perder o valor
                lista.cartas[j] = lista.cartas[j+1]; //troca a posição das cartas (o atual com o próximo)
                lista.cartas[j+1] = temp; //troca a posição das cartas novamente (o antigo atual agora vira o próximo)
                cond = 1;
            }
        }
    }
} 

void imprimir(Lista lista){
    if(lista.tamanho > 0){
        for(int i = 0; i < lista.tamanho; i++){
            cout<<lista.cartas;
        }
    }
}




#include <iostream>
#include "listaEstatica.hpp"
#include "TAD_POKEMON.hpp"
using namespace std;


int main() {

    Lista lista;
    cartaPokemon a1, a2, a3, a4;

    inicializa_baralho(lista);
    montaCarta(a1, "Pikachu", 5);
    montaCarta(a2, "Bobassauro", 4);
    montaCarta(a3, "Charmander", 3);
    montaCarta(a4, "Junior", 100);
    
    insereFim(lista, a1);
    insereFim(lista, a2);
    insereFim(lista, a3);
    insereFim(lista, a4);
    imprimir(lista);
    
    /*
    Implementação Generica duplamente encadeada

    TListaDE<cartaPokemon> lista;
    cartaPokemon carta;

    inicializaLista(lista);
    montaCarta(carta, "Pikachu", 67);
    insereFim(lista, carta);
    montaCarta(carta, "Charmander", 45);
    insereFim(lista, carta);
    imprimirItens(lista);
    */

    /*
    Implementação duplamente encadeada

    ListaDE lista;
 
    iniciaLista(lista);
    insereInicio(lista, "pikachu", 78);
    insereInicio(lista, "charmander", 54);
    insereInicio(lista, "reshiram", 100);
    imprimir(lista);

    cout << endl;

    removePosicao(lista, 2);
    imprimir(lista);
    */


    

    

    return 0;
}
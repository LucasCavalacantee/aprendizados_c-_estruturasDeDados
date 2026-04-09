#include <iostream>
using namespace std;

struct cartaPokemon{
    string nomeCarta;
    int raridade;
};

void montaCarta(cartaPokemon &carta, string nome, int nivel){
    carta.nomeCarta = nome;
    carta.raridade = nivel;
}

inline ostream& operator<<(ostream &out, const cartaPokemon &carta){
    out << "Nome: " << carta.nomeCarta << endl;
    out << "Nivel: " << carta.raridade;
    return out;
}


bool operator<(cartaPokemon a, cartaPokemon b){
    if(a.raridade < b.raridade){
        return true;
    } else {
        return false;
    }
}

bool compararRaridade(cartaPokemon a, cartaPokemon b){
    return a.raridade < b.raridade; // crescente
}
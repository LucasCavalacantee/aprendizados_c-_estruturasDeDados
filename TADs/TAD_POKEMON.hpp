#include <iostream>
using namespace std;

struct cartaPokemon{
    string nomeCarta;
    int nivel;
};

void montaCarta(cartaPokemon &carta, string nome, int nivel){
    carta.nomeCarta = nome;
    carta.nivel = nivel;
}

inline ostream& operator<<(ostream &out, const cartaPokemon &carta){
    out << "Nome: " << carta.nomeCarta << endl;
    out << "Nivel: " << carta.nivel;
    return out;
}




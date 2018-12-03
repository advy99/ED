#include <iostream>
#include <istream>
#include <ostream>
#include "Termino.h"

using namespace std;

//Constructor sin parametros

Termino::Termino(){


}

//Constructor con dos parametros

Termino::Termino (const string & palabra,
                  const string & definicion) {

	termino.first = palabra;
	termino.second.push_back(definicion);

}

Termino::Termino (const string & palabra,
                  const vector<string> & n_definiciones) {

	termino.first = palabra;
	termino.second = n_definiciones;

}

//Constructor de copia

Termino::Termino (const Termino & original){
    if (this != &original){
		 termino.first = original.termino.first;
		 termino.second = original.termino.second;
    }
}

//Funcion para obtener la palabra

string Termino::getPalabra() const{
	return termino.first;
}

//Funcion para obtener todas las definiciones

vector<string> Termino::getDefiniciones() const {
	return termino.second;
}

//Funcion para una definicion

string Termino::getDefinicion(const int indice) const {
	return termino.second.at(indice);
}


//Funcion para ver el numero de definiciones
//de una termino

int Termino::getNumDefiniciones() const{
	return termino.second.size();
}

//Operador para asignar la palabra

void Termino::setPalabra(const string & palabra){
	termino.first = palabra;
}

//Añade definiciones a un termino

void Termino::addDefinicion(const string & definicion){
	termino.second.push_back(definicion);
}


Termino::iterator Termino::begin(){
	return termino.second.begin();
}


Termino::const_iterator Termino::begin() const{
	return termino.second.begin();
}


Termino::iterator Termino::end(){
	return termino.second.end();
}


Termino::const_iterator Termino::end() const{
	return termino.second.end();
}

bool Termino::operator < (const Termino & otro) const{	
	return (termino.first < otro.termino.first);
}


//Operador de salida


ostream & operator << (ostream & os, const Termino & t){
	Termino::const_iterator it;
	for (it = t.begin(); it != t.end(); ++it){
		os << t.termino.first << "-->" << (*it) << endl;
	}
	return os;
}

//Operador de entrada

istream & operator >> (istream & in, Termino & termino){
	
	string palabra = "";
	string def = "";

	//Leemos el termino
	getline(in, palabra,';');

	termino.setPalabra(palabra);

	getline(in, def);

	termino.addDefinicion(def);


	return in;


}

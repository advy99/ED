#include <iostream>
#include <set>
#include "lista_palabras.h"

using namespace std;

lista_palabras::lista_palabras(){

}

int lista_palabras::size () const{
	return datos.size();
}

vector<string> lista_palabras::palabras_longitud(int longitud){
	vector<string> solucion;

	set<string>::const_iterator it;

	for(it = datos.begin(); it != datos.end(); it++ ){
		if( (*it).size() == longitud ){
			solucion.push_back((*it));
		}
	}

	return solucion;

}


bool lista_palabras::Esta(string palabra){
	return (datos.find(palabra) != datos.end());
}


istream & operator >> (istream & is, lista_palabras &D) {

	string palabra;

	while (getline(is, palabra)){
		D.datos.insert(palabra);
	}

	return is;

}

ostream & operator << (ostream & os, const lista_palabras &D){

	set<string>::const_iterator it;

	for(it = D.datos.begin(); it != D.datos.end(); it++){
		os << (*it) << endl;		
	}
	return os;
}


set<string>::iterator lista_palabras::begin(){
	return datos.begin();
}

set<string>::iterator lista_palabras::end(){
	return datos.end();
}

lista_palabras::iterator::iterator(){
	// no se como inicializar aqui :TT :TT
	it = begin();

}

string lista_palabras::iterator::operator *(){
	return (*it);
}

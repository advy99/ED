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

	iterator it;

	for(it = begin(); it != end(); ++it ){
		if( (*it).length() == (unsigned int) longitud ){
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


lista_palabras::iterator lista_palabras::begin(){

	// para el comienzo, lo iniciamos al comienzo de datos y lo devolvemos
	iterator iterador;
	iterador.it = datos.begin();
	return iterador;

}

lista_palabras::iterator lista_palabras::end(){
	//para el final, devolvemos uno vacio
	iterator iterador;
	iterador.it = datos.end();
	return iterador;
}

lista_palabras::iterator::iterator(){
//Creo que esto esta vacio

}

string lista_palabras::iterator::operator *(){ 
	return (*it);
}

lista_palabras::iterator & lista_palabras::iterator::operator++(){ 
	++it;
	return (*this);
}

bool lista_palabras::iterator::operator==(const lista_palabras::iterator &i){
	return i.it == it;
}

bool lista_palabras::iterator::operator!=(const lista_palabras::iterator &i){
	return !(i.it == it);
}



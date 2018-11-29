#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include "Diccionario.h"

#include "Termino.h"

using namespace std;

Diccionario::Diccionario(){

}

Diccionario::Diccionario(const Termino & termino){
	terminos.insert(termino);
}

Diccionario::Diccionario(const vector<Termino> n_terminos){
	vector<Termino>::const_iterator it;
	
	for(it = n_terminos.begin(); it != n_terminos.end(); ++it){
		terminos.insert((*it));
	}

}



Diccionario::Diccionario(const Diccionario & original){
	if (this != &original){
		terminos = original.terminos;
	}
}

vector<string> Diccionario::getDefiniciones(const string & palabra){
	set<Termino>::const_iterator it;
	vector<string> definiciones;

	Termino aux;
	aux.setPalabra(palabra);

	it = terminos.find(aux);

	if (it != terminos.end()){
		definiciones = (*it).getDefiniciones();
	}

	return definiciones;
}


set<Termino> Diccionario::getTerminos(){
	return terminos;
}

int Diccionario::numTerminos(){
   return terminos.size();        
}

void Diccionario::addTermino(const Termino & termino){
   terminos.insert(termino);
}

void Diccionario::removeTermino(const string & palabra){
	Termino aux;
	aux.setPalabra(palabra);

   terminos.erase(aux);
}


int Diccionario::posTermino(const string & palabra){
	Termino aux;
	aux.setPalabra(palabra);

	set<Termino>::iterator it;

   it = terminos.find(aux);

	int pos = distance(terminos.begin(), it);

	return pos;
}

Diccionario Diccionario::filtroIntervalo(const char & c_inicio,
                                         const char & c_fin){

}

Diccionario Diccionario::filtroClave(const string & clave){

}

int Diccionario::getNumDefiniciones(){    
   int num_definiciones = 0;
	set<Termino>::const_iterator it;
   for (it = terminos.begin(); it !=terminos.end(); ++it){
        num_definiciones += (*it).getNumDefiniciones();    
   }
   return num_definiciones;
}

int Diccionario::maxDefinicionesAsociadasAPalabra(){
	set<Termino>::const_iterator it;

	int max = 0;

	for (it = terminos.begin(); it != terminos.end(); ++it){
		if ((*it).getNumDefiniciones() > max){
			max = (*it).getNumDefiniciones();
		}
	}

	return max;

}

double Diccionario::promedioDefiniciones(){
	double promedio;

	promedio = (1.0 * getNumDefiniciones()/numTerminos());

	return promedio;
}

ostream & operator << (ostream & os, const Diccionario & d){
	Diccionario::const_iterator it;

	for(it = d.begin(); it != d.end(); ++it){
		os << *it;
	}
	
	return os;
}

istream & operator >> (istream & in, Diccionario & diccionario){

}

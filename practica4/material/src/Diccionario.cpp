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
	Diccionario filtrado;
	bool pasado = false;

	set<Termino>::iterator it;

	for (it = terminos.begin(); it != terminos.end(); it++){
		pasado = c_fin < (*it).getPalabra().at(0);

		if (c_inicio <= (*it).getPalabra().at(0) && !pasado )
			filtrado.addTermino((*it));
	}

	return filtrado;
}

Diccionario Diccionario::filtroClave(const string & clave){

	Diccionario filtrado;

	set<Termino>::iterator it;
	Termino t;

	for (it = terminos.begin(); it != terminos.end(); it++){

		Termino::const_iterator it_ter;
		
		t.setPalabra((*it).getPalabra());
		for (it_ter = (*it).begin() ;it_ter != (*it).end() ; it_ter++ ){
			
			//Si encuentra la posicion, esa definicion lo tiene
			if ((*it_ter).find(clave) != string::npos )
				t.addDefinicion((*it_ter));

		}

		if (t.getNumDefiniciones() > 0)
			filtrado.addTermino(t);
		

	}


	return filtrado;

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

Diccionario::iterator Diccionario::begin(){
	return terminos.begin();
}

Diccionario::const_iterator Diccionario::begin() const{
	return terminos.begin();
}

Diccionario::iterator Diccionario::end(){
	return terminos.end();
}

Diccionario::const_iterator Diccionario::end() const{
	return terminos.end();
}


ostream & operator << (ostream & os, const Diccionario & d){
	Diccionario::const_iterator it;

	for(it = d.begin(); it != d.end(); ++it){
		os << *it;
	}
	
	return os;
}

istream & operator >> (istream & in, Diccionario & diccionario){

	string palabra = "";
	string definicion = "";

	getline(in,palabra, ';');


	while(!in.eof()){

		Termino t;
		
		getline(in,definicion);

		t.setPalabra(palabra);
		t.addDefinicion(definicion);

		getline(in,palabra, ';');

		while (palabra == t.getPalabra()){

			getline(in,definicion);
			t.addDefinicion(definicion);

			getline(in,palabra,';');

		}

		diccionario.addTermino(t);


	}

	return in;
}

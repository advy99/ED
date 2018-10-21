#include <iostream>
#include <istream>
#include <ostream>
#include "Diccionario.h"
#include "Vector_Dinamico.h"
#include "Termino.h"

using namespace std;

Diccionario::Diccionario(){

}

Diccionario::Diccionario(const Termino & termino){
	terminos.resize(1);
	terminos[0] = termino;
}

Diccionario::Diccionario(const Vector_Dinamico<Termino> n_terminos){
	terminos = n_terminos;

}

Diccionario::Diccionario(const Diccionario & original){
	terminos = original.terminos;
}

Vector_Dinamico<string> Diccionario::getDefiniciones(const string & palabra){
	return terminos[posTermino(palabra)].getDefiniciones();
}


Vector_Dinamico<Termino> Diccionario::getTerminos(){
	return terminos;
}

int Diccionario::numTerminos(){
	return terminos.size();
}

void Diccionario::addTermino(const Termino & termino){

	int i = numTerminos() - 1;
	int pos;
	bool pos_encontrada = false;
	bool palabra_encontrada = false;

	while (i >= 0 && !pos_encontrada ){
		//Si es la misma palabra, añadimos las definiciones
		if (terminos[i].getPalabra().compare(termino.getPalabra() ) == 0){
			for(int j = 0; j < termino.getNumDefiniciones(); j++)
				terminos[i].addDefinicion(termino.getDefinicion(j));
			palabra_encontrada = true;
		}
		else if(terminos[i].getPalabra().compare(termino.getPalabra() ) > 0){
			pos = i + 1;
			pos_encontrada = true;
		}
		
		i--;

	}

	if (!palabra_encontrada){
		terminos.resize(numTerminos()+1);
		if (pos_encontrada){
			int i = numTerminos();
			while (i >= pos){
				terminos[i] = terminos[i - 1];
				i--;
			}

			terminos[pos] = termino;

		}else{	
			terminos[numTerminos()-1] = termino;
		}
	}

}

void Diccionario::removeTermino(const string & palabra){
	Vector_Dinamico<Termino> aux(terminos.size()-1 );

	int a_eliminar = posTermino(palabra);
	int i = 0;
	
	while (i < a_eliminar){
		aux[i] = terminos[i];
		i++;
	}
	//Saltamos la posicion a eliminar
	i++;

	//Copiamos los restantes
	while (i < terminos.size()){
		aux[i-1] = terminos[i];
		i++;
	}


}


int Diccionario::posTermino(const string & palabra){

	int media;
	bool encontrado = false;
	int inferior = 0, superior = terminos.size();

	while( (inferior < superior) && !encontrado){
		media = (inferior+superior)/2;

		if(terminos[media].getPalabra() == palabra)
			encontrado = true;
		else if ( terminos[media].getPalabra().compare( palabra ) < 0 )
			inferior = media + 1;
		else
			superior = media - 1;
	}

	return media;

}

Diccionario Diccionario::filtroIntervalo(const char & c_inicio,
                                         const char & c_fin){
	Diccionario filtrado;
	bool pasado = false;

	for (int i = 0; i < terminos.size() && !pasado; i++){
		pasado = c_fin > terminos[i].getPalabra().at(0);

		if (c_inicio >= terminos[i].getPalabra().at(0) && !pasado )
			filtrado.addTermino(terminos[i]);
	}

	return filtrado;
}

Diccionario Diccionario::filtroClave(const string & clave){
	Diccionario filtrado;

	for (int i = 0; i < numTerminos(); i++){

		Termino t;
		for (int j = 0; j < terminos[i].getNumDefiniciones(); j++){
			
			t.setPalabra(terminos[i].getPalabra());
			//Si encuentra la posicion, esa definicion lo tiene
			if (terminos[i].getDefinicion(j).find(clave) != string::npos )
				t.addDefinicion(terminos[i].getDefinicion(j));

		}

		if (t.getNumDefiniciones() > 0)
			filtrado.addTermino(t);
		

	}


	return filtrado;
}

int Diccionario::getNumDefiniciones(){
	int n_definiciones = 0;

	for(int i = 0; i < terminos.size(); i++)
		n_definiciones += terminos[i].getNumDefiniciones();

	return n_definiciones;
}

int Diccionario::maxDefinicionesAsociadasAPalabra(){

	int max = 0;

	for(int i = 0; i < terminos.size(); i++)
		if (max < terminos[i].getNumDefiniciones() )
			max = terminos[i].getNumDefiniciones();

	return max;
}

double Diccionario::promedioDefiniciones(){
	//Multiplicamos por 1.0 para que la operacion devuelva un double
	return  1.0*getNumDefiniciones()/numTerminos();
}

ostream & operator << (ostream & out, Diccionario & diccionario){
	for(int i = 0; i < diccionario.numTerminos(); i++){
		out << diccionario.terminos[i] << endl;
	}

	return out;
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
#include <iostream>
#include "Termino.h"
#include "Vector_Dinamico.h"

using namespace std;

//Constructor sin parametros

Termino::Termino(){
	termino = "";

}

//Constructor con dos parametros

Termino::Termino (const string & palabra,
                  const string & definicion) {
    
    termino = palabra;
	 definiciones.resize(1);
    definicion[0] = ddefinicion;
}

Termino::Termino (const string & palabra,
                  const Vector_Dinamico<string> & n_definiciones) {
    
    termino = palabra;
    definiciones = n_ddefiniciones;
}

//Constructor de copia

Termino::Termino (const Termino & original){
    if (this != &original){
        termino = original.termino;
        definiciones = original.definiciones;
    }
}

//Funcion para obtener la palabra

string Termino::getPalabra() const{
    return (termino);
}

//Funcion para obtener todas las definiciones

Vector_Dinamico<string> Termino::getDefiniciones() const {
    return (definiciones);
}

//Funcion para una definicion

Vector_Dinamico<string> Termino::getDefiniciones(const int indice) const {
    return (definiciones[indice]);
}


//Funcion para ver el numero de definiciones
//de una termino

int Termino::getNumDefiniciones() const{
    return(definiciones.size);
}

//Operador para asignar la palabra

void Termino::setPalabra(const string & palabra){
    termino = palabra;
}

//Añade definiciones a un termino

void Termino::addDefinicion(const string & definicion){
    definiciones.resize(getNumDefiniciones()+1);
    definiciones [getNumDefiniciones()-1] = definicion;
}

//Operador de salida

ostream & operator << (ostream & out, Termino termino){

	out << termino.getPalabra() << " : "  ;

	for (int i = 0; i < termino.getNumDefiniciones(); i++)
		out << "\t" << termino.getDefinicion(i) << endl;
	
	return out;

}

//Operador de entrada

istream & operator >> (istream & in, Termino termino){

	in >> termino.termino;

	string def = "";

	while (!eof()){
		getline(in, def);

		termino.addDefinicion(def);
	}

	return in;

}
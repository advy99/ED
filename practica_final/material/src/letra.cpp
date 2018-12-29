#include <iostream>
#include "letra.h"

char letra::getCaracter() const{
	return caracter;
}

int letra::getPuntuacion() const{
   return puntuacion;
}

int letra::getNumApariciones() const{
	return num_apariciones;
}


istream & operator >> (istream & is, letra & l){

	is >> l.caracter;
	is >> l.num_apariciones;
	is >> l.puntuacion;

	return is;
}

ostream & operator << (ostream & os, const letra & l){
	os << l.caracter << "\t" << l.num_apariciones << "\t" << l.puntuacion << endl;

	return os;
}
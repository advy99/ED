#include <iostream>
#include "letra.h"

letra::letra(){
	
}

char letra::getCaracter() const{
	return caracter;
}

int letra::getPuntuacion() const{
   return puntuacion;
}

int letra::getCantidad() const{
	return cantidad;
}


bool letra::operator == (const letra & otra) const{
	return otra.getCaracter() == getCaracter();
}

bool letra::operator < (const letra & otra) const{
	return caracter < otra.getCaracter();
}

istream & operator >> (istream & is, letra & l){

	is >> l.caracter;
	is >> l.cantidad;
	is >> l.puntuacion;

	return is;
}

ostream & operator << (ostream & os, const letra & l){
	os << l.caracter << "\t" << l.cantidad << "\t" << l.puntuacion << endl;

	return os;
}
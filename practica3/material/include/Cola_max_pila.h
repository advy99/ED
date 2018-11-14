#ifndef COLA_MAX_PILA
#define COLA_MAX_PILA

#include "Pila_max.h"

template <class T>
class Cola_max{
private:
	Pila_max<T> entrada;
	stack< pair<T,T> > salida;


public:
	Cola_max();

	T frente();

	T maximo();

	T final();

	T final_maximo ();

	void poner(T elemento);

	void quitar();

	bool vacia();

	int num_elementos();

};

#include "Cola_max_pila.tpp"


#endif

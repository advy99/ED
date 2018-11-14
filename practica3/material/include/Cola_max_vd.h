#ifndef COLA_MAX_VD
#define COLA_MAX_VD

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Cola_max{
private:
	vector<pair<T,T> > cola;


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


#include "Cola_max_vd.tpp"

#endif

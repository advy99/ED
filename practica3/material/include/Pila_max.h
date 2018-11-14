#ifndef PILAMAX
#define PILAMAX

#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class Pila_max{
private:
	stack< pair<T,T> > pila;

public:

	Pila_max();

	pair<T,T> top();

//	pair<T,t> top_max();

	void push(T elemento);

	void pop();

	bool empty();

	int size();

};

#include "Pila_max.tpp"

#endif

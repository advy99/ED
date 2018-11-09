/**
 * 
 * @author Antonio David Villegas Yeguas - 2B - Curso 18/19
 * 
 */

#include <iostream>
#include <stack>

using namespace std;

template<typename T>
void insertar(stack<T> &P, int pos, const T &x);

int main(){
	stack<unsigned> pila;
	int lectura;

	unsigned a_insertar, posicion;

	cout << "Introduce un numero (negativo para finalizar) : ";
	cin >> lectura;

	while (lectura >= 0){
		pila.push(lectura);

		cout << "Introduce un numero (negativo para finalizar) : ";
		cin >> lectura;
	}

	cout << "Introduce el elemento a insertar: ";
	cin >> a_insertar;

	cout << "Introduce la posicion : ";
	cin >> posicion;

	insertar(pila, posicion, a_insertar);

	cout << endl << "Elementos de la pila (mostrados segun sacamos de la pila): "
	     << endl;

	while( !pila.empty()){
		cout << pila.top() << " ";

		pila.pop();
	}


	return 0;
}


/**
 * @brief Insertar un valor en una posicion de una pila
 * 
 * @param P Pila donde insertar el valor
 * @param pos Posicion a insertar el valor
 * @param x Valor a insertar
 * 
 * Si la posicion es menor que 0, se inserta al principio
 * Si la posicion es mayor que P.size(), se inserta al final
 */

template<typename T>
void insertar(stack<T> &P, int pos, const T &x){
	stack<T> temporal;
	int i = 0;

	while (! P.empty()){
		temporal.push(P.top());

		P.pop();
	}

	while (i < pos && !temporal.empty()){
		P.push(temporal.top());
		temporal.pop();
		i++;
	}

	P.push(x);

	while (!temporal.empty()){
		P.push(temporal.top());
		temporal.pop();
	}
}
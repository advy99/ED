/**
 * 
 * @author Antonio David Villegas Yeguas - 2B - Curso 18/19
 * 
 */

#include <iostream>
#include <stack>

using namespace std;

template<typename T>
void substituye(stack<T> &P, const T &x, const T &y);


int main(){
	stack<unsigned> pila;
	int lectura;

	unsigned a_reemplazar, reemplazante;

	cout << "Introduce un numero (negativo para finalizar) : ";
	cin >> lectura;

	while (lectura >= 0){
		pila.push(lectura);

		cout << "Introduce un numero (negativo para finalizar) : ";
		cin >> lectura;
	}

	cout << "Introduce el elemento a reemplazar: ";
	cin >> a_reemplazar;

	cout << "Introduce el elemento con el que reemplazar: ";
	cin >> reemplazante;

	substituye(pila, a_reemplazar, reemplazante);

	cout << endl << "Elementos de la pila: " << endl;

	while( !pila.empty()){
		cout << pila.top() << " ";

		pila.pop();
	}


	return 0;
}


/**
 * @brief Sustituir un valor por otro en una pila
 * 
 * @param P Pila donde sustituir el valor
 * @param x Valor a sustituir
 * @param y Valor con el que sustituir
 * 
 * Si el valor no esta en la pila, no se modifica la pila original
 */

template<typename T>
void substituye(stack<T> &P, const T &x, const T &y){
	
	stack<T> temporal;

	while( !P.empty() ){
		temporal.push(P.top());

		P.pop();
	}

	while ( !temporal.empty() ){
		if(temporal.top() == x)
			P.push(y);
		else
			P.push(temporal.top());

		temporal.pop();
	}

}
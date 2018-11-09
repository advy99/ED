/**
 * 
 * @author Antonio David Villegas Yeguas - 2B - Curso 18/19
 * 
 */

#include <iostream>
#include <queue>


using namespace std;

template<typename T>
void insertar(queue<T> &P, int pos, const T &x);


int main(){
	queue<unsigned> cola;
	int lectura;

	unsigned a_insertar, posicion;

	cout << "Introduce un numero (negativo para finalizar) : ";
	cin >> lectura;

	while (lectura >= 0){
		cola.push(lectura);

		cout << "Introduce un numero (negativo para finalizar) : ";
		cin >> lectura;
	}

	cout << "Introduce el elemento a insertar: ";
	cin >> a_insertar;

	cout << "Introduce la posicion : ";
	cin >> posicion;

	insertar(cola, posicion, a_insertar);

	cout << endl << "Elementos de la cola : "
	     << endl;

	while( !cola.empty()){
		cout << cola.front() << " ";

		cola.pop();
	}
	
	
	return 0;
}

/**
 * @brief Insertar un valor en una posicion de una cola
 * 
 * @param P Cola donde insertar el valor
 * @param pos Posicion a insertar el valor
 * @param x Valor a insertar
 * 
 * Si la posicion es menor que 0, se inserta al principio
 * Si la posicion es mayor que P.size(), se inserta al final
 */
template<typename T>
void insertar(queue<T> &P, int pos, const T &x){
	queue<T> temporal;
	int i = 0;

	while (! P.empty()){
		temporal.push(P.front());

		P.pop();
	}

	while (i < pos && !temporal.empty()){
		P.push(temporal.front());
		temporal.pop();
		i++;
	}

	P.push(x);

	while (!temporal.empty()){
		P.push(temporal.front());
		temporal.pop();
	}
}
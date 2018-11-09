/**
 * 
 * @author Antonio David Villegas Yeguas - 2B - Curso 18/19
 * 
 */

#include <iostream>
#include <stack>

using namespace std;


template<typename T>
class Cola{
	private:
		stack<T> entrada;
		stack<T> salida;

		void volcar_entrada(){
			while( !entrada.empty() ){
				salida.push(entrada.top());
				entrada.pop();
			}
		}

	public:

		/**
		 * @brief Constructor por defecto
		 * 
		 */

		Cola(){

		}

		/**
		 * @brief Añadir un elemento al final de la cola
		 * 
		 */


		void push(T & elemento){
			entrada.push(elemento);
		}

		/**
		 * @brief Eliminar un elemento de la cola
		 * 
		 */

		void pop(){
			if (salida.size() == 0 )
				volcar_entrada();

			salida.pop();
		}

		/**
		 * @brief Consultar el primer elemento
		 * 
		 * @return Referencia al primer elemento de la cola
		 */

		T & front(){
			if (salida.size() == 0 )
				volcar_entrada();

			return salida.top();
		}

		/**
		 * @brief Consultar el ultimo elemento
		 * 
		 * 
		 * @return Referencia al ultimo elemento de la cola
		 */
		T & back(){
			return entrada.top();
		}


		/**
		 * @brief Consultar si la cola esta vacia
		 * 
		 * 
		 * @return bool, true si esta vacia, false si no
		 */

		bool empty(){
			return size() == 0;
		}


		/**
		 * @brief Consultar el numero de elementos de la cola
		 * 
		 * 
		 * @return Entero con el numero de elementos
		 */

		int size(){
			return (entrada.size() + salida.size());
		}


};


int main(){

	Cola<int> c1;

	int lectura;

	cout << "Introduce datos para la cola (negativos para acabar): ";
	cin >> lectura;

	while (lectura >= 0){

		c1.push(lectura);

		cin >> lectura;
	}

	cout << endl << "Tamaño: " << c1.size();
	cout << endl << endl;

	while(!c1.empty()){
		cout << c1.front() << " ";
		c1.pop();
	}

	return 0;
}
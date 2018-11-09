/**
 * 
 * @author Antonio David Villegas Yeguas - 2B - Curso 18/19
 * 
 */

#include <iostream>
#include <queue>

using namespace std;

template<typename T>
class Pila{
	private:
		queue<T> c1;
		queue<T> c2;

	public:

		/**
		 * @brief Constructor por defecto
		 * 
		 */

		Pila(){

		}

		/**
		 * @brief Añadir un elemento al final de la pila
		 * 
		 */

		void push(T & elemento){
			c1.push(elemento);
		}

		/**
		 * @brief Eliminar un elemento de la pila
		 * 
		 */

		void pop(){
			while(c1.size() > 1 ){
				c2.push(c1.front());
				c1.pop();
			}

			c1.pop();

			c1 = c2;
			
			queue<T> vacia;

			c2 = vacia;

		}


		/**
		 * @brief Consultar el tope de la pila
		 * 
		 * @return Valor del tope de la pila
		 */

		T top(){
			return c1.back();
		}

		/**
		 * @brief Consultar si la pila esta vacia
		 * 
		 * 
		 * @return bool, true si esta vacia, false si no
		 */


		bool empty(){
			return size() == 0;
		}

		/**
		 * @brief Consultar el numero de elementos de la pila
		 * 
		 * 
		 * @return Entero con el numero de elementos
		 */


		int size(){
			return c1.size() + c2.size();
		}

};


int main(){

	Pila<int> p1;

	int lectura;

	cout << "Introduce datos para la pila (negativos para acabar): ";
	cin >> lectura;

	while (lectura >= 0){

		p1.push(lectura);

		cin >> lectura;
	}

	cout << endl << "Tamaño: " << p1.size();
	cout << endl << endl;

	while(!p1.empty()){
		cout << p1.top() << " ";
		p1.pop();
	}

	return 0;
}


// La operacion push es O(1), ya que lo añadimos al final
// La operacion pop es O(n), ya que necesita mover los n elementos de la cola
//para alcanzar el que queriamos.
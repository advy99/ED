/**
 * 
 * @author Antonio David Villegas Yeguas - 2B - Curso 18/19
 * 
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template<typename T>
class Ventana{

	private:
		stack<T> izq;
		stack<T> drch;

	public:

		Ventana(){

		}

		Ventana(vector<T> vec){
			for(int i = 0; i < vec.size(); i++){
				izq.push(vec[i]);
			}
		}

		void mov_derecha(){
			if(!drch.empty()){
				izq.push(drch.top());

				drch.pop();
			}
		}

		void mov_izquierda(){
			if(!izq.empty()){
				drch.push(izq.top());

				izq.pop();
			}
		}

		void insertar(T & elemento){
			izq.push(elemento);
		}


		void borrar(){
			if (izq.size() > 0)
				izq.pop();
		}

		int size() const{
			return izq.size()+drch.size();
		}

		bool empty() const{
			return izq.empty() && drch.empty();
		}

		T cursor(){
			return izq.top();
		}

};


int main(){


	Ventana<char> ventana;

	char c = 'h';

	ventana.insertar(c);

	c = 'o';
	ventana.insertar(c);

	c = 'l';
	ventana.insertar(c);
	
	c = 'a';
	ventana.insertar(c);
	
	c = ' ';
	ventana.insertar(c);
	
	c = 'm';
	ventana.insertar(c);
	
	c = 'u';
	ventana.insertar(c);
	
	c = 'n';
	ventana.insertar(c);
	
	c = 'd';
	ventana.insertar(c);
	
	c = 'o';
	ventana.insertar(c);

	ventana.mov_izquierda();
	ventana.mov_izquierda();
	ventana.mov_izquierda();
	ventana.mov_izquierda();
	ventana.mov_izquierda();
	ventana.mov_izquierda();

	c = ' ';
	ventana.insertar(c);

	ventana.mov_izquierda();
	ventana.mov_izquierda();
	ventana.mov_izquierda();
	ventana.mov_izquierda();
	ventana.mov_izquierda();

	for (int i = 0; i < ventana.size(); i++){
		ventana.mov_derecha();
		cout << ventana.cursor();
	}


	

	cout << endl << "El tamaño de la ventana es " << ventana.size() << endl;

	if (ventana.empty())
		cout << "La ventana esta vacia" << endl;
	else
		cout << "La ventana no esta vacia" << endl;

}
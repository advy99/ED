/**
 * 
 * @author Antonio David Villegas Yeguas - 2B - Curso 18/19
 * 
 */

#include <iostream>
#include <stack>

using namespace std;

bool parentesis_correctos(string expresion);

int main(){

	string cadena = "";

	cout << "Introduce una cadena de texto: ";
	getline(cin, cadena);

	if (parentesis_correctos(cadena))
		cout << "Los parentesis estan en correcto orden" << endl;
	else
		cout << "El orden de los parentesis no es correcto" << endl;


	return 0;
}

/**
 * @brief Comprobar que los parentesis estan correctamente situados en una expresion
 * 
 * @param expresion String en el que se comprobaran los parentesis
 * 
 * @return bool: true si estan correctamente situados, false si ocurre lo contrario
 */

bool parentesis_correctos(string expresion){
	stack<char> parentesis;
	bool correctos = true;

	for(int i = 0; i < expresion.size() && correctos ; i++){
		if (expresion.at(i) == '(' || expresion.at(i) == ')' )
			parentesis.push(expresion.at(i));

		if (parentesis.size() > 1 && expresion.at(i) == ')' ){
			parentesis.pop();
			if (parentesis.top() == '(') 
				parentesis.pop();
			else
				correctos = false;
		}
	}

	correctos = parentesis.empty();

	return correctos;
	

}
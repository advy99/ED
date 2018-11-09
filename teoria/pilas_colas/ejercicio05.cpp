/**
 * 
 * @author Antonio David Villegas Yeguas - 2B - Curso 18/19
 * 
 */


#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool palindromo (string cad);

int main(){
	string cadena = "";

	cout << "Introduce una cadena de texto: ";
	getline(cin, cadena);

	if (palindromo(cadena))
		cout << "La cadena es un palindromo" << endl;
	else
		cout << "La cadena no es un palindromo" << endl;

	return 0;
}

/**
 * @brief Funcion que comprueba si una cadena conforma un palindromo
 * 
 * @param cad Cadena a comprobar 
 * 
 */

bool palindromo (string cad){
	bool palindromo = true;

	queue<char> segunda_mitad;
	stack<char> primera_mitad;

	for(int i = 0; i < cad.size(); i++){
		primera_mitad.push(cad.at(i));
		segunda_mitad.push(cad.at(i));
	}

	while (palindromo && !primera_mitad.empty()){
		palindromo = primera_mitad.top() == segunda_mitad.front();
		primera_mitad.pop();
		segunda_mitad.pop();
	}

	return palindromo;
}
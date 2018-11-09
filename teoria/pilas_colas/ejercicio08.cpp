/**
 * 
 * @author Antonio David Villegas Yeguas - 2B - Curso 18/19
 * 
 */

#include <iostream>
#include <stack>
#include <sstream>
#include <cmath>

using namespace std;

template<typename T>
T evaluar(string expresion, pair<char, T> variables[], int num_variables);
bool isoperator(char c);

template<typename T>
T operar(T val1, T val2, char op);
int obtener_num_variables(string expr);


int main(){

	string expr;
	char inicio_var = 'a';
	int val;

	cout << "Introduce una extresion: ";
	getline(cin, expr);

	int n_variables = obtener_num_variables(expr);

	pair<char, int> variables[n_variables];

	for(int i = 0; i < n_variables; i++){
		cout << "Introduce el valor de la variable " << inicio_var << " ";
		cin >> val;
		variables[i].first = inicio_var;
		variables[i].second = val;

		inicio_var++;
	}

	int res = evaluar(expr, variables, n_variables);

	cout << "El resultado de la evaluacion es " << res << endl; 

	return 0;

}

/**
 * @brief Funcion que evalua una expresion en forma postfija
 * 
 * @param expresion Expresion a evaluar
 * @param variables Variables que conforman la expresion
 * @param num_variables Numero de variables que conforman la expresion
 * 
 * @pre La expresion es correcta en forma postfija
 *
 * @return Evaluacion de la expresion 
 */

template<typename T>
T evaluar(string expresion, pair<char, T> variables[], int num_variables){
	istringstream iss;
	stack<T> var;
	T resultado;

	T var1, var2;

	iss.str(expresion);

	char c;

	iss >> c;

	while(!iss.eof()){
		

		if (isoperator(c)){
			
			var2 = var.top();
			var.pop();
		
			var1 = var.top();
			var.pop();

			var.push(operar(var1, var2, c));
			
		}else{
			bool encontrado = false;
			for (int i = 0; i < num_variables && !encontrado; i++){
				if(variables[i].first == c ){
					var.push(variables[i].second);
					encontrado = true;
				}
			}

		}

		iss >> c;
	}

	return var.top();

}

/**
 * @brief Comprueba si un caracter es un operador
 * 
 * @param c Caracter a comprobar
 * 
 * @return bool, true si es un operador
 */

bool isoperator(char c){
	return (c == '+' || c == '-' || c == '*' || c == '^' || c == '/');
}

/**
 * @brief Evalua dos valores con un operador
 * 
 * @param val1 Valor 1
 * @param val2 Valor 2
 * @param c Caracter que es el operador
 * 
 * @pre c es un operador
 * @return Evaluacion de: val1 c val2
 */

template<typename T>
T operar(T val1, T val2, char c){

	T res;
	if(c == '+'){
		res = val1 + val2;
	
	}else if (c == '-'){
		res = val1 - val2;
	
	}else if (c == '*'){
		res = val1 * val2;
	
	}else if (c == '/'){
		res = val1 / val2;
	
	}else if (c == '^'){
		res = pow(val1, val2);
	}

	return res;
}

int obtener_num_variables(string expr){
	istringstream iss;
	int n = 0;

	iss.str(expr);

	char c;

	iss >> c;

	while (!iss.eof()){
		if (! isoperator(c) )
			n++;
		iss >> c;
	}

	return n;
}
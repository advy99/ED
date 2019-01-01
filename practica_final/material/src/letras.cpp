#include <iostream>
#include <fstream>
#include "lista_palabras.h"
#include "bolsa_letras.h"

using namespace std;


int main(int argc, char * argv[]){

	if (argc != 5){
		cerr << "ERROR: Numero erroneo de argumentos." << endl
			  << "Uso : " << argv[0] << " <lista_palabras> <letras> <numero_letras> <modalidad de juego> "
			  << endl
			  << "Modalidades de jugo: " << endl << "\t L (Longitud de palabra) " 
			  << "\t P (Puntuacion de la palabra)" << endl;

		exit(1);
	}

	ifstream f(argv[1]);

	int num_letras = atoi(argv[3]);

	lista_palabras palabras;

	f >> palabras;

	f.close();

	conjunto_letras letras;

	f.open(argv[2], fstream::in);

	f >> letras;

	f.close();

	bolsa_letras bolsa(letras);

	bolsa_letras aleatorias;

	aleatorias = bolsa.getLetras( num_letras );

	cout << "Las letras son: ";

	cout << aleatorias;

	






	return 0;
}
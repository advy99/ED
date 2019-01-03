#include <iostream>
#include <fstream>
#include "lista_palabras.h"
#include "conjunto_letras.h"
#include "letra.h"


using namespace std;

int main(int argc, char * argv[]){

	if( argc != 4 ){
		cerr << "ERROR: Numero erroneo de argumentos" << endl
			  << "Uso : " << argv[0] << " <lista_palabras> <letras> <salida> "
			  << endl;


		exit(1);

	}

	fstream f(argv[1]);

	if(!f) {

		cout << "No se puede abrir el fichero" << argv[1] << endl;
		
		exit(2);
	}

	lista_palabras palabras;

	f >> palabras;

	f.close();



	f.open(argv[2], fstream::in);

	if(!f) {

		cout << "No se puede abrir el fichero" << argv[2] << endl;
		
		exit(3);
	}

	conjunto_letras letras;

	f >> letras;

	f.close();


	conjunto_letras contadas;

	contadas = letras.contarLetras(palabras);

	f.open(argv[3], fstream::out);

	if(!f) {

		cout << "No se puede abrir el fichero" << argv[3] << endl;
		
		exit(4);
	}

	int totalLetras = contadas.totalLetras();

	f << "#Letra Cantidad" << endl;

	for(conjunto_letras::iterator it = contadas.begin(); it != contadas.end(); ++it){
		f << (*it).getCaracter() << "\t" << ( (*it).getCantidad()*100.0) / totalLetras << endl;
	}



	return 0;
}
#include <iostream>
#include <fstream>
#include "lista_palabras.h"
#include "conjunto_letras.h"
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

	int num_letras = atoi(argv[3]);

	if (num_letras <= 0){
		cout << "El numero de letras con el que jugar ha de ser mayor que 0" << endl;
	
		exit(2);
	}

	if (argv[4][0] != 'P' && argv[4][0] != 'L'){
		cout << "Modos de juego no reconocidos" << endl;

		exit(3);
	}

	ifstream f(argv[1]);

	if(!f) {

		cout << "No se puede abrir el fichero" << argv[1] << endl;
		
		exit(4);
	}

	

	lista_palabras palabras;

	f >> palabras;

	f.close();

	conjunto_letras letras;

	f.open(argv[2], fstream::in);

	if(!f) {

		cout << "No se puede abrir el fichero" << argv[2] << endl;
		
		exit(5);
	}

	f >> letras;

	f.close();

	bolsa_letras bolsa(letras);

	bolsa_letras aleatorias;


	bool salir = false;

	char jugar;

	while(!salir){
		aleatorias = bolsa.getLetras( num_letras );

		cout << "Las letras son: ";

		cout << aleatorias;

		string usuario;

		cout << endl << "Dime tu solucion: ";
		cin >> usuario;

		if (aleatorias.estanLetras(usuario)){
			if( palabras.Esta(usuario) ){
				cout << endl << usuario << "\t Puntuacion: " << letras.getPuntuacion(usuario, argv[4][0]) << endl << endl;

			}else {	
				cout << endl << "Esa palabra no existe" << endl << endl;
			}
		}else{
			cout << endl << "La palabra dada contiene caracteres que no se han proporcionado" << endl;
		}



		set<pair<int, string> > soluciones = aleatorias.getSoluciones(letras, palabras, argv[4][0]);

		set<pair<int, string> >::const_iterator it;

		cout << "Posibles soluciones: " << endl;
		for(it = soluciones.begin(); it != soluciones.end(); ++it){
			cout << it->first << " Puntuacion: " << it->second << endl;  
		}

		cout << endl << "La mejor solucion es :" << endl;
		cout << soluciones.rbegin()->first << " Puntuacion " << soluciones.rbegin()->second << endl; 


		do{
			cout << "¿Quieres volver a jugar? [S/N] ";

			cin >> jugar;

			jugar = toupper(jugar);

		}while(jugar != 'S' && jugar != 'N');
		
		if (jugar != 'S')
			salir = true;

	}


	return 0;
}
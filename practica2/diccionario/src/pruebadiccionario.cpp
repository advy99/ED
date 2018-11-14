#include "Diccionario.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con el diccionario"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   

	string palabra;
	char c_inicio, c_fin;


   Diccionario mi_diccionario;

	cout << endl << "Comenzando a cargar diccionario."  << endl;

   f>>mi_diccionario; //Cargamos en memoria el diccionario

	cout << endl << "Diccionario cargado correctamente en memoria." << endl;
   
   /* Exhibir aqui la funcionalidad programada para el TDA Diccionario / TDA Termino  
    Algunas sugerencias: 
    - Obtener las definiciones asociadas a una palabra   
    - Obtener el (sub)diccionario de términos comprendidos en [caracter_inicial, caracter_final]
    - Obtener el (sub)diccionario de términos asociados a una palabra clave. Ejemplo: el diccionario de terminos asociados a "color"   
    - Obtener el numero total de definiciones, el maximo de definiciones asociadas a una unica palabra y el promedio de definiciones por palabra
    - Cualquier otra funcionalidad que considereis de interes 
   */
	

	cout << "Introduce una palabra para mostrar sus definiciones: ";
	cin >> palabra;

	Vector_Dinamico<string> def;

	def = mi_diccionario.getDefiniciones(palabra);

	cout << endl << palabra << ": " << endl;
	for (int i = 0 ; i < def.size();i++){
		cout << "\t" << def[i] << endl;

	}


	cout << endl << "Introduce el caracter de inicio para el filtro: ";
	cin >> c_inicio;

	cout << endl << "Introduce el caracter de fin para el filtro: " ;
	cin >> c_fin;

	Diccionario subdiccionario;
	subdiccionario = mi_diccionario.filtroIntervalo(c_inicio, c_fin);

	cout << subdiccionario  << endl;

	cout << endl << endl << endl << "Usando filtro clave color:" << endl;

	subdiccionario = mi_diccionario.filtroClave("color");

	cout << subdiccionario << endl;


	cout << endl << "Numero de definiciones totales: "
					 << mi_diccionario.getNumDefiniciones() << endl;

	cout << endl << "Maximo de definiciones asociadas a una palabra: "
	             << mi_diccionario.maxDefinicionesAsociadasAPalabra() << endl;

	cout << endl << "Promedio de definiciones por palabra: "
	             << mi_diccionario.promedioDefiniciones() << endl;


	cout << "Introduce una palabra a eliminar (la palabra ha de estar en el diccionario): ";
	cin >> palabra;

	mi_diccionario.removeTermino(palabra);

	cout << mi_diccionario;


}

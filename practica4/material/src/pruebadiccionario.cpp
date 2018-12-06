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

   Diccionario mi_diccionario;
   f>>mi_diccionario; //Cargamos en memoria el diccionario
   //Usamos un iterador para recorrer los terminos del diccionario e imprimirlos
   Diccionario::const_iterator it;
   for(it = mi_diccionario.begin(); it != mi_diccionario.end(); ++it){
     cout << (*it) << endl;
   }

   /* Exhibir aqui la funcionalidad programada para el TDA Diccionario / TDA Termino
    - Obtener las definiciones asociadas a una palabra
    - Obtener el (sub)diccionario de términos comprendidos en [caracter_inicial, caracter_final]
    - Obtener el (sub)diccionario de términos asociados a una palabra clave. Ejemplo: el diccionario de terminos asociados a "color"
    - Obtener el numero total de definiciones, el maximo de definiciones asociadas a una unica palabra y el promedio de definiciones por palabra
    - Cualquier otra funcionalidad que considereis de interes
   */


  string palabra;
  cout << endl << "Introduce una palabra :" << endl;
  cin >> palabra;

  vector<string> def = mi_diccionario.getDefiniciones(palabra);

  cout << "Definiciones de " << palabra << endl << endl ;
  vector<string>::const_iterator it_v;

  for(it_v = def.begin(); it_v!= def.end(); it_v++){
	  cout << (*it_v) << endl;
  }

  char inf, sup;

  cout << endl << endl << "Introduce el caracter para el extremo inferior: ";
  cin >> inf;


  cout << "Introduce el caracter para el extremo superior: ";
  cin >> sup;


  Diccionario intervalo;

  intervalo = mi_diccionario.filtroIntervalo(inf, sup);

  cout << intervalo << endl;


  cout << "Introduce una palabra: ";
  cin >> palabra;

  cout << endl << endl << "Terminos que en la definicion contienen la palabra  "
                       << palabra << ": " << endl << endl;

  Diccionario clave;


  clave = mi_diccionario.filtroClave(palabra);

  cout << clave << endl;

  cout << "El diccionario tiene " << mi_diccionario.getNumDefiniciones() << " definiciones "
       << ", " << mi_diccionario.numTerminos() << " terminos, el maximo de definiciones "
       << " asociadas a una palabra es " << mi_diccionario.maxDefinicionesAsociadasAPalabra()
       << " y cada termino tiene un promedio de " << mi_diccionario.promedioDefiniciones()
       << " definiciones " <<endl;


}

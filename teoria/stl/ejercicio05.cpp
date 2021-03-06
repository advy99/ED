//Antonio David Villegas Yeguas
// Ejercicio 5 - ED 18/19 - Relacion STL

#include <iostream>
#include <map>
#include <sstream>

using namespace std;

/**
 * @brief Comprueba las opciones y parametros de un string
 * @param cad Cadena a comprobar
 *
 * @pre Una opcion siempre va precedida de '-'
 * @pre Un argumento de una opcion siempre va despues de dicha opcion
 *
 * @return map con cada opcion, y correspondiente argumento
 */

map<string, string> params(string cad);

int main(){

   map <string, string> parametros;
   string cadena;


   cout << "Introduce una orden: ";
   getline(cin, cadena);


   parametros = params(cadena);

   cout << "Opciones: \t Parametros: " << endl;
   cout << "-----------------------------------" << endl;

   map <string, string>::const_iterator it;

   for (it = parametros.begin(); it != parametros.end(); it++){
      cout << it->first << "\t\t" << it->second << endl << endl;
   }

   return 0;

}

map<string, string> params(string cad){
   istringstream iss;
   string parte;
   map<string, string> parametros;
   pair<string, string> par;

   iss.str(cad);

   iss >> parte;

   while(!iss.eof()){

      if (parte.at(0) == '-'){
         parte.erase(parte.begin());
         par.first = parte;
         par.second = "";

         iss >> parte;

         if (parte.at(0) != '-'){
            par.second = parte;
         }

         parametros.insert(par);

      } else{
         iss >> parte;
      }

   }

   return parametros;
}

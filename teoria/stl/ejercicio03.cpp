//Antonio David Villegas Yeguas
// Ejercicio 3 - ED 18/19 - Relacion STL

#include <iostream>
#include <map>
#include <fstream>

using namespace std;

/**
 * @brief Cuenta el numero de veces que aparece cada palabra en un fichero de texto
 * @param nom_fich Nombre del fichero en el que contar las palabras
 *
 * @return map con cada palabra, y el numero de veces que aparece
 */

map<string, int> contar(string nom_fich);

int main(int argc, char * argv[]){

   string nombre;
   map<string, int> contador;

   cout << "Introduce el nombre del fichero: ";

   getline(cin, nombre);

   contador = contar(nombre);

   map<string, int>::iterator it;

   for (it = contador.begin(); it != contador.end(); it++){
      cout << "La palabra " << it->first << " aparece " << it->second
           << " veces. "<< endl;
   }

   return 0;
}


map<string, int> contar(string nom_fich){

   fstream fs;
   map<string, int> contador;

   fs.open(nom_fich);

   if (!fs.fail()){

      string palabra;

      map<string, int>::iterator it;

      while(!fs.eof()){
         fs >> palabra;

         it = contador.find(palabra);

         if (it == contador.end()){
            if (palabra != "")
               contador.insert(make_pair(palabra,1));
         }else{
            it->second++;
         }

         palabra = "";
      }

   }

   fs.close();

   return contador;
}

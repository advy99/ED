//Antonio David Villegas Yeguas
// Ejercicio 4 - ED 18/19 - Relacion STL

#include <iostream>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

/**
 * @brief Cuenta el numero de veces que aparece cada palabra en un fichero de texto
 * @param nom_fich Nombre del fichero en el que contar las palabras
 *
 * @return map con cada palabra, y el numero de veces que aparece
 */

map<string, int> contar(string nom_fich);


/**
 * @brief Devuelve las palabras que aparecen num veces en un map pasado como argumento
 * @param palabras Map con las palabras, y el numero de veces que aparecen
 *
 * @return vector con las palabras que cumplen la condicion
 */
vector<string> veces(const map<string, int> &palabras, int num);


int main(int argc, char * argv[]){

   string nombre;
   map<string, int> contador;
   vector<string> palabras;
   int num;

   cout << "Introduce el nombre del fichero: ";

   getline(cin, nombre);

   contador = contar(nombre);

   map<string, int>::iterator it;

   for (it = contador.begin(); it != contador.end(); it++){
      cout << "La palabra " << it->first << " aparece " << it->second
           << " veces. "<< endl;
   }

   cout << endl << "Introduce un numero de apariciones: ";
   cin >> num;

   palabras = veces(contador, num);

   cout << "Las palabras que aparecen " << num << " veces son:" << endl;

   vector<string>::iterator it_v;

   for (it_v = palabras.begin(); it_v != palabras.end(); it_v++){
      cout << (*it_v) << endl;
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


vector<string> veces(const map<string, int> &palabras, int num){
   map<string, int>::const_iterator it;
   vector<string> sol;

   for(it = palabras.begin(); it != palabras.end(); it++ ){
      if(it->second == num){
         sol.push_back(it->first);
      }
   }

   return sol;
}

//Antonio David Villegas Yeguas
// Ejercicio 1 - ED 18/19 - Relacion STL

#include <iostream>
#include <map>

using namespace std;

/**
 * @brief Encripta una cadena, usando el codigo pasado por argumento
 * @param cad Cadena a encriptar
 * @param codigo Codigo con el que encriptar
 *
 * @return string Codigo encriptado
 */

string encripta(string cad, const map<char, char> &codigo);


int main(int argc, char * argv[]){

   map<char, char> codigo;
   int cont = 0;
   string cadena;
   string cadena_encriptada;
   pair<char, char> par;

   //cargamos el codigo de encriptacion
   for(char i = 'A'; i <= 'Z'; i++ ){
      par = make_pair(i, 'Z' - cont);
      codigo.insert( par );
      cont++;
   }

   cont = 0;
   for(char i = 'a'; i <= 'z'; i++ ){
      par = make_pair(i, 'z' - cont);
      codigo.insert( par );
      cont++;
   }

   cout << "Introduce una cadena de caracteres: ";
   getline(cin, cadena);

   cadena_encriptada = encripta(cadena, codigo);

   cout << "La cadena encriptada es: " << cadena_encriptada << endl;

   return 0;
}


string encripta(string cad, const map<char, char> &codigo){
   string encriptada = "";

   for(int i = 0; i < cad.size(); i++){
      map<char, char>::const_iterator it;
      it = codigo.find(cad.at(i));
      if (it != codigo.end()){
         encriptada.push_back(it->second);
      }else{
         encriptada.push_back( cad.at(i) );
      }
   }

   return encriptada;
}

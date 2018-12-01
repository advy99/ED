#include <iostream>
#include <map>
#include <fstream>

using namespace std;

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

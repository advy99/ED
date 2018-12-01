#include <iostream>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

map<string, int> contar(string nom_fich);
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

#include <iostream>
#include <map>

using namespace std;

string desencripta(string cad, const map<char, char> &codigo);

int main(int argc, char * argv[]){

   map<char, char> codigo;
   int cont = 0;
   string cadena;
   string cadena_desencriptada;
   pair<char, char> par;

   //cargamos el codigo de encriptacion
   for(char i = 'A'; i <= 'Z'; i++ ){
      par = make_pair('Z' - cont, i);
      codigo.insert( par );
      cont++;
   }

   cont = 0;
   for(char i = 'a'; i <= 'z'; i++ ){
      par = make_pair('z' - cont, i);
      codigo.insert( par );
      cont++;
   }

   cout << "Introduce una cadena de caracteres encriptada: ";
   getline(cin, cadena);

   cadena_desencriptada = desencripta(cadena, codigo);

   cout << "La cadena desencriptada es: " << cadena_desencriptada << endl;

   return 0;
}


string desencripta(string cad, const map<char, char> &codigo){
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

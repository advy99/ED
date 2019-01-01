//Antonio David Villegas Yeguas
// Ejercicio 11 - ED 18/19 - Relacion STL

#include <iostream>
#include <list>

using namespace std;

/**
 * @brief Inserta el elemento x - 1 en una lista, justo despues del elemento x
 * @param l Lista con la que trabajar
 * @param x Elemento
 *
 */

void inserta_antes( list<int>  &l, int x);

int main(){

   list<int> lista;
   int num;

   cout << "Introduce un elemento (negativo para finalizar): ";
   cin >> num;
   while( num >= 0 ){
      lista.push_back(num);

      cout << "Introduce un elemento (negativo para finalizar): ";
      cin >> num;
   }

   cout << "Introduce un a elemento a buscar: ";
   cin >> num;

   list<int>::iterator it;

   cout << "Contenido de la lista: "<< endl;
   for(it = lista.begin(); it != lista.end(); it++){
      cout << (*it) << " ";
   }

   cout << endl << endl;

   inserta_antes(lista, num);

   cout << "Contenido de la lista despues de ejecutar inserta_antes: " << endl;
   for(it = lista.begin(); it != lista.end(); it++){
      cout << (*it) << " ";
   }

   cout << endl << endl;

   return 0;
}

void inserta_antes( list<int> &l, int x){
   list<int>::iterator it = l.begin();

   while(it != l.end()){

      if ((*it) == x){
         l.insert(++it, (x - 1));
      }else{
         it++;
      }

   }
}

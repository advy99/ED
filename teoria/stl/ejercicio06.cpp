//Antonio David Villegas Yeguas
// Ejercicio 6 - ED 18/19 - Relacion STL

#include <iostream>
#include <list>

using namespace std;

/**
 * @brief Elimina todas las apareciones de un elemento en una lista
 * @param l Lista
 * @param x Elemento a eliminar
 *
 */

template <typename T>
void elimina(list<T> &l, const T &x);

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

   list<int>::iterator it;

   cout << "Contenido de la lista: "<< endl;
   for(it = lista.begin(); it != lista.end(); it++){
      cout << (*it) << " ";
   }

   cout << endl << endl;


   cout << "Introduce el elemento a borrar: ";
   cin >> num;

   elimina(lista, num);

   cout << "Contenido de la lista: "<< endl;
   for(it = lista.begin(); it != lista.end(); it++){
      cout << (*it) << " ";
   }


   return 0;

}


template<typename T>
void elimina(list<T> &l, const T &x){
   typename list<T>::iterator it;

   it = l.begin();

   while(it != l.end()){
      if ( (*it) == x ){
         it = l.erase(it);
      }else{
         it++;
      }
   }

}

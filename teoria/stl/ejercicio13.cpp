//Antonio David Villegas Yeguas
// Ejercicio 13 - ED 18/19 - Relacion STL

#include <iostream>
#include <list>

using namespace std;



template<typename T>
list<T> lista_posiciones(const list<T> &l, const list< typename list<T>::iterator> &iteradores);

int main(){

   list<int> lista;
   list<int> lista2;
   list<list<int>::iterator> lista_iteradores;
   int num;

   cout << "Introduce un elemento (negativo para finalizar): ";
   cin >> num;
   while( num >= 0 ){
      lista.push_back(num);

      cout << "Introduce un elemento (negativo para finalizar): ";
      cin >> num;
   }

   list<int>::iterator it;

   cout << "Contenido de la lista : " << endl;
   for(it = lista.begin(); it != lista.end(); it++){
      cout << (*it) << " ";
      if ((*it ) % 2 == 0){
         lista_iteradores.push_back(it);
      }
   }

   lista2 = lista_posiciones(lista, lista_iteradores);

   cout << endl << endl;

   cout << "Contenido de la lista 2: "<< endl;
   for(it = lista2.begin(); it != lista2.end(); it++){
      cout << (*it) << " ";
   }

   cout << endl << endl;


}

template<typename T>
list<T> lista_posiciones(const list<T> &l, const list< typename list<T>::iterator> &iteradores){
   list<T> resultado;

   typename list< typename list<T>::iterator>::const_iterator it;

   for(it = iteradores.begin(); it != iteradores.end(); it++){
      resultado.push_back( (*(*it)) );
   }

   return resultado;

}

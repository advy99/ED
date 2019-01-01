//Antonio David Villegas Yeguas
// Ejercicio 8 - ED 18/19 - Relacion STL

#include <iostream>
#include <list>

using namespace std;

/**
 * @brief Devuelve una lista con los elementos en orden inverso
 * @param l Lista con la que trabajar
 *
 * @return Lista con los elementos de l en orden invertido
 */

template <typename T>
list<T> inversa(const list<T> &l);

int main(){

   list<int> lista;
   list<int> invertida;
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


   invertida = inversa(lista);

   cout << "Contenido de la lista inversa: "<< endl;
   for(it = invertida.begin(); it != invertida.end(); it++){
      cout << (*it) << " ";
   }


   return 0;

}


template<typename T>
list<T> inversa(const list<T> &l){
   typename list<T>::const_reverse_iterator it;
   list <T> invertida;

   for(it = l.rbegin(); it != l.rend(); it++){
      invertida.push_back((*it));
   }

   return invertida;
}

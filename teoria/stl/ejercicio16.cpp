//Antonio David Villegas Yeguas
// Ejercicio 16 - ED 18/19 - Relacion STL

#include <iostream>
#include <list>

using namespace std;

/**
 * @brief Funcion para comprimir una lista de enteros, guarda un par con el
  numero, y las veces que aparece de forma seguida
 * @param l Lista con la que trabajar
 *
 * @return Lista comprimida de la forma descrita
 */


template<typename T>
list<pair<T, int> > comprimir (const list<T> &l);

int main(){
   list<int> lista;
   int num;

   list< pair<int, int> > comprimida;

   cout << "Introduce un elemento (negativo para finalizar): ";
   cin >> num;
   while( num >= 0 ){
      lista.push_back(num);

      cout << "Introduce un elemento (negativo para finalizar): ";
      cin >> num;
   }


   comprimida = comprimir(lista);

   list<pair<int, int> >::iterator it;

   for (it = comprimida.begin(); it != comprimida.end(); it++){
      cout  << it->first << "," << it->second << "\t";
   }



}

template<typename T>
list<pair <T, int> > comprimir(const list<T> &l){

   list<pair <T, int> > solucion;

   pair<T, int> par;

   T valor_anterior;


   typename list<T>::const_iterator it;

   it = l.begin();

   valor_anterior = (*it);
   it++;

   par.first = valor_anterior;
   par.second = 1;


   while(it != l.end()){
      if((*it) == valor_anterior){
         par.second++;
      }else {
         solucion.push_back(par);
         par.first = (*it);
         par.second = 1;
         valor_anterior = (*it);
      }
      it++;
   }

   solucion.push_back(par);


   return solucion;
}

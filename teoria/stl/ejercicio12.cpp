//Antonio David Villegas Yeguas
// Ejercicio 12 - ED 18/19 - Relacion STL

#include <iostream>
#include <list>

using namespace std;

/**
 * @brief Comprueba si una lista esta contenida enn otra
 * @param l1 Lista con la que trabajar
 * @param l2 Lista con la que trabajar
 *
 * @return bool con el resultado, true si esta contenida, false si no
 */

template<typename T>
bool contenida(const list<T> &ll, const list<T> &l2);

int main(){

   list<int> lista1;
   list<int> lista2;
   bool esta_contenida;
   int num;

   cout << "Introduce un elemento para la lista 1 (negativo para finalizar): ";
   cin >> num;
   while( num >= 0 ){
      lista1.push_back(num);

      cout << "Introduce un elemento para la lista 1 (negativo para finalizar): ";
      cin >> num;
   }

   cout << "Introduce un elemento para la lista 2 (negativo para finalizar): ";
   cin >> num;
   while( num >= 0 ){
      lista2.push_back(num);

      cout << "Introduce un elemento para la lista 2 (negativo para finalizar): ";
      cin >> num;
   }

   esta_contenida = contenida(lista1, lista2);

   if (esta_contenida){
      cout << "La lista 1 esta contenida en la lista 2" << endl;
   }else {
      cout << "La lista 1 NO esta contenida en la lista 2" << endl;
   }


   return 0;
}


template<typename T>
bool contenida (const list<T> &l1, const list<T> &l2){
   typename list<T>::const_iterator it;
   typename list<T>::const_iterator it_contenida;

   bool lo_esta = false;
   int correctos = 0;

   it_contenida = l1.begin();
   it = l2.begin();

   while( it != l2.end() && it_contenida != l1.end()){
      if ((*it) == (*it_contenida)){
         it_contenida++;
         correctos++;
      }

      it++;
   }

   return correctos == l1.size();

}

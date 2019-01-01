//Antonio David Villegas Yeguas
// Ejercicio 17 - ED 18/19 - Relacion STL

#include <iostream>
#include <list>

using namespace std;

/**
* @brief Implementacion del vector dinamico
*/

template<typename T>
class vector_dinamico{
private:
   list<T> elementos;

public:

   /**
    * @brief Constructor vacio
    *
    */
   vector_dinamico(){

   }

   /**
    * @brief Añadir un elemento al vector
    * @param elemento Elemeento a añadir
    */

   void push_back(const T &elemento){
      elementos.push_back(elemento);
   }

   /**
    * @brief Consultar el tamaño del vector
    *
    * @return valor con el resultado
    */

   int size() const{
      return elementos.size();
   }

   /**
    * @brief Consultar si esta vacio
    * @return bool con el resultado
    */

   bool empty() const{
      return elementos.empty();
   }

   /**
    * @brief Consultar un elemento
    *
    * @param i indice a consultar
    *
    * @return valor con el resultado
    */

   T at(int i) const{
      typename list<T>::const_iterator it;

      it = elementos.begin();

      for (int j = 0; j < i; j++)
         it++;

      return (*it);
   }


   /**
    * @brief Eliminar un elemento
    * @param posicion  a eliminar
    *
    */

   void erase(int i){

      typename list<T>::const_iterator it;

      it = elementos.begin();

      for (int j = 0; j < i; j++)
         it++;

      elementos.erase(it);
   }


   /**
    * @brief Eliminar el ultimo elemento
    *
    */

   void pop_back(){
      elementos.pop_back();
   }

};


int main(){
   vector_dinamico<int> v;

   int num;

   cout << "Introduce un elemento (negativo para finalizar): ";
   cin >> num;
   while( num >= 0 ){
      v.push_back(num);

      cout << "Introduce un elemento (negativo para finalizar): ";
      cin >> num;
   }

   for(int i = 0; i < v.size(); i++){
       cout << v.at(i) << " ";
   }

   return 0 ;
}

#include <iostream>
#include <list>

using namespace std;

template <typename T>
list<T> mezclar(const list<T> &l1, const list<T> &l2);

int main(){

   list<int> lista1;
   list<int> lista2;
   list<int> mezcla;
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

   lista1.sort();
   lista2.sort();

   list<int>::iterator it;

   cout << "Contenido de la lista 1: "<< endl;
   for(it = lista1.begin(); it != lista1.end(); it++){
      cout << (*it) << " ";
   }

   cout << endl << endl;


   cout << "Contenido de la lista 2: "<< endl;
   for(it = lista2.begin(); it != lista2.end(); it++){
      cout << (*it) << " ";
   }

   cout << endl << endl;


   mezcla = mezclar(lista1, lista2);


   cout << "Contenido de la lista conjunta: "<< endl;
   for(it = mezcla.begin(); it != mezcla.end(); it++){
      cout << (*it) << " ";
   }



   return 0;

}


template<typename T>
list<T> mezclar(const list<T> &l1, const list<T> &l2){
   list<T> mezcla;

   typename list<T>::const_iterator it;
   typename list<T>::const_iterator it2;

   it = l1.begin();

   it2 = l2.begin();

   while (it != l1.end() && it2 != l2.end() ){
      if ((*it) < (*it2)){
         mezcla.push_back((*it));
         it++;
      }else{
         mezcla.push_back((*it2));
         it2++;
      }
   }


   while(it != l1.end()){
      mezcla.push_back((*it));
      it++;
   }

   while(it2 != l2.end()){
      mezcla.push_back((*it2));
      it2++;
   }

   return mezcla;


}

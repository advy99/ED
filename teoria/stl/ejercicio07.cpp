#include <iostream>
#include <list>

using namespace std;

template <typename T>
void elimina_duplicados(list<T> &l);

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


   elimina_duplicados(lista);

   cout << "Contenido de la lista despues de eliminar los duplicados: "<< endl;
   for(it = lista.begin(); it != lista.end(); it++){
      cout << (*it) << " ";
   }


   return 0;

}


template<typename T>
void elimina_duplicados(list<T> &l){
   typename list<T>::iterator it;
   typename list<T>::iterator interno;

   it = l.begin();
   interno = it;
   interno++;

   while(it != l.end()){
      while(interno != l.end()){
         if ( (*it) == (*interno) ){
            interno = l.erase(interno);
         }else{
            interno++;
         }
      }

      it++;

      interno = it;
      interno++;

   }

}

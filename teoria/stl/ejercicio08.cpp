#include <iostream>
#include <list>

using namespace std;

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

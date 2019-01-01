//Antonio David Villegas Yeguas
// Ejercicio 18 - ED 18/19 - Relacion STL

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Intercalar un vector, con los elementos y posiciones dados en el vector pos
 * @param v vector en el que introducir los datos
 * @param pos vector con las posiciones y valores donde intercalar los datos
 *
 */


template<typename T>
void intercalar(vector<T> &v, vector<pair<int, T> > pos);

int main(){
   vector<int> v;

   int num;

   cout << "Introduce un elemento (negativo para finalizar): ";
   cin >> num;
   while( num >= 0 ){
      v.push_back(num);

      cout << "Introduce un elemento (negativo para finalizar): ";
      cin >> num;
   }

   vector<int>::iterator it;

   for(it = v.begin(); it != v.end(); it++){
      cout << (*it) << " ";
   }

   cout << endl << endl;

   vector<pair<int, int> > posiciones;

   posiciones.push_back(make_pair(0,9));
   posiciones.push_back(make_pair(1,1));
   posiciones.push_back(make_pair(3,0));

   intercalar(v, posiciones);


   for(it = v.begin(); it != v.end(); it++){
      cout << (*it) << " ";
   }

   cout << endl << endl;

}


template<typename T>
void intercalar(vector<T> &v, vector<pair<int, T> > pos){

   typename vector< pair<int, T> >::iterator it;
   typename vector<T>::iterator it_v;

   for (it = pos.begin(); it != pos.end(); it++){

      it_v = v.begin();

      for(int i = 0; i < it->first; i++){
         it_v++;
      }

      v.emplace(it_v, it->second);
   }
}

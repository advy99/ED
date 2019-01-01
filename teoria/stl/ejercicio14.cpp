//Antonio David Villegas Yeguas
// Ejercicio 14 - ED 18/19 - Relacion STL

#include <iostream>
#include <list>
#include <vector>

using namespace std;

template<typename T>
class vdisperso{
public:

   /**
    * @brief Constructor con parametros
    * @param v vector a copiar
    *
    */
   vdisperso(const vector<T> &v){
      typename vector<T>::const_iterator it;
      pair<int, T> par;

      for(it = v.begin(); it != v.end(); it++){
         if ((*it) != 0){
            par.first = distance(v.begin(), it);
            par.second = (*it);
            coefs.push_back(par);
         }
         n++;
      }
   }

   /**
   * @brief Asignar un valor a un coeficiente, si no existe el coeficiente lo añade
   * @param i coeficiente
   * @param x valor
   *
   */

   void asignar_coeficiente(int i, const T &x){
      typename list< pair<int, T> >::iterator it;

      bool encontrado = false;

      for (it = coefs.begin(); it != coefs.end() && !encontrado; it++){
         if ( it->first == i ){
            it->second = x;
            encontrado = true;
         }
      }

      if (!encontrado){
         coefs.push_back(make_pair(i, x));
         if (i > n){
            n = i + 1;
         }
      }

   }


   /**
    * @brief Convertir vector disperso en std::vector
    *
    * @return vector de la STL
    */


   vector<T> convertir() const{
      vector<T> v;
      T nulo;

      typename list< pair<int, T> >::iterator it;

      coefs.sort();

      it = coefs.begin();
      for(int i = 0; i < n; i++){
         if (i == it->first ){
            v.push_back(it->second);
            it++;
         }else{
            v.push_back(nulo);
         }
      }
   }

   /**
    * @brief operador [] para acceder a un elemento
    * @param i indice del elemento en el vector
    *
    * @return bool con el resultado, true si esta contenida, false si no
    */



   T operator[] (const int i) const{

      T valor = 0;

      typename list< pair<int, T> >::const_iterator it;

      bool encontrado = false;

      for (it = coefs.begin(); it != coefs.end() && !encontrado; it++){
         if ( it->first == i ){
            valor = it->second;
         }
      }

      return valor;
   }


   /**
   * @brief Devuelve el tamaño del vector
   *
   * @return entero con el tamaño
   */


   int size() const{
      return n;
   }

   /**
   * @brief Comprueba si una lista esta vacia
   *
   * @return bool con el resultado, true si esta vacia, false si no
   */


   bool empty() const{
      return size() == 0;
   }

private:
   list< pair<int, T> > coefs;
   int n;
};




int main(){
   vector<int> v1;

   v1.push_back(0);
   v1.push_back(0);
   v1.push_back(1);
   v1.push_back(0);
   v1.push_back(0);
   v1.push_back(0);
   v1.push_back(2);
   v1.push_back(0);
   v1.push_back(1);
   v1.push_back(0);
   v1.push_back(0);

   vdisperso<int> vector(v1);


   for(int i = 0; i < vector.size() ; i++){
      cout << vector[i] << " ";

   }


   cout << endl;
   return 0;
}

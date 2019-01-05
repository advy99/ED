/**
  * @file lista_palabras.h
  * @brief Fichero cabecera del TDA lista_palabras
  *
  */

#ifndef __lista_palabras_h__
#define __lista_palabras_h__


#include <set>
#include <iostream>
#include <vector>

using namespace std;
        

/**
  *  @brief T.D.A. lista_palabras
  *
  * Una instancia del tipo de datos abstracto @c lista_palabras, es un objeto
  * compuesto por un listado de palabras.
  *  
  * Lo reprentamos como:
  * 
  * palabra
  * .
  * .
  * .
  * .
  * palabra
  *
  * @author María Sánchez Marcos
  * @author Antonio David Villegas Yeguas
  * @date Diciembre 2018
  */

class lista_palabras{

	private:

		/**
		 * @page repLista_palabras Rep del TDA lista_palabras
		 *
		 * @section invTermino Invariante de la representación
		 * 
		 * datos != NULL y datos.size() >= 0
		 * 
		 * Como vemos, permitimos un listado de palabras vacio
		 *
		 *
		 * @section faConjunto Función de abstracción
		 *
		 * Un objeto valido @e rep del TDA lista_palabras representa al valor
		 *
		 * (rep.datos)
		 *
		 */

		set<string> datos;

	public:
		/**
		 * @brief Construye un lista_palabras vacio.
		 */

		lista_palabras();

		/**
		 * @brief Devuelve el numero de palabras en el lista_palabras 
		 */

		int size() const;

		/**
		 * @brief Obtiene todas las palabras en el lista_palabras de una longitud dada
		 * @param longitud La longitud de las palabras de salida
		 * @return un vector con las palabras de longitud especificada en el parametro de entrada
		 * 
		 */

		vector<string> palabras_longitud(int longitud);

		/**
		 * @brief Indica si una palabra está en el lista_palabras o no
		 * @param palabra La palabra que se quiere buscar
		 * @return true si la palabra eseta en el lista_palabras. false en caso contrario
		 */

		bool Esta ( string palabra) const; //
		
		/**
		 * @brief Lee de un flujo de entrada un lista_palabras
		 * @param is flujo de entrada
       * @param D el objeto donde se realiza la lectura
       * @return el flujo de entrada
       * 
      **/

      friend istream & operator >> (istream & is, lista_palabras &D);

      /**
       * @brief Escribe en un flujo de salida un lista_palabras
       * @param os flujo de salida
       * @param D el objeto lista_palabras que se escribe
       * @return el flujo de salida
       **/
      friend ostream & operator << (ostream & os, const lista_palabras &D);      


		class iterator {
			public:

				/**
				 * @brief Constructor por defecto, crea un iterator vacio
				 * 
				 */
				iterator();

				/**
				 * @brief Operador de acceso *
				 * 
				 * @return string Objeto al que apunta el iterador
				 * 
				 */
				string operator *();

				/**
				 * @brief Operador ++, avanza en una posicion el iterador constante 
				 * 
				 * @return const_iterator Iterados actual
				 */
				iterator & operator ++ ();


				/**
				 * @brief Operador ==, comprueba si un operador es igual a otro
				 * 
				 * @param i Iterador a comparar con el iterador implicito
				 * 
				 * @return bool Resultado de la comprobacion, true si se cumple, false si no
				 */


				bool operator ==(const iterator &i);

				/**
				 * @brief Operador !=, comprueba si un operador es distinto a otro
				 * 
				 * @param i Iterador a comparar con el iterador implicito
				 * 
				 * @return bool Resultado de la comprobacion, true si se cumple, false si no
				 */
				bool operator !=(const iterator &i);
				friend class lista_palabras;
			private:		

				/**
				 * @page repIterator Rep del TDA iterator
				 *
				 * @section invIterator Invariante de la representación
				 *
				 * it == NULL o datos.begin() <= it <= datos.end()
				 *
				 * @section faConjunto Función de abstracción
				 *
				 * Un objeto valido @e rep del TDA iterator representa al valor
				 *
				 * (rep.it)
				 *
				 */



				set<string>::iterator it;
		};

		class const_iterator {
			public:
				
				/**
				 * @brief Constructor por defecto, crea un iterator vacio
				 * 
				 */

				const_iterator();

				/**
				 * @brief Operador de acceso *
				 * 
				 * @return string Objeto al que apunta el iterador
				 * 
				 */

				string operator *() const;

				/**
				 * @brief Operador ++, avanza en una posicion el iterador constante 
				 * 
				 * @return const_iterator Iterados actual
				 */
				const_iterator & operator ++ ();

				/**
				 * @brief Operador ==, comprueba si un operador es igual a otro
				 * 
				 * @param i Iterador a comparar con el iterador implicito
				 * 
				 * @return bool Resultado de la comprobacion, true si se cumple, false si no
				 */

				bool operator ==(const const_iterator &i) const;


				/**
				 * @brief Operador !=, comprueba si un operador es distinto a otro
				 * 
				 * @param i Iterador a comparar con el iterador implicito
				 * 
				 * @return bool Resultado de la comprobacion, true si se cumple, false si no
				 */
				bool operator !=(const const_iterator &i) const;



				friend class lista_palabras;
			private:

				/**
				 * @page repIterator Rep del TDA const_iterator
				 *
				 * @section invIterator Invariante de la representación
				 *
				 *
				 * @section faConjunto Función de abstracción
				 *
				 * Un objeto valido @e rep del TDA iterator representa al valor
				 *
				 * (rep.it)
				 *
				 */

				set<string>::const_iterator it;
		};
		

		/**
		 * @brief Devuelve un iterador del TDA iterator, que apunta al inicio de la lista de palabras
		 * 
		 * @return iterator Iterador que apunta al inicio de la lista_palabras
		 * 
		 */
		iterator begin();

		/**
		 * @brief Devuelve un iterador del TDA const_iterator, que apunta al inicio de la lista de palabras
		 * 
		 * @return const_iterator Iterador que apunta al inicio de la lista_palabras
		 * 
		 */
		const_iterator begin() const;

		/**
		 * @brief Devuelve un iterador del TDA iterator, que apunta al fin de la lista de palabras
		 * 
		 * @return iterator Iterador que apunta al fin de la lista_palabras
		 * 
		 */
		iterator end();

		/**
		 * @brief Devuelve un iterador del TDA const_iterator, que apunta al fin de la lista de palabras
		 * 
		 * @return const_iterator Iterador que apunta al fin de la lista_palabras
		 * 
		 */	
		const_iterator end() const;

};



#endif
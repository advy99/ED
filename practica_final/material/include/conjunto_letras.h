#ifndef __conjunto_letras_h__
#define __conjunto_letras_h__

#include <iostream>
#include <set>
#include "letra.h"
#include "lista_palabras.h"

using namespace std;

/**
  *  @brief T.D.A. conjunto_letras
  *
  * Una instancia del tipo de datos abstracto @c conjunto_letras, es un objeto
  * compuesto por un conjunto de letras.
  *  
  * Lo reprentamos como:
  * 
  * letra
  * .
  * .
  * .
  * .
  * letra
  *
  * @author María Sánchez Marcos
  * @author Antonio David Villegas Yeguas
  * @date Diciembre 2018
  */


class conjunto_letras{

	private:
		/**
		 * @page repConjunto_letras Rep del TDA conjunto_letras
		 *
		 * @section invTermino Invariante de la representación
		 * 
		 * letras != NULL y letras.size() >= 0
		 * 
		 * Como vemos, permitimos un conjunto de letras vacio
		 *
		 *
		 * @section faConjunto Función de abstracción
		 *
		 * Un objeto valido @e rep del TDA conjunto_letras representa al valor
		 *
		 * (rep.letras)
		 *
		 */


		set<letra> letras;


	public:

		/**
		 * @brief Construye un conjunto_letras vacio.
		 */

		conjunto_letras();

		/**
		 * @brief Devuelve el numero de letras en el conjunto_letras 
		 */

		int size() const;

		/**
		 * @brief Obtener las letras del conjunto
		 * 
		 * @return set<letras> con las letras del conjunto
		 * 
		 */

		set<letra> getLetras() const;

		/**
		 * @brief Añadir una letra al conjunto de letras
		 * @param letra Letra a añadir
		 * 
		 */

		void addLetra(const letra & letra);

		/**
		 * @brief Eliminar una letra del conjunto de letras
		 * @param letra Letra a eliminar
		 * 
		 */

		void removeLetra(const letra & letra);

		/**
		 * @brief Obtener una letra del conjunto de letras
		 * 
		 * @param letra Letra a buscar
		 * 
		 * @return letra del conjunto
		 */

		letra getLetra(const letra & letra) const;


		/**
		 * @brief Obtener una letra del conjunto de letras
		 * 
		 * @param c Caracter con el que buscar la letra
		 * 
		 * 
		 * @return letra del conjunto de letras
		 */
		letra getLetra(const char & c) const;


		/**
		 * @brief Comprobar su una letra pertenece al conjunto de letras
		 * 
		 * @param letra Letra a comprobar si esta en el conjunto
		 * 
		 * 
		 * @return bool Resultado de la comprobacion
		 */

		bool Esta( const letra & letra) const;


		/**
		 * @brief Obtener la puntuacion de una palabra, dado un modo de juego
		 * 
		 * @param palabra Palabra a obtener la puntuacion
		 * @param modo Mode de juego
		 * 
		 * @return int con la puntuacion de la palabra dada
		 * 
		 */
		int getPuntuacion(const string palabra, const char & modo) const;


		/**
		 * @brief Cantidad total de letras en el conjunto
		 * 
		 * @return int con la suma de todas las cantidades de las letras
		 */

		int totalLetras() const;


		/**
		 * @brief Contar las letras de una lista de palabras
		 *
		 * @param lista Lista de palabras donde contar las letras
		 * 
		 * @return conjunt_letras con cada letra y la respectiva cantidad de apariciones
		 */
		conjunto_letras contarLetras(const lista_palabras & lista);

		/**
		 * @brief Lee de un flujo de entrada un conjunto_letras
		 * @param is flujo de entrada
       * @param conjunto el objeto donde se realiza la lectura
       * @return el flujo de entrada
       * 
      **/

		friend istream & operator >> (istream & is, conjunto_letras &conjunto );


		/**
       * @brief Escribe en un flujo de salida un conjunto_letras
       * @param os flujo de salida
       * @param conjunto el objeto lista_palabras que se escribe
       * @return el flujo de salida
       **/
		friend ostream & operator << (ostream & os, const conjunto_letras &conjunto); 


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
				letra operator *();

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
				friend class conjunto_letras;
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
				set<letra>::iterator it;
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
				letra operator *() const;

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
				friend class conjunto_letras;
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
				set<letra>::const_iterator it;
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
#ifndef __bolsa_letras_h__
#define __bolsa_letras_h__


#include "letra.h"
#include "conjunto_letras.h"
#include "lista_palabras.h"
#include <unordered_set>


/**
  *  @brief T.D.A. bolsa_letras
  *
  * Una instancia del tipo de datos abstracto @c bolsa_letras, es un objeto
  * compuesto por un conjunto de caracteres.
  *  
  * Lo reprentamos como:
  * 
  * caracter ...... caracter
  *
  * @author María Sánchez Marcos
  * @author Antonio David Villegas Yeguas
  * @date Diciembre 2018
  */


class bolsa_letras{
	private:


		/**
		 * @page repBolsa_letras Rep del TDA bolsa_letras
		 *
		 * @section invTermino Invariante de la representación
		 * 
		 * bolsa != NULL y bolsa.size() >= 0
		 * 
		 * Como vemos, permitimos una bolsa de letras vacia
		 *
		 *
		 * @section faConjunto Función de abstracción
		 *
		 * Un objeto valido @e rep del TDA lista_palabras representa al valor
		 *
		 * (rep.bolsa)
		 *
		 */
		unordered_multiset<char> bolsa;


		//metodo privado para obtener las combinaciones de un string, ej
		// string abc:
		//  a ab ac b ba bc c ca cb abc acb bac bca cab cba

		/**
		 * @brief Obtener las combinacion es de un string dado
		 * 
		 * @param str String a buscar combinaciones
		 * @param res Resultado de esa combinacion
		 * @param total Resultado de todas las combinaciones
		 * 
		 */

		void getCombinaciones( string str, string res, string & total );
		
	public:

		/**
		 * @brief Construye una bolsa de letras vacia.
		 */

		bolsa_letras();

		/**
		 * @brief Construye una bolsa de a partir de otra dada.
		 * 
		 * @param otra bolsa_letras a copiar
		 */

		bolsa_letras(const bolsa_letras & otra);

		/**
		 * @brief Construye una bolsa de a partir de un conjunto de letras.
		 * 
		 * @param c conjunto de letras con el que llenar la bolsa
		 */
		bolsa_letras(const conjunto_letras & c);

		/**
		 * @brief Devuelve el numero de letras en la bolsa 
		 */
		int size() const;


		/**
		 * @brief Devuelve la bolsa
		 * 
		 * @return unordered_multiset<char> Bolsa de letras
		 */
		unordered_multiset<char> getBolsa();

		/**
		 * @brief Añadir una letra a la bolsa
		 * 
		 * @param l Letra a añadir (a partir de un objeto del TDA letra)
		 * 
		 */
		void addLetra(const letra & l);

		/**
		 * @brief Añadir una letra a la bolsa
		 * 
		 * @param l Letra a añadir (a partir de un caracter)
		 * 
		 */
		void addLetra(const char & l);

		/**
		 * @brief Eliminar una letra a la bolsa
		 * 
		 * @param l Letra a eliminar (a partir de un objeto del TDA letra)
		 * 
		 */
		void removeLetra(const letra & l);

		/**
		 * @brief Eliminar una letra a la bolsa
		 * 
		 * @param l Letra a eliminar (a partir de un caracter)
		 * 
		 */
		void removeLetra(const char & l);

		/**
		 * @brief Obtener una bolsa con num letras aleatorias de la bolsa actual
		 * 
		 * @param num Tamaño de la bolsa a obtener
		 * 
		 * @return bolsa_letras con num letras aleatorias
		 * 
		 */
		bolsa_letras getLetras(int num);


		/**
		 * @brief Obtiene todas las soluciones de la bolsa, es decir,
		 * todas las palabras que se pueden formar con las letras de la bolsa, 
		 * que esten en la lista_palabras, y obtiene la puntiacion segun el
		 * conjunto_letras letras y el modo
		 * 
		 * @param letras Conjunto de letras para obtener la puntuacion de cada palabra
		 * @param lista Lista de palabras donde comprobar si una palabra es correcta
		 * @param modo Modo de juego
		 * 
		 * @return conjunto de pares, con la solucion, el primer elemento del
		 *  pair es la puntuacion y el segundo la palabra
		 */

		set< pair<int, string> > getSoluciones(const conjunto_letras & letras, const lista_palabras & lista, const char & modo);


		/**
		 * @brief Comprobar si una letra dada esta
		 * 
		 * @param l Letra a comprobar
		 * 
		 * 
		 * @bool resultado con la operacion
		 */
		bool Esta(const letra & l);

		/**
		 * @brief Comprobar si una letra dada esta
		 * 
		 * @param c Caracter a comprobar
		 * 
		 * 
		 * @bool resultado con la operacion
		 */
		bool Esta(const char & c);


		/**
		 * @brief Comprobar si una palabra se puede formar con las letras de la bolsa
		 * 
		 * @param palabra Palabra a comprobar
		 * 
		 * @return resultado con la operacion
		 */
		bool estanLetras(const string palabra);


		/**
		 * @brief Lee de un flujo de entrada una bolsa de letras
		 * @param is flujo de entrada
       * @param bolsa objeto donde se realiza la lectura
       * @return el flujo de entrada
       * 
      **/
		friend istream & operator >> (istream & is, bolsa_letras & bolsa );


		/**
       * @brief Escribe en un flujo de salida una bolsa_letras
       * @param os flujo de salida
       * @param bolsa el objeto bolsa_letras que se escribe
       * @return el flujo de salida
       **/
		friend ostream & operator << (ostream & os, const bolsa_letras & bolsa); 



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
				char operator *();

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
				friend class bolsa_letras;
			private:	

				/**
				 * @page repIterator Rep del TDA Iterator
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
				unordered_multiset<char>::iterator it;
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
				char operator *() const;

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
				friend class bolsa_letras;
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
				unordered_multiset<char>::const_iterator it;
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
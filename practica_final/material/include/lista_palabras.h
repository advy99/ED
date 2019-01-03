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
  *  *
  *
  * @author María Sánchez Marcos
  * @author Antonio David Villegas Yeguas
  * @date Diciembre 2018
  */

class lista_palabras{

	private:

		/**
		 * @page repTermino Rep del TDA lista_palabras
		 *
		 * @section invTermino Invariante de la representación
		 *
		 *
		 * @section faConjunto Función de abstracción
		 *
		 * Un objeto valido @e rep del TDA lista_palabras representa al valor
		 *
		 * (rep.palabra)
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
				iterator();
				string operator *();
				iterator & operator ++ ();
				bool operator ==(const iterator &i);
				bool operator !=(const iterator &i);
				friend class lista_palabras;
			private:			
				set<string>::iterator it;
		};

		class const_iterator {
			public:
				const_iterator();
				string operator *() const;
				const_iterator & operator ++ ();
				bool operator ==(const const_iterator &i) const;
				bool operator !=(const const_iterator &i) const;
				friend class lista_palabras;
			private:			
				set<string>::const_iterator it;
		};
		
		iterator begin();
		const_iterator begin() const;
		iterator end();	
		const_iterator end() const;

};



#endif
#ifndef __letras_h__
#define __letras_h__

#include <iostream>

using namespace std;


/**
  *  @brief T.D.A. letra
  *
  * Una instancia del tipo de datos abstracto @c letra, es un objeto
  * compuesto por un caracter, la cantidad de veces que aparece, y una
  * puntuacion asociada.
  *  
  * Lo reprentamos como:
  * 
  * Caracter  Cantidad  Puntuacion
  *
  * @author María Sánchez Marcos
  * @author Antonio David Villegas Yeguas
  * @date Diciembre 2018
  */


class letra{
	private:


		/**
		 * @page repLetra Rep del TDA letra
		 *
		 * @section invTermino Invariante de la representación
		 * 
		 * 'A' <= caracter <= 'Z' o 'a' <= caracter <= 'z'
		 * cantidad >= 0
		 * puntuacion >= 0
		 *
		 *
		 * @section faConjunto Función de abstracción
		 *
		 * Un objeto valido @e rep del TDA lista_palabras representa al valor
		 *
		 * (rep.caracter, rep.cantidad, rep.puntuacion)
		 *
		 */

	   char caracter; 
		int cantidad;
      int puntuacion;
        
	public:

		/**
		 * @brief Construye una letra vacia.
		 */

		letra();

		/**
		 * @brief Construye una letra con los valores de caracter, puntuacion y cantidad dados.
		 */

		letra( const char & c, const int & cant,const int & p);

		/**
		 * @brief Obtener el caracter asociado a una letra
		 * 
		 * @return char Caracter asociado a la letra
		 * 
		 */
		char getCaracter() const;

		/**
		 * @brief Obtener la puntuacion asociada a una letra
		 * 
		 * @return int Puntuacion asociada a la letra
		 * 
		 */
      int getPuntuacion () const;

		/**
		 * @brief Obtener la cantidad asociada a una letra
		 * 
		 * @return int Cantidad asociada a la letra
		 * 
		 */
		int getCantidad() const;


		/**
		 * @brief Establecer el caracter asociado a una letra
		 * 
		 * @param c Caracter asociado a la letra
		 * 
		 */
		void setCaracter(const char & c);

		/**
		 * @brief Establecer la cantidad asociada a una letra
		 * 
		 * @param int Cantidad asociada a la letra
		 * 
		 */
		void setCantidad( const int & c);

		/**
		 * @brief Establecer la puntuacion asociada a una letra
		 * 
		 * @param int Puntuacion asociada a la letra
		 * 
		 */
		void setPuntuacion(const int & p);


		/**
		 * @brief Operador ==, comprobar si una letra es igual a otra
		 * 
		 * @param otra Letra a comparar con la letra implicita
		 * 
		 * @return bool Resultado con la comparacion
		 * 
		 */
		bool operator == (const letra & otra) const;


		/**
		 * @brief Operador <, comprobar si una letra es menor a otra
		 * 
		 * @param otra Letra a comparar con la letra implicita
		 * 
		 * @return bool Resultado con la comparacion
		 * 
		 */
		bool operator < (const letra & otra) const;


		/**
		 * @brief Lee de un flujo de entrada una letra
		 * @param is flujo de entrada
       * @param l el objeto donde se realiza la lectura
       * @return el flujo de entrada
       * 
       */
		friend istream & operator >> (istream & is, letra & l);


		/**
       * @brief Escribe en un flujo de salida una letra
       * @param os flujo de salida
       * @param l el objeto lista_palabras que se escribe
       * @return el flujo de salida
       */
		friend ostream & operator << (ostream & os, const letra & l);

};



#endif
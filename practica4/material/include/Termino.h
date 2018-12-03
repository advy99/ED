/**
  * @file Termino.h
  * @brief Fichero cabecera del TDA Termino
  *
  */

#ifndef TERMINO
#define TERMINO

#include <iostream>
#include <istream>
#include <ostream>
#include <vector>

using namespace std;

/**
  *  @brief T.D.A. Termino
  *
  * Una instancia del tipo de datos abstracto @c Termino, es un objeto
  * compuesto por una palabra y una o más definiciones de dicha palabra
  * Lo representamos como:
  *
  *  termino: definicion
  *
  *
  * @author María Sánchez Marcos
  * @author Antonio David Villegas Yeguas
  * @date Octubre 2018
  */

class Termino{
private:

  /**
  * @page repTermino Rep del TDA Termino
  *
  * @section invTermino Invariante de la representación
  *
  * El invariante es; termino != "" y definiciones.size() > 0
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto valido @e rep del TDA Termino representa al valor
  *
  * (rep.termino,rep.definiciones)
  *
  */

   pair < string, vector<string> > termino;


public:


   typedef vector<string>::iterator iterator;
   typedef vector<string>::const_iterator const_iterator;


   /**
    * @brief Constructor sin parametros
    */

   Termino();

   /**
    * @brief Constructor con dos parametros, el termino, y la primera definicion
    * @param palabra Palabra a asignar en el termino
    * @param definicion Primera definición a asociar al termino
    * @pre palabra != ""
    * @pre definicion != ""
    */

   Termino(const string & palabra, const string & definicion);


	/**
    * @brief Constructor con dos parametros, el termino, y un array de definiciones
    * @param palabra Palabra a asignar en el termino
    * @param n_definiciones Definiciones de la palabra
    * @pre palabra != ""
    * @pre definiciones != ""
    */

   Termino(const string & palabra, const vector<string> & definiciones);

   /**
    * @brief Constructor de copia
    * @param original Termino a copiar
    * @pre original ha de ser un termino valido
    */

   Termino(const Termino & original);

	/**
	 * @brief Obtener la palabra
	 * @param indice
	 * @return string con la palabra
	 */

	string getPalabra() const;

   /**
    * @brief Consultor de definiciones de un termino
    */

   vector<string> getDefiniciones() const;

	/**
    * @brief Consultor de una definicion de un termino
	 * @param indice Numero de la definicion
    */

   string getDefinicion(const int indice) const;

	/**
	 * @brief Obtener el numero de definiciones de un termino
	 *
	 * @return entero con numero de definiciones
	 */

	int getNumDefiniciones() const;

	/**
	 * @brief Establecer la palabra del termino
	 * @param palabra a establecer
	 * @pre palabra != ""
	 *
	 */

	void setPalabra(const string & palabra);

	/**
	 * @brief Añadir una definicion a una palabra
	 * @param definicion
	 *
	 */

	void addDefinicion(const string & definicion);


   Termino::iterator begin();
   Termino::const_iterator begin() const;

   Termino::iterator end();
   Termino::const_iterator end() const;



	bool operator < (const Termino & otro ) const;




	/**
	 * @brief Operador de salida de flujo
	 * @param os Flujo al que mandar termino
	 * @param t Termino a mandar por el flujo
	 *
	 * @return referencia al flujo de salida
	 */

	friend ostream & operator << (ostream & os, const Termino & t);


	/**
	 * @brief Operador de entrada de flujo
	 * @param in Flujo por el que leer
	 * @param termino Termino a leer por el flujo
	 *
	 * @return referencia al flujo de entrada
	 */

	friend istream & operator >> (istream & in, Termino & termino);


};


 #endif

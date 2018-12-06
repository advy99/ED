/**
  * @file Diccionario.h
  * @brief Fichero cabecera del TDA Diccionario
  *
  */


#ifndef DICCIONARIO
#define DICCIONARIO

#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <set>

#include "Termino.h"


using namespace std;

/**
  *  @brief T.D.A. Diccionario
  *
  * Una instancia del tipo de datos abstracto @c Diccionario, es un objeto
  * compuesto por un conjunto de Terminos y sus respectivas definiciones
  * Lo representamos como:
  *
  *  termino: definicion
  *
  *
  * Con tantos terminos y definiciones como tenga el diccionario
  *
  * @author María Sánchez Marcos
  * @author Antonio David Villegas Yeguas
  * @date Diciembre 2018
  */

class Diccionario{
private:

  /**
  * @page repTermino Rep del TDA Diccionario
  *
  * @section invDiccionario Invariante de la representación
  *
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto valido @e rep del TDA Diccionario representa al valor
  *
  * (rep.terminos)
  *
  */



   set <Termino> terminos;


public:

   /**
    * @brief Declaracion del iterador de la clase como un iterador
    * sobre un set de Termino
    *
    */

   typedef set<Termino>::iterator iterator;

   /**
   * @brief Declaracion del iterador constante de la clase como un iterador
   * constante sobre un set de Termino
   *
   */

   typedef set<Termino>::const_iterator const_iterator;

   /**
    * @brief Constructor sin parametros
    */

   Diccionario();

   /**
    * @brief Constructor con un parametro, diccionario con un termino
    * @param termino Termino a añadir
    * @pre termino es valido
    */

   Diccionario(const Termino & termino);


	/**
    * @brief Constructor un parametro, conjunto de terminos
    * @param terminos Conjunto de terminos a asignar
    * @pre termino.size > 0
    */

   Diccionario(const vector<Termino> n_terminos);

   /**
    * @brief Constructor de copia
    * @param original Termino a copiar
    * @pre original ha de ser un termino valido
    */

   Diccionario(const Diccionario & original);

	/**
	 * @brief Obtener las definiciones asociadas a un termino
	 * @param palabra Palabra a la que se buscaran las definiciones
	 * @pre palabra esta en el diccionario
	 * @return Array con las definiciones de palabra
	 */

	vector<string> getDefiniciones(const string & palabra);

	/**
	 * @brief Obtener los terminos del diccionario
	 *
	 * @return Set con los terminos del diccionario
	 */

	set<Termino> getTerminos();

	/**
	 * @brief Obtener el numero de terminos del diccionario
	 *
	 * @return Entero con el numero de terminos
	 */

	int numTerminos();


	/**
	 * @brief Añadir un nuevo termino
	 * @param termino Termino a añadir
	 *
	 * @pre termino es un termino valido
	 * @pre si el termino ya esta, las definiciones del parametro son distintas
	 * a las que ya hay
	 */

	void addTermino(const Termino & termino);

	/**
	 *
	 * @brief Eliminar un termino
	 * @param palabra Palabra que contiene el termino a eliminar
	 *
	 * @pre termino esta en el diccionario
	 */

	void removeTermino(const string & palabra);


	/**
	 * @brief Devuelve la posicion del termino con la palabra dada
	 * @param palabra Palabra del termino a buscar
	 *
	 * @pre El termino con palabra esta en el diccionario
	 * @return Posicion del termino en el diccionario
	 *
	 */

	int posTermino(const string & palabra);

	/**
	 * @brief Obtener una seccion delimitada del diccionario
	 * @param c_inicio Caracter de inicio de la seccion
	 * @param c_fin Caracter de fin de la seccion
	 *
	 * c_inicio y c_fin estan incluidos en los extremos
	 *
	 * @return Diccionario, subconnjunto del diccionario original
	 */

	Diccionario filtroIntervalo(const char & c_inicio,
	                            const char & c_fin);


	/**
	 * @brief Obtener un subconjunto con los terminos que contengan
	 * la clave en sus definiciones, se devuelven las definiciones
	 * que contengan la clave
	 *
	 *
	 * @return Diccionario, subconnjunto del diccionario original
	 */

	Diccionario filtroClave(const string & clave);

	/**
	 * @brief Obtener el numero de definiciones de todo el diccionario
	 *
	 * @return entero con el numero de definiciones
	 */

	int getNumDefiniciones();

	/**
	 * @brief Obtener el numero maximo de definiciones asociadas a una palabra
	 *
	 * @return numero maximo de definiciones asociadas a una palabra
	 */

	int maxDefinicionesAsociadasAPalabra();


	/**
	 * @brief Promedio de definiciones por palabra
	 * @return Promedio de definiciones por palabra
	 */

	double promedioDefiniciones();



   /**
   * @brief Iterador que de vuelve el inicio de los terminos de un diccionario
   *
   * @return iterador con el inicio de los terminos del diccionario
   */


   Diccionario::iterator begin();

   /**
   * @brief Iterador constante que de vuelve el inicio de los terminos de un diccionario
   *
   * @return iterador constante con el inicio de los terminos del diccionario
   */

   Diccionario::const_iterator begin() const;


   /**
   * @brief Iterador que de vuelve el fin de los terminos de un diccionario
   *
   * @return iterador con el fin de los terminos del diccionario
   */

   Diccionario::iterator end();


   /**
   * @brief Iterador constante que de vuelve el fin de los terminos de un diccionario
   *
   * @return iterador constante con el fin de los terminos del diccionario
   */

   Diccionario::const_iterator end() const;



	/**
	 * @brief Operador de salida de flujo
	 * @param out Flujo al que mandar termino
	 * @param diccionario Diccionario a mandar por el flujo
	 *
	 * @return referencia al flujo de salida
	 */

	friend ostream & operator << (ostream & out, const Diccionario & diccionario);


	/**
	 * @brief Operador de entrada de flujo
	 * @param in Flujo por el que leer
	 * @param diccionario Diccionario a leer por el flujo
	 *
	 * @return referencia al flujo de entrada
	 */

	friend istream & operator >> (istream & in, Diccionario & diccionario);


};


 #endif

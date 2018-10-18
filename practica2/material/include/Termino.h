/**
  * @file Termino.h
  * @brief Fichero cabecera del TDA Termino
  *
  */

#ifndef TERMINO
#define TERMINO

#include <iostream>

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

   string termino;

   Vector_Dinamico definiciones();


public:

   /**
    * @brief Constructor con dos parametros, el termino, y la primera definicion
    * @param palabra Palabra a asignar en el termino
    * @param definicion Primera definición a asociar al termino
    * @pre palabra != ""
    * @pre definicion != ""
    */

   Termino(const string & palabra, const string & definicion);
   

   /**
    * @brief Constructor de copia
    * @param original Termino a copiar
    * @pre original ha de ser un termino valido
    */

   Termino(const Termino & original);

	/**
	 * @brief getPalabra
	 * @param indice
	 * @return string con la palabra
	 */

	string getPalabra(const int indice) const;

   /**
    * @brief Consultor de definicion
    * @param palabra
    */

   string getDefinicion(const string palabra) const;


};


 #endif
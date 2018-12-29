#ifndef __conjunto_letras_h__
#define __conjunto_letras_h__

#include <iostream>
#include "letra.h"

using namespace std;

class conjunto_letras{

	private:

		set<letra> letras;


	public:

		conjunto_letras();

		set<letra> getLetras() const;

		letra getLetra(const char letra) const;

		bool Esta( const & letra) const;

		friend istream & operator >> (istream & is, conjunto_letras &conjunto );

		friend ostream & operator << (ostream & os, const conjunto_letras &conjunto); 

};

#endif
#ifndef __conjunto_letras_h__
#define __conjunto_letras_h__

#include <iostream>
#include <set>
#include "letra.h"

using namespace std;

class conjunto_letras{

	private:

		set<letra> letras;


	public:

		conjunto_letras();

		int size() const;

		set<letra> getLetras() const;

		void addLetra(const letra & letra);

		void removeLetra(const letra & letra);

		letra getLetra(const letra & letra) const;

		bool Esta( const letra & letra) const;

		friend istream & operator >> (istream & is, conjunto_letras &conjunto );

		friend ostream & operator << (ostream & os, const conjunto_letras &conjunto); 




		class iterator {
			public:
				iterator();
				letra operator *();
				iterator & operator ++ ();
				bool operator ==(const iterator &i);
				bool operator !=(const iterator &i);
				friend class conjunto_letras;
			private:			
				set<letra>::iterator it;
		};
			
		iterator begin();
		iterator end();	



};

#endif
#ifndef __conjunto_letras_h__
#define __conjunto_letras_h__

#include <iostream>
#include <set>
#include "letra.h"
#include <algorithm>

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

		int getPuntuacion(const string palabra, const char & modo) const;

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


		class const_iterator {
			public:
				const_iterator();
				letra operator *() const;
				const_iterator & operator ++ ();
				bool operator ==(const const_iterator &i) const;
				bool operator !=(const const_iterator &i) const;
				friend class conjunto_letras;
			private:			
				set<letra>::const_iterator it;
		};
			
		iterator begin();
		const_iterator begin() const;
		iterator end();	
		const_iterator end() const;




};

#endif
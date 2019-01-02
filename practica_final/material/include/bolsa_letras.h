#ifndef __bolsa_letras_h__
#define __bolsa_letras_h__


#include "letra.h"
#include "conjunto_letras.h"
#include "lista_palabras.h"
#include <unordered_set>


class bolsa_letras{
	private:
		unordered_multiset<char> bolsa;


		//metodo privado para obtener las combinaciones de un string, ej
		// string abc:
		//  a ab ac b ba bc c ca cb abc acb bac bca cab cba
		void getCombinaciones( string str, string res, string & total );
		
	public:
		bolsa_letras();
		bolsa_letras(const bolsa_letras & otra);
		bolsa_letras(const conjunto_letras & c);

		int size() const;

		unordered_multiset<char> getBolsa();
		void addLetra(const letra & l);
		void addLetra(const char & l);
		void removeLetra(const letra & l);
		void removeLetra(const char & l);
		bolsa_letras getLetras(int num);


		set< pair<int, string> > getSoluciones(const conjunto_letras & letras, const lista_palabras & lista, const char & modo);


		bool Esta(const letra & l);
		bool Esta(const char & c);

		bool estanLetras(const string palabra);

		friend istream & operator >> (istream & is, bolsa_letras & bolsa );

		friend ostream & operator << (ostream & os, const bolsa_letras & bolsa); 



	class iterator {
		public:
			iterator();
			char operator *();
			iterator & operator ++ ();
			bool operator ==(const iterator &i);
			bool operator !=(const iterator &i);
			friend class bolsa_letras;
		private:			
			unordered_multiset<char>::iterator it;
	};


	class const_iterator {
		public:
			const_iterator();
			char operator *() const;
			const_iterator & operator ++ ();
			bool operator ==(const const_iterator &i) const;
			bool operator !=(const const_iterator &i) const;
			friend class bolsa_letras;
		private:			
			unordered_multiset<char>::const_iterator it;
	};
	
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;

};




#endif
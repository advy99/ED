#ifndef __bolsa_letras_h__
#define __bolsa_letras_h__


#include "letra.h"
#include <multiset>


class bolsa_letras{
	private:
		multiset<char> bolsa;
		
	public:
		bolsa_letras();

		multiset<char> getBolsa();
		void addLetra(const letra & l);
		void removeLetra(const letra & l);

		bool Esta(const letra & l);
		bool Esta(const char & c);

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
			multiset<char>::iterator it;
	};
	
	iterator begin();
	iterator end();

};








#endif
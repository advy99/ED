#ifndef __letras_h__
#define __letras_h__

//#include <set> // en principio creo que no los usaremos, asi que comento
#include <iostream> //este si, para I/O
//#include <vector>

using namespace std;

class letra{
	private:

	   char caracter; 
		int num_apariciones;
      int puntuacion;
        
	public:
		letra();

		char getCaracter() const;
      int getPuntuacion () const;
		int getNumApariciones() const;

		bool operator == (const letra & otra);

		friend istream & operator >> (istream & is, letra & l);
		friend ostream & operator << (ostream & os, const letra & l);

};



#endif
#ifndef __letras_h__
#define __letras_h__

//#include <set> // en principio creo que no los usaremos, asi que comento
#include <iostream> //este si, para I/O
//#include <vector>

using namespace std;

class letra{
	private:

	   char caracter; 
		int cantidad;
      int puntuacion;
        
	public:
		letra();
		letra(char c, int cant, int p);

		char getCaracter() const;
      int getPuntuacion () const;
		int getCantidad() const;

		void setCaracter( char c);
		void setCantidad(int c);
		void setPuntuacion(int p);

		bool operator == (const letra & otra) const;
		bool operator < (const letra & otra) const;

		friend istream & operator >> (istream & is, letra & l);
		friend ostream & operator << (ostream & os, const letra & l);

};



#endif
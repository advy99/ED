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
		letra( const char & c, const int & cant,const int & p);

		char getCaracter() const;
      int getPuntuacion () const;
		int getCantidad() const;

		void setCaracter(const char & c);
		void setCantidad( const int & c);
		void setPuntuacion(const int & p);

		bool operator == (const letra & otra) const;
		bool operator < (const letra & otra) const;

		friend istream & operator >> (istream & is, letra & l);
		friend ostream & operator << (ostream & os, const letra & l);

};



#endif
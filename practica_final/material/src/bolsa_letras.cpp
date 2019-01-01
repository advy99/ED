#include "bolsa_letras.h"
#include "conjunto_letras.h"

bolsa_letras::bolsa_letras(){

}

multiset<char> bolsa_letras::getBolsa(){
	return bolsa;
} 

void addLetra(const letra & l){

	char caracter = l.getCaracter();

	for(int i = 0; i < l.getCantidad(); i++){
		bolsa.insert(caracter);
	}


}


void removeLetra(const letra & l){

	char caracter = l.getCaracter();

	itarator it;

	it = bolsa.find(caracter);

	while (it != end()){

		bolsa.erease(it);

		it = bolsa.find(caracter);

	}


}

bool bolsa_letras::Esta(const letra & l){
	return ( bolsa.find(l.getCaracter()) != bolsa.end() ) ;
}

bool bolsa_letras::Esta(const char & c){
	return ( bolsa.find(c) != bolsa.end() ) ;
}




istream & operator >> (istream & is, bolsa_letras & bolsa){
	conjunto_letras c;

	is >> c;

	conjunto_letras::iterator it;

	for (it = c.begin(); it != c.end(); ++it){
		addLetra((*it));
	}

	return is;

}


ostream & operator << (ostream & os, const bolsa_letras & b){
	iterator it;

	for (it = b.begin(); it != b.end(); ++it){
		os << (*it) << " ";
	}

	return os;
}



bolsa_letras::iterator bolsa_letras::begin(){

	// para el comienzo, lo iniciamos al comienzo de bolsa y lo devolvemos
	iterator iterador;
	iterador.it = bolsa.begin();
	return iterador;

}

bolsa_letras::iterator bolsa_letras::end(){
	//para el final, devolvemos uno vacio
	iterator iterador;
	iterador.it = bolsa.end();
	return iterador;
}

bolsa_letras::iterator::iterator(){
//Creo que esto esta vacio

}

char bolsa_letras::iterator::operator *(){ 
	return (*it);
}

bolsa_letras::iterator & bolsa_letras::iterator::operator++(){ 
	++it;
	return (*this);
}

bool bolsa_letras::iterator::operator==(const bolsa_letras::iterator &i){
	return i.it == it;
}

bool bolsa_letras::iterator::operator!=(const bolsa_letras::iterator &i){
	return !(i.it == it);
}



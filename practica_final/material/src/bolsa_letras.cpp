#include "bolsa_letras.h"
#include "conjunto_letras.h"

bolsa_letras::bolsa_letras(){

}

bolsa_letras::bolsa_letras(const bolsa_letras & otra){
	bolsa = otra.bolsa;
}



bolsa_letras::bolsa_letras( const conjunto_letras & c){
	
	conjunto_letras::const_iterator it;

	for (it = c.begin(); it != c.end(); ++it){
		addLetra((*it));
	}

}

int bolsa_letras::size() const{
	return bolsa.size();
}

unordered_multiset<char> bolsa_letras::getBolsa(){
	return bolsa;
} 

void bolsa_letras::addLetra(const letra & l){

	char caracter = l.getCaracter();

	for(int i = 0; i < l.getCantidad(); i++){
		bolsa.insert(toupper(caracter));
	}


}

void bolsa_letras::addLetra(const char & caracter){


	bolsa.insert(toupper(caracter));

}



void bolsa_letras::removeLetra(const letra & l){

	char caracter = l.getCaracter();

	iterator it;

	it.it = bolsa.find(caracter);

	while (it != end()){

		bolsa.erase(it.it);

		it.it = bolsa.find(caracter);

	}

}


void bolsa_letras::removeLetra(const char & caracter){

	bolsa.erase( bolsa.find(caracter) );

}







bolsa_letras bolsa_letras::getLetras(int num){
	bolsa_letras aux;
	iterator it;
	int avance;

	for (int i = 0; i < num; i++){
		it = begin();
		srand(time(NULL));
		avance = rand() % size();
		for(int i = 0; i < avance; i++)
			++it;
		aux.addLetra((*it));
		it.it = bolsa.erase(it.it);

	
	}

	return aux;
}







bool bolsa_letras::Esta(const letra & l){
	return ( bolsa.find(l.getCaracter()) != bolsa.end() ) ;
}

bool bolsa_letras::Esta(const char & c){
	return ( bolsa.find(c) != bolsa.end() ) ;
}


bool bolsa_letras::estanLetras(const string palabra){
	bool estan = true;

	for(size_t i = 0; i < palabra.size(); i++){
		estan = bolsa.find( toupper(palabra.at(i)) ) != bolsa.end();
	}

	return estan;
}



istream & operator >> (istream & is, bolsa_letras & bolsa){
	conjunto_letras c;

	is >> c;

	conjunto_letras::iterator it;

	for (it = c.begin(); it != c.end(); ++it){
		bolsa.addLetra((*it));
	}

	return is;

}


ostream & operator << (ostream & os, const bolsa_letras & b){
	bolsa_letras::const_iterator it;

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


bolsa_letras::const_iterator bolsa_letras::begin() const{

	// para el comienzo, lo iniciamos al comienzo de bolsa y lo devolvemos
	const_iterator iterador;
	iterador.it = bolsa.begin();
	return iterador;

}

bolsa_letras::iterator bolsa_letras::end(){
	//para el final, devolvemos uno vacio
	iterator iterador;
	iterador.it = bolsa.end();
	return iterador;
}

bolsa_letras::const_iterator bolsa_letras::end() const{
	//para el final, devolvemos uno vacio
	const_iterator iterador;
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



bolsa_letras::const_iterator::const_iterator(){
//Creo que esto esta vacio

}

char bolsa_letras::const_iterator::operator *() const{ 
	return (*it);
}

bolsa_letras::const_iterator & bolsa_letras::const_iterator::operator++(){ 
	++it;
	return (*this);
}

bool bolsa_letras::const_iterator::operator==(const bolsa_letras::const_iterator &i) const{
	return i.it == it;
}

bool bolsa_letras::const_iterator::operator!=(const bolsa_letras::const_iterator &i) const{
	return !(i.it == it);
}


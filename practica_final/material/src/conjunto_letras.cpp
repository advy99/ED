#include "conjunto_letras.h"

conjunto_letras::conjunto_letras(){

}

int conjunto_letras::size() const{
	return letras.size();
}


set<letra> conjunto_letras::getLetras() const{
	return letras;
}

void conjunto_letras::addLetra(const letra & letra){
	letras.insert(letra);
}

void conjunto_letras::removeLetra(const letra & letra){
	
	letras.erase(letras.find(letra));
}

letra conjunto_letras::getLetra(const letra & letra) const{
	return ( *(letras.find(letra)) );
}

bool conjunto_letras::Esta(const letra & letra) const{
	return ( letras.find(letra) != letras.end() ) ;
}

istream & operator >> (istream & is, conjunto_letras & conjunto){

	letra l;
	string primera_linea;

	getline(is, primera_linea);

	if(primera_linea.at(0) != '#'){
		cerr << "ERROR: No se puede leer el conjunto de letras" << endl;
	} else {

		while (is >> l ){
			conjunto.letras.insert(l);
		}

	}

	return is;
}

ostream & operator << (ostream & os, const conjunto_letras &conjunto){
	
	os << "#Letra Cantidad Puntos" << endl;

	set<letra>::const_iterator it;

	for(it = conjunto.letras.begin(); it != conjunto.letras.end(); it++){
		os << (*it) << endl;		
	}
	return os;

}







conjunto_letras::iterator conjunto_letras::begin(){

	// para el comienzo, lo iniciamos al comienzo del conjunto y lo devolvemos
	iterator iterador;
	iterador.it = letras.begin();
	return iterador;

}

conjunto_letras::iterator conjunto_letras::end(){
	//para el final, devolvemos uno vacio
	iterator iterador;
	iterador.it = letras.end();
	return iterador;
}

conjunto_letras::iterator::iterator(){
//Creo que esto esta vacio

}

letra conjunto_letras::iterator::operator *(){ 
	return (*it);
}

conjunto_letras::iterator & conjunto_letras::iterator::operator++(){ 
	++it;
	return (*this);
}

bool conjunto_letras::iterator::operator==(const conjunto_letras::iterator &i){
	return i.it == it;
}

bool conjunto_letras::iterator::operator!=(const conjunto_letras::iterator &i){
	return !(i.it == it);
}


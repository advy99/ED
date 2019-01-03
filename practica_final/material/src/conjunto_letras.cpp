#include "conjunto_letras.h"
#include <map>

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

letra conjunto_letras::getLetra(const char & c){

	letra l;
	l.setCaracter(c);
	return *(letras.find(l));
}

bool conjunto_letras::Esta(const letra & letra) const{
	return ( letras.find(letra) != letras.end() ) ;
}

int conjunto_letras::getPuntuacion(const string palabra, const char & modo) const{
	int total = 0;

	if (modo == 'P'){
		letra l;

		for(size_t i = 0; i < palabra.size(); i++){
			
			l.setCaracter( toupper(palabra.at(i)) );

			l = (*letras.find(l));

			total += l.getPuntuacion();


		}

	}else{
		total = palabra.size();
	}
	

	return total;
}


int conjunto_letras::totalLetras() const{
	int total = 0;

	set<letra>::iterator it;

	for (it = letras.begin(); it != letras.end(); ++it){
		total += (*it).getCantidad();
	}

	return total;
}



conjunto_letras conjunto_letras::contarLetras(const lista_palabras & lista){
	map<char, int> map_sol;


	for(iterator it = begin(); it != end(); ++it){
		map_sol.insert( make_pair((*it).getCaracter(), 0) );
	}


	map<char,int>::iterator it_find;

	for(lista_palabras::const_iterator it = lista.begin(); it != lista.end(); ++it){

		for(string::iterator sit = (*it).begin(); sit != (*it).end(); ++sit){

			it_find = map_sol.find(toupper(*sit));

			if (it_find != map_sol.end())
				it_find->second += 1;

		}
	}

	conjunto_letras sol;
	letra l;

	for(map<char, int>::iterator it = map_sol.begin(); it != map_sol.end(); ++it){
		l.setCaracter( it->first );
		l.setCantidad( it->second );
		sol.addLetra(l);
	}

	return sol;

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

	conjunto_letras::const_iterator it;

	for(it = conjunto.begin(); it != conjunto.end(); ++it){
		os << (*it);		
	}
	return os;

}







conjunto_letras::iterator conjunto_letras::begin(){

	// para el comienzo, lo iniciamos al comienzo del conjunto y lo devolvemos
	iterator iterador;
	iterador.it = letras.begin();
	return iterador;

}

conjunto_letras::const_iterator conjunto_letras::begin() const{

	// para el comienzo, lo iniciamos al comienzo del conjunto y lo devolvemos
	const_iterator iterador;
	iterador.it = letras.begin();
	return iterador;

}

conjunto_letras::iterator conjunto_letras::end(){
	//para el final, devolvemos uno vacio
	iterator iterador;
	iterador.it = letras.end();
	return iterador;
}

conjunto_letras::const_iterator conjunto_letras::end() const{
	//para el final, devolvemos uno vacio
	const_iterator iterador;
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
	return i.it != it;
}



conjunto_letras::const_iterator::const_iterator(){
//Creo que esto esta vacio

}

letra conjunto_letras::const_iterator::operator *() const{ 
	return (*it);
}

conjunto_letras::const_iterator & conjunto_letras::const_iterator::operator++(){ 
	++it;
	return (*this);
}

bool conjunto_letras::const_iterator::operator==(const conjunto_letras::const_iterator &i) const{
	return i.it == it;
}

bool conjunto_letras::const_iterator::operator!=(const conjunto_letras::const_iterator &i) const{
	return i.it != it;
}


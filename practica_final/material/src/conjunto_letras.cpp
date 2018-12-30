#include "conjunto_letras.h"

conjunto_letras::conjunto_letras(){

}


set<letra> conjunto_letras::getLetras() const{
	return letras;
}

letra conjunto_letras::getLetra(const letra letra) const{
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


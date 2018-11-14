template <typename T>
Cola_max<T>::Cola_max(){

}

template <typename T>
T Cola_max<T>::frente(){
	if (salida.empty()){
		while(!entrada.empty()){
			salida.push(entrada.top());
			entrada.pop();
		}
	}

	return salida.top().first;

}

template <typename T>
T Cola_max<T>::maximo(){
	if (salida.empty()){
		while(!entrada.empty()){
			salida.push(entrada.top());
			entrada.pop();
		}
	}

	return salida.top().second;
}

template <typename T>
T Cola_max<T>::final(){
	if (entrada.empty()){

		while(!salida.empty()){
			entrada.push(salida.top());
			salida.pop();
		}

	}
	return entrada.top();
}

template <typename T>
T Cola_max<T>::final_maximo(){
	if (entrada.empty()){

		while(!salida.empty()){
			entrada.push(salida.top());
			salida.pop();
		}

	}
	return entrada.top_max();
}


template <typename T>
void Cola_max<T>::poner(T elemento){

	while (!salida.empty()){
		entrada.push(salida.top().first);
		salida.pop();
	}

	entrada.push(elemento);
}

template <typename T>
void Cola_max<T>::quitar(){
	if (salida.empty()){

		while(!entrada.empty()){
			salida.push(entrada.top());
			entrada.pop();
		}
	}
   salida.pop();
}


template <typename T>
bool Cola_max<T>::vacia(){
	return ( entrada.empty() && salida.empty() );
}

template <typename T>
int Cola_max<T>::num_elementos(){
	return ( entrada.size() + salida.size() );
}


template <typename T>
Pila_max<T>::Pila_max(){

}

template <typename T>
pair<T,T> Pila_max<T>::top(){
	return pila.top();
}

//template <typename T>
//T Pila_max<T>::top_max(){
//	return pila.top().second;
//}

template <typename T>
void Pila_max<T>::push(T elemento){

	pair<T,T> anadir;

	anadir.first = elemento;
	anadir.second = elemento;


	if (!pila.empty()){

		if (pila.top().second < anadir.second){

			stack< pair<T,T> > aux;

			while (!pila.empty()){
					aux.push(pila.top());
					pila.pop();
			}

			while (!aux.empty()){
				if(aux.top().second < anadir.second)
					aux.top().second = anadir.second;
				pila.push(aux.top());
				aux.pop();
			}

		}
	}

	pila.push(anadir);

}

template <typename T>
void Pila_max<T>::pop(){

	return pila.pop();
}

template <typename T>
bool Pila_max<T>::empty (){
	return pila.empty();
}

template <typename T>
int Pila_max<T>::size(){
	return pila.size();
}

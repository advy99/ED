
template <typename T>
Cola_max<T>::Cola_max(){

}

template <typename T>
T Cola_max<T>::frente(){
	return cola[0].first;
}

template <typename T>
T Cola_max<T>::maximo(){
	return cola[0].second;
}

template <typename T>
T Cola_max<T>::final(){
	return cola[cola.size-1].first;
}

template <typename T>
T Cola_max<T>::final_maximo(){
	return cola[cola.size-1];
}


template<typename T>
void Cola_max<T>::poner(T elemento){

	pair<T,T> tmp;

	tmp.first = elemento;
	tmp.second = elemento;

	for (int i = 0; i < cola.size(); i++){
		if (cola[i].second < tmp.second)
			cola[i].second = tmp.second;
	}

	cola.push_back(tmp);

}

template<typename T>
void Cola_max<T>::quitar (){

	cola.erase(cola.begin());
}

template <typename T>
bool Cola_max<T>::vacia(){
	return cola.empty();
}

template <typename T>
int Cola_max<T>::num_elementos(){
	return cola.size();
}

#include <fstream>
#include <iostream>
#include <string>
#include <set>

int main (int argc, char * argv[]){

    if (argc != 2) {

        cout << "Los parametros son:" << endl;
        cout << "1.- El fichero con las palabras";

        return 0;
    }

    ifstream f(argv[1]);

    if(!f) {

        cout << "No se puede abrir el fichero" << argv[1] << endl;
        
        return 0;
    }

    lista_palabras D;

    cout << "Cargando lista_palabras..." << endl;

    f >> D;

    cout << "Leido el lista_palabras..." << endl;
    cout << D;

    int longitud;

    cout << "Dime la longitud de palabras que quieres ver: "
    
    cin >> longitud;

    vector <string>
    v = D.palabras_longitud(longitud);

    cout << "Palabras de Longitud " << longitud << endl;

    for (unsigned int i = 0; i < v.size(); i++ ) {
        cout << v[i] << endl;
    }

    string p;
    cout << "Dime una palabra: ";
    cin >> p;

    if (D.Esta(p)) {
        cout << "Esa palabra EXISTE" ;
    } else {
        cout << "Esa palabra NO existe";
        }

}
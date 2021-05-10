#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Devuelve el numero de vocales de un fichero
int cuentaVocal(string nombreFichero){
    ifstream in(nombreFichero);
    int nVocal;
    nVocal=0;
    char c;
    
    if(in.is_open()){
	while(in.get(c)){
	    if(c == 'a' || c =='e' || c =='i' || c =='o' || c =='u'){
		nVocal++;
	    }
	    else if(c =='A' || c =='E' || c =='I' || c =='O' || c =='U'){
		nVocal++;
	    }
	}
	in.close();
    }
    else{
	cout << "Error al abrir el fichero." << endl;
    }
    return nVocal;
}

//Devuelve el número de consonantes de un fichero
int cuentaConsonante(string nombreFichero){
    ifstream in(nombreFichero);
    int nConsonante;
    nConsonante=0;
    char c;
    
    if(in.is_open()){
	while(in.get(c)){
	    if(c != 'a' || c!='e' || c!='i' || c!='o' || c!='u'){
		nConsonante++;
	    }
	    else if(c != 'A' || c != 'E' || c != 'I' || c != 'O' || c != 'U'){
		nConsonante++;
	    }
	}
	in.close();
    }
    else{
	cout << "Error al abrir el fichero." << endl;
    }
    return nConsonante;
}

int cuentaLinea(string nombreFichero){
    ifstream in(nombreFichero);
    int nLinea;
    string linea;
    nLinea=0;
    
    if(in.is_open()){
	while(getline(in, linea)){
	    nLinea++;
	}
	in.close();
    }
    else{
	cout << "Error al abrir el fichero." << endl;
    }
    
    return nLinea;
}

//Devuelve el numero de palabras de un fichero
int cuentaPalabra(string nombreFichero){
    ifstream in(nombreFichero);
    int nPal;
    string palabra;
    nPal=0;
    
    if(in.is_open()){
	in >> palabra;
	while( !in.eof() ){
	    if(in.eof()){
		nPal++;
	    }
	}
	in.close();
    }
    else{
	cout << "Error al abrir el fichero." << endl;
    }
    return nPal;
}

int main(){
    string fichero;
    int numeroVocales, numeroConsonantes, numeroLineas, numeroPalabras;
    
    cout << "Introduce un fichero:" << endl;
    cin >> fichero;
    
    numeroVocales = cuentaVocal(fichero);
    numeroConsonantes = cuentaConsonante(fichero);
    numeroLineas = cuentaLinea(fichero);
    numeroPalabras = cuentaPalabra(fichero);
    
    cout << "Fichero seleccionado: " << fichero << endl;
    cout << "\tNumero de vocales: " << numeroVocales << endl;
    cout << "\tNumero de consonantes: " << numeroConsonantes << endl;
    cout << "\tNumero de Lineas: " << numeroLineas << endl;
    cout << "\tNumero de Palabras: " << numeroPalabras << endl;
    
    return 0;
}

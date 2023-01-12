#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

//by RAW

/*
Escriba una clase para gestionar la tabla de las N mejores puntuaciones de un
juego. La clase debe permitir ingresar un nuevo puntaje (y encargarse de ubicarlo
en la posición de la tabla que corresponda, o descartarlo), consultar los datos, y
almacenar y recuperar los mismos mediante un archivo binario.
*/

class Puntuaciones{
	string archivo;int cant;int n;
public:
	Puntuaciones(string nom,int c):archivo(nom),cant(c){
		ofstream archi(archivo,ios::binary);int puntos=50;
		for(int i=0;i<cant;++i){
			archi.write(reinterpret_cast<char*>(&puntos),sizeof(int));
			puntos+=5;
		}
		archi.close();
	}
	
	void verlista(){
		cout<<endl<<endl<<"LISTA:"<<endl;
		ifstream archi(archivo,ios::binary|ios::in|ios::ate);
		n=archi.tellg()/sizeof(int);int p;
		archi.seekg(0);
		for(int i=0;i<n;++i){
			archi.read(reinterpret_cast<char*>(&p),sizeof(p));
			cout<<p<<"    ";
		}
		archi.close();
	}
	void agregarp(int np){
		fstream archi(archivo,ios::binary|ios::in|ios::out);int u=0,el;
		archi.seekg(0);
		for(int i=0;i<n;++i){
			archi.read(reinterpret_cast<char*>(&el),sizeof(int));
			if(np==el){cout<<"el puntaje ya estaba"<<endl;u=-1;}
			else{
				if(np>el){
					u=i+1;}}
		}
		if(u!=-1){
			cout<<endl<<" la pos es: "<<u<<endl;
			int mov=n;
			for(int i=u+1;i<=n;++i){
				archi.seekg((mov-1)*sizeof(int));
				archi.read(reinterpret_cast<char*>(&el),sizeof(int));
				archi.seekp(mov*sizeof(int));
				archi.write(reinterpret_cast<char*>(&el),sizeof(int));
				--mov;
			}
			n++;
			archi.seekp(u*sizeof(int));
			archi.write(reinterpret_cast<char*>(&np),sizeof(int));
		}
		archi.close();
	}
};

int main() {
	Puntuaciones l("ganadores.bin",20);
	l.verlista();
	int p;
	cout<<endl<<"Ingrese nuevo puntaje"<<endl;cin>>p;
	l.agregarp(p);
	l.verlista();
	return 0;
}


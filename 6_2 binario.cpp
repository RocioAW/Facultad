#include <iostream>
#include <fstream>
using namespace std;

//by RAW

/*
Escriba un programa abra el archivo generado en el ejercicio anterior y solicite al
usuario que ingrese un entero, un flotante y una posición. El programa debe
sobrescribir el par en la posición ingresada por el usuario por el nuevo par. Luego
muestre la lista de datos en consola mostrando un par por línea.
*/


struct par{
	float f;
	int e;
};

int main() {
	par p;
	fstream archi("grupo.dat",ios::binary|ios::in|ios::out|ios::ate);
	int n=archi.tellg()/sizeof(p);
	archi.seekg(0);
	for(int i=0;i<n;++i){
		archi.read(reinterpret_cast<char*>(&p),sizeof(p));
		cout<<p.e<<"  "<<p.f<<endl;
	}
	cout<<"Ingrese un entero, un flotante y una posición"<<endl;
	int e,pos;float f;
	cin>>e>>f>>pos;
	p.e=e;p.f=f;
	archi.seekp(pos*sizeof(p));
	archi.write(reinterpret_cast<char*>(&p),sizeof(p));
	archi.close();
	return 0;
}


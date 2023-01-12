#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

//by RAW
/*
Escriba a través de un programa C++ un archivo binario llamado grupo.dat , formado
por un conjunto de 200 pares de números generados aleatoriamente. Cada par de
datos se conforma por un entero y un flotante.
*/
struct par{
	float f;
	int e;
};

int main() {
	ofstream archi("grupo.dat",ios::binary);
	par aux;
	for(int i=0;i<200;++i){
		aux.f=(rand()%1001)/1000.0;
		aux.e=rand()%100+1;
		cout<<aux.f<<" "<<aux.e<<endl;
		archi.write(reinterpret_cast<char*>(&aux),sizeof(aux));
	}
	return 0;
}


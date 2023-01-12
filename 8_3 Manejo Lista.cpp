#include <iostream>
#include <list>
#include <fstream>
using namespace std;

//by RAW

/*
Cree un programa que lea valores flotantes por teclado y los inserte en una lista.
Luego:
a. Muestre dicha lista.
b. Inserte en medio de cada par de elementos contiguos el promedio de
dichos elementos y guarde la lista resultante en un archivo de texto llamado
“listafloat.txt” .
*/

int main() {
	cout<<"Ingrese dimensión y valores flotantes"<<endl;int n;
	cin>>n;
	list<float>l(n);
	for(auto it=l.begin();it!=l.end();++it){
		float v;cin>>v;
		*it=v;
	}
	for(auto it=l.begin();it!=l.end();++it){
		cout<<*it<<"   ";
	}
	float prom;
	for(auto it=next(l.begin());it!=l.end();++it){
		if(distance(l.begin(),it)%2==0){
			prom=((*(prev(it))+*it)/2.0);
			l.insert(it,prom);}
	}
	cout<<endl<<endl<<"Lista con prom"<<endl;
		for(auto it=l.begin();it!=l.end();++it){
			cout<<*it<<"   ";
		}
		cout<<endl<<endl;
		
	ofstream archi("listafloat.txt");
	if(!archi.is_open()){
		cerr<<"No se pudo abrir el archivo"<<endl;
		return 1;
	}
	for(auto it=l.begin();it!=l.end();++it){
		archi<<*it<<"   ";
	}
	archi.close();
	return 0;
}


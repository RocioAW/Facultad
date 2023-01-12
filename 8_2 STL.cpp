#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//by RAW
/*
Escriba un programa que defina un vector dinámico de 30 enteros aleatorios
menores que 25. Luego:
a. Ordene en forma descendente los elementos ubicados entre las posiciones
10 y 20 inclusive, y muestre el vector.
b. Inserte en un nuevo vector los elementos que fueron ordenados en el
apartado anterior, y quítelos del vector original.
c. Permita ingresar un valor por teclado, y muestre cuántas veces aparece
dicho valor en el vector.
d. Elimine todas las ocurrencias del valor ingresado en el punto c, utilizando la
función remove.
*/

int rand_30(){
	return 1+rand()%35;
}

int main() {
	vector<int>v(30);
	generate(v.begin(),v.end(),rand_30);
	for(int x:v)cout<<x<<" ";
	cout<<endl<<endl;
	
	auto it_10=v.begin();
	auto it_20=v.begin();
	advance(it_10,10);
	advance(it_20,21);
	sort(it_10,it_20);
	reverse(it_10,it_20);
	for(int x:v)cout<<x<<" ";
	
	
	vector<int>v2;
	for(auto it=it_10;it!=it_20;++it){
		v2.push_back(*it);
	}
	cout<<endl<<endl<<"Vector extraído: "<<endl;
	for(int x:v2)cout<<x<<"  ";
	cout<<endl<<endl;
	
	v.erase(it_10,it_20);
	cout<<endl<<endl<<"Vector resultante: "<<endl;
	for(int x:v)cout<<x<<"  ";
	cout<<endl<<endl;
	
	int busc;cout<<"Ingrese valor a buscar: "<<endl;cin>>busc;
	int c=0;
	c=count(v.begin(),v.end(),busc);cout<<"El valor aparece: "<<c<<"  veces"<<endl<<endl;
	auto ite=remove(v.begin(),v.end(),busc);
	v.erase(ite,v.end());
	for(int x:v)cout<<x<<"  ";
	cout<<endl<<endl;
	return 0;
}


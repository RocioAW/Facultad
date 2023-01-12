#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
//by RAW
/*
Declare un arreglo estático de 20 elementos enteros ( int v[20]; ) y luego:
a. Implemente una función int rand10() que genere un entero aleatorio entre
-10 y 10, y utilícela como argumento para generate para inicializar el arreglo
con valores aleatorios.
b. Implemente una función bool es_par(int x) que retorne true si el entero que
recibe es par; y utilícela en combinación con count_if para contar cuantos
elementos pares hay en el contenedor generado.
c. Implemente una función bool menor_abs(int a, int b) que reciba dos enteros
y retorne verdadero cuando el valor absoluto del primero sea menor que el
valor absoluto del segundo; y utilice esta función en como argumento de
sort para ordenar el vector por valor absoluto.
d. Elimine los elementos repetidos utilizando los algoritmos genéricos de la
STL, y luego muestre el arreglo resultante.

*/
int rand10(){
	return +rand()%21-10;
}
bool es_par(int x){
	if(x%2==0)return true;
	return false;}
bool menor_abs(int a,int b){
	if(abs(a)>abs(b))return true;
	return false;
}

int main() {
	int v[20];
	auto itb=&v[0];
	auto ite=&v[20];
	generate(itb,ite,rand10);
	cout<<"Vector Generado: "<<endl;
	for(int x:v)
		cout<<x<<"  ";
	cout<<endl<<endl;
	
	int c;
	c=count_if(itb,ite,es_par);cout<<"Cantidad de pares:  "<<c<<endl;
	sort(itb,ite);
	sort(itb,ite,menor_abs);
	cout<<"Vector ordenado por valor absoluto:"<<endl;
	for(int x:v)
		cout<<x<<"  ";
	cout<<endl<<endl;
	
	auto itu=unique(itb,ite);//borra los repetidos y devuelve la nueva última posición
	
	for(auto it=itu;it!=ite;++it){//completa con 0
		*it=0;
	}
	for(int x:v)
		cout<<x<<"  ";
	cout<<endl<<endl;
	
	return 0;
}


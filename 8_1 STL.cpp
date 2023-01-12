#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
using namespace std;

//by RAW

/*
Escriba un programa que permita al usuario ingresar 15 valores por teclado, los
almacene en un vector y luego:
a. Muestre el vector generado utilizando 3 mecanismos de iteración diferentes.
1. utilizando el operador []
2. utilizando iteradores
3. utilizando el for basado en rangos
4. ¿en qué caso es conveniente utilizar cada mecanismo?
b. Calcule y muestre
1. los valores de los elementos máximo y mínimo
2. la suma de todos los elementos del arreglo
3. el promedio y la mediana de los elementos del arreglo
c. Permita al usuario ingresar un valor, e informe si se encuentra en el vector,
y en caso afirmativo, en qué posición.
*/

int main() {
	vector<int>v;cout<<"Ingrese 10 valores"<<endl;
	for(int i=0;i<10;++i){
		int s;
		cin>>s;
		v.push_back(s);
	}
	for(int x:v){
		cout<<x<<"  ";
	}
	cout<<endl<<endl;
	for(vector<int>::iterator it=v.begin();it!=v.end();++it){
		cout<<*it<<"  ";
	}
	cout<<endl<<endl;
	for(int i=0;i<v.size();++i){
		cout<<v[i]<<"  ";
	}
	cout<<endl<<endl;
	auto itm=max_element(v.begin(),v.end());cout<<"Max elemento: "<<*itm<<"  en la pos: "<<itm-v.begin()<<endl;
	auto itmi=min_element(v.begin(),v.end());cout<<"Min elemento: "<<*itmi<<"  en la pos: "<<distance(v.begin(),itmi)<<endl;
	
	int suma=accumulate(v.begin(),v.end(),0);
	cout<<" La suma es: "<<suma<<endl;
	float prom=suma/10.0;cout<<"El prom es: "<<prom<<endl;
	
	int bus;cout<<"Ingrese valor a buscar"<<endl;cin>>bus;
	auto itb=v.end();
	for(auto it=v.begin();it!=v.end;++it){
		if(*it==bus){
			itb=it;
			cout<<"Se encuentra en la pos: "<<itb-v.begin()<<endl;
		}
	}if(itb==v.end())cout<<"No se encuentró el valor"<<endl;
	
	sort(v.begin(),v.end());
	int m=v.size()/2;
	auto itm= v.begin();
	advance(itm,m);
	
	cout<<"La media es: "<<*itm<<endl;
	return 0;
}


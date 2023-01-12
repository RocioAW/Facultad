#include <iostream>
using namespace std;

//by RAW
/*
Implemente una función Clamp(...) que reciba como parámetros una variable (por
referencia) y dos valores indicando los límites superior e inferior para el valor de
dicha variable. Si el valor de la variable supera su máximo, este debe ajustarse al
máximo valor permitido. De la misma forma si el valor es inferior al mínimo. Pruebe
la función templatizada desde un programa cliente.
*/

template<typename T>
void Clamp(T &x,T max,T min){
	if(x>max)
		x=max;
	if(x<min)
	   x=min;
}
int main() {
	cout<<"Ingrese max y min"<<endl;
	int max,min;cin>>max>>min;
	int x=rand()%10;cout<<"Valor generado: "<<x<<endl;
	Clamp(x,max,min);
	cout<<"Valor ajustado: "<<x<<endl;
	return 0;
}


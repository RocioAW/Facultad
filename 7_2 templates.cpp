#include <iostream>
using namespace std;

//by RAW
/*
Implemente una funci�n Clamp(...) que reciba como par�metros una variable (por
referencia) y dos valores indicando los l�mites superior e inferior para el valor de
dicha variable. Si el valor de la variable supera su m�ximo, este debe ajustarse al
m�ximo valor permitido. De la misma forma si el valor es inferior al m�nimo. Pruebe
la funci�n templatizada desde un programa cliente.
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


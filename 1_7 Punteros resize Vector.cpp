#include <iostream>
using namespace std;

//by RAW
/*
Se tiene un arreglo dinámico de n enteros, y se quiere insertar al final c ceros.
Implemente una función redimensionar() que reserve dinámicamente un nuevo
arreglo que contenga lugar para guardar los n datos anteriores y los c ceros que
serán insertados, luego copie en la nueva memoria los datos del vector viejo y
agregue los ceros al final. La memoria del primer arreglo debe ser liberada y la
dirección del arreglo nuevo será retornada para que el programa cliente actualice
su puntero. La función debería poder invocarse de la siguiente manera:
vector_int_dinamico arreglo;
...
arreglo = redimensionar( arreglo, c );
Finalmente, implemente un programa cliente que muestre el arreglo resultante.
*/

struct vector{
	int*p;
	int size;
};

void resize (vector &v,int nueva_size);

int main() {
	vector v;
	int n;
	cout<<"ingrese dimension del vector"<<endl;
	cin>>n;
	
	v.p=new int[n];
	v.size=n;
	
	for(int i=0;i<v.size;i++){
		v.p[i]=1000+rand()%501;
		cout<<v.p[i]<<"  ";
	}
	int nd;
	cout<<endl<<endl<<"ingrese nueva dimensión"<<endl;
	cin>>nd;
	
	resize(v,nd);
	
	for(int i=0;i<v.size;i++){
		cout<<v.p[i]<<"  ";
	}	   
		   
	delete[] v.p;
	return 0;
}

void resize (vector &v,int nueva_size){
	vector nv;
	nv.p=new int[nueva_size];
	nv.size=nueva_size;
	for(int i=0;i<nv.size;i++){
		if(i>=v.size){
			nv.p[i]=0;
		}else{
			nv.p[i]=v.p[i];
		}
	}
	delete[]v.p;
	v.p=nv.p;
	v.size=nv.size;
}

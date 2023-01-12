#include <iostream>
using namespace std;

//by RAW
/*
Programe una clase templatizada llamada VectorDinamico
La clase debe poseer:
a. Un constructor que reciba el tamaño inicial del vector, y reserve la memoria
necesaria.
b. Un destructor que se encargue de liberar la memoria reservada.
c. Una sobrecarga del operador[] que reciba el número de elemento, devuelva
su valor, y permita modificarlo.
d. Modifique o sobrecargue el constructor para que permita generar valores
aleatorios con los cuales inicializar las posiciones del arreglo que reserva.
e. Utilice la clase desde un programa cliente creando vectores aleatorios con
diversos tipos de datos (int,double,string, etc).
*/

float rand_f(){
	return (rand()%1000)/(rand()%15+5)*0.77;
}
int rand_i(){
	return 1+rand()%100;
}
	string rand_s(){
		return "persona"+to_string(rand()%30+3);
	}

template<typename T>
class VectorDinamico{
	int n;T *p;
public:
	
	VectorDinamico(int d):n(d){
		p=new T[n];
	}
	template<typename T2>
		VectorDinamico(int d,T2 gen_rand):n(d){
		p=new T[n];
		for(int i=0;i<n;++i){
			p[i]=gen_rand();
		}
	}	
	T &operator[](int i){return *(p+i);}
	
	template<typename T2>
	void ModificarN(int nd,T2 gen_rand){
		T *pn=new T[nd];
		for(int i=0;i<n;++i){
			pn[i]=p[i];
		}
		for(int i=n;i<nd;++i){
			pn[i]=gen_rand();
		}
		n=nd;
		delete[]p;
		p=pn;
		
	}
	
	~VectorDinamico(){delete[]p;}
};


int main() {
	string modo;
	cout << "Ingrese con que tipo de dato quiere trabajar (int/string/float)"<<endl;cin>>modo;
	int n;cout<<"Ingrese dimensión"<<endl;cin>>n;
	if(modo=="int"){
		VectorDinamico<int>v(n,rand_i);
		for(int i=0;i<n;++i)cout<<v[i]<<"  ";
		int nd;
		cout<<endl<<"Ingrese nueva dimensión"<<endl;cin>>nd;
		v.ModificarN(nd,rand_i);
		for(int i=0;i<nd;++i)cout<<v[i]<<"  ";
	}
	if(modo=="float"){
		VectorDinamico<float>v(n,rand_f);
		for(int i=0;i<n;++i)cout<<v[i]<<"  ";
		int nd;
		cout<<endl<<"Ingrese nueva dimensión"<<endl;cin>>nd;
		v.ModificarN(nd,rand_f);
		for(int i=0;i<nd;++i)cout<<v[i]<<"  ";
	}
	if(modo=="string"){
		VectorDinamico<string>v(n,rand_s);
		for(int i=0;i<n;++i)cout<<v[i]<<"  ";
		int nd;
		cout<<endl<<"Ingrese nueva dimensión"<<endl;cin>>nd;
		v.ModificarN(nd,rand_s);
		for(int i=0;i<nd;++i)cout<<v[i]<<"  ";
	}
	
	return 0;
}


#include <iostream>
#include <vector>
using namespace std;

//by RAW

/*
Implemente una función templatizada llamada Mayor(...) que reciba dos valores y
devuelva el mayor. Compruebe el correcto funcionamiento de la rutina probándola
desde un programa cliente con valores de tipo int , float y string .
a. Programe una sobrecarga de la función Mayor(...) que reciba un vector y
retorne el mayor elemento del mismo. Pruebe la función sobrecargada
desde un programa cliente con diversos tipos de datos.
*/

struct Persona{
	string nombre;
	string apellido;
	int dni;
};

int rand_chico(){
	return (1+rand()%100);
}
bool operator>(Persona a,Persona b){
	if (a.dni<b.dni)
		return true;
	return false;
}
	
	
template <typename T>
T mayor(T a,T b){
	if(a>b){return a;}
	else{return b;}
}
	
	template <typename T>
T mayor_elem(vector<T>v){
		T mayor(v[0]);
		for(int i=0;i<v.size();++i){
			if(v[i]>mayor){
				mayor=v[i];
			}
		}return mayor;
	}
	
int main() {
	cout<<"Ingrese dos entreros"<<endl;
	int a,b;
	cin>>a>>b;
	cout<<"El mayor es: "<<mayor<int>(a,b)<<endl;
	cout<<"Ingrese dos strings"<<endl;
	cin.ignore();string c,d;
	getline(cin,c);getline(cin,d);
	cout<<"El mayor es: "<<mayor<string>(c,d)<<endl;
	cout<<"Ingrese dos flotantes"<<endl;
	float e,f;
	cin>>e>>f;
	cout<<"El mayor es: "<<mayor<float>(e,f)<<endl;
	
	cout<<endl<<endl<<"VECTOR: "<<endl;
	vector<int>v(10);
	for(int &x:v){
		x=rand_chico();
		cout<<x<<"  ";
	}
	cout<<"El mayor elemento es: "<<mayor_elem<int>(v);
	return 0;
}


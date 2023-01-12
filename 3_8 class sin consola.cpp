#include <iostream>
#include <cmath>
using namespace std;
//by RAW
/*
Una fábrica de Tanques los hace de forma de Cilindro o de Esfera, en ambos
envases debemos rotular el volumen en m3 y el peso en kilogramos.
Modele una clase base Tanque con los atributos volumen y peso. Un método
público AsignarPeso(p), un método virtual puro CalcularVolumen() que calcule el
volumen de acuerdo a los parámetros de los hijos y otros 2 métodos para
VerVolumen() y VerPeso().
Modele la clase hija Cilindro que tendrá los atributos radio y altura, cuya fórmula de
volumen es: área de la base x altura, donde el area de la base se calcula como
PI*radio^2; y otra clase hija Esfera que tendrá el atributo radio, cuya fórmula de
volumen es: 4/3*PI*radio^3. Los atributos (medidas y peso) los debe cargar con un
constructor.
En el programa principal debe usar un único puntero de tipo Tanque para crear
primero un Cilindro y mostrar su volúmen, y luego una Esfera y también mostrar su
volúmen.
*/
class Tanque{
protected:
	float volumen;
private:
	float peso;
public:
	void AsignarPeso(float p){peso=p;}
	virtual void CalcularVolumen()=0;
	float VerVolumen(){return volumen;}
	float VerPeso(){return peso;}
	virtual ~Tanque(){}; // !! importante el destructor
};

class Cilindro:public Tanque{
	float radio,altura;
public:
	Cilindro(float r,float a,float p):radio(r),altura(a){AsignarPeso(p);}
	void CalcularVolumen()override{volumen=(radio*radio*3.14)*altura;}
};

class Esfera:public Tanque{
	float radio;
public:
	Esfera(float r,float p):radio(r){AsignarPeso(p);}
	void CalcularVolumen()override{volumen=(4.0/3.0)*3.14*pow(radio,3);}
};




int main(int argc, char *argv[]) {
	Tanque *t;

		float r,a,p;
		cout<<"Ingrese radio, altura y peso del cilindro"<<endl;
		cin>>r>>a>>p;
		t=new Cilindro(r,a,p);

		
	t->CalcularVolumen();
	cout<<"el volumen es:  "<<t->VerVolumen()<<" m3"<<endl;	
		
	delete t;
		
		cout<<"ingrese radio y peso de la esfera"<<endl;
		r=0;p=0;
		cin>>r>>p;
		t=new Esfera(r,p);
	
	
	
	t->CalcularVolumen();
	cout<<"el volumen es:  "<<t->VerVolumen()<<" m3"<<endl;
	
	delete t;
	
	
	return 0;
}

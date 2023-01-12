#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//by RAW 

/*
	Un conjunto de archivos de texto contiene información guardada en el formato que
se muestra en el recuadro, donde cada línea contiene el nombre de un campo y su
respectivo valor separados por el signo igual (=). Las líneas que comienzan con el
carácter '#' deben ser ignoradas.
	Escriba una clase llamada ConfigFile que permita interpretar el contenido de estos
archivos. La clase debe poseer:
a) un constructor que reciba el nombre del archivo y cargue sus datos en un
vector de structs (cada elemento es struct con dos strings: campo y valor).
b) un método para consultar el valor asociado a un campo
c) un método para modificar el valor asociado a un campo
d) un método para guardar el archivo con los datos actualizados

*/
struct linea{
	string campo;
	string valor;
};

class ConfigFile{
private:
	vector<linea>v;string nom_archivo;
public:
	ConfigFile(string archivo):nom_archivo(archivo){
		string a;int u;linea aux;
		ifstream archi(archivo);
		if(!archi.is_open()){
			cerr<<"No se pudo abrir el archivo"<<endl;
		}
		while(getline(archi,a)){
			if (a[0]=='#'){}
			else{
				u=a.find('=');
				aux.campo=a.substr(0,u);
				aux.valor=a.substr(u+1);
				v.push_back(aux);
			}
		}archi.close();
	}
	string consultarvalor(string campo){
		for(int i=0;i<v.size();++i){
			if(v[i].campo==campo)
				return v[i].valor;
		}return "  ";
	}
	void modifvalor(string campo,string valor){
		for(int i=0;i<v.size();++i){
			if(v[i].campo==campo)
				v[i].valor=valor;}
	}
	void vervector(){
		cout<<endl<<"VECTOR:"<<endl;
			for(linea a:v){
				cout<<a.campo<<": "<<a.valor<<endl;
			}
		}
	void ActualizarArchivo(){
		ofstream archi2(nom_archivo,ios::trunc);
		for(linea a:v){
			archi2<<a.campo<<"="<<a.valor<<endl;
		}
		archi2.close();
	}
};
	
int main() {
	string archivo="confipractica.txt";
	ConfigFile f(archivo);
	f.vervector();
	string campo,valor;
	cout<<"Ingrese campo para consultar su valor"<<endl;
	getline(cin,campo);
	valor=f.consultarvalor(campo);
	cout<<"El valor es: "<<valor<<endl;
	
	cout<<"Ingrese campo para modificar su valor y luego el nuevo valor"<<endl;
	getline(cin,campo);getline(cin,valor);f.modifvalor(campo,valor);
	f.vervector();
	f.ActualizarArchivo();
	return 0;
}


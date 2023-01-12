#include <iostream>
#include <vector>
using namespace std;

//by RAW

/*
Una casa de venta de música, cuenta con un stock de CDS y DVDs, de cada uno de ellos tiene los siguientes datos Nombre o título del álbum, artista, género musical, stock disponible y precio. Codificar la carga de los datos iniciales hasta que el nombre del álbum sea "ZZZ".
Codifique una función que retorne la posición de un álbum en el vector buscando por nombre.
Use esa función simulando ventas, se ingresa el nombre de un álbum y, si existe y hay stock suficiente, se decuenta 1 del stock, sino debe emitir un mensaje alusivo. La venta termina cuando se ingresa álbum  "ZZZ".
Codifique una funcíon que retorne una sublista de CDs según el artista que entra como parámetro.

*/
struct album{
	string titulo;
	string artista;
	string genero;
	int stock;
	float precio;
};
int GetPosicionAlbum(vector<album>albumnes,string titulo);
vector<album>GetSubLista(vector<album>albumnes,string artista);

int main() {
	/// carga inicial del vector de albumnes 
	
	vector<album>albumnes;
	string titulo;
	cout<<"Ingrese titulo para agregar a la lista: ";getline(cin,titulo);
	while (titulo != "ZZZ"){
		/// declaro una instancia nueva del struct 
		album a;
		a.titulo = titulo;
		cout<<"Artista "; getline(cin,a.artista);
		cout<<"Genero "; getline(cin,a.genero);
		cout<<"Stock actual ";cin>>a.stock;
		cout<<"Precio ";cin>>a.precio;
		/// agrego la instancia del struct al vector 
		albumnes.push_back(a);cin.ignore();
		cout<<"Ingrese titulo para agegar a la lista: ";getline(cin,titulo);
	}
	
	/// simular la venta 
	cout<<endl<<endl<<"Ingrese titulo para vender: ";getline(cin,titulo);
	while (titulo != "ZZZ"){
		int pos = GetPosicionAlbum(albumnes,titulo);
		if (pos != -1){
			if (albumnes[pos].stock > 0){
				albumnes[pos].stock --;
			cout<<"Quedan en stock: "<<albumnes[pos].stock<<endl;}
			else{
				cout<<"No hay stock suficiente del álbum "<<titulo<<endl;
			}
		}else{
				cout<<"No se encuentra el album "<<titulo<<endl;
		}
		cout<<endl<<"Ingrese titulo para vender: ";getline(cin,titulo);
	}
	
	string artistas;
	cout<<endl<<endl<<"Ingrese artista para generar sublista: ";getline(cin,artistas);
	vector<album>subl=GetSubLista(albumnes,artistas);
	cout<<endl<<endl<<"SUBLISTA:"<<subl.size()<<endl;
	for(int i=0;i<subl.size();i++){
		cout<<subl[i].titulo<<endl;
	}

	return 0;
}


///FUNCIONES:
int GetPosicionAlbum(vector<album>albumnes,string titulo){
	for(int i = 0;i<albumnes.size();i++){
		if (albumnes[i].titulo == titulo){
			return i; /// retorno la posicion
		}
	}
	return -1;
}
vector<album>GetSubLista(vector<album>albumnes,string artista){
		vector<album>sublis;
		for(int i=0;i<albumnes.size();i++){
			if (albumnes[i].artista==artista){
				album aux=albumnes[i];
				sublis.push_back(aux);
			}
		}
		return sublis;
	}

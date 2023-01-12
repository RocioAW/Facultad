#include <iostream>
#include <matrix>
#include <tuple>
using namespace std;

//by RAW

/*codificar una funcion que reciba como parametros una matriz y un nro a buscar
si lo encuentra, debe retornar una tupla con la fila y columna de la posicion
 sino, debe retornar la tupla -1,-1
*/

tuple<int,int>Busqueda(matrix<int>m,int nrobuscar);
	
int main(int argc, char *argv[]) {
	matrix<int>m(8,8);
	for (size_t i=0;i<m.size(0);i++){
		for (size_t j=0;j<m.size(1);j++){
			m[i][j]=100+rand()%600;
			cout<<m[i][j]<<"   ";
		}
		cout<<endl<<endl;
	}
	int nrobuscar;
	cout<<endl<<"ingrese un nro para buscar en la matriz"<<endl;
	cin>>nrobuscar;
	int fila;int columna;
	tie(fila,columna)=Busqueda(m,nrobuscar);
	if (fila!=-1){
		cout<<endl<<"Se encuentra en fila: "<<fila<<"   y columna: "<<columna;
	}
	else{
		cout<<endl<<"No se encontró el nro en la matriz"<<endl;
	}
	return 0;
}
tuple<int,int>Busqueda(matrix<int>m,int nrobuscar){
	for (int i=0;i<m.size(0);i++){
		for (int j=0;j<m.size(1);j++){
			if(m[i][j]==nrobuscar){
				//encontro la fila columna
				return make_tuple(i,j);}
		}
	}//no encontro el nro
	return make_tuple(-1,-1);}


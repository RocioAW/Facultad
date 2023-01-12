#include <iostream>
#include <matrix>
using namespace std;
///By Rocío Widmer
/*
Codifique un algoritmo C++ que llene una matriz cuadrada de NxN elementos 
con datos enteros al azar (N es dato incial y que sea par).
Implemente una función que retorne una matriz float con el promedio de los 4 cuadrantes.
*/

matrix<float>GetPromediosCuadrantes(matrix<int>m){
	matrix<float>m2(2,2);
	float suma;
	/// 1 bucle for anidado por cuadrante
	
	/// 1er cuadrante
	suma=0;
	for (int i=0;i<m.size(0)/2;i++){
		for (int j=0;j<m.size(1)/2;j++){
           suma+=m[i][j];
		}
	}
	m2[0][0]= suma / (m.size(0) * m.size(1) / 4);
	
	
	/// 2do cuadrante
	suma = 0;
	for (int i = 0;i<m.size(0)/2;i++){
		for (int j = m.size(1)/2;j<m.size(1);j++){
			suma += m[i][j];
		}
	}
	m2[0][1] = suma / (m.size(0) * m.size(1) / 4);
	
	/// 3er cuadrante
	suma = 0;
	for (int i=m.size(0)/2;i<m.size(0);i++){
		for (int j = 0;j<m.size(1)/2;j++){
			suma += m[i][j];
		}
	}
	m2[1][0] = suma / (m.size(0) * m.size(1) / 4);
	
	/// 4to cuadrante
	suma = 0;
	for (int i = m.size(0)/2;i<m.size(0);i++){
		for (int j = m.size(1)/2;j<m.size(1);j++){
			suma += m[i][j];
		}
	}
	m2[1][1] = suma / (m.size(0) * m.size(1) / 4);
	
	return m2;
}

int main() {
	int N;
	cout<<"Ingrese cantidad de filas y columnas ";cin>>N;
	
	matrix<int>m(N,N);  ///N  par 
	for (int i=0;i<m.size(0);i++){
		for (int j=0;j<m.size(1);j++){
			m[i][j] = 100+rand()%600;
			cout<<m[i][j]<< "    ";
		}
		cout<<endl<<endl;
	}
	cout<<"SUBLISTA CON PROMEDIO DE CUADRANTES:"<<endl<<endl;
	matrix<float>sublistaprom;
	sublistaprom=GetPromediosCuadrantes(m);
	for (int i = 0;i<sublistaprom.size(0);i++){
		for (int j = 0;j<sublistaprom.size(1);j++){
			cout<<sublistaprom[i][j]<< "    ";
		}
		cout<<endl<<endl;
		}
	
	return 0;
}


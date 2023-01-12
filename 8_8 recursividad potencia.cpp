#include <iostream>
using namespace std;

//by RAW

int potencia (int nro,int exp);
int main() {
	int nro,exp,result;
	cin>>nro;cin>>exp;
	if(nro==0)
		cout<<0;
	else {
		result= potencia(nro,exp);
		cout<<result<<endl;
	}
		
	return 0;
}

int potencia (int nro,int exp){
	if(exp==0)
		return 1;
	return nro*potencia(nro,exp-1);
	
}

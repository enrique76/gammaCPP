#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
//#include "termino.hpp"
//#include "operaciones.hpp"
//#include "ecuacion.hpp"
#include"variable.hpp"

using namespace std;

int main(){

	Variable *v = new Variable(2,"x",2);
	

	cout<<"f("<<v->getVariable()<<") = "; v->Imprimir(); 

	for(int n=0;n<10;n++){
		cout<<"\nf("<<n<<") = "<<v->evaluar(n);
	}

	return 0;
}

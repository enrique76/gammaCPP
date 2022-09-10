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
	system("cls");

	string f; 
	int li,ls;

	cout<<"Funcion: "; getline(cin,f);
	cout<<"\nLimite inferior: "; cin>>li;
	cout<<"\nLimite superior: "; cin>>ls;

	Variable *v = new Variable(f,"x");

	system("cls");
	cout<<"\n\nFuncion: "; v->Imprimir();
	v->Imprimir_ARG();

	for(int i=li;i<ls;i++){
		cout<<"\nF("<<i<<") = "<<v->evaluar(i);
	}

	return 0;
}

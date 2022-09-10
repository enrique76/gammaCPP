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
	

	cout<<"Funcion#1: "; getline(cin,f);

	Variable *v = new Variable(f,"x");

	cout<<"\n\nFuncion#2: "; getline(cin,f);

	Variable *v2 = new Variable(f,"x");

	system("cls");
	cout<<"\n\nFuncion: "; v->Imprimir(); cout<<" \t "; v2->Imprimir(); 
	cout<<"\nDerivada: "; v->diff()->Imprimir(); cout<<" \t "; v2->diff()->Imprimir();
	cout<<"\nIntegral indefinida: "; v->Int()->Imprimir(); cout<<" \t "; v2->Int()->Imprimir();

	
	
	return 0;
}

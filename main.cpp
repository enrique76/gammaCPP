#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include "termino.hpp"
//#include "operaciones.hpp"
//#include "ecuacion.hpp"
#include"variable.hpp"
#include<vector>

using namespace std;

int main(){
	system("cls");

	string f; 
	

	cout<<"Funcion#1: "; getline(cin,f);

	Variable *v = new Variable(f,"x");

	cout<<"\n\nFuncion#2: "; getline(cin,f);

	Variable *v2 = new Variable(f,"x");

	system("cls");
	cout<<"\n\nFuncion#1: "; v->Imprimir();
	cout<<"\nFuncion#2: "; v2->Imprimir();

	cout<<"\nDerivada#1: "; v->diff()->Imprimir(); 
	cout<<"\nDerivada#2: "; v2->diff()->Imprimir();

	cout<<"\nIntegral indefinida#1: "; v->Int()->Imprimir(); 
	cout<<"\nIntegral Indefinica#2: "; v2->Int()->Imprimir();

	cout<<"\n\nOperaciones Aritmeticas";

	cout<<"\n\n"; v->Imprimir(); cout <<" + "; v2->Imprimir(); cout<<" = "; (*v+v2)->Imprimir();
	cout<<"\n"; v->Imprimir(); cout <<" - "; v2->Imprimir(); cout<<" = "; (*v-v2)->Imprimir();
	cout<<"\n"; v->Imprimir(); cout <<" * "; v2->Imprimir(); cout<<" = "; (*v*v2)->Imprimir();
	cout<<"\n"; v->Imprimir(); cout <<" / "; v2->Imprimir(); cout<<" = "; (*v/v2)->Imprimir();

	// vector<string> v;

	// v.push_back("x");
	// v.push_back("y");
	// v.push_back("z");

	// Termino *t = new Termino("25xy^2z^3",v);
	
	return 0;
}

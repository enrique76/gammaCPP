#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include "termino.hpp"
#include "operaciones.hpp"
#include "ecuacion.hpp"

using namespace std;

int main(){

//	string aux;
//
//	cout<<"\n\nIngrese su primer Ternino: "; cin>>aux;
//
//	termino *a = new termino();
//	a->SetData(aux);
//
//	cout<<"\n\nIngrese su segundo Termino: "; cin>>aux;
//
//	termino *b = new termino();
//	b->SetData(aux);
//
//	system("cls");
	
	termino *a = new termino(2,"x",2,0);
	termino *b = new termino(5,"x",2,0);
	termino *s = new termino();
	termino *r = new termino();
	termino *m = new termino();
	termino *d = new termino();
	ecuacion *e = new ecuacion();

	s = a->operator+(b);
	r = a->operator-(b);
	producto(a,b,m);
	division(a,b,d);
	
	e->add(a); e->add(b); e->add(s); e->add(r); e->add(m); e->add(d); 

	e->Ordenar();

	cout<<"\n\nPrimer Termino: "; a->Imprimir();
	cout<<"\n\nSegundo Termino: "; b->Imprimir();
	cout<<"\n\nSuma de "; a->Imprimir(); cout<<" + "; b->Imprimir(); cout<<" = "; s->Imprimir();
	cout<<"\n\nResta de "; a->Imprimir(); cout<<" - "; b->Imprimir(); cout<<" = "; r->Imprimir();
	cout<<"\n\nProducto de "; a->Imprimir(); cout<<" * "; b->Imprimir(); cout<<" = "; m->Imprimir();
	cout<<"\n\nDivision de "; a->Imprimir(); cout<<" / "; b->Imprimir(); cout<<" = "; d->Imprimir();
	cout<<"\n\nEcuacion: "; e->Imprimir();
	//cout<<"\n\nOrden Mayor: "; e->getOrdenMayor();

	getch();
	return 0;
}

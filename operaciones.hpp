#ifndef OPERACIONES
#define OPERACIONES

#include<iostream>
#include<math.h>
#include<stdlib.h>
#include "termino.hpp"

void suma(termino *a,termino *b,termino *t){
	if((a->variable == b->variable)&&(a->exponente == b->exponente)){
		t->variable = a->variable;
		t->exponente = a->exponente;
		t->coeficiente = a->coeficiente + b->coeficiente;
	}
}

void resta(termino *a,termino *b,termino *r){
	if((a->variable == b->variable)&&(a->exponente == b->exponente)){
		r->variable = a->variable;
		r->exponente = a->exponente;
		r->coeficiente = a->coeficiente - b->coeficiente;
	}
}

void producto(termino *a,termino *b,termino *p){
	p->coeficiente = a->coeficiente * b->coeficiente;
	p->variable = a->variable;
	p->exponente = a->exponente + b->exponente;
}

void division(termino *a,termino *b,termino *d){
	d->coeficiente = a->coeficiente / b->coeficiente;
	d->variable = a->variable;
	d->exponente = a->exponente - b->exponente;
}


#endif // OPERACIONES

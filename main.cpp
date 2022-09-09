#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include "termino.hpp"
#include "operaciones.hpp"
#include "ecuacion.hpp"
#include"variable.hpp"

using namespace std;

int main(){

	Variable *v = new Variable("x");

	v->evaluar(6);

	cout<<v->getVariable()<<" = "<<v->getValor();

	return 0;
}

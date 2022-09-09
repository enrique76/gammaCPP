#ifndef VARIABLE
#define VARIABLE

#include<iostream>
#include<math.h>
#include<stdio.h>

using namespace std;

class Variable{
    private:
        string variable;
        double valor = NULL;
    public:
        // constructores

        Variable(string variable){
            this->variable = variable;
        }

        Variable(double valor){
            this->valor = valor;
        }

        Variable(string variable, double valor){
            this->variable = variable;
            this->valor = valor;
        }

        Variable(){
            this->variable = "x";
            this->valor = 1;
        }

        // dar valor 

        void evaluar(double v){
            this->valor = v;
        }

        // getters 

        string getVariable(){
            return this->variable;
        }

        double getValor(){
            return this->valor;
        }

        // setters 

        void setVariable(string v){
            this->variable = v;
        }
};

#endif // VARIABLE
#ifndef TERMINO
#define TERMINO

#include<iostream>
#include<string>

using namespace std; // 

class termino{
	public:
		double coeficiente;
		string variable;
		double exponente;
		int pos;
	public:
		termino(double coeficiente,string variable,double exponente,int pos){
			this->coeficiente = coeficiente;
			this->variable = variable;
			this->exponente = exponente;
			this->pos = pos;
		}

		termino(){
			this->coeficiente = 0;
			this->variable = "x";
			this->exponente = 1;
			this->pos = 0;
		}

		termino(termino *t,int i){
			this->coeficiente = t->coeficiente;
			this->variable = t->variable;
			this->exponente = t->exponente;
			this->pos = i;
		}

		termino(termino *t){
			this->coeficiente = t->coeficiente;
			this->variable = t->variable;
			this->exponente = t->exponente;
			this->pos = t->pos;
		}

		~termino(){

		}

		void Imprimir(){
			if(this->coeficiente != 0){
				if(this->coeficiente > 0){
					if(this->pos != 0){
						cout<<" + "<<this->coeficiente;
					}
					else{
						cout<<this->coeficiente;
					}
				}
				else{
					cout<<" "<<this->coeficiente;
				}

				if(this->exponente == 0){
					// no se imprime nada
				}
				else if(this->exponente == 1){
					cout<<this->variable;
				}
				else{
					cout<<this->variable<<"^"<<this->exponente;
				}
			}
		}

		void Imprimir_full(){
			if(this->coeficiente != 0){
				if(this->coeficiente > 0){
					if(this->pos != 0){
						cout<<" + "<<this->coeficiente;
					}
					else{
						cout<<this->coeficiente;
					}
				}
				else{
					cout<<" "<<this->coeficiente;
				}

				if(this->exponente == 0){
					// no se imprime nada
				}
				else if(this->exponente == 1){
					cout<<this->variable;
				}
				else{
					cout<<this->variable<<"^"<<this->exponente;
				}
			}

			cout<<", "<<this->pos;
		}

		void operator = (termino *t){
			this->coeficiente = t->coeficiente;
			this->variable = t->variable;
			this->exponente = t->exponente;
			this->pos = t->pos;
		}

		termino * operator + (termino *b){
			termino *t = new termino();

			if((this->variable == b->variable)&&(this->exponente == b->exponente)){
				t->variable = this->variable;
				t->exponente = this->exponente;
				t->coeficiente = this->coeficiente + b->coeficiente;
				return t;
			}
			else{
				return b;
			}
		}

		termino * operator - (termino *b){
			termino *t = new termino();

			if((this->variable == b->variable)&&(this->exponente == b->exponente)){
				t->variable = this->variable;
				t->exponente = this->exponente;
				t->coeficiente = this->coeficiente - b->coeficiente;
				return t;
			}
			else{
				return b;
			}
		}

//		void SetData(string datos){
//			string aux;
//			
//			for(int i=0;i<datos.find("^")-1;i++){
//				aux<<datos[i];
//			}
//
//			this->coeficiente = stod(aux);
//			this->variable = datos.at(datos.find("^")-1);
//			this->exponente = stod(datos.substr(datos.find("^"),datos.size()));
//		}
};

#endif // TERMINO


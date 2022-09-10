#ifndef VARIABLE
#define VARIABLE

#include<iostream>
#include<string>
#include<math.h>
#include<conio.h>

using namespace std; // 

class Variable{
	public:
		double coeficiente;
		string variable;
		double exponente;
		double valor = NULL;
		int pos = 0;
		string expresion = " ";
	public:

		// operadores 
		Variable(string v){
			this->variable = v;
			this->exponente = 1;
			this->coeficiente = 1;
		}

		Variable(double coeficiente,string variable,double exponente,int pos){
			this->coeficiente = coeficiente;
			this->variable = variable;
			this->exponente = exponente;
			this->pos = pos;
		}

		Variable(double coeficiente,string variable,double exponente){
			this->coeficiente = coeficiente;
			this->variable = variable;
			this->exponente = exponente;
		}

		Variable(){
			this->coeficiente = 0;
			this->variable = "x";
			this->exponente = 1;
			this->pos = 0;
		}

		Variable(Variable *t,int i){
			this->coeficiente = t->coeficiente;
			this->variable = t->variable;
			this->exponente = t->exponente;
			this->pos = i;
		}

		Variable(Variable *t){
			if(t->getValor() != NULL){
				this->valor = t->getValor();
				this->exponente = 1;
				this->coeficiente = 1;
				this->variable = t->getVariable();
				this->pos = t->getPos();
			}
			else{
				this->coeficiente = t->coeficiente;
				this->variable = t->variable;
				this->exponente = t->exponente;
				this->pos = t->pos;
			}
		}

		Variable(string f,string v){
			if(f.find("(") == 0 && f.find(")") ==  f.size()-1){
				f = f.substr(1,f.size()-1);
			}

			this->expresion = f;

			if(f.find(v) > 0){
				this->coeficiente = stod(f.substr(0,f.find(v)));
				this->variable = v;
				this->exponente = 1;
			}
			else if(f.find(v) == 0){
				if(f.find(v+"^")){
					this->coeficiente = stod(f.substr(0,f.find(v+"^")));
					this->variable = v;
					this->exponente = stod(f.substr(f.find("^")+1,f.size()-1));
				}
				else{
					this->coeficiente = 1;
					this->variable = v;
					this->exponente = 1;
				}
			}
			else{
				this->coeficiente = stod(f);
				this->variable = v;
				this->exponente = 1;
			}	
		}
		// destructor 

		~Variable(){

		}

		// imprimir 

		void Imprimir(){
			if(this->coeficiente != 0){
				if(this->coeficiente == 1){
					if(this->pos != 0){
						cout<<" + ";
					}
				}
				else if(this->coeficiente > 0){
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
			else if(this->valor != NULL){
				cout<<this->valor;
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
			else if(this->valor != NULL){
				cout<<this->valor;
			}

			cout<<", "<<this->pos;
		}

		void Imprimir_ARG(){
			cout<<"\nCoeficiente: "<<this->coeficiente;
			cout<<"\nVariable: "<<this->variable;
			cout<<"\nExponente: "<<this->exponente;
			cout<<"\nValor: "<<this->valor;
			cout<<"\nPos: "<<this->pos;
		}
		// setters 

		void setVariable(string v){
			this->variable = v;
		}

		void setCoeficiente(double c){
			this->coeficiente = c;
		}

		void setExponente(double e){
			this->exponente = e;
		}

		void setValor(double v){
			this->valor = v;
			this->exponente = 1;
			this->coeficiente = 1;
		}

		void setPos(int v){
			this->pos = v;
		}
		// getters 

		string getVariable(){
			return this->variable;
		}

		double getCoeficiente(){
			return this->coeficiente;
		}

		double getExponente(){
			return this->exponente;
		}

		double getValor(){
			return this->valor;
		}
		
		int getPos(){
			return this->pos;
		}
		
		string getExpresion(){
			return this->expresion;
		}
		// operadores logicos por Variable =,==,!=,<,>,<=,>=

		void operator = (Variable *t){
			this->coeficiente = t->coeficiente;
			this->variable = t->variable;
			this->exponente = t->exponente;
			this->pos = t->pos;
			this->valor = t->valor;
		}

		bool operator == (Variable *t){
			bool v = false; 

			if((this->valor && t->getValor()) != NULL){ 
				if(this->valor == t->getValor()){
					v = true;
				}
			}
			else if((this->coeficiente == t->coeficiente) && 
				(this->variable == t->variable) && 
				(this->exponente == t->exponente)){
				v = true;
			}

			return v;
		}

		bool operator != (Variable *t){
			bool v = false; 

			if((this->valor && t->getValor()) != NULL){ 
				if(this->valor != t->getValor()){
					v = true;
				}
			}
			else if((this->coeficiente != t->coeficiente) && 
				(this->variable != t->variable) && 
				(this->exponente != t->exponente)){
				v = true;
			}

			return v;
		}

		bool operator < (Variable *t){
			bool v = false; 

			if((this->valor && t->getValor()) != NULL){ 
				if(this->valor < t->getValor()){
					v = true;
				}
			}
			return v;
		}
		
		bool operator > (Variable *t){
			bool v = false; 

			if((this->valor && t->getValor()) != NULL){ 
				if(this->valor > t->getValor()){
					v = true;
				}
			}
			return v;
		}
		
		bool operator <= (Variable *t){
			bool v = false; 

			if((this->valor && t->getValor()) != NULL){ 
				if(this->valor <= t->getValor()){
					v = true;
				}
			}
			return v;
		}
		
		bool operator >= (Variable *t){
			bool v = false; 

			if((this->valor && t->getValor()) != NULL){ 
				if(this->valor >= t->getValor()){
					v = true;
				}
			}
			return v;
		}

		// operadores logicos por Valor  =,==,!=,<,>,<=,>=

		void operator = (double v){
			this->setValor(v);
		}

		bool operator == (double t){
			bool v = false;

			if(this->valor != NULL){
				if(this->valor == t){
					v = true;
				}
			}
			
			return v;
		}

		bool operator != (double t){
			bool v = false;

			if(this->valor != NULL){
				if(this->valor != t){
					v = true;
				}
			}
			
			return v;
		}
		
		bool operator < (double t){
			bool v = false;

			if(this->valor != NULL){
				if(this->valor < t){
					v = true;
				}
			}
			
			return v;
		}
		
		bool operator > (double t){
			bool v = false;

			if(this->valor != NULL){
				if(this->valor > t){
					v = true;
				}
			}
			
			return v;
		}
		
		bool operator <= (double t){
			bool v = false;

			if(this->valor != NULL){
				if(this->valor <= t){
					v = true;
				}
			}
			
			return v;
		}

		bool operator >= (double t){
			bool v = false;

			if(this->valor != NULL){
				if(this->valor >= t){
					v = true;
				}
			}
			
			return v;
		}		
		
		// operadores logicos por String =,==,!=,<,>,<=,>=
		
		void operator = (string e){
			Variable *v = new Variable(e,this->getVariable());

			this->coeficiente = v->getCoeficiente();
			this->exponente = v->getExponente();
		}

		bool operator == (string e) {
			Variable *v = new Variable(e,this->getVariable());

			if(e.find(v->getVariable())){
				if((this->variable == v->getVariable()) && 
					(this->exponente == v->getExponente()) && 
					(this->coeficiente == v->getCoeficiente())){
						return true;
				}
			}

			return false;
		}
		
		bool operator != (string e){
			Variable *v = new Variable(e,this->getVariable());

			if(!e.find(v->getVariable())){
				if((this->variable != v->getVariable()) && 
					(this->exponente != v->getExponente()) && 
					(this->coeficiente != v->getCoeficiente())){
						return true;
				}
			}

			return false;
		}
		
		// operadores aridmeticos por Variable +,+=,-,-=,*,*=,/,/=,
		
		Variable * operator + (Variable *v){
			if(this->variable == v->getVariable() && this->exponente == v->getExponente()){
				Variable *e = new Variable();

				e->setVariable(this->variable);
				e->setExponente(this->exponente);
				e->setCoeficiente(this->coeficiente + v->getCoeficiente());

				return e;
			} 

			return v;
		}

		void operator += (Variable *v){
			if(this->variable == v->getVariable() && this->exponente == v->getExponente()){
				this->setCoeficiente(this->coeficiente + v->getCoeficiente());
			} 
		}

		Variable * operator - (Variable *v){
			if(this->variable == v->getVariable() && this->exponente == v->getExponente()){
				Variable *e = new Variable();

				e->setVariable(this->variable);
				e->setExponente(this->exponente);
				e->setCoeficiente(this->coeficiente - v->getCoeficiente());

				return e;
			} 

			return v;
		}

		void operator -= (Variable *v){
			if(this->variable == v->getVariable() && this->exponente == v->getExponente()){
				this->setCoeficiente(this->coeficiente - v->getCoeficiente());
			} 
		}

		Variable * operator * (Variable *v){
			if(this->variable == v->getVariable()){
				Variable *e = new Variable();

				e->setVariable(this->variable);
				e->setExponente(this->exponente + v->getExponente());
				e->setCoeficiente(this->coeficiente * v->getCoeficiente());

				return e;
			}

			return v;
		}

		void operator *= (Variable *v){
			if(this->variable == v->getVariable() && this->exponente == v->getExponente()){
				this->setCoeficiente(this->coeficiente * v->getCoeficiente());
				this->setCoeficiente(this->getExponente() + v->getExponente());
			} 
		}

		Variable * operator / (Variable *v){
			if(this->variable == v->getVariable()){
				Variable *e = new Variable();

				e->setVariable(this->variable);
				e->setExponente(this->exponente - v->getExponente());
				e->setCoeficiente(this->coeficiente / v->getCoeficiente());

				return e;
			}

			return v;
		}
		
		void operator /= (Variable *v){
			if(this->variable == v->getVariable() && this->exponente == v->getExponente()){
				this->setCoeficiente(this->coeficiente / v->getCoeficiente());
				this->setCoeficiente(this->getExponente() - v->getExponente());
			} 
		}
		// operadores aridmeticos por valor *,*=,/,/=,^,^=,
		
		Variable * operator * (double v){
			Variable *e = new Variable();

			e->setVariable(this->variable);
			e->setExponente(this->exponente);
			e->setCoeficiente(this->coeficiente * v);

			return e;
		}

		void operator *= (double v){
			this->coeficiente *= v;
		}
	
		Variable * operator / (double v){
			Variable *e = new Variable();

			e->setVariable(this->variable);
			e->setExponente(this->exponente);
			e->setCoeficiente(this->coeficiente / v);

			return e;
		}
	
		void operator /= (double v){
			this->coeficiente /= v;
		}
	
		Variable * operator ^ (double v){
			Variable *e = new Variable();

			e->setVariable(this->variable);
			e->setExponente(this->exponente*v);
			e->setCoeficiente(pow(this->coeficiente,v));

			return e;
		}
	
		void operator ^= (double v){
			this->coeficiente = pow(this->coeficiente,v);
			this->exponente *= v;
		}
	// evaluar   

	double evaluar(double v){
		return (this->coeficiente * pow(v,this->exponente));
	}

	// calculo   
		// derivadas 
	
	Variable * diff(){
		Variable *v = new Variable();  

		v->setVariable(this->getVariable());  
		v->setCoeficiente(this->getExponente()*this->getCoeficiente());
		v->setExponente(this->getExponente()-1);
	}

		// integrales 
	Variable * Int(){
		Variable *v = new Variable();

		v->setCoeficiente(this->getCoeficiente()/(this->getExponente()+1));
		v->setVariable(this->getVariable());
		v->setExponente(this->getExponente()+1);
	}

	double Int(double li,double ls){
		Variable *v = new Variable();

		v->setCoeficiente(this->getCoeficiente()/(this->getExponente()+1));
		v->setVariable(this->getVariable());
		v->setExponente(this->getExponente()+1);

		return ((v->evaluar(ls)) - (v->evaluar(li)));
	}
};

#endif // Variable


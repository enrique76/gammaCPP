#include<iostream>
#include<string>
#include<math.h>
#include<conio.h>
#include "termino.hpp"
#include<vector>

using namespace std;

class ecuacion{
    private:
        vector<termino *> v;
        int OrdenMayor;
    public:
        ecuacion(){

        }

        void add(termino *t){
            termino *n = new termino(t,v.size());

            v.push_back(n);

            SetOrdenMayor();

            n->~termino();
        }

        void Resucir(){
            termino *t;

            for(int i=0;i>v.size();i++){
                if(v[i]->exponente == v[i+1]->exponente){
                    t = new termino();

                    if(v[i+1]->coeficiente > 0){
                        t = v[i]->operator+(v[i+1]);
                    }
                    else if(v[i+1]->coeficiente < 0){
                        t = v[i]->operator-(v[i+1]);
                    }

                    v.push_back(t);
                    //v.erase(i); v.erase(i+1);
                }
            }
        }

        void Ordenar(){
            //Resucir();

            //ecuacion *e = new ecuacion();
            int orden = this->OrdenMayor;


            
        }

        void getOrdenMayor(){
            cout<<this->OrdenMayor;
        }

        void SetOrdenMayor(){
            this->OrdenMayor = v[0]->exponente;
            for(int i=0;i<v.size();i++){
                if(v[i]->exponente > this->OrdenMayor){
                    this->OrdenMayor = v[i]->exponente;
                }
            }
        }

        void Imprimir(){
            for(int i=0;i<v.size();i++){
                v[i]->Imprimir();
            }
        }
};


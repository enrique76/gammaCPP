#ifndef TERMINO
#define TERMINO

#include<iostream>
#include<math.h>
#include<stdio.h>
#include<vector>
#include"variable.hpp"

using namespace std;

class Termino{
    private:
        vector<Variable *> termino;
        double coeficiente;
    public:
        // constructores
        Termino(string t,vector<string> v){

            if(t.find("(") == 0 && t.find(")") ==  t.size()-1){
				t = t.substr(1,t.size()-1);
			}

            int i;
            string aux;
            for(i=0;i<t.size();i++){
                if(isdigit(t[i])){
                    aux+=t[i];
                }
                else{
                    break;
                }
            }
            
            this->coeficiente = stod(aux);
            t = t.substr(i,t.size()-1);

            vector<string> aux2;
            aux.clear();

            for(int j=0;j<t.size();j++){
                for(int z=0;z<v.size();z++){
                    if(string(1,t[i]) == v.at(z)){
                        aux += t[i] + ",";
                        z=v.size();
                    }
                }
            }

            cout<<aux;
        }

        
};

#endif //  TERMINO
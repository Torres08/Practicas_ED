/**
 * @file conjuntodeletras.h
 * @author Torres Ramos, Juan Luis
 * @brief TDA Conjunto de letras
 * @version 0.1
 * @date 2021-12-28
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
#include <string>

#include "../include/conjuntoletras.h"

using namespace std;

    conjuntoletras::conjuntoletras(){

    }
     conjuntoletras::conjuntoletras(set<letra> origen){

    }

    int conjuntoletras::size() const{
        return letras.size();
    }
    void conjuntoletras::Asignar (int indice, char l, int c, int p){
            letra para_aniadir(l,c,p);
            letras.insert(para_aniadir);

          // letras[indice].setCantidad(c);
          // letras[indice].setLetra(l);
          // letras[indice].setPuntuacion(p);
    }

    letra conjuntoletras::getLetra(int indice){
        set<letra>::const_iterator it = letras.begin();
        for (int i =0; i < indice; i++)
            ++it;
        
        return (*it);


    }

istream & operator>>(istream &is, conjuntoletras &C){
    
    string aux;
    letra laux;
    //cout << "\nTELLG: " << is.tellg() << endl;;
    bool b1=false;

    //getline(is, aux);
    
    while (!is.eof() && !b1)
    {
     //cout << "adios";
      char l;
      int n, p;

      // Entrada
      is >> l >> n >> p;
      //cout << endl;
      //cout << l << " " << n << " " << p;

      //Guardamos los valores
      //laux.setCantidad(n);
      //laux.setLetra(l);
      //laux.setPuntuacion(p);
      //cout << l << endl;
      // Añadimos la letra a nuestro conjunto
      C.Asignar(0,l,n,p);
    }
    return is;
    

     
}

int conjuntoletras::calcularPuntuacion(string palabra){
    int puntuacion=0;
    set<letra>::iterator it;
    for(int i=0; i<palabra.length(); i++){
        for(it=letras.begin(); it!=letras.end(); it++){
            if(tolower((*it).getLetra())==palabra[i])
                puntuacion+=(*it).getPuntuacion();
        }
    }
    
    return puntuacion;
}





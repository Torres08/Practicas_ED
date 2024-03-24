/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */


#include <iostream>
#include <cassert>
#include <climits> //INT_MIN, minumun value for an object of type int


#include "../src/pila.cpp"
#include "../include/pila.h"

#include "../include/Cola_max_Pila.h"

ostream& operator<<(ostream &flujo, const Elemento &p) {
    flujo << "[ " << p.valor << " / " << p.max << " ]" << "\n";
    return flujo;
}

cola_max::cola_max(const cola_max &otra) : elementos(otra.elementos) {
}

cola_max& cola_max::operator=(const cola_max& otra) {
    if (&otra != this)
        elementos = otra.elementos;
    return *this;
}

void cola_max::poner(const int &n) {

    int mayor = n > getMaximo() ? n : getMaximo();
    Elemento p;
    p.valor = n;
    p.max = mayor;

    // Tengo una estructura de pila, solo accedo por el frente !!

    //cola_max aux(*this);
    elementos.poner(p);
    
}


Elemento& cola_max::frente() {
    
    
    Pila<Elemento> aux;
    Elemento topa;
    topa = elementos.tope();
    
    // hay que darle la vuelta tanto en frente como quitar
    // viene en el libro, no se por que se me sale, hay segmentation fault
    // igual para quitar, tengo que darle
    // hay problema de segmentation fault nose.
    
    /*
    if (aux.vacia()){
        while (elementos.num_elementos()>0){
            aux.poner(elementos.tope());
            elementos.quitar();
        }
        
       
       // topa=aux.tope();
         
        return aux.tope();
        
         while (!aux.vacia()){
             elementos.poner(aux.tope());
             aux.quitar();
             
         }
        
        
     
    }
    
    */
    return elementos.tope();
 
}

void cola_max::quitar() {
   return elementos.quitar();
}

int cola_max::getMaximo() {
    if (elementos.vacia()) return INT_MIN;
    return frente().max;
}



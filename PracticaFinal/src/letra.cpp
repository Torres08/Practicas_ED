/**
 * @file letras.h
 * @author Torres Ramos, Juan Luis
 *
 * @brief TDA letra
 *
 * @version 0.1
 * @date 2021-12-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/letra.h"
#include <iostream>
using namespace std;


letra::letra(){
    _letra='\0';
    puntuacion=0;
    cantidad=0;
}

letra::letra(char l, int c, int p){
    _letra=l;
    puntuacion=p;
    cantidad=c;
}

int letra::getCantidad() const{
    return cantidad;
}
int letra::getPuntuacion() const{ 
    return puntuacion;
} 

char letra::getLetra() const{
    return _letra;
}

void letra::setCantidad(int _cantidad){
    if(_cantidad>0)
        cantidad=_cantidad;
}

void letra::setPuntuacion(int _puntuacion){
    if(_puntuacion>0)
        puntuacion=_puntuacion;
}

void letra::setLetra(char letra){
    if(letra!='\0')
        _letra=letra;
}

letra & letra::operator=(const letra& l) {
    _letra = l._letra;
    cantidad = l.cantidad;
    puntuacion = l.puntuacion;

    return *this;
}

bool letra::operator<(const letra& l)const {
    bool menor=false;
    if(_letra<l._letra){
        menor=true;
    }
    return menor;
}


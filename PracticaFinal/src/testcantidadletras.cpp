/**
 * @file testcantidadletras.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

// solo leo mi diccionario y devuelvo su fichero letras
//#include "../include/cantidadletras.h"

#include "cantidadletras.cpp"

// no uso letras.txt IMPORTANTE

using namespace std;

int main(int argc, char** argv) {

if (argc!=4){
      cout<<"Sintaxis: <lista_palabras> <letras> <fichero salida>"<<endl;
      return 0;
 }

   ifstream f (argv[1]); //fichero lista_palabras
   ifstream fl (argv[2]); //fichero letras
   ofstream salida;
   salida.open(argv[3]);

    if (!f){
    cout<<"No puedo abrir el fichero  "<<argv[1]<<endl;
    return 0;
   }
   if (!fl){
    cout<<"No puedo abrir el fichero  "<<argv[2]<<endl;
    return 0;
   }

   cantidadletras c;
   Diccionario d;
   f >> d;

   c.Cuenta_Letras(d);

   salida << c;
   
   salida.close();
}
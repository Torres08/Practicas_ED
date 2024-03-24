/**
 * @file Diccionario.cpp
 * @author Torres Ramos, Juan Luis
 *
 * @brief TDA diccionario 
 *
 * @version 0.1
 * @date 2021-12-28
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "../include/diccionario.h"

using namespace std;

int Diccionario::size() const { return datos.size(); }

vector<string> Diccionario::PalabrasLongitud(unsigned Longitud) {
  set<string>::iterator it;
  vector<string> resultado;

  for (it = datos.begin(); it != datos.end(); ++it) {
    if ((*it).length() == Longitud)
      resultado.push_back(*it);
  }

  return resultado;
}

bool Diccionario::Esta(string palabra) {
  return datos.find(palabra) != datos.end();
}


istream & operator>>(istream &is, Diccionario &D ){
    string palabra;

    while( getline(is,palabra) ){
        D.datos.insert(palabra);
    }

    return is;
}


ostream& operator<<(ostream &os, const Diccionario &D ){
    set<string>::iterator it;

    for( it=D.datos.begin(); it != D.datos.end(); ++it ){
        os << (*it) << endl;
    }

    return os;
}
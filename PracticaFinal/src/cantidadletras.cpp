/**
 * @file cantidadletras.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-29
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/cantidadletras.h"
#include <iostream>

cantidadletras::cantidadletras() {
  cantidad_letras = new int[TAM_ABECEDARIO];
  for (int i = 0; i < TAM_ABECEDARIO; ++i)
    cantidad_letras[i] = 0;
}

cantidadletras::~cantidadletras() { delete[] cantidad_letras; }

int cantidadletras::size() const { return TAM_ABECEDARIO; }

int cantidadletras::getCantidadLetras(int indice) const {
  return cantidad_letras[indice];
}

void cantidadletras::Cuenta_Letras(Diccionario &D) {
  Diccionario::iterator it;
  for (it = D.begin(); it != D.end(); ++it) {
    string palabra_actual = *it;
    for (unsigned i = 0; i < palabra_actual.length(); ++i) {
      cantidad_letras[(int)palabra_actual[i] - 'a']++;
      total++;
      if (frec_max < cantidad_letras[i]) {
        frec_max = cantidad_letras[i];
      }
    }
  }
}

int cantidadletras::Puntuacion(int indice) const {
  int puntuacion = 0;
  int rango = frec_max / 10;
  if (cantidad_letras[indice] <=frec_max - 9 * rango) { // los más lejanos a la máxima frecuencia
    puntuacion = 10;
  } else if (cantidad_letras[indice] <= frec_max - 8 * rango) {
    puntuacion = 9;
  } else if (cantidad_letras[indice] <= frec_max - 7 * rango) {
    puntuacion = 8;
  } else if (cantidad_letras[indice] <= frec_max - 6 * rango) {
    puntuacion = 7;
  } else if (cantidad_letras[indice] <= frec_max - 5 * rango) {
    puntuacion = 6;
  } else if (cantidad_letras[indice] <= frec_max - 4 * rango) {
    puntuacion = 5;
  } else if (cantidad_letras[indice] <= frec_max - 3 * rango) {
    puntuacion = 4;
  } else if (cantidad_letras[indice] <= frec_max - 2 * rango) {
    puntuacion = 3;
  } else if (cantidad_letras[indice] <= frec_max - rango) {
    puntuacion = 2;
  } else { // cantidad_letras[indice] <= frec_max , es decir, los más cercanos a
           // la máxima frecuencia
    puntuacion = 1;
  }
  return puntuacion;
}

ostream &operator<<(ostream &os, const cantidadletras &C) {
  // os << "#Letra      Cantidad        Puntos" << endl;
  for (int i = 0; i < C.size(); ++i) {
    os << (char)(i + 'A') << "\t" << C.getCantidadLetras(i) << "\t"
       << C.Puntuacion(i) << endl;
  }
  return os;
}


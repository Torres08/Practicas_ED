/**
 * @file cantidadletras.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-29
 *
 * @copyright Copyright (c) 2021
 *
 */

//#include "diccionario.h"
#include "../src/diccionario.cpp"
using namespace std;

class cantidadletras {
private:
  const int TAM_ABECEDARIO = 26;
  int *cantidad_letras;
  int total = 0;
  int frec_max = 0;

public:
  
  cantidadletras();
 
  ~cantidadletras();
 
  int size() const;
 
  int getCantidadLetras(int indice) const;
  
  void Cuenta_Letras(Diccionario &D);
 
  int Puntuacion(int indice) const;

  friend ostream & operator<<(ostream &os, const cantidadletras &C);

  
};
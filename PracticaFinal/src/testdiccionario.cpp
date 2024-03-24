/**
 * @file Testdiccionario.cpp
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

int main(int argc, char *argv[]) {

  if (argc != 2) {
    cout << "\nERROR Los parametros son" << endl;
    cout << "1.- El fichero con las palabra" << endl;
    return 0;
  }

  fstream f(argv[1]);

  if (!f) {
    cout << "No se encontro el archivo indicado : " << endl;
    return 0;
  }

  Diccionario D;
  cout << "\nCargando el diccionario (" << argv[1] << ") ..." << endl;
  f >> D;
  cout << "¡Leido el diccionario (" << argv[1] << ") con exito!" << endl;
  cout << D << endl;

  unsigned Longitud;
  cout << "Dime la longitud de las palabras que quieres ver: ";
  cin >> Longitud;

  vector<string> v = D.PalabrasLongitud(Longitud);

  cout << "Palabras de longitud (" << Longitud << "): " << endl;

  for (unsigned int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }

  string p;
  cout << "\nDime una palabra: ";
  cin >> p;
  if (D.Esta(p))
    cout << "Si esa palabra existe" << endl;
  else
    cout << "Esa palabra no existe" << endl;
}

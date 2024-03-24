/**
 * @file Diccionario.h
 * @author Torres Ramos, Juan Luis

 * @brief TDA diccionario

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

using namespace std;

class Diccionario {
private:
  // set<string> datos;

public:
  set<string> datos;
  /**
   * @brief Construye diccionario vacio
   *
   */
  Diccionario() : datos(set<string>()){};

  /**
   * @brief Devuelve el numero de palabras de un diccionario
   *
   */
  int size() const;

  /**
   * @brief Obtiene todas las palabras en el diccionario de una longitud dada
   *
   * @param Longitud la longitud de las palabras de salida
   * @return vector<string> vector con las palabras de longitud especifica en el
   * parametro de entrada
   */
  vector<string> PalabrasLongitud(unsigned Longitud);

  /**
   * @brief Indica si una palabra esta en el diccionario
   *
   * @param palabra la palabra a buscar
   * @return true si existe la palabra
   * @return false si no existe la palabra
   */
  bool Esta(string palabra);

  /**
   * @brief Lee un flujo de entrada de un diccionario
   *
   * @param is flujo de entrada
   * @param D el objeto donde se realiza la lectura
   * @return ifstream& el flujo de entrada
   */
  friend istream &operator>>(istream &is, Diccionario &D);
  
  /**
   * @brief Lee un flujo de salida un diccionario
   *
   * @param os flujo de salida
   * @param D el objeto diccionario que se escribe
   * @return ofstream& flujo de salida
   */
  friend ostream &operator<<(ostream &os, const Diccionario &D);

  /**
   * @brief Definicion del iterador del diccionario
   *
   */
  class iterator {
  private:
    set<string>::iterator it;

  public:
    iterator() {}
    string operator*() { return *it; }
    iterator &operator++() {
      ++it;
      return *this;
    }
    iterator &operator--() {
      --it;
      return *this;
    }
    bool operator==(const iterator &i) { return i.it == it; }
    bool operator!=(const iterator &i) { return i.it != it; }
    friend class Diccionario;
  };

  iterator begin() {
    iterator i;
    i.it = datos.begin();
    return i;
  }

  iterator end() {
    iterator i;
    i.it = datos.end();
    return i;
  }
};
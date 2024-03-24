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
//#include "letra.h"
#include "../src/letra.cpp"
#include <set>

using namespace std;

class conjuntoletras {
private:
  set<letra> letras;

public:
  /**
   * @brief Constructor
   *
   */
  conjuntoletras();
  
  conjuntoletras(set<letra> origen);
  
  /**
   * @brief Devuelve el tamaño conjunto letras
   *
   * @return int tamaño
   */
  int size() const;

  /**
   * @brief Asigna los datos a cada letrras
   *
   * @param indice indice de la letra a asignar
   * @param l letra
   * @param c cantidad
   * @param p puntuacion
   */
  void Asignar(int indice, char l, int c, int p);

  /**
   * @brief Asigna los datos a cada letrras
   *
   * @param indice indice de la letra a asignar
   * @param l letra
   * @param c cantidad
   * @param p puntuacion
   */
  void Aniadir(int indice, char l, int c, int p);

  /**
   * @brief Get the Letra object
   *
   * @param indice
   * @return letra
   */
  letra getLetra(int indice);

  int calcularPuntuacion(string palabra);

  /**
   * @brief Sobrecarga del operador de escritura
   *
   * @param is flujo de salida
   * @param C conjunto de letras
   * @return istream& flujo de salida
   */

  


  friend istream &operator>>(istream &is, conjuntoletras &C);
};
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
#include <iostream>
using namespace std;

class letra {
private:
  char _letra;
  int cantidad;
  int puntuacion;

public:
  /**
   * @brief Constructor sin parametros
   *
   */
  letra();
  /**
   * @brief Constructor copia
   *
   */
  letra(char Letra, int cantidad, int puntuación);

  /**
   * @brief Get the Letra object
   *
   * @return char
   */
  char getLetra() const;
  /**
   * @brief Get the Cantidad object
   *
   * @return int
   */
  int getCantidad() const;
  /**
   * @brief Get the Puntuacion object
   *
   * @return int
   */
  int getPuntuacion() const;
  /**
   * @brief Set the Letra object
   *
   * @param letra
   */
  void setLetra(char letra);
  /**
   * @brief Set the Puntuacion object
   *
   * @param _puntuacion
   */
  void setPuntuacion(int _puntuacion);
  /**
   * @brief Set the Cantidad object
   *
   * @param _cantidad
   */
  void setCantidad(int _cantidad);

  /**
   * @brief Operador =
   *
   * @param l
   * @return letra&
   */
  letra &operator=(const letra &l);

  /**
   * @brief Operador <
   * 
   * @param _letra 
   * @return true 
   * @return false 
   */
  bool operator<(const letra& _letra) const;
};
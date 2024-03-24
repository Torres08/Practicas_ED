/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */



#ifndef COLA_MAX_PILA_H
#define COLA_MAX_PILA_H

#include <cassert>
#include <iostream>
#include "pila.h"

using namespace std;

 struct Elemento{
  /**
    * @page repConjunto Representativo del struct Elemento
    */
  int valor = 0;   /**< valor del elemento */
  int max = 0;     /**< valor máximo almacenado en la pila */
  
  }; 
  
   /**
  * @brief Sobrecarga del operador <<
  * @param flujo Flujo de salida
  * @param p @c Elemento que se quiere escribir
  */

  ostream& operator << (ostream &flujo, const Elemento &p);


  /**
   *    @brief TDA de cola_max_pila
   * 
   * Para la implementación de la cola, se ha usado una estructura pila, y hemos
   * situado el frente de la Cola en el tope de la Pila. 

   */

  class cola_max{
  
  private:
     /**
     * @page repConjunto Representativo del TDA PilaMax
     *
     */
  Pila<Elemento> elementos;     /**< Pila con elementos, implementamos una cola basandonos en una pila */

  public:
  // ---------------  Constructores ----------------
    /**
     * @brief Constructor por defecto
     */
    cola_max(): elementos(){};
    
     /**
     * @brief Constructor de copias
     * @param original La cola de la que se hará la copia..
     */
    cola_max(const cola_max &otra);
   
    
    // --------------- Otras funciones ---------------
    /**
     * @brief Operador de asignación
     * @param otra La cola que se va a asignar.
     */
    cola_max& operator= (const cola_max &otra);
    
    /**
     * @brief Comprueba si la cola está vacía
     */
    bool vacia() const{
      return elementos.vacia();
    }
    
    /**
     * @brief Devuelve el elemento del frente de la cola
     */
    
    Elemento& frente ();
    
  

    
     /**
     * @brief Añade un elemento al final de la cola
     * @param elem Elemento que se va a añadir.
     */
    void poner(const int &elem); // problema
    
    /**
     * @brief Quita el elemento del frente de la cola
     */
    
    void quitar(); // problema
    
    /**
     * @brief Devuelve el número de elementos de la cola
     */
    int num_elementos() const{ 
      return elementos.num_elementos(); 
    }
    
    /**
    * @brief Devuelve el valor máximo almacenado en la cola
    */
    
    int getMaximo();
      
      
      
  };


#endif /* COLA_MAX_PILA_H */


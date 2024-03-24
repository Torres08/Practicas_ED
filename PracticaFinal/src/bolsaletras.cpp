/**
 * @file bolsaletras.cpp
 * @author Torres Ramos, Juan Luis
 * @brief TDA Bolsa Letra
 * @version 0.1
 * @date 2021-12-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

 #include "../include/bolsaletras.h"
 
 using namespace std;

 void bolsaletras::creabolsa(conjuntoletras conjunto){
      for (int i = 0; i < 27; i++){
          letra _letra = conjunto.getLetra(i);
          for (int j = 0; j < _letra.getCantidad(); ++j){
              bolsa.push_back(_letra);
          }
      }
 }

 int bolsaletras::size() const{
     return bolsa.size();
 }
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */


#include <cstdlib>
#include "../include/Cola_max_Pila.h"
//#include "pila.cpp"


using namespace std;

/*
 * 
 */
int main() {

   cola_max q;
   //int i ;
   
   // 10 9 8 7 6 5 4 3 2 1 
   //for (int i = 10; i >= 0; i-- )
   //    q.poner(i);
    
   // 12 5 6 20 2 3 0 
   q.poner(2);
   q.poner(7);
   q.poner(6);
   q.poner(9);
   
  
   
   while(!q.vacia()){
       Elemento x = q.frente();
       cout << x << endl;
       q.quitar();
   }
   
   
    return 0;
}


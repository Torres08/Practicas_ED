/**
 * @file letras.cpp
 * @author your name (you@domain.com)
 * @brief Main, mi juego
 * @version 0.1
 * @date 2021-12-29
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <time.h>
#include <vector>

//#include "../include/bolsaletras.h"
//#include "../include/cantidadletras.h"

#include "bolsaletras.cpp"
#include "cantidadletras.cpp"
//#include "conjuntoletras.cpp"
//#include "diccionario.cpp"
//#include "letra.cpp"

using namespace std;

// FUNCIONES


vector<letra> aleatorio(int num, bolsaletras &bolsa) {
  int random;
  vector<letra> l;
  
  cout << "\nCreando bolsa aleatorios" << endl;
 
  for (int i = 0; i < num; i++) {
    random = rand()%bolsa.size() ;
    
    bolsaletras::iterator it = (bolsa.begin()+random);
  
    l.push_back(*it);
    //cout << random << endl;
    //cout  <<  " " << l[i].getLetra() <<  endl;
  }
  return l;
}

void mostraraleatorio(vector<letra> aleatorio) {
  cout << "\nLas letras aleatorias son: " << endl;
  for (unsigned  i = 0; i < aleatorio.size(); i++)
    cout << "  " << aleatorio[i].getLetra();

  cout << " " << endl;
}

bool SolucionCorrecta(Diccionario D,string palabra, vector<letra> LetrasSacadas){
    bool resul=false;
    bool esta;
    bool palabracorrecta=true;
    vector<letra>::iterator itl;
    vector<letra> letraEliminada;
    if(D.Esta(palabra)){
        
        for(int j=0; j<palabra.length(); j++){
            esta=false;
            for(itl=LetrasSacadas.begin(); itl!=LetrasSacadas.end() && !esta; itl++){
                if(palabra[j]==tolower(((*itl).getLetra()))){
                    esta=true;
                    letraEliminada.push_back(*itl);
                    LetrasSacadas.erase(itl);
                }
            }
            if(!esta)
                palabracorrecta=false;
        }
        if(palabracorrecta)
            resul=true;
        else
            resul=false;
        
    }
    else
        resul=false;
     
    
    return resul;
}


vector<string> palabras_puntuacion(Diccionario D,int puntuacionmax,int puntuacionmin,conjuntoletras conj){
    
    vector<string> final;
    
    set<string>::iterator it=D.datos.begin();
    for(it; it!=D.datos.end(); it++){
        if(conj.calcularPuntuacion((*it))<=puntuacionmax && conj.calcularPuntuacion((*it))>puntuacionmin){
            final.push_back((*it));
        }
    }
    return final;
    
}

void CalcularSolucionesL(Diccionario D,vector<letra> aleatoria, int longitudMaxima, int longitudSolucion) {
//void CalcularSolucionesL(Diccionario D, int puntuacionmaxima, int puntuacionsolucion, vector<letra> aleatoria) {
    cout << "Calcular soluciones L" << endl;
    int longitudmaxima = aleatoria.size();
    vector<letra>::iterator itl;
    vector<letra>::iterator ite;
    vector<string>::iterator it;
    bool palabracorrecta=true;
    bool esta=false;
    vector<letra> letraEliminada;
    int contadorSoluciones=0;
    pair<string,int> Mejor;
    
    Mejor.first="Tu solución es la mejor. Enhorabuena!";
    Mejor.second=longitudSolucion;
    
        for(int i=longitudmaxima; i>longitudSolucion && contadorSoluciones<10; i--){
            vector<string> soluciones=D.PalabrasLongitud(i);
            for(it=soluciones.begin(); it!=soluciones.end() && contadorSoluciones<10; it++){
                palabracorrecta=true;
                if(aleatoria.size()<longitudmaxima){
                    //cout << "aleatorio size " << endl;
                    for(ite=letraEliminada.end(); ite!=letraEliminada.begin() && contadorSoluciones<10;ite--){
                        letra le(letraEliminada[letraEliminada.size()-1].getLetra(),0,0); //
                        aleatoria.push_back(le);
                        letraEliminada.pop_back();
                    }
                }
                    for(int j=0; j<(*it).length()&& contadorSoluciones<10; j++){
                        esta=false;
                       for(itl=aleatoria.begin(); itl!=aleatoria.end() && !esta; itl++){
                         // cout << (*it).operator [](j) << " " << tolower(((*itl).getLetra())) << endl;
                           if((*it).operator [](j)==tolower(((*itl).getLetra()))){
                               //cout << "tolower" << endl;
                               esta=true;
                               letraEliminada.push_back(*itl);
                               aleatoria.erase(itl);  
                           }
                       }
                       if(!esta){
                           //cout << "INcorrecto " << endl;
                           palabracorrecta=false;
                       }
                           
                    }
                if(palabracorrecta){
                    cout << (*it) << "  " << "Puntuacion: " << i << endl;
                    if(i>Mejor.second){
                        //cout << "MEJORO" << endl;
                        Mejor.first=(*it);
                        Mejor.second=i;
                    }
                        
                    contadorSoluciones++;
                }            
            }
           
        }
    cout << "Mejor Solucion: " << Mejor.first << endl;  
}

void CalcularSolucionesP(Diccionario D, conjuntoletras l,vector<letra> letrasSacadas, int puntuacionMaxima, int puntuacionSolucion){
    
    int longitudMaxima=letrasSacadas.size();
    vector<letra>::iterator itl;
    vector<letra>::iterator ite;
    vector<string>::iterator it;
    bool palabracorrecta=true;
    bool esta=false;
    vector<letra> letraEliminada;
    int contadorSoluciones=0;
    pair<string,int> Mejor;
    
    Mejor.first="Tu solución es la mejor. Enhorabuena!";
    Mejor.second=puntuacionSolucion;
    
            vector<string> soluciones=palabras_puntuacion(D,puntuacionMaxima,puntuacionSolucion,l);
            
                for(it=soluciones.begin(); it!=soluciones.end() && contadorSoluciones<10; it++){
                    palabracorrecta=true;
                    if(letrasSacadas.size()<longitudMaxima){
                        for(ite=letraEliminada.end(); ite!=letraEliminada.begin() && contadorSoluciones<10;ite--){
                            letrasSacadas.push_back(letraEliminada.back());
                            letraEliminada.pop_back();
                        }
                    }
                        for(int j=0; j<(*it).length()&& contadorSoluciones<10; j++){
                            esta=false;
                           for(itl=letrasSacadas.begin(); itl!=letrasSacadas.end() && !esta; itl++){
                               if((*it).operator [](j)==tolower(((*itl).getLetra()))){
                                   esta=true;
                                   letraEliminada.push_back(*itl);
                                   letrasSacadas.erase(itl);
                               }
                           }
                           if(!esta)
                               palabracorrecta=false;
                        }
                    if(palabracorrecta){
                        cout << (*it) << "  " << "Puntuacion: " <<l.calcularPuntuacion((*it))  << endl;
                        if(l.calcularPuntuacion((*it))>Mejor.second){
                            Mejor.first=(*it);
                            Mejor.second=l.calcularPuntuacion((*it));
                        }

                        contadorSoluciones++;
                    }
                }

    cout << "Mejor Solucion: " << Mejor.first << endl;   
}





// MAIN
int main(int argc, char *argv[]) {

  if (argc != 5) {
    cout << "\nERROR Falta algún argumento" << endl;
    cout << "Argumentos : <fichero_diccionario.txt> <fichero_letras.txt> "
            "<numero_letras_a_general> <modalidad(L o P)>"
         << endl;
    return 0;
  }

  fstream fd(argv[1]);         // diccionario
  fstream fs(argv[2]);         // salida letras
  int nletras = atoi(argv[3]); // numero : 8
  char modo = argv[4][0];      // modo
  string palabra;
  int p1, p2;

 
  if (!fd) {
    cout << "No se encontro el archivo indicado : " << endl;
    return 0;
  }

  Diccionario D;
  cout << "\nCargando el diccionario ..." << endl;
  fd >> D;
  cout << "Leido el diccionario ..." << endl;

  fd.close();

  cantidadletras cantidad;
  cout << "\nCargando la cantidad de letras ..." << endl;

  cantidad.Cuenta_Letras(D);
  //fs << cantidad; 
  
  //cout<< "\nFS TAMAÑO " <<fs.rdbuf()->in_avail() << endl;

  //cout << "\n CANTIDAD SIZE"<< endl;
  //cout << cantidad.size();

  cout << "Leido la cantidad ..." << endl;
  
  

  conjuntoletras conjunto;
  cout << "\nCargando el conjunto de letras ..." << endl;
  fs >> conjunto;
  //cout << conjunto;
  
  cout << "Leido el conjunto ..." << endl;
 

  bolsaletras bolsa;
  cout << "\nCargando la bolsa de letras ..." << endl;
  bolsa.creabolsa(conjunto);

  //cout << "bolsa ejemplo" << bolsa.size();

  cout << "Creada la bolsa ..." << endl;
  bool salir=false;
   
  while(!salir){
    palabra = "";

    vector<letra> LetrasSacadas = aleatorio(nletras, bolsa);
    mostraraleatorio(LetrasSacadas);

    cout << "Introduce tu palabra: ";
    // mientras no este vacia y se encuentre en el diccionario continuo
    cin >> palabra;
    
     if(*argv[4]=='L'){
            
            if(!SolucionCorrecta(D,palabra,LetrasSacadas)){
                cout << "Tu palabra no es válida" << endl;
                cout << "Mis Soluciones son:" << endl;
               
                CalcularSolucionesL(D,LetrasSacadas, nletras,1);
            }
            else{
                cout << palabra << " ";
                cout << "Puntuacion: " << palabra.length() << endl << endl;
                
                cout << "Mis Soluciones son:" << endl;
                CalcularSolucionesL(D,LetrasSacadas, nletras, palabra.length());
            }
            
            
            char palabra;
            cout << "¿Quieres volver a jugar? (s/n) ";
            cin >> palabra;

            if(palabra!='s')
                salir=true;
            else{
                vector<letra>::iterator it;
                for(it=LetrasSacadas.end(); it!=LetrasSacadas.begin();it--)
                    LetrasSacadas.pop_back();
                
            } 
           
        }
        else
            cout << "Parámetro número 4 mal introducido: L/P" << endl;
    }
    
    //return 0;
   

}
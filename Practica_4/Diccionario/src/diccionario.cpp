#include <iostream>
#include <string>
#include <list>
#include "../include/diccionario.h"

using namespace std;

// funciones a implantar nuevas

/*
    1. Borra un elemento por su clave
    2. Hacer la union de diccionarios ( como operator +)
    3. Devolver elementos dentro de un rango de claves
    4. hacer la diferencia de diccionarios (operator-)
*/

/*
    bool Esta_Clave(const T &p, typename  list<data<T,U> >::iterator &it_out)
    void Insertar(const T& clave,const list<U> &info)
    void AddSignificado_Palabra(const U & s ,const T &p)
    list<U>  getInfo_Asoc(const T & p)
    int size()const
*/

// 1. Borra un elemento por su clave
template <class T, class U>
void Diccionario<T,U>::Elimina_Palabra(const T& clave){
    typename list<data<T,U> >::iterator it;

    if(!Esta_Clave(clave, it)){
        cout << "La palabra no esta en el diccionario" << endl;
    }else{
        datos.erase(it);
    }
}

// 3. Devuelve elementos dentro de un rango
template <class T, class U>
void Diccionario<T,U>::filtra_Diccionario(const char letra, const char letra1, const Diccionario<T,U>& D){
    Diccionario<string,string>::const_iterator it;
	
    for (it=D.begin(); it!=D.end(); ++it){
        if( (*it).clave[0] >= letra && (*it).clave[0] <= letra1){ //Compruebe que la primera letra de clave este entre las dos letras
            list<string>::const_iterator it_s;
            cout<<endl<<(*it).clave<<endl<<" informacion asociada:"<<endl;
                        
            for (it_s=(*it).info_asoci.begin();it_s!=(*it).info_asoci.end();++it_s){
                cout<<(*it_s)<<endl;
            }
        cout <<"**************************************"<<endl;
        }   
    }
}

// 2. hacer la SUMA de diccionarios (operator+)
template <class T, class U>
Diccionario<T,U> operator+(const Diccionario<T,U> &D){
    //Diccionario<T,U> aux(*this);
    Diccionario<T,U> aux(D);
		typename list<data<T, U>>::const_iterator it;
		for (it = D.datos.begin(); it != D.datos.end(); ++it)
		{
			aux.Insertar(it->clave, it->info_asoci);
		}
		return aux;
}



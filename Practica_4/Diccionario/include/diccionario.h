#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <string>
#include <list>

using namespace std;


/**
	@brief Struct que contiene la clave y una lista de info asociada 
*/
template <class T,class U>
struct data{
    T clave;
    list<U> info_asoci;
 };

 
/**
	@brief Operator < para el orden en el diccionario
*/
template <class T, class U>
bool operator< (const data<T,U> &d1,const data <T,U>&d2){
	   if (d1.clave<d2.clave)
		     return true;
	   return false;
}	   


/**
 * @brief T.D.A Diccionario
 *
 * Una instancia @e del tipo de dato abstracto @c Diccionario es una lista de
 * struct data , formada por una clave unica y pueden tener asocioda varias definiciones
 * Se comporta como el tipo map.
 * La clase es un template y por tanto se puede usar como clave y definicion el tipo
 * de dato que mejor le convenga
 *
 * Invariante de datos: la palabra no debe contener número
 * Funcion de abstraccion: Una lista de data
 *
 * 
 * @tparam T 
 * @tparam U 
 */

template <class T,class U>
class Diccionario{
	  private:
		    
		  
 		    list<data<T,U> > datos;
		    
			/**
			 * @brief Copia de otro diccionario el objeto implicito
			 * 
			 * @param D, otro diccionario a partir del cual se copia
			 */


		    void Copiar(const Diccionario<T,U>& D){
			   /*typename list<data<T,U> >::const_iterator it_d;
			   typename list<data<T,U> >::iterator it=this->datos.begin();*/
			   
			   datos.assign(D.datos.begin(),D.datos.end());
			   /*for (it_d=D.datos.begin(); it_d!=D.datos.end();++it_d,++it){
				     this->datos.insert(it,*it_d);
				     
			   }*/
		    }
		    /**
		     * @brief Borra los datos de la lista de datos
		     * 
		     */
		    void Borrar(){
			       
			      this->datos.erase(datos.begin(),datos.end());
		    }	      
			   
			       
	  public:
	    
		/**
		 * @brief Constructor por defecto de la clase
		 * @return objeto con una lista vacia
		 */
		 Diccionario():datos(list<data<T,U> >()){}
		 
		 
		 /**
		  * @brief Constructor de copia de la clase
		  * 
		  * @param D Otro Diccionario
		  * @return Un objeto con los mismos datos que el otro diccionario
		  */
		 Diccionario(const Diccionario &D){
			   Copiar(D);
		 }
		 
		 
		 /**
		  * @brief Destruye el objeto diccionario
		  * 
		  */
		 ~Diccionario(){}
		 
		 /**
		  * @brief OPeracion de asignacion
		  * 
		  * @param D Otro Diccionario
		  * @return Un objeto que es copia del parametro dado
		  */
		 Diccionario<T,U> & operator=(const Diccionario<T,U> &D){
			   if (this!=&D){
				     Borrar();
				     Copiar(D);
			   }
			   return *this;
		 }
		

		/**
		 * @brief Busca una clave dentro del diccionario
		 * 
		 * @param p la clave referencia a buscar
		 * @param it_out Iterador. Si esta la clave se apunta a ella, si no, a donde deberia ir
		 * @return true si esta la clave
		 * @return false si no esta la clave
		 */

		bool Esta_Clave(const T &p, typename  list<data<T,U> >::iterator &it_out){
			  
			  if (datos.size()>0){
				    
			      typename list<data<T,U> >::iterator it;
			      
			      for (it=datos.begin(); it!=datos.end() ;++it){
					if ((*it).clave==p) {
						  it_out=it;
						  return true;
					}
					else if ((*it).clave>p){
						  it_out=it;
						  return false;
					}	  
					   
			      }
			      
			      it_out=it;
			      return false;
			  }
			  else {	
				    it_out=datos.end();
				    return false;
			  }	    
		 }
		
		/**
		  * @brief Inserta un nuevo registro en el diccionario
		  * 
		  * @param clave la clave que se usa
		  * @param info Lista con las definiciones de la clave
		  */
		 void Insertar(const T& clave,const list<U> &info){
			   
		     typename list<data<T,U> >::iterator it;
		     
		     if (!Esta_Clave(clave,it)){
			       data<T,U> p;
			       p.clave = clave;
			       p.info_asoci=info;
			 
			       datos.insert(it,p);
			      	 
		     }
		     
		 }
		 
		 /**
		  * @brief Añade una nueva info asociada a una clave que esta en el diccionario
		  * 
		  * @param s clave a usar
		  * @param p el significado a agregar la clave
		  */
		 void AddSignificado_Palabra(const U & s ,const T &p){
			   typename list<data<T,U> >::iterator it;
			   
			   if (!Esta_Clave(p,it)){
				    datos.insert(it,p);
			   }	    
			   
			    //Insertamos el siginificado al final
		           (*it).info_asoci.insert((*it).info_asoci.end(),s);
		 }
		 
		  /**
		   * @brief Se busca la info relativa asociada a una clave
		   * 
		   * @param p la clave a buscar info
		   * @return list<U> una lista con la info de la clave asociada
		   */

		  list<U>  getInfo_Asoc(const T & p) {
			   typename list<data<T,U> >::iterator it;
			   
			   if (!Esta_Clave(p,it)){
				return list<U>();
			   }
			   else{
				return (*it).info_asoci;
			   }
		 }			   
				

		/**
		 * @brief Devuelve el numero de claves/elementos en la lista
		 * 
		 * @return El tamaño de la lista
		 */
		 int size()const{
			   return datos.size();
		 }

		// /*Funciones begin y end asociadas al diccionario*/
		// list<data<string,string> >::iterator &begin(){
		// 	return datos.begin();
		// }

		// list<data<string,string> >::iterator &end(){
		// 	return datos.end();
		// }
		 
		// list<data<string,string> >::const_iterator &begin()const{
		// 	return datos.begin();
		// }

		// list<data<string,string> >::const_iterator &end()const {
		// 	return datos.end();
		// }

		// Nuevas funciones

		/**
		 * @brief Invierte el orden del diccionario A-Z -> Z-A
		 * 
		 */
		void invierte_Diccionario();

		/**
		 * @brief Devuelve las palabras entre un rango dado
		 * 
		 * @param letra extremo del rango
		 * @param letra1 otro extremo
		 * @param D objeto diccionario
		 */
		void filtra_Diccionario(const char letra, const char letra1, const Diccionario<T,U>& D);

		/* Elimina una palabra de diccionario incluyendo todos sus significados */
		/**
		 * @brief Elimina una palabra del diccionario incluyendo todos sus significados
		 * 
		 * @param clave palabra a borrar del
		 */

		void Elimina_Palabra(const T& clave);

		/**
		 * @brief Diferencia de guias de diccionarios
		 * 
		 * @param D diccionario a restar
		 * @return Diccionario<T,U>  nueva guia resultado
		 */
		Diccionario<T,U> operator-(const Diccionario<T,U> &D);


		// Añade la clase iteradora y su cte correspondiente

		/**
		* @brief Clase Iteradora, Iterador para el uso externo
		* 
		*/


		class Iterator{
			private:
				typename std::list<data<T,U>>::iterator it;

			public:
				Iterator(): it(0){}
				~Iterator(){}

				Iterator& operator++(){
					it++;
					return *this;
				}

				Iterator& operator--(){
					it--;
					return *this;
				}

				data<T,U>&operator*()const{
					return *it;
				}

				bool operator != (const Iterator& i) const{
					return(it != i.it);
				}

				bool operator == (const Iterator& i) const{
					return(it == i.it);
				}

				friend class Diccionario;

				
		};


		class const_iterator{
					private:
						typename list<data<T,U> >::const_iterator it;
					public:
						const_iterator(){}

						bool operator==(const const_iterator &i){
							return i.it == it;
						}

						bool operator!=(const const_iterator &i){
							return i.it != it;
						}

						const data<T,U> & operator*() const{
							return *it;
						}

						const_iterator & operator++(){
							it++;
							return *this;
						}
						friend class Diccionario;
		};

		Iterator begin(){
			Iterator i;
			i.it = datos.begin();
			return i;
		}

		Iterator end(){
			Iterator i;
			i.it = datos.end();
			return i;
		}

		const_iterator begin() const{
			const_iterator i;
			i.it = datos.begin();
			return i;
		}

		const_iterator end() const{
			const_iterator i;
			i.it = datos.end();
			return i;
		}

		
		
};


#endif
	 
	  

	  

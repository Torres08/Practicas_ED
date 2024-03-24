/**
 * @file imagen.h
 * @brief Fichero cabecera para la manipulación de imágenes.
 *
 * Permite la manipulación de archivos de tipo PGM.
 */

#ifndef IMAGEN
#define IMAGEN

#include <cstring>
#include <fstream>
#include <string>

using namespace std;


typedef unsigned char byte;
enum TipoImagen{IMG_DESCONOCIDO, IMG_PGM};

class Imagen
{
	private:

	::byte** datos;
	int filas, columnas;


	public:

	/**
	 * @brief Constructor por defecto de la clase imagen
	 * @post Imagen vacía, sin filas ni columnas
	 */

	Imagen();


	/**
	 * @brief Constructor de imagen con filas filas y columnas columnas
	 *
	 * @param fils Número de filas de la imagen
	 * @param cols Número de columnas de la imagen
	 * @pre filas > 0 && columnas > 0
	 * @post Imagen con valores basura, sin inicializar
	 */

	Imagen(int fils, int cols);
	

	/**
	 * @brief Constructor de copia de la clase imagen
	 *
	 * @param otra Imagen que se quiere copiar
	 * @post La imagen será identica a otra
	 */

	Imagen(const Imagen & otra);


	/**
	 * @brief Destructor de la clase Imagen
	 * @post Imagen inutilizable salvo que sea "reinicializada"
	 */

	~Imagen();


	/**
	 * @brief Operador = de la clase imagen, que copia los datos de otra
	 * 
	 * @param otra Imagen que se quiere copiar
	 * @return Referencia a un objeto Imagen
	 */

	Imagen & operator =(const Imagen & otra);


	/**
	 * @brief Devuelve el número de filas de la imagen
	 * @return Número de filas de la imagen
	 */

	int NumFilas() const;


	/**
	 * @brief Devuelve el número de columnas de la imagen
	 * @return Número de columnas de la imagen
	 */

	int NumColumnas() const;


	/**
	 * @brief Lee una imagen PGM
	 * 
	 * @param nombre Nombre del archivo de entrada
	 */

	void LeerImagenPGM(const string nombre);


	/**
	 * @brief Guarda una imagen en formato PGM
	 * 
	 * @param nombre Nombre del archivo de salida
	 */

	void EscribirImagenPGM(const string nombre);


	/**
	 * @brief Consulta el valor de un píxel de la imagen
	 *
	 * @param fil Índice de la fila del píxel cuyo valor se quiere consultar
	 * @param col índice de la columna del píxel cuyo valor se quiere consultar
	 * @pre 0 <= fil < NumFilas() && 0 <= col < NumColumnas()
	 * @return Valor de luminosidad del píxel especificado
	 */

	::byte GetValor(int fil, int col) const;


	/**
	 * @brief Modifica el valor de un píxel de la imagen
	 *
	 * @param fil Índice de la fila del píxel cuyo valor se quiere modificar
	 * @param col Índice de la columna del píxel cuyo valor se quiere modificar
	 * @pre 0 <= fil < NumFilas() && 0 <= col < NumColumnas()
	 * && 0 <= valor <= 255
	 */

	void SetValor(int fil, int col, ::byte valor);


	/**
	 * @brief Inserta una fila de píxeles vacíos en la posición indicada
	 * 
	 * @param pos Índice en el que se insertará la fila de píxeles
	 */

	void InsertarFila(int pos);


	/**
	 * @brief Inserta una columna de píxeles vacíos en la posición indicada
	 * 
	 * @param pos Índice en el que se insertará la columna de píxeles
	 */

	void InsertarColumna(int pos);


	/**
	 * @brief Llena la imagen de píxeles de la luminosidad indicada
	 * 
	 * @param valor Valor con el que se rellenará la imagen
	 */

	void Ecualizar(int valor);


	/**
	 * @brief Llena una fila de píxeles con el valor indicado
	 * 
	 * @param fil Índice de la fila a llenar
	 * @param valor Valor con el que se rellena la fila
	 */

	void EcualizarFila(int fil, int valor);


	/**
	 * @brief Llena una columna de píxeles con el valor indicado
	 * 
	 * @param fil Índice de la columna a llenar
	 * @param valor Valor con el que se rellena la columna
	 */

	void EcualizarColumna(int col, int valor);


	/**
	 * @brief Extrae una subimagen PGM de otra imagen PGM
	 *
	 * @param otra Imagen de la que extraer la subimagen
	 * @param fil Índice de la fila a partir de la cual se creará la subimagen
	 * resultante
	 * @param col Índice de la columna a partir de la cual se creará la
	 * subimagen resultante
	 * @param fils_sub Tamaño vertical de la imagen resultado
	 * @param cols_sub Tamaño horizontal de la imagen resultado
	 * @pre (fil + filas_sub) < fich_orig.NumFilas()
	 * && (col + filas_col) < fich_orig.NumColumnas()
	 * @post El contenido de la imagen se ve reescrito por el de la subimagen
	 * indicada de otra.
	 */

	void ExtraerSubimagen(const Imagen& otra, const int fil, const int col,
						  const int fils_sub, const int cols_sub);


	/**
	 * @brief Hace zoom a una imagen, esto es:
	 * - Extrae de ella una subimagen.
	 * - Aplica a la subimagen una interpolacion consistente en añadir filas (y
	 * columnas) en las que el valor de cada píxel será una media de los valores
	 * de los píxeles que tenga arriba y abajo (a izquierda y derecha,
	 * respectivamente)
	 * 
	 * @param fich_orig Nombre del fichero que contiene la imagen original
	 * @param fich_rdo Nombre del fichero que contendrá el resultado
	 * @param fil Fila a partir de la cual se creará la subimagen resultante
	 * @param col Columna a partir de la cual se creará la subimagen resultante
	 * @param fils_sub Tamaño vertical de la imagen resultado
	 * @param cols_sub Tamaño horizontal de la imagen resultado
	 * @pre (fil + filas_sub) < fich_orig.NumFilas()
	 * && (col + filas_col) < fich_orig.NumColumnas()
	 */

	void HacerZoom(const Imagen& otra, const int fil, const int col,
				   const int fils_sub, const int cols_sub);


	/**
	 * @brief Aplica a la subimagen una interpolacion consistente en añadir
	 * filas (y columnas) en las que el valor de cada píxel será una media de
	 * los valores de los píxeles que tenga arriba y abajo (a izquierda y
	 * derecha, respectivamente)
	 */

	void Interpolar();


	/**
	 * @brief Aumenta el contraste de una imagen mediante un estiramiento de su
	 * histograma
	 *
	 * @param fich_orig Nombre del fichero que contiene la imagen original
	 * @param fich_rdo Nombre del fichero que contendrá el resultado
	 * @param e1 Coordenada x del primer punto que transforma la gráfica de la 
	 * @param e2
	 * @param s1
	 * @param s2
	 * @return Si la operación ha tenido éxito
	 */

	void AumentarContraste(const int e1, const int e2, const int s1,
						   const int s2);


	private:

	/**
	 * @brief Reserva memoria para un dato de tipo Imagen
	 * 
	 * @param fils Filas a reservar
	 * @param cols Columnas a reservar
	 */
	
	void ReservarMemoria(int fils, int cols);


	/**
	 * @brief Libera la memoria ocupada por un objeto de tipo Imagen
	 */
	void LiberarMemoria();


	/**
	 * @brief Copia los datos de otra imagen
	 * 
	 * @param otra Imagen de la que se quieren copiar los datos
	 */

	void CopiarDatos(const Imagen otra);


	/**
	 * @brief Devuelve el tipo de imagen del archivo
	 *
	 * @param f Flujo a usar.
	 * @return Devuelve el tipo de la imagen en el archivo
	 *
	 * @see TipoImagen
	**/

	TipoImagen LeerTipoImagen(ifstream& f);


	/**
	 * @brief Devuelve el tipo de imagen del archivo
	 * 
	 * @param nombre 
	 * @return Devuelve el tipo de la imagen en el archivo
	 *
	 * @see TipoImagen
	 */

	TipoImagen LeerTipoImagen(const char* nombre);


	/**
	 * @brief Permite saltar los separadores de un archivo PGM para leer
	 * seguidamente la imagen
	 * 
	 * @param f Flujo a usar para leer los separadores
	 * @return char
	 */

	char SaltarSeparadores(ifstream& f);


	/**
	 * @brief Lee la cabecera de un archivo PGM, que contiene entre otras cosas
	 * las dimensiones de la imagen
	 *
	 * @param f Flujo usado para leer la cabecera
	 */

	bool LeerCabecera(ifstream& f, int& fils, int& cols);
};


#endif

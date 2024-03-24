#include <iostream>
#include <cstring>
#include <string>
#include "imagen.h"

using namespace std;


/**
 * @brief Prueba la función HacerZoom()
 * 
 * @param fich_orig Nombre del fichero del que obtener la imagen
 * @param fich_rdo Nombre del fichero que contendrá el resultado
 * @param fil Índice de la fila a partir de la cual se creará la subimagen
 * resultante
 * @param col Índice de la columna a partir de la cual se creará la
 * subimagen resultante
 * @param fils_sub Tamaño vertical de la imagen resultado
 * @param cols_sub Tamaño horizontal de la imagen resultado
 * @pre (fil + filas_sub) < fich_orig.NumFilas()
 * && (col + filas_col) < fich_orig.NumColumnas()
 */

int main(int argc, char* argv[])
{
	if (argc != 7)
	{
		cout << endl;
		cout << "ERROR: Argumentos necesarios <fich_orig> <fich_rdo> <fil> "
			 << "<col> <fils_sub> <cols_sub>";
		cout << endl << endl;

		return 0;
	}

	string fich_orig = argv[1],
		   fich_rdo = argv[2];

	int fil = atoi(argv[2]),
		col = atoi(argv[3]),
		fils_sub = atoi(argv[4]),
		cols_sub = atoi(argv[5]);

	Imagen orig;
	orig.LeerImagenPGM(fich_orig);

	Imagen sub;
	sub.HacerZoom(orig, fil, col, fils_sub, cols_sub);
	sub.EscribirImagenPGM(fich_rdo);
}
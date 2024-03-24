#include <iostream>
#include <cstring>
#include <string>
#include "imagen.h"

using namespace std;


/**
 * @brief Prueba la función ExtraerSubimagen()
 * 
 * @param fich_orig Nombre del fichero del que obtener la imagen
 * @param fich_rdo Nombre del fichero que contendrá el resultado
 * @param e1 Primer umbral usado para la transformación (x)
 * @param e2 Segundo umbral usado para la transformación (x)
 * @param s1 Primer umbral usado para la transformación (T(x))
 * @param s2 Segundo umbral usado para la transformación (T(x))
 */

int main(int argc, char* argv[])
{
	if (argc != 7)
	{
		cout << endl;
		cout << "ERROR: Argumentos necesarios <fich_orig> <fich_rdo> <e1> "
			 << "<e2> <s1> <s2>";
		cout << endl << endl;

		return 0;
	}

	string fich_orig = argv[1],
		   fich_rdo = argv[2];

	int e1 = atoi(argv[2]),
		e2 = atoi(argv[3]),
		s1 = atoi(argv[4]),
		s2 = atoi(argv[5]);

	Imagen orig;
	orig.LeerImagenPGM(fich_orig);

	Imagen sub(orig);
	sub.AumentarContraste(e1, e2, s1, s2);
	sub.EscribirImagenPGM(fich_rdo);
}
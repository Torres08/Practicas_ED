/**
 * @file imagen.cpp
 * @brief Fichero con definiciones para la manipulación de imágenes.
 *
 * Permite la manipulación de archivos de tipo PGM.
 */

#include <cstring>
#include <fstream>
#include <string>
#include <cmath>
#include "imagen.h"

using namespace std;


//-----------------------------------------------------------------------------

Imagen::Imagen(): filas(0), columnas(0), datos(nullptr){}


//-----------------------------------------------------------------------------

Imagen::Imagen(int fils, int cols): datos(nullptr)
{
	ReservarMemoria(fils, cols);
}


//-----------------------------------------------------------------------------

Imagen::Imagen(const Imagen & otra)
{
	ReservarMemoria(otra.filas, otra.columnas);
	CopiarDatos(otra);
}


//-----------------------------------------------------------------------------

Imagen::~Imagen()
{
	LiberarMemoria();
}


//-----------------------------------------------------------------------------

Imagen & Imagen::operator =(const Imagen & otra)
{
	if (this != &otra)
	{
		LiberarMemoria();

		if (otra.filas > 0 && otra.columnas > 0)
		{
			ReservarMemoria(otra.filas, otra.columnas);
			CopiarDatos(otra);
		}
	}

	return (*this);
}


//-----------------------------------------------------------------------------

int Imagen::NumFilas() const
{
	return filas;
}


//-----------------------------------------------------------------------------

int Imagen::NumColumnas() const
{
	return columnas;
}


//-----------------------------------------------------------------------------

void Imagen::LeerImagenPGM(const string nombre)
{
	ifstream f(nombre);

	if (LeerTipoImagen(f) == IMG_PGM)
	{
		int fils, cols;

		if (LeerCabecera(f, fils, cols))
		{
			ReservarMemoria(fils, cols);

			for (int i = 0; i < filas; i++)
			{
				f.read(reinterpret_cast<char*>(datos[i]), columnas);
			}

			if (!f)
			{
				LiberarMemoria();
			}
		
		}
	}
}


//-----------------------------------------------------------------------------

void Imagen::EscribirImagenPGM(const string nombre)
{
	ofstream f(nombre);

	if (f)
	{
		f << "P5" << endl;
		f << columnas << " " << filas << endl;
		f << 255 << endl;

		for (int i = 0; i < filas; i++)
		{
			f.write(reinterpret_cast<const char*>(datos[i]), columnas);
		}
	}
}


//-----------------------------------------------------------------------------

::byte Imagen::GetValor(int fil, int col) const
{
	return datos[fil][col];
}


//-----------------------------------------------------------------------------

void Imagen::SetValor(int fil, int col, ::byte valor)
{
	datos[fil][col] = valor;
}


//-----------------------------------------------------------------------------

void Imagen::InsertarFila(int pos)
{
	::byte** nuevos_datos = new ::byte*[filas + 1];

	for (int i = 0; i < pos; i++)
	{
		nuevos_datos[i] = datos[i];
	}

	nuevos_datos[pos] = new ::byte[columnas];

	for (int i = pos; i < filas; i++)
	{
		nuevos_datos[i + 1] = datos[i];
	}

	delete [] datos;

	datos = nuevos_datos;

	filas++;

	EcualizarFila(pos, 0);
}


//-----------------------------------------------------------------------------

void Imagen::InsertarColumna(int pos)
{
	::byte** nuevos_datos = new ::byte*[filas];

	for (int i = 0; i < filas; i++)
	{
		::byte* nueva_fila = new ::byte[columnas + 1];

		for (int j = 0; j < pos; j++)
		{
			nueva_fila[j] = datos[i][j];
		}

		for (int j = pos; j < columnas; j++)
		{
			nueva_fila[j + 1] = datos[i][j];
		}

		delete [] datos[i];

		datos[i] = nueva_fila;
	}

	columnas++;

	EcualizarColumna(pos, 0);
}


//-----------------------------------------------------------------------------

void Imagen::Ecualizar(int valor)
{
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			datos[i][j] = valor;
		}
	}
}


//-----------------------------------------------------------------------------

void Imagen::EcualizarFila(int fil, int valor)
{
	for (int i = 0; i < columnas ; i++)
	{
		datos[fil][i] = valor;
	}
}


//-----------------------------------------------------------------------------

void Imagen::EcualizarColumna(int col, int valor)
{
	for (int i = 0; i < filas; i++)
	{
		datos[i][col] = valor;
	}
}


//-----------------------------------------------------------------------------

void Imagen::ExtraerSubimagen(const Imagen& otra, const int fil, const int col,
					 		  const int fils_sub, const int cols_sub)
{
	LiberarMemoria();

	ReservarMemoria(fils_sub, cols_sub);
	
	for (int i = 0; i < fils_sub; i++)
	{
		for (int j = 0; j < cols_sub; j++)
		{
			SetValor(i, j, otra.GetValor(i + fil, j + col));
		}
	}
}


//-----------------------------------------------------------------------------

void Imagen::HacerZoom(const Imagen& otra, const int fil, const int col,
					   const int fils_sub, const int cols_sub)
{
	ExtraerSubimagen(otra, fil, col, fils_sub, cols_sub);
	Interpolar();
}


//-----------------------------------------------------------------------------

void Imagen::Interpolar()
{
	for (int i = 1; i < filas; i += 2)
	{
		InsertarFila(i);

		for (int j = 0; j < columnas; j++)
		{
			int media = (datos[i - 1][j]+ datos[i + 1][j]) / 2;
			datos[i][j] = media;
		}
	}

	for (int j = 1; j < columnas; j += 2)
	{
		InsertarColumna(j);

		for (int i = 0; i < filas; i++)
		{
			int media = (datos[i][j - 1] + datos[i][j + 1]) / 2;
			datos[i][j] = media;
		}
	}
}


//-----------------------------------------------------------------------------

void Imagen::AumentarContraste(const int e1, const int e2, const int s1,
							   const int s2)
{
	const double c1 = (double) s1/e1,
				 c2 = (double) (s2 - s1)/(e2 - e1),
				 c3 = (double) (255 - s2)/(255 - e2);

	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			if (datos[i][j] < (e1 - 1))
			{
				datos[i][j] = round((c1 * datos[i][j]));
			}

			if (e1 <= datos[i][j] && datos[i][j] <= e2)
			{
				datos[i][j] = round(s1 + (c2 * (datos[i][j] - e1)));
			}

			if ((e2 - 1) < datos[i][j])
			{
				datos[i][j] = round(s2 + (c3 * (datos[i][j] - e2)));
			}
		}
	}
}


//-----------------------------------------------------------------------------

void Imagen::ReservarMemoria(int fils, int cols)
{
	if (fils > 0 && cols > 0)
	{
		datos = new ::byte*[fils];

		for (int i = 0; i < fils; i++)
		{
			datos[i] = new ::byte[cols];
		}

		filas = fils;
		columnas = cols;

		Ecualizar(0);
	}

	else
	{
		datos = nullptr;
		filas = 0;
		columnas = 0;
	}
}


//-----------------------------------------------------------------------------

void Imagen::LiberarMemoria()
{
	if (datos)
	{
		for (int i = 0; i < filas; i++)
		{
			delete [] datos[i];
		}

		delete [] datos;

		datos = nullptr;
		filas = 0;
		columnas = 0;
	}
}


//-----------------------------------------------------------------------------

void Imagen::CopiarDatos(Imagen otra)
{
	filas = otra.filas;
	columnas = otra.columnas;

	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			datos[i][j] = otra.datos[i][j];
			//memcpy(datos[i], otra.datos[i], columnas*sizeof(byte));
		}
	}
}


//-----------------------------------------------------------------------------

TipoImagen Imagen::LeerTipoImagen(ifstream& f)
{
	char c1, c2;
	TipoImagen tipo = IMG_DESCONOCIDO;

	if (f)
	{
		c1 = f.get();
		c2 = f.get();

		if (f && c1 == 'P')
		{
			if (c2 == '5')
			{
				tipo = IMG_PGM;
			}

			else
			{
				tipo = IMG_DESCONOCIDO;
			}
		}
	}

	return tipo;
}


//-----------------------------------------------------------------------------

TipoImagen Imagen::LeerTipoImagen(const char* nombre)
{
	ifstream f(nombre);
	return LeerTipoImagen(f);
}


//-----------------------------------------------------------------------------

char Imagen::SaltarSeparadores(ifstream& f)
{
	char c;

	do
	{
		c = f.get();
	} while (isspace(c));

	f.putback(c);

	return c;
}


//-----------------------------------------------------------------------------

bool Imagen::LeerCabecera(ifstream& f, int& fils, int& cols)
{
	int maxvalor;
	string linea;

	while (SaltarSeparadores(f) == '#')
	{
		getline(f, linea);
	}

	f >> cols >> fils >> maxvalor;

	if (f && fils > 0 && fils < 5000 && cols > 0 && cols < 5000)
	{
		f.get();
		
		return true;
	}

	else
	{
		return false;
	}
}


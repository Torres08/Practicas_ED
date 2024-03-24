#include "../include/guiatlf.h"
#include <cctype>
#include <fstream>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Dime el nombre del fichero con la guia" << endl;
    return 0;
  }
  ifstream f(argv[1]);
  if (!f) {
    cout << "No puedo abrir el fichero " << argv[1] << endl;
    return 0;
  }

  Guia_Tlf g;

  f >> g;
  cout << "La guia insertada " << g << endl;
  cin.clear();

  cin.ignore();
  system("clear");

  int opcion;
  cout << "\n             MENU           \n\n- 1. Visualizar la guia"
          "\n- 2. Obtener información sobre una persona\n- 3. Inserccion de un contacto en mi guia"
          "\n- 4. Devuelve telefonos cuyos nombres asociados estan en un rango\n- 5. Devuelve los telefonos de aquellos que empiecen por una letra"
           "determinada\n- 6. Modifica un telefono\n"
       << endl;

  cin >> opcion;
  cin.ignore();
  Guia_Tlf::iterator it;
  Guia_Tlf::iterator it2;
  string n;
  string tlf = g.gettelefono(n);
  char filtro1, filtro2;
  Guia_Tlf aux;
  char letra;
  string nombre,num_nuevo;

  while (opcion != 7) {
    switch (opcion) {
    case 1:
      cout <<"**************************************"<<endl;
      cout << "\nListando la guia con iteradores:\n" << endl;
      for (it = g.begin(); it != g.end(); ++it)
        cout << *it << endl;

      cout <<"**************************************"<<endl;
      cin.ignore();
      system("clear");

      break;
    case 2:
      cout <<"**************************************"<<endl;
      cout << "\nDime un nombre sobre el que quieres obtener el telefono" << endl;
      
      getline(cin, n);
        cout << "Buscando " << n << "...." << endl;
        if (tlf == "") {
          cout << "No existe ese nombre en la guia" << endl;
        } else
          cout << "El telefono es " << tlf << endl;
       
      break;

    case 3:
         cout <<"**************************************"<<endl;  
        cout << "\nNombre del contacto: ";
				getline(cin, n);
				cout << "Introduce un numero de telefono: ";
				getline(cin, tlf);
				g.insert(n, tlf);

				cin.clear();
				break;
          
      break;
    case 4:
          cout <<"**************************************"<<endl;
          cout << "Introduzca entre que letras quiere hacer el filtro: ";
          cin >> filtro1 >> filtro2;
          filtro1 = toupper(filtro1);
          filtro2 = toupper(filtro2);
          aux = g.NumerosEntreRango(filtro1, filtro2);

          cout << "\nListando la guia : \n" << endl;
          for (it2 = aux.begin(); it2 != aux.end(); ++it2)
            cout << *it2 << endl;

          cout <<"**************************************"<<endl;
          cin.ignore();
          system("clear");

      break;
    
    case 5:
        cout <<"**************************************"<<endl;
        cout << "\nIntroduce una letra para buscar sus numeros: ";
        cin >> letra;
        aux = g.NumerosEmpiezan(letra);

        cout << "\nListando la guia : \n" << endl;
        for (it2 = aux.begin(); it2 != aux.end(); ++it2)
          cout << *it2 << endl;

        cout <<"**************************************"<<endl;
      break;

      case 6:
          cout <<"**************************************"<<endl;
          cout << "\nIntroduce un nombre y un numero de telefono nuevo: ";
          cout << "\nsi no esta el nombre se introduce\n";

          cout << "\nNombre del contacto: ";
				  getline(cin, nombre);
          cout << "Introduce un numero de telefono: ";
			   	getline(cin, num_nuevo);

          g.ModificaNum(nombre, num_nuevo); 

      break;

    default:
      cout << "Error al introducir la opcion\n" << endl;
    }

    cout << "\n             MENU           \n\n- 1. Visualizar la guia"
          "\n- 2. Obtener información sobre una persona\n- 3. Inserccion de un contacto en mi guia"
          "\n- 4. Devuelve telefonos cuyos nombres asociados estan en un rango\n- 5. Devuelve los telefonos de aquellos que empiecen por una letra"
           "determinada\n- 6. Salir\n"
       << endl;
    cin >> opcion;
    cin.ignore();
    system("clear");
  }
}

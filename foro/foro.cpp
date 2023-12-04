// Actividad 7 Foro de trabajo
// Alumno: García López Omar

/*
Construir un programa que admita cadenas y permita al usuario seleccionar si desea ver la cadena en mayúsculas o minúsculas.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

int main() {
    string cadena;
    int opcion;

    do {
        cout << "Ingresa una cadena: ";
        getline(cin, cadena);   // lee la cadena incluidos los espacios
        cout << "Selecciona una opcion: \n\t1. Mostrar en Mayusculas \n\t2. Mostrar en minusculas \n\t3. Salir" << endl;
        cin >> opcion;
        // Limpia el buffer después de leer un número
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (opcion) {
        case 1:
            // Utilizamos la funcion transform de la libreria algorithm para convertir la cadena a mayúsculas
            transform(cadena.begin(), cadena.end(), cadena.begin(), ::toupper);
            cout << "\n" << cadena << endl;
            break;
        case 2:
            // Utilizamos la funcion transform de la libreria algorithm para convertir la cadena a minúsculas
            transform(cadena.begin(), cadena.end(), cadena.begin(), ::tolower);
            cout << "\n" << cadena << endl;
            break;
        case 3:
            cout << "\nHasta luego!" << endl;
            break;
        default:
            cout << "\nOpción no valida" << endl;
            break;
        }
    } while (opcion != 3);       
    
    return 0;
}

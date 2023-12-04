// Actividad 7 Foro de trabajo
// Alumno: Garc�a L�pez Omar

/*
Construir un programa que admita cadenas y permita al usuario seleccionar si desea ver la cadena en may�sculas o min�sculas.
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
        // Limpia el buffer despu�s de leer un n�mero
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (opcion) {
        case 1:
            // Utilizamos la funcion transform de la libreria algorithm para convertir la cadena a may�sculas
            transform(cadena.begin(), cadena.end(), cadena.begin(), ::toupper);
            cout << "\n" << cadena << endl;
            break;
        case 2:
            // Utilizamos la funcion transform de la libreria algorithm para convertir la cadena a min�sculas
            transform(cadena.begin(), cadena.end(), cadena.begin(), ::tolower);
            cout << "\n" << cadena << endl;
            break;
        case 3:
            cout << "\nHasta luego!" << endl;
            break;
        default:
            cout << "\nOpci�n no valida" << endl;
            break;
        }
    } while (opcion != 3);       
    
    return 0;
}

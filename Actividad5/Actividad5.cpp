// Actividad 5
// Ejercicio 4
// Alumno: Garc�a L�pez Omar

/* 
Realizar un programa que permita guardar en un struct los datos relacionados a un estudiante, los datos de inter�s son:
-Matricula
-Nombre
-Carrera
-Promedio
-Direcci�n
Se debe de realizar las siguientes funciones:
a) Captura de los datos
b) Mostrar los datos
c) La funci�n main que llame de la forma correcta a las funciones captura y mostrar.
*/

#include <iostream>
#include <string>

using namespace std;

// Definici�n de la estructura Estudiante
struct Estudiante {
    string matricula;
    string nombre;
    string carrera;
    float promedio;
    string direccion;
};

// a) Funci�n para capturar los datos del estudiante
void capturarDatos(Estudiante& estudiante) {
    cout << "Ejercicio 4: Permitir guardar en un struct los datos\n";
    cout << "relacionados a un estudiante\n";
    cout << " \n";
        cout << "Ingrese la matricula: ";
    getline(cin, estudiante.matricula);
    cout << "Ingrese el nombre: ";
    getline(cin, estudiante.nombre);
    cout << "Ingrese la carrera: ";
    getline(cin, estudiante.carrera);
    cout << "Ingrese el promedio: ";
    cin >> estudiante.promedio;
    cin.ignore();  // Ignorar el salto de l�nea restante en el buffer
    cout << "Ingrese la direccion: ";
    getline(cin, estudiante.direccion);
}

// b) Funci�n para mostrar los datos del estudiante
void mostrarDatos(const Estudiante& estudiante) {
    cout << "\nDatos del Estudiante:\n";
    cout << "Matricula: " << estudiante.matricula << endl;
    cout << "Nombre: " << estudiante.nombre << endl;
    cout << "Carrera: " << estudiante.carrera << endl;
    cout << "Promedio: " << estudiante.promedio << endl;
    cout << "Direccion: " << estudiante.direccion << endl;
}

// c) Funci�n main
int main() {
    Estudiante estudiante;

    capturarDatos(estudiante);
    mostrarDatos(estudiante);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Presiona la tecla Enter para salir...";
    cin.get();
    return 0;
}

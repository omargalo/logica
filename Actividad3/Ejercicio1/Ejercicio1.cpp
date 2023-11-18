// Alumno: García López Omar
// Ejercicio 1: Escriba un programa que lea un número entero
// y determine si es par o impar.

#include <iostream>
using namespace std;

int main(){
    int numeroIngresado;
    char continuar;

    do{
        cout << "Ingresa un numero: ";
        cin >> numeroIngresado;
        if(numeroIngresado % 2 == 0){
            cout << "El numero que ingresaste es par." << endl;
        }else{
            cout << "El numero que ingresaste es impar." << endl;
        }
        cout << "¿Quieres intentar con otro numero? [y/n]: ";
        cin >> continuar;
    }while(continuar == 'y' || continuar == 'Y');
    return 0;
}

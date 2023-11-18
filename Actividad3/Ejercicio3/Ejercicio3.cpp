// Alumno: García López Omar
// Crea un programa que lea un numero entero y 
// determine si es un numero primo o no.
// Un numero primo es aquel que es solo divisible entre 1 y el mismo.

#include <iostream>

using namespace std;

int main(){
    int numeroIngresado;
    bool esNumeroPrimo;
    char continuar;
    do{
        cout << "Ingresa un numero: ";
        cin >> numeroIngresado;
        esNumeroPrimo = true;
        for(int i = 2; i < numeroIngresado; i++){
            if(numeroIngresado % i == 0){
                esNumeroPrimo = false;
                break;
            }
        }
        if(esNumeroPrimo){
            cout << "El numero que ingresaste es primo." << endl;
        }else{
            cout << "El numero que ingresaste no es primo." << endl;
        }
        cout << "¿Quieres intentar con otro numero? [y/n]: ";
        cin >> continuar;
    }while(continuar == 'y' || continuar == 'Y');
    return 0;
}

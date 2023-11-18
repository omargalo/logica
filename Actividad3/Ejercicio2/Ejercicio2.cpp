// Alumno: García López Omar
// Ejercicio 2: Escriba un programa que muestre un mensaje acorde
// a la calificación ingresada.

#include <iostream>
using namespace std;

int main(){
    float calificacion;
    char continuar;
    do{
        cout << "Ingresa una calificacion: ";
        cin >> calificacion;
        if(calificacion < 0 || calificacion > 10){
            cout << "Hubo un error." << endl;
        }else if(calificacion == 10){
            cout << "Excelente." << endl;
        }else if(calificacion == 9){
            cout << "Muy bien." << endl;
        }else if(calificacion == 8){
            cout << "Bien." << endl;
        }else if(calificacion == 7){
            cout << "Regular." << endl;
        }else if(calificacion >= 0 && calificacion <= 6){
            cout << "No acreditado." << endl;
        }
        cout << "¿Quieres intentar con otra calificacion? [y/n]: ";
        cin >> continuar;
    }while(continuar == 'y' || continuar == 'Y');
    return 0;
}

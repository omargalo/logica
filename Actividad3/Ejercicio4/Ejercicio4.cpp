// Alumno: García López Omar
// Ejercicio 4: Dado n artículos pedir para cada uno de ellos
// la cantidad y el precio y calcular el total a pagar.

#include <iostream>
using namespace std;

int main(){

    int numeroArticulos;
    float precioArticulo, totalArticulo, totalCompra;
    char reiniciar;

    do{
        numeroArticulos, precioArticulo, totalArticulo, totalCompra = 0;
        cout << "¿Cuantos articulos vas a comprar?: ";
        cin >> numeroArticulos;
        for(int i = 0; i < numeroArticulos; i++){
            cout << "Ingresa la cantidad del articulo " << i + 1 << ": ";
            cin >> totalArticulo;
            cout << "Ingresa el precio unitario del articulo " << i + 1 << ": ";
            cin >> precioArticulo;
            totalCompra += precioArticulo * totalArticulo;
        }
        cout << "El total de su compra es: $" << totalCompra << endl;
        cout << "¿Quieres realizar una nueva compra? [y/n]: ";
        cin >> reiniciar;
    }while(reiniciar == 'y' || reiniciar == 'Y');
    cout << "¡Gracias por comprar con nosotros!" << endl;
    return 0;
}

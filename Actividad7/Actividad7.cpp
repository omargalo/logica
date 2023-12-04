// Actividad7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
construir un programa que
admita cadenas y permita al usuario seleccionar si desea ver la
cadena en mayúsculas o minúsculas
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
int main()
{
    string str;
    int option;
    cout << "Escriba una cadena: ";
    getline(cin, str);
    cout << "Elija una opcion: " << endl;
    cout << "1. Convertir a mayusculas" << endl;
    cout << "2. Convertir a minusculas" << endl;
    cin >> option;
    switch (option) {
    case 1:
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        cout << str << endl;
        break;
    case 2:
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        cout << str << endl;
        break;
    default:
        cout << "Opcion no valida" << endl;
    }
}


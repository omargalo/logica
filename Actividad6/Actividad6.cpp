// Actividad 6: Proyecto Integrador Etapa 2
// Equipo: 17 García López Omar

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib> 

using namespace std;

class Album {
public:
    string artista;
    string nombreAlbum;
    int aLanzamiento;

    Album(string artista, string nombreAlbum, int aLanzamiento) {
        this->artista = artista;
        this->nombreAlbum = nombreAlbum;
        this->aLanzamiento = aLanzamiento;
    }

    void mostrarInformacion() {
        cout << "Artista: " << artista << endl;
        cout << "Nombre del Album: " << nombreAlbum << endl;
        cout << "Lanzamiento: " << aLanzamiento << endl;
    }
};

class CatalogoMusica {
private:
    vector<Album> catalogo;

    string leerLinea() {
        string linea;
        getline(cin, linea);
        return linea;
    }

public:
    void agregarAlbum() {
        string artista, nombreAlbum;
        int aLanzamiento;
        cout << "Ingresa nombre del artista: ";
        artista = leerLinea();
        cout << "Ingresa nombre del album: ";
        nombreAlbum = leerLinea();
        cout << "Ingresa fecha de lanzamiento: ";
        cin >> aLanzamiento;
        cin.ignore(10000, '\n');
        Album nuevoAlbum(artista, nombreAlbum, aLanzamiento);
        catalogo.push_back(nuevoAlbum);
        cout << "Album agregado exitosamente." << endl;
    }

    void eliminarAlbum() {
        string nombreAlbum;
        cout << "Ingresa nombre del album a eliminar: ";
        getline(cin, nombreAlbum);

        auto it = find_if(catalogo.begin(), catalogo.end(), [&](const Album& album) {
            return album.nombreAlbum == nombreAlbum;
            });

        if (it != catalogo.end()) {
            cout << "Album encontrado:\n";
            it->mostrarInformacion();

            string confirmacion;
            cout << "\nRealmente deseas eliminar este album? (si/no): ";
            getline(cin, confirmacion);

            if (confirmacion == "si") {
                catalogo.erase(it);
                cout << "Album eliminado exitosamente.\n";
            }
            else {
                cout << "Eliminación cancelada.\n";
            }
        }
        else {
            cout << "Album no encontrado.\n";
        }

        cout << "Presione Enter para continuar...";
        cin.get(); // Espera un Enter para continuar
    }

    void modificarAlbum() {
        string artista, nombreAlbum;
        cout << "Ingresa nombre del artista a modificar: ";
        artista = leerLinea();
        cout << "Ingresa nombre del album a modificar: ";
        nombreAlbum = leerLinea();

        for (auto& album : catalogo) {
            if (album.artista == artista && album.nombreAlbum == nombreAlbum) {
                cout << "Ingresa nuevo nombre del artista: ";
                album.artista = leerLinea();
                cout << "Ingresa nuevo nombre del album: ";
                album.nombreAlbum = leerLinea();
                cout << "Ingresa nueva fecha de lanzamiento: ";
                cin >> album.aLanzamiento;
                cin.ignore();
                cout << "Album modificado exitosamente." << endl;
                return;
            }
        }
        cout << "Album no encontrado." << endl;
    }

    void buscarAlbum() {
        string busqueda;
        cout << "Ingresa nombre del artista o album a buscar: ";
        busqueda = leerLinea();

        bool encontrado = false;
        for (auto& album : catalogo) {
            if (album.artista == busqueda || album.nombreAlbum == busqueda) {
                album.mostrarInformacion();
                encontrado = true;
            }
        }

        if (!encontrado) {
            cout << "Album no encontrado." << endl;
        }
    }
};

void limpiarPantalla() {
#ifdef _WIN32
    system("cls"); // Para Windows
#else
    system("clear"); // Para Unix/Linux
#endif
}

int main() {

    CatalogoMusica catalogo;
    int opcion;

    do {
        cout << "\nCatalogo Musical\n";
        cout << "\n----------------\n";
        cout << "\nMenu Principal:\n";
        cout << "\n----------------\n";
        cout << "1. Agregar album\n";
        cout << "2. Eliminar album\n";
        cout << "3. Modificar album\n";
        cout << "4. Buscar album\n";
        cout << "5. Salir\n";
        cout << "\n";
        cout << "Elige una opcion: ";
        cin >> opcion;
        if (cin) {
            cin.ignore(10000, '\n');
        }
        else {
			cin.clear();
			cin.ignore(10000, '\n');
			opcion = 0;
		}

        switch (opcion) {
        case 1:
            catalogo.agregarAlbum();
            break;
        case 2:
            catalogo.eliminarAlbum();
            break;
        case 3:
            catalogo.modificarAlbum();
            break;
        case 4:
            catalogo.buscarAlbum();
            break;
        case 5:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }

        if (opcion != 5) {
            cout << "\nPresione Enter para continuar...";
            cin.get();
            limpiarPantalla();
        }

    } while (opcion != 5);

    return 0;
}

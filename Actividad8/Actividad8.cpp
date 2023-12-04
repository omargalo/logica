// Actividad 8: Proyecto Integrador Etapa 3
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

    void mostrarInformacion() const {
        cout << "Detalles del album encontrado:\n ";
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
            cout << "Album encontrado, sus datos son:\n";
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
    }

    void modificarAlbum() {
        string nombreAlbum;
        cout << "Ingresa nombre del album a modificar: ";
        nombreAlbum = leerLinea();

        auto it = find_if(catalogo.begin(), catalogo.end(), [&](const Album& album) {
            return album.nombreAlbum == nombreAlbum;
            });

        if (it != catalogo.end()) {
            it->mostrarInformacion();
            cout << "\nEstas seguro de modificar el album?\n1 para Si\n2 para No\n";
            cout << "Ingresa tu opcion: ";
            int confirmacion;
            cin >> confirmacion;
            cin.ignore();

            if (confirmacion == 1) {
                string artista, nombre;
                int lanzamiento;
                cout << "Ingresa nuevo nombre del artista: ";
                getline(cin, artista);
                cout << "Ingresa nuevo nombre del album: ";
                getline(cin, nombre);
                cout << "Ingresa nueva fecha de lanzamiento: ";
                cin >> lanzamiento;
                cin.ignore();

                // Actualizar el album
                it->artista = artista;
                it->nombreAlbum = nombre;
                it->aLanzamiento = lanzamiento;

                cout << "Album modificado exitosamente.\n";
            }
            else {
                cout << "Modificación Cancelada.\n";
            }
        }
        else {
            cout << "Album no encontrado.\n";
        }
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

    const vector<Album>& obtenerCatalogo() const {
        return catalogo;
    }
};

void mostrarTodos(const vector<Album>& catalogo) {
    if (catalogo.empty()) {
        cout << "El catalogo esta vacio." << endl;
        return;
    }

    for (const auto& album : catalogo) {
        album.mostrarInformacion();
        cout << endl;
    }
}

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
        cout << "3. Mostrar todos los albumes\n";
        cout << "4. Modificar album\n";
        cout << "5. Buscar album\n";
        cout << "6. Salir\n";
        cout << "\nElige una opcion: ";
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
            mostrarTodos(catalogo.obtenerCatalogo());
            break;
        case 4:
            catalogo.modificarAlbum();
            break;
        case 5:
            catalogo.buscarAlbum();
            break;
        case 6:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }

        if (opcion != 6) {
            cout << "\nPresione Enter para regresar al Menu principal...";
            cin.get();
            limpiarPantalla();
        }

    } while (opcion != 6);

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
        cout << "Ingresa año de lanzamiento: ";
        cin >> aLanzamiento;
        cin.ignore(10000, '\n'); 
        Album nuevoAlbum(artista, nombreAlbum, aLanzamiento);
        catalogo.push_back(nuevoAlbum);
        cout << "Album agregado exitosamente." << endl;
    }

    void eliminarAlbum() {
        string artista, nombreAlbum;
        cout << "Ingresa nombre del artista a eliminar: ";
        artista = leerLinea();
        cout << "Ingresa nombre del album a eliminar: ";
        nombreAlbum = leerLinea();

        auto it = remove_if(catalogo.begin(), catalogo.end(), [&](Album const& album) {
            return album.artista == artista && album.nombreAlbum == nombreAlbum;
            });

        if (it != catalogo.end()) {
            catalogo.erase(it, catalogo.end());
            cout << "Album eliminado exitosamente." << endl;
        }
        else {
            cout << "Album no encontrado." << endl;
        }
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

int main() {

    CatalogoMusica catalogo;
    int opcion;

    do {
        cout << "\nCatalogo Musical\n";
        cout << "\n----------------\n";
        cout << "\nMenu Principal\n";
        cout << "\n----------------\n";
        cout << "1. Agregar album\n";
        cout << "2. Eliminar album\n";
        cout << "3. Modificar album\n";
        cout << "4. Buscar album\n";
        cout << "5. Salir\n";
        cout << "\n";
        cout << "Elige una opcion: ";
        cin >> opcion;
        cin.ignore(10000, '\n');

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
    } while (opcion != 5);

    return 0;
}

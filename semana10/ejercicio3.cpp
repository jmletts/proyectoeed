#include <iostream>

using namespace std;

struct garage {
    int ubicacion;
    garage *sig;
};

garage *pila = NULL;

void espacios();
void agregarPila(garage *&pila, int ubicacion);
int GarageLLeno(garage *pila);
void liberarMemoria(garage *&pila);

int main() {
    int opcion, espaciosReservar;

    cout << "¿Cuántos espacios de garaje desea reservar? ";
    cin >> espaciosReservar;

    espacios(); 

    do {
        cout << "----- Menú -----" << endl;
        cout << "1. Añadir carro" << endl;
        cout << "2. Verificar si hay espacios disponibles" << endl;
        cout << "3. Salir" << endl;
        cout << "Elija una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                espacios(); 
                break;
            case 2:
                if (GarageLLeno(pila) < espaciosReservar) {
                    cout << "Hay espacios disponibles en el garaje." << endl;
                } else {
                    cout << "El garaje está lleno." << endl;
                }
                break;
            case 3:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }

        cout << endl;
    } while (opcion != 3);

    liberarMemoria(pila);
    return 0;
}

void espacios() {
    int n, ubicacion;
    cout << "¿Cuántos vehículos desea añadir? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Ingrese la ubicación del vehículo " << (i + 1) << ": ";
        cin >> ubicacion;
        agregarPila(pila, ubicacion); 
    }
}

void agregarPila(garage *&pila, int ubicacion) {
    garage *nuevo = new garage();
    nuevo->ubicacion = ubicacion;
    nuevo->sig = pila;
    pila = nuevo;
}

int GarageLLeno(garage *pila) {
    garage *aux = pila;
    int cont = 0;

    while (aux != NULL) {
        cont++;
        aux = aux->sig;
    }
    return cont; 
}

void liberarMemoria(garage *&pila) {
    garage *aux;
    while (pila != NULL) {
        aux = pila;
        pila = pila->sig;
        delete aux;
    }
}

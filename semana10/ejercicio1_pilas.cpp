#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo {
    int dato;
    nodo *sig;
};

// Prototipos de las funciones
void agregarpila(nodo *&, int);
void sacarpila(nodo *&, int &);
void mostrarPila(nodo *);
bool buscarElemento(nodo *, int);
void eliminarElemento(nodo *&, int);
void eliminarTodaLaPila(nodo *&);
void contarParesImpares(nodo *, int &, int &);

// Función principal
int main() {
    setlocale(LC_CTYPE, "Spanish");
    int opcion, dato, cant, pares = 0, impares = 0;
    nodo *pila = NULL;

    do {
        cout << "------------------------\n";
        cout << "MENU DE PILAS\n";
        cout << "------------------------\n";
        cout << "1. Ingresar elementos a la pila\n";
        cout << "2. Mostrar elementos de la pila\n";
        cout << "3. Buscar elemento en la pila\n";
        cout << "4. Eliminar elemento de la pila\n";
        cout << "5. Eliminar toda la lista\n";
        cout << "6. Cantidad de pares e impares de elementos de la pila\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese cantidad de nodos: ";
                cin >> cant;
                for (int i = 1; i <= cant; i++) {
                    cout << "Digite numero: ";
                    cin >> dato;
                    agregarpila(pila, dato);
                }
                break;

            case 2:
                cout << "Elementos de la pila: ";
                mostrarPila(pila);
                cout << endl;
                break;

            case 3:
                cout << "Ingrese el elemento a buscar: ";
                cin >> dato;
                if (buscarElemento(pila, dato)) {
                    cout << "El elemento " << dato << " se encuentra en la pila.\n";
                } else {
                    cout << "El elemento " << dato << " NO se encuentra en la pila.\n";
                }
                break;

            case 4:
                cout << "Ingrese el elemento a eliminar: ";
                cin >> dato;
                eliminarElemento(pila, dato);
                break;

            case 5:
                eliminarTodaLaPila(pila);
                cout << "La pila ha sido eliminada.\n";
                break;

            case 6:
                contarParesImpares(pila, pares, impares);
                cout << "Cantidad de pares: " << pares << "\n";
                cout << "Cantidad de impares: " << impares << "\n";
                break;

            case 7:
                cout << "Saliendo del programa.\n";
                break;

            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }

        cout << endl;

    } while (opcion != 7);

    return 0;
}

void agregarpila(nodo *&pila, int n) {
    nodo *nuevonodo = new nodo(); // Crear el espacio de memoria para almacenar el nodo
    nuevonodo->dato = n;          // Cargar el valor dentro del nodo
    nuevonodo->sig = pila;        // Pasar la pila al siguiente nodo
    pila = nuevonodo;             // Asignar pila al nuevo nodo
    cout << "\nEl elemento " << n << " se agregó correctamente \n\n";
}

void sacarpila(nodo *&pila, int &n) {
    nodo *aux = pila;             // Crear variable auxiliar que señalará la cima de la pila
    n = aux->dato;                // Igualar n a la variable auxiliar
    pila = aux->sig;              // Pila debe de pasar al siguiente nodo
    delete aux;                   // Eliminar el nodo
}

void mostrarPila(nodo *pila) {
    if (pila == NULL) {
        cout << "La pila está vacía.";
        return;
    }
    while (pila != NULL) {
        cout << pila->dato << " ";
        pila = pila->sig;
    }
}

bool buscarElemento(nodo *pila, int n) {
    while (pila != NULL) {
        if (pila->dato == n) {
            return true;
        }
        pila = pila->sig;
    }
    return false;
}

void eliminarElemento(nodo *&pila, int n) {
    nodo *actual = pila;
    nodo *anterior = NULL;

    while (actual != NULL) {
        if (actual->dato == n) {
            if (anterior == NULL) {
                pila = actual->sig; // Eliminar el primer nodo
            } else {
                anterior->sig = actual->sig; // Eliminar nodo intermedio o final
            }
            delete actual;
            cout << "Elemento " << n << " eliminado.\n";
            return;
        }
        anterior = actual;
        actual = actual->sig;
    }
    cout << "Elemento " << n << " no encontrado en la pila.\n";
}

void eliminarTodaLaPila(nodo *&pila) {
    while (pila != NULL) {
        int dato;
        sacarpila(pila, dato);
    }
}

void contarParesImpares(nodo *pila, int &pares, int &impares) {
    pares = 0;
    impares = 0;
    while (pila != NULL) {
        if (pila->dato % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
        pila = pila->sig;
    }
}

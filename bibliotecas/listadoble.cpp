#include <iostream>

using namespace std;

struct nodo {
    int dato;
    nodo *sig;
    nodo *ant;
};

void insertarElementosI(nodo *&inicio, int n);
void insertarElementosF(nodo *&inicio, int n);
void mostrarI(nodo *inicio);
void mostrarF(nodo *inicio);
void eliminarElemento(nodo *&inicio, int n);

int main() {
    nodo *inicio = NULL;
    int opcion, n;

    do {
        cout << "\n--- Menú de Opciones ---\n";
        cout << "1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Mostrar desde el inicio\n";
        cout << "4. Mostrar desde el final\n";
        cout << "5. Eliminar un elemento\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un número para insertar al inicio: ";
                cin >> n;
                insertarElementosI(inicio, n);
                break;
            case 2:
                cout << "Ingrese un número para insertar al final: ";
                cin >> n;
                insertarElementosF(inicio, n);
                break;
            case 3:
                cout << "Mostrando lista desde el inicio:\n";
                mostrarI(inicio);
                break;
            case 4:
                cout << "Mostrando lista desde el final:\n";
                mostrarF(inicio);
                break;
            case 5:
                cout << "Ingrese el elemento que desea eliminar: ";
                cin >> n;
                eliminarElemento(inicio, n);
                break;
            case 6:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
        }
    } while (opcion != 6);

    return 0;
}

void insertarElementosI(nodo *&inicio, int n) {
    nodo *nuevo = new nodo();
    nuevo->dato = n;
    nuevo->sig = inicio;
    nuevo->ant = NULL;

    if (inicio != NULL) {
        inicio->ant = nuevo;
    }

    inicio = nuevo;
}

void insertarElementosF(nodo *&inicio, int n) {
    nodo *nuevo = new nodo();
    nodo *aux = inicio;
    nuevo->dato = n;
    nuevo->sig = NULL;

    if (inicio == NULL) {
        nuevo->ant = NULL;
        inicio = nuevo;
        return;
    }

    while (aux->sig != NULL) {
        aux = aux->sig;
    }

    aux->sig = nuevo;
    nuevo->ant = aux;
}

void mostrarI(nodo *inicio) {
    nodo *aux = inicio;

    while (aux != NULL) {
        cout << aux->dato << " ";
        aux = aux->sig;
    }
    cout << endl;
}

void mostrarF(nodo *inicio) {
    if (inicio == NULL) return;

    nodo *aux = inicio;
    while (aux->sig != NULL) {
        aux = aux->sig;
    }

    while (aux != NULL) {
        cout << aux->dato << " ";
        aux = aux->ant;
    }
    cout << endl;
}

void eliminarElemento(nodo *&inicio, int n) {
    nodo *aux = inicio;

    while (aux != NULL && aux->dato != n) {
        aux = aux->sig;
    }

    if (aux == NULL) {
        cout << "Elemento no encontrado.\n";
        return;
    }

    if (aux->ant != NULL) {
        aux->ant->sig = aux->sig;
    } else {
        inicio = aux->sig;
    }

    if (aux->sig != NULL) {
        aux->sig->ant = aux->ant;
    }

    delete aux;
    cout << "Elemento eliminado.\n";
}
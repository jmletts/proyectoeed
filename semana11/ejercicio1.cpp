#include <iostream>

using namespace std;

struct nodo {
    int dato;
    nodo *sig;
};

nodo *frente = NULL;
nodo *fin = NULL;

void menu();
void insertarElemento(nodo *&frente, nodo *&fin, int n);
bool cola_vacia(nodo *frente);
void eliminarElemento(nodo *&frente, nodo *&fin, int &n);
void mostrarCola(nodo *frente);
void buscarElemento(nodo *frente, int n);
void eliminarCola(nodo *&frente, nodo *&fin);

int main(int argc, char const *argv[]) {
    menu();
    return 0;
}

void menu() {
    int op, dato;
    do {
        cout << "\n1. Ingresar elementos" << endl;
        cout << "2. Eliminar elementos" << endl;
        cout << "3. Buscar elementos" << endl;
        cout << "4. Mostrar elementos" << endl;
        cout << "5. Eliminar cola" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingresa una opcion: ";
        cin >> op;

        switch (op) {
            case 1:
                cout << "Ingresar dato: ";
                cin >> dato;
                insertarElemento(frente, fin, dato);
                break;
            
            case 2:
                if (!cola_vacia(frente)) {
                    eliminarElemento(frente, fin, dato);
                    cout << "Elemento eliminado: " << dato << endl;
                } else {
                    cout << "La cola está vacía" << endl;
                }
                break;

            case 3:
                cout << "Ingresar dato a buscar: ";
                cin >> dato;
                buscarElemento(frente, dato);
                break;

            case 4:
                mostrarCola(frente);
                break;

            case 5:
                eliminarCola(frente, fin);
                cout << "Cola eliminada" << endl;
                break;

            default:
                break;
        }
    } while (op != 6);
}

void insertarElemento(nodo *&frente, nodo *&fin, int n) {
    nodo *nuevo = new nodo();
    nuevo->dato = n;
    nuevo->sig = NULL;

    if (cola_vacia(frente)) {
        frente = nuevo;
    } else {
        fin->sig = nuevo;
    }
    fin = nuevo;  // Actualizar el puntero fin
}

bool cola_vacia(nodo *frente) {
    return (frente == NULL);
}

void eliminarElemento(nodo *&frente, nodo *&fin, int &n) {
    n = frente->dato;
    nodo *aux = frente;
    
    if (frente == fin) {
        frente = NULL;
        fin = NULL;
    } else {
        frente = frente->sig;
    }
    delete aux;
}

void mostrarCola(nodo *frente) {
    nodo *aux = frente;

    if (!cola_vacia(frente)) {
        cout << "Elementos en la cola: ";
        while (aux != NULL) {
            cout << aux->dato << " ";
            aux = aux->sig;
        }
        cout << endl;
    } else {
        cout << "La cola está vacía." << endl;
    }
}

void buscarElemento(nodo *frente, int n) {
    nodo *aux = frente;
    bool band = false;
    while (aux != NULL) {
        if (aux->dato == n) {
            band = true;
            break;
        }
        aux = aux->sig;
    }

    if (band) {
        cout << "\nElemento encontrado: " << n << endl;
    } else {
        cout << "\nElemento NO encontrado: " << n << endl;
    }
}

void eliminarCola(nodo *&frente, nodo *&fin) {
    int aux;
    while (frente != NULL) {
        eliminarElemento(frente, fin, aux);
    }
}

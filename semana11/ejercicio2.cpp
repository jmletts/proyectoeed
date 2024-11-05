#include <iostream>
#include <iomanip>

using namespace std;

struct cliente {
    string Nombre;
    string Direccion;
    string nombJuego;
    int dias;
    double montoT;
    cliente *sig;
};

struct cola {
    cliente *inicio = nullptr;
    cliente *fin = nullptr;

    void ingresarCliente();
    void mostrarClientes();
};

int main(int argc, char const *argv[]) {
    cola cola1;
    int op;
    
    do {
        cout << "\n\tMenu\n";
        cout << "1. Ingresar Cliente" << endl;
        cout << "2. Mostrar Clientes" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> op;

        switch (op) {
            case 1:
                cola1.ingresarCliente();
                break;
            case 2:
                cola1.mostrarClientes();
                break;
        }
    } while (op != 3);

    return 0;
}

void cola::ingresarCliente() {
    cliente *nuevo = new cliente();
    
    cout << endl << "Ingresa el nombre del cliente: ";
    cin >> nuevo->Nombre;
    cout << "Ingresa la direccion del cliente: ";
    cin >> nuevo->Direccion;
    cout << "Ingresa el nombre del juego: ";
    cin >> nuevo->nombJuego;
    cout << "Ingresa el numero de dias: ";
    cin >> nuevo->dias;
    nuevo->montoT = 10 * nuevo->dias;
    nuevo->sig = nullptr;

    if (inicio == nullptr) {
        inicio = nuevo;
    } else {
        fin->sig = nuevo;
    }
    fin = nuevo;
}

void cola::mostrarClientes() {
    if (inicio == nullptr) {
        cout << "La cola está vacía." << endl;
        return;
    }

    cout << setw(10) << "Nombre"
         << setw(11) << "Direccion"
         << setw(12) << "Juego"
         << setw(11) << "Dias"
         << setw(12) << "Monto Total" << endl;

    cliente *aux = inicio;
    while (aux != nullptr) {
        cout << setw(10) << aux->Nombre
             << setw(11) << aux->Direccion
             << setw(12) << aux->nombJuego
             << setw(11) << aux->dias
             << setw(12) << aux->montoT << endl;
        aux = aux->sig;
    }
}

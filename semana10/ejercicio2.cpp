#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo {
    int dato;
    nodo *sig;
};

nodo *pila = NULL;

// Prototipos de las funciones
void IngresarElementos(nodo *&, int);
void mostrarPila(nodo *);
bool buscarElemento(nodo *, int);
void eliminarElemento(nodo *&, int);
void eliminarTodaLaPila(nodo *&);
void contarParesImpares(nodo *, int &, int &);

int main(int argc, char const *argv[])
{
    int op, cant, n;
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
        cin >> op;

        switch (op) {
            case 1:
                cout << "Ingrese cantidad de nodos: ";
                cin >> cant;
                for (int i = 1; i <= cant; i++) {
                    cout << "Ingrese un elemento: ";
                    cin >> n;
                    IngresarElementos(pila, n);
                }
                break;

            case 2:
                cout << "Elementos de la pila: ";
                mostrarPila(pila);
                cout << endl;
                break;

            case 3:
                cout << "Ingrese el elemento a buscar: ";
                cin >> n;
                buscarElemento(pila, n);

       }
       }
    return 0;
}

void IngresarElementos(nodo *&pila, int n) {
    nodo *aux = NULL;
    aux = new(nodo);
    aux->dato = n;

    if (pila == NULL)
    {
        cout << "Pila Vacia";
    } else{
        aux->sig = pila;
        
    }
    pila = aux;
    cout << "Elemento agregado.";


}

void mostrarPila(nodo *pila){

    nodo *aux = pila;

    if (pila == NULL)
    {
       cout << "Pila Vacia";
    } else {
        while (aux != NULL)     
        {
           cout << aux->dato << endl;
           aux = aux->sig;
        }
        

    }
}

bool buscarElemento(nodo *pila, int n){
    nodo *actual = new nodo();
    actual = pila;
    bool band = false;

    while (actual != NULL)  
    {
        if (actual->dato == n)
        {
            band = true;
        } 
        actual = actual->sig;
    }

    if (band == true)
    {
        cout << "Elemento"<<n<< " encontrado";
    } else {

          cout << "Elemento"<<n<< " NO encontrado";
    }
}

void eliminarElemento(nodo *&pila, int n){


}
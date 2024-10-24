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
void buscarElemento(nodo *, int);
void eliminarElemento(nodo *&, int);
void eliminarTodaLaPila(nodo *&, int n);
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
                    cout << "Ingrese un elemento: ";
                    cin >> n;
                    IngresarElementos(pila, n);
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

            case 4:
                while (pila != NULL)
                {
                   eliminarTodaLaPila(pila, n);
                }
                

       }
       }while(op != 4);

    return 0;
}

void IngresarElementos(nodo *&pila, int n) {
    nodo *aux = NULL;
    aux = new(nodo);
    aux->dato = n;

    if (pila == NULL)
    {
        aux->sig = NULL;
        
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

void buscarElemento(nodo *pila, int n){
    nodo *actual = new nodo();
    actual = pila;
    int posi;
    bool band = false;

    while (actual != NULL)  
    {
        if (actual->dato == n)
        {
            band = true;
        } 
        actual = actual->sig;
        posi++;
    }

    if (band == true)
    {
        cout << "Elemento"<<n<< " encontrado , en " << posi;
    } else {

          cout << "Elemento"<<n<< " NO encontrado";
    }
}

void eliminarElemento(nodo *&pila, int n){
    nodo *aux = pila;
    pila = aux->sig;
    cout << "Elemento desapilado: " << aux->dato << endl;
    delete(aux);
}

void eliminarTodaLaPila(nodo *&pila, int n){

    nodo *aux = pila;
    n = aux->dato;
    pila = aux->sig;
    delete aux;
}
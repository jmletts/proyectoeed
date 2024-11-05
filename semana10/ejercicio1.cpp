#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo {
    int dato;
    nodo *sig;
};

void agregarpila(nodo *&, int);
void sacarpila(nodo *&, int &);

int main() {
    setlocale(LC_CTYPE, "Spanish");
    int dato, i, cant;
    nodo *pila = NULL; 

    cout << "Ingrese cantidad de nodos : \n";
    cin >> cant;

    for (i = 1; i <= cant; i++) {
        cout << "Digite numero: ";
        cin >> dato;
        agregarpila(pila, dato);
    }

    cout << "sacando valores de la pila \n";
    while (pila != NULL) {
        sacarpila(pila, dato);
        if (pila != NULL) {
            cout << dato << " , ";
        } else {
            cout << dato << ". ";
        }
    }
}

void agregarpila(nodo *&pila, int n) {
    nodo *nuevonodo = new nodo(); 
    nuevonodo->dato = n;          
    nuevonodo->sig = pila;        
    pila = nuevonodo;             
    cout << "\nEl elemento " << n << " Se agregó correctamente \n\n";
}

void sacarpila(nodo *&pila, int &n) {
    nodo *aux = pila;     
    n = aux->dato;        
    pila = aux->sig;     
    delete aux;           
}

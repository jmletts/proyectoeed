#include <iostream>

using namespace std;

struct nodo
{
    int dato;
    nodo *sig; 
    nodo *ant;  
};



void insertarElementos();
void insertarElementosF(nodo *&inicio, int n);
void mostrarI(nodo *inicio);
void mostrarF(nodo *inicio);


int main(int argc, char const *argv[])
{
    nodo *inicio = NULL;
    nodo *fin = NULL;
    
    return 0;
}

void insertarElementosI(nodo *&inicio, int n)
{
    nodo *nuevo = new nodo(); // s reserva mmemoria
    nuevo->dato = n; 
    nuevo->sig = inicio; // el puntero seigueinete apuntara al inicio
    nuevo->ant = NULL; // como sera el primero en la lista entoces su anteriior sera null

    if (inicio != NULL)
    {
        inicio->ant = nuevo; // entonces el anterior de inicio se actualiza como nuevo
    }
    
    inicio = nuevo; // se actualiza para que sea el primero en la lista

}

void insertarElementosF(nodo *&inicio, int n)
{
    nodo *nuevo = new nodo();
    nodo *aux = inicio;
    nuevo->dato = n; 
    nuevo->sig = NULL; // el nuevo sieguiente sera null porque este sera el ultimo en a la lista

    if (inicio == NULL) // verificar el inicio de la lista
    {
        nuevo->ant = NULL; // el anterior debera ser nuloya queno tiene un nodo anterior
        inicio = nuevo; // y se actaulize para que inicio apunte a nuevo
        return;

    }
    
    while (aux->sig != NULL) // recorremos desde el inicio hasta encontrar uno que el siegiinte sa null
    {
        aux = aux->sig; 
    }
    
    aux->sig = nuevo; // aasigna el ulimo nodo con el nuevo
    nuevo->ant = aux; // el puntero anterior del nuevo, apunta al antiguo nodo de la lista

}

void mostrarI(nodo *inicio)
{
    nodo *aux = inicio;

    while (aux != NULL)
    {
        cout << aux->dato << " ";
        aux = aux->sig;
    }
    cout << endl;

}

void mostrarF(nodo *inicio)
{
    nodo *aux = inicio;
    
}

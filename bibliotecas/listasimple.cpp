#include <iostream>

using namespace std;


struct nodo
{
   int dato;
   nodo *sig;
};
nodo *inicio = NULL;

void insertarElemento(nodo *&inicio, int n);
void eliminarElemento(nodo *&inicio, int n);
void mostrarElementos(nodo *inicio);
void buscarElemento(nodo *inicio, int n);
void eliminarlista(nodo *&inicio);
int main(int argc, char const *argv[])
{
    
    insertarElemento(inicio, 23);
    insertarElemento(inicio, 2);
    insertarElemento(inicio, 21);

    mostrarElementos(inicio);

    eliminarElemento(inicio, 2);
    mostrarElementos(inicio);

    buscarElemento(inicio, 23);
    buscarElemento(inicio, 234);

    mostrarElementos(inicio);

    eliminarlista(inicio);



    

    return 0;
}

void insertarElemento(nodo *&inicio, int n)
{
    nodo *nuevo = new nodo();
    nuevo->dato = n;
    nuevo->sig = NULL;

    if (inicio == NULL)
    {
        inicio = nuevo;

    } else {
        nodo *aux = inicio;
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nuevo;

    }   
}

void eliminarElemento(nodo *&inicio, int n)
{
    nodo *aux = inicio;
    nodo *anterior = NULL;

    while (aux != NULL && aux->dato != n)
    {   
        anterior = aux;
        aux = aux->sig;
    }


    if (aux == NULL) //si no lo encontro
    {
        return;
    }

    if (anterior == NULL)
    {
        inicio = aux->sig;
    } else {
        anterior->sig = aux->sig;
    }  

    delete aux;
}

void eliminarlista(nodo *&inicio)
{
    int aux;
    while (inicio != NULL)
    {
        eliminarElemento(inicio, aux);
    }
    

}

void mostrarElementos(nodo *inicio){

    nodo *aux = inicio;

    while (aux != NULL)
    {
        cout << aux->dato << " ";
        aux = aux->sig;
    }

    cout << endl;
    

}


void buscarElemento(nodo *inicio, int n) {
    nodo *aux = inicio;
    bool band = false;
    int cont = 0;

    while (aux != NULL)
    {
        if (aux->dato == n)
        {
            band = true;
        }
        cont ++;
        aux = aux->sig;
    }
    
    if (band == true)
    {
        cout << "Elemento: "<<n<<"Encontrado en la posicion "<<cont;
    }
    else {
        cout << "Elemento: "<<n<<"NO encontrado";
    }
}


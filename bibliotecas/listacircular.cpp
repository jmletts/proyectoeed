#include <iostream>

using namespace std;

struct nodo
{
    int dato;
    nodo *sig; 
};

nodo *inicio = NULL;

void insertarElemento(nodo *&inicio, int n);
void mostrarElementos(nodo *inicio);

int main(int argc, char const *argv[])
{
    insertarElemento(inicio, 10);
    insertarElemento(inicio, 4);
    insertarElemento(inicio, 14);

    mostrarElementos(inicio);

    return 0;
}

void insertarElemento(nodo *&inicio, int n)
{
    nodo *nuevo = new nodo();
    nuevo->dato = n;

    if (inicio == NULL)
    {
        inicio = nuevo;
        nuevo->sig = inicio;

    }else{
        nodo *aux = inicio;
        while (aux->sig != inicio)
        {
            aux = aux->sig;
        }
        aux->sig =nuevo;
        nuevo->sig = inicio;
    }
    
}

void mostrarElementos(nodo *inicio){
    
    if (inicio == NULL)
    {
        cout << "Lista vacica" <<endl;

    } else{
        nodo *aux = inicio;

        do
        {
            cout << aux->dato << " ";
            aux = aux->sig;
        } while (aux != inicio);
    
        

    }
    
}
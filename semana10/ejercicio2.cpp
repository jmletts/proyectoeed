#include <iostream>

using namespace std;

struct nodo
{
    int dato;
    nodo *sgt;
};

nodo *pila = NULL;

void menu();
void insertarElementos(nodo *&pila, int n);
void mostrarElementos(nodo *pila);
void BuscarElemento(nodo *pila, int n);
void EliminarElemento(nodo *&pila);
void EliminarTodo(nodo *&pila);
void CantidadParesImpares(nodo *pila);
void DisplayError () {cout << "Error Ingrese de nuevo"<<endl; }


int main(int argc, char const *argv[])
{
    menu();
    return 0;
}

void menu(){
    int op;
    int n;
    do
    {
        cout << "\tMenu"<<endl;
        cout << "[1] Ingresar Elementos a la pila" << endl;
        cout << "[2] Mostrar elementos de la pila" << endl;
        cout << "[3] Buscar un elemento en la pila" << endl;
        cout << "[4] Elimininar elemento de la pila" << endl;
        cout << "[5] Eliminar toda la pila" << endl;
        cout << "[6] Cantidad de numeros pares e impares" << endl;
        cout << "[7] Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "Ingrese un valor: ";
            cin >> n;
            insertarElementos(pila, n);
            
            break;
        
        case 2:
            mostrarElementos(pila);
            
            break;
        
        case 3:
            cout << "Ingrese el elemento a buscar: ";
            cin >> n;
            BuscarElemento(pila, n);
            
            break;

        case 4:
            EliminarElemento(pila);
            
            break;

        case 5:
            EliminarTodo(pila);
            cout << "Pila eliminada" <<endl;

            break;

        case 6:
            CantidadParesImpares(pila);   
            
            break;
        
        default:
            DisplayError();
            break;
        }
        
    } while (op != 7);
    
}

void insertarElementos(nodo *&pila, int n)
{

    nodo *nuevoNodo = new nodo();
    nuevoNodo->dato = n;

    if (pila == NULL)
    {
        nuevoNodo->sgt = NULL;
    } else{
        nuevoNodo ->sgt = pila;
    }
    pila = nuevoNodo; // para que sea como escalera

}

void mostrarElementos(nodo *pila)
{

    nodo *aux = pila;

    if (pila == NULL)
    {
        DisplayError ();
        cout << "La pila esta vacia"<<endl;

    } else {
        while (aux != NULL)
        {
            cout << aux->dato << endl;
            aux = aux->sgt;
        }
    }
}

void BuscarElemento(nodo *pila, int n){

    nodo *actual = pila;
    bool band = false;
    int cont=0;

    while (actual != NULL)
    {
        if (actual->dato == n)
        {
            band = true;
            break;

        }
        
        actual = actual->sgt;
        cont++;
    }

    if (band == true)
    {
       cout << "Elemento "<<n<<" encontrado, en la posicion: "<<cont;

    }else {
        cout << "Elemento "<<n<<" NO encontrado";
    }
}

void EliminarElemento(nodo *&pila){

    nodo *aux = pila;
    pila = aux->sgt;
    cout << "Elemento eliminado";
    delete(aux);
}

void EliminarTodo(nodo *&pila) {

    nodo *aux;

    while (pila != NULL)
    {
        aux = pila;
        pila = aux->sgt;
        delete(aux);
    }
    
}

void CantidadParesImpares(nodo *pila){
    nodo *aux = pila;
    int contador[2] = {0};

    while (aux != NULL)
    {
        if (aux->dato % 2 == 0)
        {
            contador[0]++;

        } else{
            contador[1]++;
        }
        aux = aux->sgt;   
    }
    
    cout << "La cantidad de numeros pares es: "<<contador[0] <<endl;
    cout << "La cantidad de numeros impares es: "<<contador[1] <<endl;

}

#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *sgte;
};

Nodo *lista = NULL;

void InsertarLista(Nodo *&lista, int n);
void MostrarLista(Nodo *lista);
void BuscarLista(Nodo *lista, int n);
void EliminarNodo(Nodo *&lista, int n);
void Eliminarlista(Nodo *&lista, int n);
void CalcularMM(Nodo *lista);
void Menu();

int main(int argc, char const *argv[])
{
    Menu();

    return 0;
}

void Menu(){
    int n;
    int op;

    do
    {
        cout << endl;
        cout << "\t Menu \n";
        cout << "[1] Insertar elementos \n";
        cout << "[2] Mostrar elementos \n";
        cout << "[3] Buscar elementos \n";
        cout << "[4] Eliminar elementos \n";
        cout << "[5] Eliminar toda la lista \n";
        cout << "[6] Calcular el numero mayor y menor \n";
        cout << "[7] Salir \n";
        cout << "opcion: ";
        cin >> op;

        switch (op)
        {
        case 1:    

            cout << "Ingrese un dato";
            cin >> n;
            InsertarLista(lista, n);
            break;

        case 2:   MostrarLista(lista); break;
        case 3: 
            cout << "Ingrese el elemento a buscar: ";
            cin >> n;
            BuscarLista(lista, n);
        break;

        case 4: 
            cout << "Ingrese el elemento a eliminar: ";
            cin >> n;
            EliminarNodo(lista, n);
        break;

        case 5: 
            while (lista != NULL)
            {
                Eliminarlista(lista, n);
            }

        cout << "Se elimino toda la lista";
            
        break;

        case 6: 
            CalcularMM(lista);
        break;
        }
        
    } while (op != 6);
    
}
void InsertarLista(Nodo *&lista, int n) {
    Nodo *nodo_nuevo = new Nodo(); // Crear nuevo nodo y reservar memoria
    nodo_nuevo->dato = n; // asignar n al dato

    // auxiliares
    Nodo *aux1 = lista; // se iguala a la cabecera
    Nodo *aux2; //para ordenar la lista

    while (aux1 != NULL && aux1->dato < n)
    {
        aux2 = aux1;
        aux1 = aux1->sgte;
    }
    
    if (lista == aux1) //si este se cumple entnces noentro al while
    {
        lista = nodo_nuevo; // se insertara al inicio

    }else{ aux2->sgte = nodo_nuevo; } // es mayor al elemento

    nodo_nuevo->sgte = aux1;
    
}

void MostrarLista(Nodo *lista){

    Nodo *actual = new Nodo();
    actual = lista; //primera poscionde la lista
    while (actual != NULL)
    {
        cout << actual->dato << " -> ";
        actual = actual->sgte;
    }
}

void BuscarLista(Nodo *lista, int n){
    // Igualar el nuevo nodo a lista o primera posicion
    Nodo *actual = new Nodo();
    actual = lista;
    bool indicador = false;

    while (actual != NULL && actual->dato <= n) // este erecorre la lista en roden de menor a mayor
    {
        // determinar existe 
        if (actual->dato == n)
        {
            indicador = true; // para saber si encontro el elemento
        }
        actual = actual->sgte; //corre una posicion
    }
    
    if (indicador == true)
    {
        cout << "El elemento: "<<n<<" fue encontrado";
    } else { 
        cout << "El elemento: "<<n<<" no fue encontrado";
    }
    
}

void EliminarNodo(Nodo *&lista, int n){
    if (lista != NULL) // para saber si la lista no esta vacia
    {
        // punteros auxliares
        Nodo *aux_borrar;
        Nodo *anterior = NULL;

        aux_borrar = lista; // al inicio de la lista

        // recorrrer la lista

        while (aux_borrar != NULL && aux_borrar->dato != n)
        {
            anterior = aux_borrar;
            aux_borrar = aux_borrar->sgte;
        }
        
        // si elelementon no existe 
        if (aux_borrar == NULL)
        {
            cout << "El elemento: "<< n <<" no existe en la lista";
        }
        
        // si es el primer elemento de la lista

        if (anterior == NULL)
        {
            lista = lista->sgte; // apunta al siguiene elemento
            delete aux_borrar;
        } else {
            
            anterior->sgte = aux_borrar->sgte; // apuntaria al siguiente elemento
            delete aux_borrar;
        }
        

    }
    
}

void Eliminarlista(Nodo *&lista, int n)
{
    Nodo *aux = lista;
    n = aux->dato;
    lista = aux->sgte;
    delete aux;
}

void CalcularMM(Nodo *lista){
    int mayor = 0;
    int menor = 99999999;
     while (lista != NULL)
     {
        if (lista ->dato > mayor)
        {
            mayor = lista->dato;
        }
        if (lista->dato < menor)
        {
            menor = lista->dato;
        }
        lista = lista->sgte;
        
     }

     cout << "El mayor elemento: " <<mayor <<endl;
     cout << "El menor elemento: " <<menor <<endl;
     

}
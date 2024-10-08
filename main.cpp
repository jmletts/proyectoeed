≈#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 10;
struct trabajador
{
    string nombre;
    float sueldo;
    char genero;
};

void getdatos(trabajador trabajadores[]);
void displayTable (trabajador *Ptrabajadores);

int main(int argc, char const *argv[])
{
    trabajador trabajadores[MAX];

    
    getdatos(trabajadores);
    displayTable(trabajadores);
    
    return 0;
}

void getdatos(trabajador trabajadores[]) {

    for (int i = 0; i < MAX; i++)
    {
        cout << "Ingresa el nombre: ";
        cin >> trabajadores[i].nombre;

        cout << "Ingresa el sueldo: ";
        cin >> trabajadores[i].sueldo;

        cout << "Ingresa el genero (M/F): ";
        cin >> trabajadores[i].genero;

    }
    
}

void displayTable (trabajador *Ptrabajadores) {

    int contMujeres = 0;
    float contSueldoMujeres = 0;
    float contSueldo = 0;
    float mayor = 0;
    float menor = (Ptrabajadores)->sueldo;


    cout << setw(14)<< "Nombre"
         << setw(14)<< "Sueldo"
         << setw(14)<< "Genero" << endl;
    
    cout << "********************************************************"<<endl;

    for (int i = 0; i < 10; i++)
    {
         cout << setw(14)<< (Ptrabajadores + i)->nombre  //  para array de strucutre (pA + i)-> titulo
         << setw(14)<< (Ptrabajadores + i)->sueldo
         << setw(14)<< (Ptrabajadores + i)->genero << endl;

         //  logica y contadores

        if ((Ptrabajadores + i)->genero == 'F')
        {
            contMujeres++;
            contSueldoMujeres += (Ptrabajadores + i)->sueldo;
        }

        if ((Ptrabajadores + i)->sueldo > mayor)
        {
            mayor = (Ptrabajadores + i)->sueldo;
        }
        
        if ((Ptrabajadores + i)->sueldo < menor)
        {
            menor = (Ptrabajadores + i)->sueldo;
        }
        
        
        contSueldo += (Ptrabajadores + i)->sueldo;
    }
    
    cout << "La cantidad de mujeres es: " <<contMujeres <<endl;
    cout << "el monto total de mujeres en sueldo es: " <<contSueldoMujeres <<endl;
    cout << "el monto total de suledos es: " <<contSueldo <<endl;

}

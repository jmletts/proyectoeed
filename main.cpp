#include <iostream>
#include <iomanip>
#include <string.h>
#include <cstdlib>

using namespace std; 

//Estructuras
struct horario{
    string curso;
    int hora_inicio; 
    int minuto_inicio;
    int hora_final;
    int minuto_final;
};

const int MAX = 20;

//Arreglos globales
horario lunes[MAX];
horario martes[MAX];
horario miercoles[MAX];
horario jueves[MAX];
horario viernes[MAX];
horario sabado[MAX];
horario domingo[MAX];


//Variables Globalas

int count_lunes = 0;
int count_martes = 0; 
int count_miercoles = 0;
int count_jueves = 0;
int count_viernes = 0; 
int count_sabado = 0;
int count_domingo = 0;

//Modulos 
void displayError();
int inicio();
int seleccionar_semestre();
void seleccionar_cursos(int n, int &opcion);
void seleccionar_horario(int opcion_curso, int opcion_semestre);
void seleccionar_examenes(int opcion_curso, int opcion_semestre);
void horas_extra();
void getMetodoEstudio();

void mostrar_horario();
void ordenar_horarios(horario horarios[], int n);




string semestre_curso[10][7] = { //FILAS → Semestres || COLUMNAS → Cursos
        { "MATEMÁTICA SUPERIOR", 
          "HABILIDADES COMUNICATIVAS", 
          "GESTIÓN DEL APRENDIZAJE", 
          "INTRODUCCIÓN A LA INGENIERÍA DE SISTEMAS E INFORMÁTICA", 
          "QUÍMICA 1", 
          "LABORATORIO DE LIDERAZGO", 
          "HERRAMIENTAS VIRTUALES PARA EL APRENDIZAJE" },
          
        { "ÁLGEBRA MATRICIAL Y GEOMETRÍA ANALÍTICA", 
          "FUNDAMENTOS DEL CÁLCULO", 
          "MATEMÁTICA DISCRETA", 
          "COMUNICACIÓN EFECTIVA", 
          "ÉTICA, CIUDADANÍA Y GLOBALIZACIÓN", 
          "GESTIÓN BASADA EN PROCESOS", 
          "" }, // Espacio vacío para mantener el tamaño uniforme
          
        { "CÁLCULO DIFERENCIAL", 
          "FÍSICA 1", 
          "FUNDAMENTOS DE PROGRAMACIÓN", 
          "SISTEMAS DE INFORMACIÓN", 
          "ESTADÍSTICA GENERAL", 
          "LABORATORIO DE INNOVACIÓN", 
          "" },
          
        { "CÁLCULO INTEGRAL", 
          "FÍSICA 2", 
          "PROGRAMACIÓN ORIENTADA A OBJETOS", 
          "COMUNICACIÓN Y ARGUMENTACIÓN", 
          "ESTADÍSTICA APLICADA", 
          "ESTRUCTURA DE DATOS", 
          "" },
          
        { "ECUACIONES DIFERENCIALES", 
          "ANÁLISIS Y REQUERIMIENTOS DE SOFTWARE", 
          "BASE DE DATOS", 
          "SISTEMAS DIGITALES", 
          "LABORATORIO AVANZADO DE INNOVACIÓN Y LIDERAZGO", 
          "CURSO ELECTIVO", 
          "" },
          
        { "ARQUITECTURA DEL COMPUTADOR", 
          "DISEÑO DE SOFTWARE", 
          "INVESTIGACIÓN OPERATIVA", 
          "ADMINISTRACIÓN DE BASE DE DATOS", 
          "SEMINARIO DE INVESTIGACIÓN", 
          "SISTEMAS OPERATIVOS", 
          "" },
          
        { "ARQUITECTURA EMPRESARIAL", 
          "CONSTRUCCIÓN DE SOFTWARE", 
          "REDES DE COMPUTADORES", 
          "INGENIERÍA ECONÓMICA", 
          "INNOVACIÓN SOCIAL", 
          "GESTIÓN PROFESIONAL", 
          "" },
          
        { "CONMUTACIÓN Y ENRUTAMIENTO", 
          "DIRECCIÓN DE PROYECTOS", 
          "PRUEBAS Y CALIDAD DE SOFTWARE", 
          "SIMULACIÓN", 
          "CONVERSATION CLASS", 
          "SUPERVISIÓN PRÁCTICAS PREPROFESIONALES - INGENIERÍA", 
          "" },
          
        { "DESARROLLO DE APLICACIONES MÓVILES", 
          "INGENIERÍA WEB", 
          "TALLER DE INVESTIGACIÓN 1 - INGENIERÍA DE SISTEMAS E INFORMÁTICA", 
          "TALLER DE PROYECTOS 1 - INGENIERÍA DE SISTEMAS E INFORMÁTICA", 
          "GESTIÓN DE SERVICIOS TI", 
          "ELECT ESP1", 
          "" },
          
        { "AUDITORÍA DE SISTEMAS", 
          "TALLER DE INVESTIGACIÓN 2 - INGENIERÍA DE SISTEMAS E INFORMÁTICA", 
          "TALLER DE PROYECTOS 2 - INGENIERÍA DE SISTEMAS E INFORMÁTICA", 
          "CLOUD COMPUTING", 
          "INTELIGENCIA DE NEGOCIOS", 
          "ELECT ESP2", 
          "" }
    };  

string examanes_semestre_curso[10][7] = { //FILAS → Semestres || COLUMNAS → Cursos
        { "Examen de MATEMÁTICA SUPERIOR", 
          "Examen de HABILIDADES COMUNICATIVAS", 
          "Examen de GESTIÓN DEL APRENDIZAJE", 
          "Examen de INTRODUCCIÓN A LA INGENIERÍA DE SISTEMAS E INFORMÁTICA", 
          "Examen de QUÍMICA 1", 
          "Examen de LABORATORIO DE LIDERAZGO", 
          "Examen de HERRAMIENTAS VIRTUALES PARA EL APRENDIZAJE" },
          
        { "Examen de ÁLGEBRA MATRICIAL Y GEOMETRÍA ANALÍTICA", 
          "Examen de FUNDAMENTOS DEL CÁLCULO", 
          "Examen de MATEMÁTICA DISCRETA", 
          "Examen de COMUNICACIÓN EFECTIVA", 
          "Examen de ÉTICA, CIUDADANÍA Y GLOBALIZACIÓN", 
          "Examen de GESTIÓN BASADA EN PROCESOS", 
          "" }, // Espacio vacío para mantener el tamaño uniforme
          
        { "Examen de CÁLCULO DIFERENCIAL", 
          "Examen de FÍSICA 1", 
          "Examen de FUNDAMENTOS DE PROGRAMACIÓN", 
          "Examen de SISTEMAS DE INFORMACIÓN", 
          "Examen de ESTADÍSTICA GENERAL", 
          "Examen de LABORATORIO DE INNOVACIÓN", 
          "" },
          
        { "Examen de CÁLCULO INTEGRAL", 
          "Examen de FÍSICA 2", 
          "Examen de PROGRAMACIÓN ORIENTADA A OBJETOS", 
          "Examen de COMUNICACIÓN Y ARGUMENTACIÓN", 
          "Examen de ESTADÍSTICA APLICADA", 
          "Examen de ESTRUCTURA DE DATOS", 
          "" },
          
        { "Examen de ECUACIONES DIFERENCIALES", 
          "Examen de ANÁLISIS Y REQUERIMIENTOS DE SOFTWARE", 
          "Examen de BASE DE DATOS", 
          "Examen de SISTEMAS DIGITALES", 
          "Examen de LABORATORIO AVANZADO DE INNOVACIÓN Y LIDERAZGO", 
          "Examen de CURSO ELECTIVO", 
          "" },
          
        { "Examen de ARQUITECTURA DEL COMPUTADOR", 
          "Examen de DISEÑO DE SOFTWARE", 
          "Examen de INVESTIGACIÓN OPERATIVA", 
          "Examen de ADMINISTRACIÓN DE BASE DE DATOS", 
          "Examen de SEMINARIO DE INVESTIGACIÓN", 
          "Examen de SISTEMAS OPERATIVOS", 
          "" },
          
        { "Examen de ARQUITECTURA EMPRESARIAL", 
          "Examen de CONSTRUCCIÓN DE SOFTWARE", 
          "Examen de REDES DE COMPUTADORES", 
          "Examen de INGENIERÍA ECONÓMICA", 
          "Examen de INNOVACIÓN SOCIAL", 
          "Examen de GESTIÓN PROFESIONAL", 
          "" },
          
        { "Examen de CONMUTACIÓN Y ENRUTAMIENTO", 
          "Examen de DIRECCIÓN DE PROYECTOS", 
          "Examen de PRUEBAS Y CALIDAD DE SOFTWARE", 
          "Examen de SIMULACIÓN", 
          "Examen de CONVERSATION CLASS", 
          "Examen de SUPERVISIÓN PRÁCTICAS PREPROFESIONALES - INGENIERÍA", 
          "" },
          
        { "Examen de DESARROLLO DE APLICACIONES MÓVILES", 
          "Examen de INGENIERÍA WEB", 
          "Examen de TALLER DE INVESTIGACIÓN 1 - INGENIERÍA DE SISTEMAS E INFORMÁTICA", 
          "Examen de TALLER DE PROYECTOS 1 - INGENIERÍA DE SISTEMAS E INFORMÁTICA", 
          "Examen de GESTIÓN DE SERVICIOS TI", 
          "Examen de ELECT ESP1", 
          "" },
          
        { "Examen de AUDITORÍA DE SISTEMAS", 
          "Examen de TALLER DE INVESTIGACIÓN 2 - INGENIERÍA DE SISTEMAS E INFORMÁTICA", 
          "Examen de TALLER DE PROYECTOS 2 - INGENIERÍA DE SISTEMAS E INFORMÁTICA", 
          "Examen de CLOUD COMPUTING", 
          "Examen de INTELIGENCIA DE NEGOCIOS", 
          "Examen de ELECT ESP2", 
          "" }
    };  
    
string dias[7]={
    "LUNES", "MARTES", "MIERCOLES", "JUEVES", "VIERNES", "SÁBADO", "DOMINGO"
};


int main(int argc, char const *argv[]) {   
    cout << setw(20) << "============================== BIENVENIDO ================================" << setw(20) << endl << endl;
    cout << setw(20) << "===== SISTEMA DE GESTIÓN DE HORARIOS PARA ALUMNOS DE ING DE SISTEMAS =====" << endl << " Plan de estudios 2019 - 10" << setw(20) << endl << endl;
    
    int opcion_semestre = seleccionar_semestre();
    int opcion_inicio = 0;

    do {
        opcion_inicio = inicio(); // Llama a la función para seleccionar la opción
        switch(opcion_inicio) {
            case 1: {
                // Ingresar horario por asignatura
                int opcion_curso = 0;
                seleccionar_cursos(opcion_semestre, opcion_curso); // Variable por referencia → opcion_curso
                seleccionar_horario(opcion_curso - 1, opcion_semestre - 1);  
            } break;

            case 2: {
                // Completar horario con exámenes
                int opcion_curso2 = 0;
                seleccionar_cursos(opcion_semestre, opcion_curso2); // Variable por referencia → opcion_curso2
                seleccionar_examenes(opcion_curso2 - 1, opcion_semestre - 1);
            } break; // Añadir break

            case 3: {
                // Horas fuera de la universidad
                horas_extra();
                break;
            }

            case 4: {
                // Plan de estudios
                cout << "Mostrando plan de estudios..." << endl; 
                getMetodoEstudio();

                break;
            }

            case 5: {
                // Mostrar horario final
                mostrar_horario();  
                break;
            }
        }
    } while (true); 

    return 0; 
}

void displayError() {
    cout << " - - - - - - - - ERROR, INGRESA NUEVO - - - - - - - -" << endl; 
}

int inicio() {
    int op;
    do {
        cout << " ↓↓↓ Ingrese una opción ↓↓↓ " << endl << endl;

        cout << "1. Ingresar horario por asignatura" << endl;
        cout << "2. Completar horario con examenes" << endl;
        cout << "3. Horas fuera de la universidad" << endl;
        cout << "4. Plan de estudios" << endl;
        cout << "5. Mostrar horario final" << endl;
        cin >> op;
        if (op < 1 || op > 5) { displayError(); }
        
    } while (op < 1 || op> 5);
    return op;
}

int seleccionar_semestre() {
    int n = 0;
    cout << " ↓↓↓ INGRESE SU SEMESTRE ACTUAL ↓↓↓" << endl;
    cout << "1. Primer semestre" << endl;
    cout << "2. Segundo semestre" << endl;
    cout << "3. Tercer semestre" << endl;
    cout << "4. Cuarto semestre" << endl;
    cout << "5. Quinto semestre" << endl;
    cout << "6. Sexto semestre" << endl;
    cout << "7. Séptimo semestre" << endl;
    cout << "8. Octavo semestre" << endl;
    cout << "9. Noveno semestre" << endl;
    cout << "10. Décimo semestre" << endl;

    cin >> n;
    return n;
}

void seleccionar_cursos(int n, int &opcion) {

    switch (n) {
        case 1:
            cout << " ↓↓↓ ESCOGA UNA ASIGNATURA ↓↓↓" << endl;
            for (int i = 0; i < 1; i++)
            {
                cout << i+1 << ". " << semestre_curso[0][i];
            }     
            cin >> opcion;
            break;

        case 2:
            cout << " ↓↓↓ ESCOGA UNA ASIGNATURA ↓↓↓" << endl;
            for (int i = 0; i < 6; i++)
            {
                cout << i+1 << ". " << semestre_curso[1][i] << endl;
            }     
            cin >> opcion;
            break;

        case 3:
            cout << " ↓↓↓ ESCOGA UNA ASIGNATURA ↓↓↓" << endl;
            for (int i = 0; i < 6; i++)
            {
               cout << i+1 << ". " << semestre_curso[2][i] << endl;
            }     
            cin >> opcion;
            break;

        case 4:
            cout << " ↓↓↓ ESCOGA UNA ASIGNATURA ↓↓↓" << endl;
            for (int i = 0; i < 6; i++)
            {
                cout << i+1 << ". " << semestre_curso[3][i] << endl;
            } 
            cin >> opcion;
            break;

        case 5:
            cout << " ↓↓↓ ESCOGA UNA ASIGNATURA ↓↓↓" << endl;
            for (int i = 0; i < 6; i++)
            {
                cout << i+1 << ". " << semestre_curso[4][i] << endl;
            } 
            cin >> opcion;
            break;

        case 6:
            cout << " ↓↓↓ ESCOGA UNA ASIGNATURA ↓↓↓" << endl;
            for (int i = 0; i < 6; i++)
            {
                cout << i+1 << ". " << semestre_curso[5][i] << endl;
            } 
            cin >> opcion;
            break;

        case 7:
            cout << " ↓↓↓ ESCOGA UNA ASIGNATURA ↓↓↓" << endl;
            for (int i = 0; i < 6; i++)
            {
               cout << i+1 << ". " << semestre_curso[6][i] << endl;
            } 
            cin >> opcion;
            break;

        case 8:
            cout << " ↓↓↓ ESCOGA UNA ASIGNATURA ↓↓↓" << endl;
            for (int i = 0; i < 6; i++)
            {
                cout << i+1 << ". " << semestre_curso[7][i]<< endl;
            }
            cin >> opcion;
            break;

        case 9:
            cout << " ↓↓↓ ESCOGA UNA ASIGNATURA ↓↓↓" << endl;
            for (int i = 0; i < 6; i++)
            {
                cout << i+1 << ". " << semestre_curso[8][i] << endl;
            }
            cin >> opcion;
            break;

        case 10:
            cout << " ↓↓↓ ESCOGA UNA ASIGNATURA ↓↓↓" << endl;
            for (int i = 0; i < 6; i++)
            {
                cout << i+1 << ". " << semestre_curso[9][i] << endl;
            }
            cin >> opcion;
            break;

        default:
        displayError();
            break;
    }
}

void seleccionar_horario(int opcion_curso, int opcion_semestre)
{
    int dia_opcion;
    int hora_inicio, minuto_inicio, hora_final, minuto_final;

    cout << " ↓↓↓ Selecciona el día que cursa " << semestre_curso[opcion_semestre][opcion_curso] << " ↓↓↓" << endl;

     cout << "1. Lunes " << endl
          << "2. Martes" << endl
          << "3. Miercoles" << endl
          << "4. Jueves" << endl
          << "5. Viernes" << endl
          << "6. Sábado" << endl
          << "7. Domingo" << endl;
    cin >> dia_opcion;
  
    cout << " ↓↓↓ Ingrese a qué hora cursa " << semestre_curso[opcion_semestre][opcion_curso] << " el dia " << dias[dia_opcion-1]<<  " ↓↓↓ " << endl;
    do
    {
        cout << "Hora de inicio (Formato 24h): "; cin >> hora_inicio;
        if(hora_inicio<0 || hora_inicio>24){
            displayError();
        }
    } while (hora_inicio<0 || hora_inicio>24);
    
    do
    {
        cout << "Minutos de inicio: "; cin >>minuto_inicio;
        if (minuto_inicio<0 || minuto_inicio>59) {
            displayError();
        }
        
    } while (minuto_inicio<0 || minuto_inicio>59);
    

    do
    {
        cout << "Hora de termino (Formato 24h): "; cin >> hora_final;
        if(hora_final<0 || hora_final>24){
        displayError();
        }
    } while (hora_final<0 || hora_final>24);;

    do
    {
        cout << "Minutos de termino: "; cin >>minuto_final;
        if (minuto_final<0 || minuto_final>59) {
        displayError();
        }
    } while (minuto_final<0 || minuto_final>59);

    horario nuevo_horario = {semestre_curso[opcion_semestre][opcion_curso], hora_inicio, minuto_inicio, hora_final, minuto_final};

    switch (dia_opcion) {
        case 1: lunes[count_lunes++] = nuevo_horario; break;
        case 2: martes[count_martes++] = nuevo_horario; break;
        case 3: miercoles[count_miercoles++] = nuevo_horario; break;
        case 4: jueves[count_jueves++] = nuevo_horario; break;
        case 5: viernes[count_viernes++] = nuevo_horario; break;
        case 6: sabado[count_sabado++] = nuevo_horario; break;
        case 7: domingo[count_domingo++] = nuevo_horario; break;
        default: displayError(); break;
    }
    // CRUCE DE HORARIOS
}

void seleccionar_examenes(int opcion_curso, int opcion_semestre){
    int dia_opcion;
    int hora_inicio, minuto_inicio, hora_final, minuto_final;

    cout << " ↓↓↓ Selecciona el día en que tendrás examen de  " << semestre_curso[opcion_semestre][opcion_curso] << " ↓↓↓" << endl;

     cout << "1. Lunes " << endl
          << "2. Martes" << endl
          << "3. Miercoles" << endl
          << "4. Jueves" << endl
          << "5. Viernes" << endl
          << "6. Sábado" << endl
          << "7. Domingo" << endl;
    cin >> dia_opcion;

    cout << " ↓↓↓ Ingrese a qué hora tendrás examen de  " << semestre_curso[opcion_semestre][opcion_curso] << " el dia " << dias[dia_opcion-1]<<  " ↓↓↓ " << endl;
    cout << "Hora de inicio (Formato 24h): "; cin >> hora_inicio;
    cout << "Minutos de inicio: "; cin >>minuto_inicio;
    cout << "Hora de termino (Formato 24h): "; cin >> hora_final;
    cout << "Minutos de termino: "; cin >> minuto_final;

    horario nuevo_horario = {examanes_semestre_curso[opcion_semestre][opcion_curso], hora_inicio, minuto_inicio, hora_final, minuto_final};

    switch (dia_opcion) {
        case 1: lunes[count_lunes++] = nuevo_horario; break;
        case 2: martes[count_martes++] = nuevo_horario; break;
        case 3: miercoles[count_miercoles++] = nuevo_horario; break;
        case 4: jueves[count_jueves++] = nuevo_horario; break;
        case 5: viernes[count_viernes++] = nuevo_horario; break;
        case 6: sabado[count_sabado++] = nuevo_horario; break;
        case 7: domingo[count_domingo++] = nuevo_horario; break;
        default: displayError(); break;
    }
        // CRUCE DE HORARIOS

}

void horas_extra()
{
    int dia_opcion;
    int hora_inicio, minuto_inicio, hora_final, minuto_final;
    string actividad;
    cout << "¿Qué tienes que hacer?: "; 
    getline(cin, actividad);
    cout << " ↓↓↓ Selecciona el día en que harás → "  << actividad << " ← ↓↓↓" << endl;
     cout << "1. Lunes " << endl
          << "2. Martes" << endl
          << "3. Miercoles" << endl
          << "4. Jueves" << endl
          << "5. Viernes" << endl
          << "6. Sábado" << endl
          << "7. Domingo" << endl;
    cin >> dia_opcion;
    
    cout << " ↓↓↓ Ingrese a qué hora harás → " << actividad << " ← el diá " << dias[dia_opcion-1]<<  " ↓↓↓ " << endl;
    cout << "Hora de inicio (Formato 24h): "; cin >> hora_inicio;
    cout << "Minutos de inicio: "; cin >>minuto_inicio;
    cout << "Hora de termino (Formato 24h): "; cin >> hora_final;
    cout << "Minutos de termino: "; cin >> minuto_final;

     horario nuevo_horario = {actividad, hora_inicio, minuto_inicio, hora_final, minuto_final};

    switch (dia_opcion) {
        case 1: lunes[count_lunes++] = nuevo_horario; break;
        case 2: martes[count_martes++] = nuevo_horario; break;
        case 3: miercoles[count_miercoles++] = nuevo_horario; break;
        case 4: jueves[count_jueves++] = nuevo_horario; break;
        case 5: viernes[count_viernes++] = nuevo_horario; break;
        case 6: sabado[count_sabado++] = nuevo_horario; break;
        case 7: domingo[count_domingo++] = nuevo_horario; break;
        default: displayError(); break;
    }
    // CRUCE DE HORARIOS

}

void mostrar_horario() {

    cout << "\n↓↓↓ LUNES ↓↓↓" << endl;

    ordenar_horarios(lunes, count_lunes);

    for (int i = 0; i < count_lunes; i++) {

        cout << setfill('0') << setw(2) << lunes[i].hora_inicio << ":" << setw(2) <<lunes[i].minuto_inicio
             << " - " << setw(2) << lunes[i].hora_final << ":" << setw(2) << lunes[i].minuto_final
             << " → " << lunes[i].curso << endl;
    }

    cout << "\n↓↓↓ MARTES ↓↓↓" << endl;

    ordenar_horarios(martes, count_martes);

    for (int i = 0; i < count_martes; i++) {
        cout << setfill('0') << setw(2) << martes[i].hora_inicio << ":" << setw(2) << martes[i].minuto_inicio
             << " - " << setw(2) << martes[i].hora_final << ":" << setw(2) << martes[i].minuto_final
             << " → " << martes[i].curso << endl;
    }

    cout << "\n↓↓↓ MIÉRCOLES ↓↓↓" << endl;

    ordenar_horarios(miercoles, count_miercoles);

    for (int i = 0; i < count_miercoles; i++) {
        cout << setfill('0') << setw(2) << miercoles[i].hora_inicio << ":" << setw(2) << miercoles[i].minuto_inicio
             << " - " << setw(2) << miercoles[i].hora_final << ":" << setw(2) << miercoles[i].minuto_final
             << " → " << miercoles[i].curso << endl;
    }

    cout << "\n↓↓↓ JUEVES ↓↓↓" << endl;

    ordenar_horarios(jueves, count_jueves);

    for (int i = 0; i < count_jueves; i++) {
        cout << setfill('0') << setw(2) << jueves[i].hora_inicio << ":" << setw(2) << jueves[i].minuto_inicio
             << " - " << setw(2) << jueves[i].hora_final << ":" << setw(2) << jueves[i].minuto_final
             << " → " << jueves[i].curso << endl;
    }

    cout << "\n↓↓↓ VIERNES ↓↓↓" << endl;

    ordenar_horarios(viernes, count_viernes);

    for (int i = 0; i < count_viernes; i++) {
        cout << setfill('0') << setw(2) << viernes[i].hora_inicio << ":" << setw(2) << viernes[i].minuto_inicio
             << " - " << setw(2) << viernes[i].hora_final << ":" << setw(2) << viernes[i].minuto_final
             << " → " << viernes[i].curso << endl;
    }

    cout << "\n↓↓↓ SÁBADO ↓↓↓" << endl;

    ordenar_horarios(sabado, count_sabado);

    for (int i = 0; i < count_sabado; i++) {
        cout << setfill('0') << setw(2) << sabado[i].hora_inicio << ":" << setw(2) << sabado[i].minuto_inicio
             << " - " << setw(2) << sabado[i].hora_final << ":" << setw(2) << sabado[i].minuto_final
             << " → " << sabado[i].curso << endl;
    }

    cout << "\n↓↓↓ DOMINGO ↓↓↓" << endl;

    ordenar_horarios(domingo, count_domingo);

    for (int i = 0; i < count_domingo; i++) {
        cout << setfill('0') << setw(2) << domingo[i].hora_inicio << ":" << setw(2) << domingo[i].minuto_inicio
             << " - " << setw(2) << domingo[i].hora_final << ":" << setw(2) << domingo[i].minuto_final
             << " → " << domingo[i].curso << endl;
    }

}

void ordenar_horarios(horario horarios[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (horarios[j].hora_inicio > horarios[j + 1].hora_inicio || (horarios[j].hora_inicio == horarios[j + 1].hora_inicio && horarios[j].minuto_inicio > horarios[j + 1].minuto_inicio)) 
            {
                horario temp = horarios[j];
                horarios[j] = horarios[j + 1];
                horarios[j + 1] = temp;
            }
        }
    }
}

// PLAN ESTUDIOS

void getMetodoEstudio(){    
int op;

    cout << "\n --- Ingrese el método de Estudio --- \n";
    cout << "\n [1.] Método Pomodoro \n";
    cout << "\n [2.] Método Feynman \n";
    cout << "\n [3.] Método etiquetas \n";
    cin >> op;

    switch (op) {
        case 1: {
            //Pomodoro
            cout << "\nEjecutando el Método Pomodoro...\n";
            system("powershell -command \"while ($true) {Start-Sleep -Seconds 1800; Write-Host 'Tiempo de Descanso - 10 Minutos'; Start-Sleep -Seconds 600; Write-Host '¡Hora de Estudiar otra vez!'}\"");
            break;
        }
        case 2: {
            //Feynman
            string concepto;
            cout << "\nIngrese el concepto que quiere aprender utilizando el método Feynman: ";
            getline(cin, concepto); 

            cout << "\n** Método Feynman para aprender: " << concepto << " **\n";
            cout << "1. Explica el concepto con tus propias palabras.\n";
            cout << "2. Enséñalo a alguien más (o a ti mismo en voz alta).\n";
            cout << "3. Si te atascas, vuelve a la fuente y simplifica.\n";
            cout << "4. Repite hasta que el concepto sea claro y puedas explicarlo fácilmente.\n";
            break;
        }
        case 3: {
            // etiquetas
            cout << "\nMétodo de estudio con etiquetas:\n";
            cout << "Puedes asignar etiquetas a tus tareas para organizarlas mejor. Ejemplo:\n";
            cout << "1. Importante\n";
            cout << "2. Urgente\n";
            cout << "3. A largo plazo\n";

            break;
        }
        default:
            cout << "\nOpción no válida, intenta de nuevo.\n";
    
            break;
    }

}
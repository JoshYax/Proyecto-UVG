#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Tarea {
    int codigo;
    string titulo, descripcion, fecha, prioridad, estado;
};

vector <Tarea> mis_tareas;

void registrar_tarea(){
    
    Tarea nueva_tarea;
    et1:
    cout << "Ingrese codigo de tarea: (Puede colocar un numero entero del 1 al 50)";
    cin >> nueva_tarea.codigo;
    for (const auto &tarea : mis_tareas) {
        if (nueva_tarea.codigo == tarea.codigo) {
            cout << "Error: El codigo de tarea ingresado ya existe." << endl;
            goto et1;
        }
    }
    
    cout << "Ingrese el titulo de la tarea: " << endl;
    cin.ignore();
    getline(cin, nueva_tarea.titulo);

    cout << "Ingrese una descripcion de la tarea: " << endl;
    getline(cin, nueva_tarea.descripcion);

    cout << "Ingrese fecha limite de la tarea: " << endl;
    getline(cin, nueva_tarea.fecha);

    string prioridad;
    do {
        cout << "Cual es la prioridad de su tarea?" << endl;
        cout << "[a] Alta" << endl;
        cout << "[b] Media" << endl;
        cout << "[c] Baja" << endl;
        cout << "Ingrese la prioridad: ";
        getline(cin, prioridad);

        if (prioridad == "a" || prioridad == "b" || prioridad == "c") {
            if (prioridad == "a") {
                nueva_tarea.prioridad = "Alta";
            } if (prioridad == "b") {
                nueva_tarea.prioridad = "Media";
            } if (prioridad == "c") {
                nueva_tarea.prioridad = "Baja";
            }
            break;
        } else {
            cout << "Por favor, ingrese una opcion valida (a, b, c)" << endl;
        }
    } while (true);
    
    string estado;
    do {
        cout << "Ingrese en que estado se encuentra la tarea: " << endl;
        cout << "[a] Realizada" << endl;
        cout << "[b] En progreso" << endl;
        cout << "[c] Sin realizar" << endl;
        cout << "Ingrese el estado: ";
        getline(cin, estado);

        if (estado == "a" || estado == "b" || estado == "c") {
            if (estado == "a") {
                nueva_tarea.estado = "Realizada";
            } if (estado == "b") {
                nueva_tarea.estado = "En progreso";
            } if (prioridad == "c") {
                nueva_tarea.estado = "Sin realizar";
            }
            break;
        } else {
            cout << "Por favor, ingrese una opcion valida (a, b, c)" << endl;
        }
    } while (true);

    mis_tareas.push_back(nueva_tarea);
}

void actualizar_tarea() {
    int buscar_cod;
    cout << "Ingrese el codigo de la tarea a modificar: ";
    cin >> buscar_cod;

    bool tarea_encontrada = false;

    for (int i = 0; i < mis_tareas.size(); i++) {
        if (buscar_cod == mis_tareas[i].codigo) {
            
            tarea_encontrada = true;
             
            cout << "Tarea encontrada. Ingrese los nuevos datos:" << endl;
            
            cout<<"Titulo actual:"<<endl<<mis_tareas[i].titulo<<endl; 
            cout << "Ingrese un nuevo titulo de la tarea: ";
            cin.ignore();
            getline(cin, mis_tareas[i].titulo);

            cout<<"Descripcion actual:"<<endl<<mis_tareas[i].descripcion<<endl;
            cout << "Ingrese una nueva descripcion de la tarea: ";
            getline(cin, mis_tareas[i].descripcion);

            cout<<"Fecha actual:"<<endl<<mis_tareas[i].fecha<<endl;
            cout << "Ingrese la nueva fecha limite de la tarea: ";
            getline(cin, mis_tareas[i].fecha);

            string prioridad;
            do {
                 cout<<"Priodidad actual:"<<endl<<mis_tareas[i].prioridad<<endl; 
                cout << "Cual es la nueva prioridad de su tarea?" << endl;
                cout << "[a] Alta" << endl;
                cout << "[b] Media" << endl;
                cout << "[c] Baja" << endl;
                cout << "Ingrese la prioridad: ";
                getline(cin, prioridad);

                if (prioridad == "a" || prioridad == "b" || prioridad == "c") {
                    if (prioridad == "a") {
                        mis_tareas[i].prioridad = "Alta";
                    } if (prioridad == "b") {
                        mis_tareas[i].prioridad = "Media";
                    } if (prioridad == "c") {
                        mis_tareas[i].prioridad = "Baja";
                    }
                    break;
                } else {
                    cout << "Por favor, ingrese una opcion valida (a, b, c)" << endl;
                }
            } while (true);

            string estado;
            do {
                 cout<<"Estado actual:"<<endl<<mis_tareas[i].estado<<endl; 
                cout << "Ingrese un nuevo estado para la tarea: " << endl;
                cout << "[a] Realizada" << endl;
                cout << "[b] En progreso" << endl;
                cout << "[c] Sin realizar" << endl;
                cout << "Ingrese el estado: ";
                getline(cin, estado);

                if (estado == "a" || estado == "b" || estado == "c") {
                    if (estado == "a") {
                        mis_tareas[i].estado = "Realizada";
                    } if (estado == "b") {
                        mis_tareas[i].estado = "En progreso";
                    } if (estado == "c") {
                        mis_tareas[i].estado = "Sin realizar";
                    }
                    break;
                } else {
                    cout << "Por favor, ingrese una opcion valida (a, b, c)" << endl;
                }
            } while (true);

            cout << "Tarea actualizada exitosamente :)" << endl;
            break;
        }
      
         
    }

    if (!tarea_encontrada) {
        cout << "No se encontró ninguna tarea con el código especificado :(" << endl;
    }
}


int main() {
    setlocale(LC_ALL, "spanish");
    
        mis_tareas.push_back({1, "terrario", "realice un terrario de organismos", "28 de mayo", "Alta", "En progreso"});
        mis_tareas.push_back({2, "blog de clases", "redacte un blog de clases", "21 de mayo", "Media", "Realizada"});
        mis_tareas.push_back({3, "Informe Ciencias de la Vida", "Realizar un informe sobre el proceso de siembra de los hongos", "4 de junio", "Media", "Realizada"});
        mis_tareas.push_back({4, "Revista", "Diseniar una revista con los ejercicios de escritura realizados en clase", "5 de junio", "Baja", "Realizada"});
        mis_tareas.push_back({5, "Cuenta github", "Crear una cuenta y subir el proyecto", "10 de junio", "Alta", "Sin realizar"});

    int opcion;
	
    do {
    cout << "                    Bienvenido a tu Gestor de Tareas" << endl;
    cout << "Organizar tus actividades nunca fue tan facil. Crea, visualiza y actualiza tus tareas."<<endl;
    cout << endl;
    cout << "       Menu de opciones" << endl;
    cout<<"+-----------------------------------+"<<endl;
    cout<<"|1. Registrar Nueva Tarea           |" << endl;
    cout<<"|-----------------------------------|"<<endl;
    cout<<"|2. Visualizar Mis Tareas           |" << endl;
    cout<<"|-----------------------------------|"<<endl;
    cout<<"|3. Actualizar Mis Tareas           |" << endl;
    cout<<"|-----------------------------------|"<<endl;
    cout<<"|4. Salir del Gestor de Tareas      |" << endl;
    cout<<"+-----------------------------------+"<<endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    cin.ignore();
    system ("cls");

    switch (opcion) {
    case 1: {
 
    registrar_tarea();
    	system ("pause");
    	system ("cls");
	}
    break;
    
    case 2: {
    	system ("cls");
    cout << "Tareas Guardadas" << endl;
    cout << "Visualiza tus tareas, presta atencion al codigo y si quieres modificar algun elemento,"<<endl;
    cout << "ve al menu, elige opcion 3 e ingresa el codigo de la tarea que deseas modificar."<<endl;
    
    for (int i = 0; i < mis_tareas.size(); i++) {
    cout << "--------------------------------------" << endl;
    cout << "Codigo: " << mis_tareas[i].codigo << endl;
    cout << "Titulo: " << mis_tareas[i].titulo << endl;
    cout << "Descripcion: " << mis_tareas[i].descripcion << endl;
    cout << "Fecha: " << mis_tareas[i].fecha << endl;
    cout << "Prioridad: " << mis_tareas[i].prioridad << endl;
    cout << "Estado: " << mis_tareas[i].estado << endl;
    cout << "--------------------------------------" << endl;
	}
	system ("pause");
	system ("cls");
    cout << endl;
    break;
    }
    case 3:{
    
    	system ("cls");

    actualizar_tarea();
    
    	system ("pause");
    	system ("cls");
    break;
        
    
    }
    case 4:
    	system ("cls");
    cout <<"   Desarrollado por: " << endl;
    cout <<"++++++++++++++++++++++" << endl;
    cout <<"+ Briseida Morales   +"<<endl; 
	cout <<"+ ELena Brito        +"<<endl;
	cout <<"+ Estuardo Gutierrez +"<<endl;
	cout <<"+ Josue Yax          +" << endl;
	cout <<"++++++++++++++++++++++" << endl;
	cout << endl;
    cout << "Saliendo del Programa... Hasta Pronto :)" << endl;
    	system ("pause");
    	system ("cls");
    break;
    default:
    cout << "Opcion no valida. Por favor, seleccione una opcion del 1 al 4. :(" << endl;
    } 
    }while (opcion != 4);

    return 0;
}
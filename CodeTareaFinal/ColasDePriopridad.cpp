#include <iostream>
#include <cstdlib>
using namespace std;

struct Nodo {
    int data;
    int priority;  // MODIFICADO: Nuevo campo para la prioridad
    Nodo *next;
};

Nodo *head = NULL;
// ELIMINADO: Nodo *tail = NULL;  -- Ya no necesitamos un puntero al final en una cola de prioridad

// MODIFICADO: Función para agregar elementos con prioridad
void AgregarElemento(int n, int p) {  // MODIFICADO: Agregado parámetro p para prioridad
    Nodo *new_Nodo = new Nodo();
    new_Nodo->data = n;
    new_Nodo->priority = p;  // MODIFICADO: Asignar la prioridad al nuevo nodo
    new_Nodo->next = NULL;

    // MODIFICADO: Insertar el nodo en la posición correcta según su prioridad
    if (head == NULL || p > head->priority) {
        new_Nodo->next = head;
        head = new_Nodo;
    } else {
        Nodo *temp = head;
        while (temp->next != NULL && temp->next->priority >= p) {
            temp = temp->next;
        }
        new_Nodo->next = temp->next;
        temp->next = new_Nodo;
    }
    cout << "Elemento agregado correctamente." << endl;
}

// MODIFICADO: Función para imprimir elementos con su prioridad
void ImprimirElementos() {  // MODIFICADO: Ya no necesita parámetro head
    Nodo *temp = head;
    while (temp != NULL) {
        cout << "(" << temp->data << ", " << temp->priority << ") ";  // MODIFICADO: Mostrar también la prioridad
        temp = temp->next;
    }
    cout << endl;
}

// MODIFICADO: Función para suprimir el elemento de mayor prioridad
void SuprimirElemento() {  // MODIFICADO: Ya no necesita parámetros head y tail
    if (head == NULL) {
        cout << "La cola está vacía." << endl;
        return;
    }
    Nodo* aux_delete = head;
    head = head->next;
    cout << "Se suprimió el elemento (" << aux_delete->data << ", " << aux_delete->priority << ")" << endl;  // MODIFICADO: Mostrar también la prioridad
    delete aux_delete;
}

// MODIFICADO: Función para eliminar toda la cola
void EliminarCola() {  // MODIFICADO: Ya no necesita parámetros head y tail
    Nodo* aux_delete;
    while (head != NULL) {
        aux_delete = head;
        head = head->next;
        delete aux_delete;
    }
    cout << "Cola eliminada." << endl;
}

// MODIFICADO: Función para buscar un elemento
void BuscarItem(int n) {  // MODIFICADO: Ya no necesita parámetro head
    Nodo* temp = head;
    bool flag = false;
    while (temp != NULL) {
        if (temp->data == n) {
            cout << "El número " << n << " se encontró con prioridad: " << temp->priority << endl;  // MODIFICADO: Mostrar también la prioridad
            flag = true;
            break;
        } else {
            temp = temp->next;
        }
    }
    if (!flag) {
        cout << "El número " << n << " no se encontró en la cola." << endl;
    }
}

void menu() {
    int opcion, n, p;  // MODIFICADO: Agregada variable p para prioridad
    bool flag = true;
    do {
        cout << endl << "****" << endl;
        cout << "\tMenú de opciones:" << endl;
        cout << "1. Agregar elementos a la cola de prioridad" << endl;  // MODIFICADO: Texto actualizado
        cout << "2. Imprimir cola" << endl;
        cout << "3. Suprimir el elemento de mayor prioridad" << endl;  // MODIFICADO: Texto actualizado
        cout << "4. Eliminar cola" << endl;
        cout << "5. Buscar en cola" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << endl << "Ingresa un número entero: ";
                cin >> n;
                cout << "Ingresa la prioridad (mayor número = mayor prioridad): ";  // MODIFICADO: Solicitar prioridad
                cin >> p;
                AgregarElemento(n, p);  // MODIFICADO: Pasar también la prioridad
                break;
            case 2:
                if (head == NULL) {
                    cout << "La cola está vacía." << endl;
                } else {
                    cout << endl << "Imprimiendo elementos de la cola ...\t";
                    ImprimirElementos();  // MODIFICADO: Ya no se pasa head como argumento
                }
                break;
            case 3:
                SuprimirElemento();  // MODIFICADO: Ya no se pasan head y tail como argumentos
                break;
            case 4:
                EliminarCola();  // MODIFICADO: Ya no se pasan head y tail como argumentos
                break;
            case 5:
                if (head == NULL) {
                    cout << "La cola está vacía..." << endl;
                } else {
                    cout << endl << "Ingrese el número a buscar: ";
                    cin >> n;
                    BuscarItem(n);  // MODIFICADO: Ya no se pasa head como argumento
                }
                break;
            default:
                cout << endl << "Saliendo del programa ..." << endl;
                flag = false;
                break;
        }
    } while (flag);
}

int main() {
    system("cls");
    menu();
    return 0;
}

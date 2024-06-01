#include <iostream>
#include <cstdlib>

using namespace std;

struct Nodo{
    int numero;
    Nodo *next;
};

void insertar(Nodo *&, int);
void mostrarPila(Nodo *, int);
void mover(Nodo *&, Nodo *&);
void Hanoi (int, Nodo *& ,Nodo *& , Nodo *& , int);

Nodo *Origen = NULL;
Nodo *Aux = NULL;
Nodo *Destino = NULL;

int main() {
    system("cls");
    int num;
    cout << "Introduzca el numero de discos: ";
    cin >> num;

    insertar(Origen, num);
    mostrarPila(Origen, num);
    mostrarPila(Aux, num);
    mostrarPila(Destino, num);


    Hanoi(num, Origen, Aux, Destino, num);

    return 0;
}


void insertar(Nodo *& cima, int num){ 
    if(num != 0) {
        Nodo *nuevoNodo = new Nodo();
        nuevoNodo -> numero = num;
        nuevoNodo -> next = cima;
        cima = nuevoNodo;
        insertar(cima, num-1); 
    }    
}

void mostrarPila(Nodo *cima, int num){
    bool flag = false;
    Nodo *actual = new Nodo();
    actual = cima;
    cout << "cima" << endl;

    while(actual != NULL){
        cout << "\t|" << actual -> numero << "|" << endl;
        actual = actual->next;
        flag = true;
    }
    if(!flag){
        for (int i = 1; i <= num; i++) {
            cout << "\t| |" << endl;
        }
    }
}

void mover (Nodo *& Salida, Nodo *& Entrada){
   Nodo *aux_eliminar = Salida;
    Salida = Salida->next; 

    aux_eliminar->next = Entrada;
    Entrada = aux_eliminar;

}

void Hanoi(int n, Nodo *&Origen, Nodo *&Aux, Nodo *&Destino, int num) {
    if (n > 0) {
        Hanoi(n - 1, Origen, Destino, Aux, num);
        mover(Origen, Destino);
        cout << "________________________________________" << endl;
        mostrarPila(Origen, num);
        mostrarPila(Aux, num);
        mostrarPila(Destino, num);
        Hanoi(n - 1, Aux, Origen, Destino, num);
    }
}

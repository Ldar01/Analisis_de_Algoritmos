#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
}*inicio, *fin;

class Pila{
    public:
        Pila(){
            inicio = nullptr;
        }
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n-> dato = valor;
            n->sig = nullptr;
            return n;
        }

        void push(int valor){
            Nodo *n = crearNodo(valor);
            n->sig = inicio;
            inicio=n;
        }
        void mostrarLista(){
            Nodo *temp = inicio;
            if (!inicio){
                cout<<"Lista Vacia"<<endl;
            }else{
                while (temp){
                    cout<<temp->dato<<",";
                    temp = temp->sig;
                }
                
            }
            
        }
};

class Tarea_Lab2{
    public:
        Tarea_Lab2(){
            inicio = nullptr;
        }
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n-> dato = valor;
            n->sig = nullptr;
            return n;
        }
 
        void mostrarTarea_Lab2(){
            Nodo *temp = inicio;
            if (!inicio){
                cout<<"Tarea_Lab2 Vacia"<<endl;
            }else{
                while (temp){
                    cout<<temp->dato<<",";
                    temp = temp->sig;
                }
                
            }
            
        }

        void push(int valor){
            Nodo *n = crearNodo(valor);
            if (!inicio){
                inicio = n;
                fin = n;
            }else{
                fin->sig = n;
                fin = n;
            }
            
        }

        void pop(){
            Nodo *temp = inicio;
            inicio = inicio->sig;
            free(temp);
        }

        Pila invertirCola(){
            Nodo *temp = inicio;
            if (!inicio){
                cout<<"No se puede invertir la cola porque no datos almacenados en ella";
            }else{
                Pila aux;
                while (temp){
                    aux.push(temp->dato);
                    temp = temp->sig;
                }
            }
            
        }
};



int main(int argc, char const *argv[])
{
    Tarea_Lab2 l1;
    Pila l_aux;

    l1.push(1);
    l1.push(2);
    l1.push(3);

    l1.mostrarTarea_Lab2();
    //cout<<"Prueba :v"<<endl;
    l1.invertirCola();
    //l1.mostrarTarea_Lab2();
    l_aux = l1.invertirCola();
    l_aux.mostrarLista();

    return 0;
}
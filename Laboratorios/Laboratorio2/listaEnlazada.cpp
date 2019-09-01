#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
}*inicio;

class ListaEnlazada{
    public:
        ListaEnlazada(){
            inicio = nullptr;
        }
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n-> dato = valor;
            n->sig = nullptr;
            return n;
        }
        void agregarNodo(int valor){
            Nodo *n = crearNodo(valor), *temp;
            if(inicio == nullptr){
                inicio = n;
            }else{
                for (temp = inicio; temp->sig; temp = temp->sig);
                temp ->sig = n;
            }
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

int main(int argc, char const *argv[])
{
    ListaEnlazada l1;

    l1.agregarNodo(1);
    l1.agregarNodo(2);
    l1.agregarNodo(3);

    l1.mostrarLista();

    return 0;
}

#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
    Nodo *prev;
}*inicio, *previo;

class ListaDoble{
    public:
        ListaDoble(){
            inicio = nullptr;
            previo = nullptr;
        }
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n-> dato = valor;
            n->sig = nullptr;
            n->prev = nullptr;
            return n;
        }
        void agregarNodo(int valor){
            Nodo *n = crearNodo(valor), *temp;
            if(inicio == nullptr){
                inicio = n;
                previo = n;
            }else{
                //for (temp = inicio; temp->sig; temp = temp->sig);
                previo->sig = n;
                n->prev = previo;
                previo = n;
            }
        }
 
        void mostrarListaAdelante(){
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

        void mostrarListaAtras(){
            Nodo *temp = previo;
            if (!inicio){
                cout<<"Lista Vacia"<<endl;
            }else{
                while (temp){
                    cout<<temp->dato<<",";
                    temp = temp->prev;
                }
                
            }
            
        }
};

int main(int argc, char const *argv[])
{
    ListaDoble l1;

    l1.agregarNodo(1);
    l1.agregarNodo(2);
    l1.agregarNodo(3);

    l1.mostrarListaAdelante();
    cout<<"Atras :v"<<endl;
    l1.mostrarListaAtras();

    return 0;
}

#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
    Nodo *prev;
}*inicio, *fin;

class ListaCircularDoble{
    public:
     ListaCircularDoble(){
            inicio = nullptr;
            fin = nullptr;
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
                inicio = fin = n;
                inicio->sig = fin->sig = nullptr;
                inicio->prev = fin->prev = nullptr;
            }else{
                //for (temp = inicio; temp->sig; temp = temp->sig);
                fin->sig = n;
                n->prev = fin;
                fin = n;
                inicio->prev =fin;
                fin->sig = inicio;
            }
        }
 
        void mostrarListaAdelante(){
            Nodo *temp = inicio;
            if ((!inicio) && (inicio == fin)){
                cout<<"Lista Vacia"<<endl;
            }else{
                while (temp->sig != inicio){
                    cout<<temp->dato<<",";
                    temp = temp->sig;
                }
                cout<<temp->dato;
            }
            
        }

        void mostrarListaAtras(){
            Nodo *temp = fin;
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
 ListaCircularDoble l1;

    l1.agregarNodo(1);
    l1.agregarNodo(2);
    l1.agregarNodo(3);

    l1.mostrarListaAdelante();
    //cout<<"Atras :v"<<endl;
    //l1.mostrarListaAtras();

    return 0;
}
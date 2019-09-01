#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
}*inicio, *fin;

class Cola{
    public:
        Cola(){
            inicio = nullptr;
        }
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n-> dato = valor;
            n->sig = nullptr;
            return n;
        }/* 
        void agregarNodo(int valor){
            Nodo *n = crearNodo(valor), *temp;
            if(inicio == nullptr){
                inicio = n;
            }else{
                for (temp = inicio; temp->sig; temp = temp->sig);
                temp ->sig = n;
            }
        }*/
 
        void mostrarCola(){
            Nodo *temp = inicio;
            if (!inicio){
                cout<<"Cola Vacia"<<endl;
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
            Nodo *temp= inicio;
            inicio = inicio->sig;
            free(temp);
        }
};

int main(int argc, char const *argv[])
{
    Cola l1;

    l1.push(1);
    l1.push(2);
    l1.push(3);

    l1.mostrarCola();

    return 0;
}
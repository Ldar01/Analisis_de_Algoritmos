#include <iostream>
#include <string>

using namespace std;

struct Nodo{
    string nombre;
    int edad;
    char sexo;
    Nodo *sig;
}*inicio;

class ListaEnlazada{
    public:
        ListaEnlazada(){
            inicio = nullptr;
        }
        Nodo* crearNodo(string nombre, int edad, char sexo){
            Nodo *n = new Nodo;
            n-> nombre = nombre;
            n->edad = edad;
            n->sexo = sexo;
            n->sig = nullptr;
            return n;
        }
        void agregarNodo(string nombre, int edad, char sexo){
            Nodo *n = crearNodo(nombre, edad, sexo), *temp;
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
                    cout<<temp->nombre<<",";
                    cout<<temp->edad<<",";
                    cout<<temp->sexo<<";";
                    temp = temp->sig;
                }
            }
        }

        void ordenarLista(){
            Nodo *temp = inicio, *aux = temp->sig;
            if (!inicio){
                cout<<"Lista Vacia"<<endl;
            }else{
                while (temp){
                    //tengo que terminar
                    if(temp->sexo == 'M'){
                        aux = inicio->sig;
                    }
                    temp = temp->sig;
                }
            }
        }
};

int main(int argc, char const *argv[])
{
    ListaEnlazada l1;

    l1.mostrarLista();

    return 0;
}
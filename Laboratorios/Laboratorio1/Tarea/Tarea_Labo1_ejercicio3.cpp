//Luisa Daniela Arevalo Rodas   00038617
#include <iostream>

using namespace std;

int menorDelArreglo(int arreglo[], int i, int m){
    int menor,aux;

    if (i == m-1){
        return menor = arreglo[i];
    }else{
        menor = menorDelArreglo(arreglo, i + 1, m);
        if (arreglo[i] < menor){
            aux = arreglo[i];
        }else{
            aux = menor;
        }
    }
    return aux;
};

int main(int argc, char const *argv[]){

    int list1[]={8,120,4,3,6,8,90,100};
    int tamanio = sizeof(list1)/sizeof(int);

    cout<<menorDelArreglo(list1,0,tamanio)<<endl;

    return 0;
}

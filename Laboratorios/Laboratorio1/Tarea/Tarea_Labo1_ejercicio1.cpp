//Luisa Daniela Arevalo Rodas   00038617
#include <iostream>
#define SIZE 3

using namespace std;

void imprimirMatriz(int matrix[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            cout<< matrix[i][j]<<"\t";
        }
        cout<<'\n';
    }
    
}

void sumarMatrices(int matrixA[SIZE][SIZE], int matrixB[SIZE][SIZE],int matrixC[SIZE][SIZE],int fila, int columna){

    if(fila > SIZE-1 && columna > SIZE-1){
        cout<<"Esta es la matriz :v"<<endl;
        imprimirMatriz(matrixC);
    }else{
        //cout<<"HOlaaaaaaa, desde el else";
        if (columna < SIZE){
            matrixC[fila][columna] = matrixA[fila][columna]+matrixB[fila][columna];
            //cout<<matrixC[fila][columna]<<"<- esta es la suma :v";
            sumarMatrices(matrixA,matrixB,matrixC,fila,columna+1);
        }else{
            columna = 0;
            fila++;
            matrixC[fila][columna] = matrixA[fila][columna]+matrixB[fila][columna];
            sumarMatrices(matrixA,matrixB,matrixC,fila,columna);
        }
    }
}

int main(int argc, char const *argv[])
{
    int m1[SIZE][SIZE] = {{1,2,3},{4,10,6},{7,8,9}};
    int m2[SIZE][SIZE] = {{1,2,3},{4,5,6},{7,8,9}};
    int m3[SIZE][SIZE] = {{0,0,0},{0,0,0},{0,0,0}};

    sumarMatrices(m1,m2,m3,0,0);

    //imprimirMatriz(m1);

    return 0;
}

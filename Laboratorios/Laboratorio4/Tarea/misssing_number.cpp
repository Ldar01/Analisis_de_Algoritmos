#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <bits/stdc++.h>
 

using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
        i++; 
        swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
    int pi = partition(arr, low, high);
    
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
    }
}

void printAnswers(int arr[], int lenght)
{
    for (int i = 0; i < lenght; i++){
        cout << arr[i] << endl;
    }
}


int main(int argc, char const *argv[])
{
    int t,n, numbers,cont = 0, i = 0;
        
    //cout<<"valor de t: ";

    cin>> t;
    cin.ignore();

    int answers[t];

    while (t!=0)
    {
        cont = 0;
        cout<<"t : "<<t<<endl;
        cin>> n ;
        cin.ignore();
        int lista[n];


        while (n--) { 
            scanf("%d", &numbers);
            lista[cont] = numbers;
            cont++;
        } 

        quickSort(lista,0, cont);

        int j, cont_2=1;
        for (j = 0; j < n; j++){
            if(lista[j]>=(cont_2*2)){
                
                cont_2+=1;
            
            }
        }
        answers[i]=(cont_2*2);
        i++;

        //getline(cin,numbers);
        //cin.clear();               

        //cout<<"Primer elemento: "<<lista[0]<<endl;    
        //cout<<"Ultimo elemento: "<<lista[cont-1]<<endl;        

        t--;
    }

    printAnswers(answers,i);

    return 0;
}
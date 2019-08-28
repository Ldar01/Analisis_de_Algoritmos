#include <iostream>

using namespace std;

int fibonacci_recursivo(int n){
    if (n < 2){
        return n;
    }else{
        return fibonacci_recursivo(n-1) + fibonacci_recursivo(n-2);
    }
}

int main(int argc, char const *argv[])
{
    cout<< fibonacci_recursivo(5);
    return 0;
}

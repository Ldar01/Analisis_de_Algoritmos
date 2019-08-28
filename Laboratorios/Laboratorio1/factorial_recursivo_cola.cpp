#include <iostream>

using namespace std;

int factorial_cola(int n, int res){
    if(n == 0){
        return res;
    }else{
        return factorial_cola(n-1, n*res);
    }
}

int imprimirFactorial(int n){
    return factorial_cola(n,1);
}

int main(int argc, char const *argv[])
{
    cout<<imprimirFactorial(5);
    return 0;
}

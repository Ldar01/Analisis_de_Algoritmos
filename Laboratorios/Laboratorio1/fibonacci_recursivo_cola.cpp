#include <iostream>

using namespace std;

int fibo_cola(int a, int b, int res){
    if(a < 2){
        return res;
    }else{
        return fibo_cola(a-1,b, res+b); // must fix
    }
}

int fibo(int n){
    return fibo_cola(n,1, 0);
}

int main(int argc, char const *argv[])
{
    cout<<fibo(5);
    return 0;
}

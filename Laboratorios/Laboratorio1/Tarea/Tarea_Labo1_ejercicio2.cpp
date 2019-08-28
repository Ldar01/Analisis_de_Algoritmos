//Luisa Daniela Arevalo Rodas   00038617
#include <iostream>

using namespace std;

int power(int x, int n){
    if (n == 0){
        return 1;
    }else{
        return (power(x,n-1))*x;
    }
}


int main(int argc, char const *argv[])
{
    
    cout<<power(2,5)<<endl;

    return 0;
}

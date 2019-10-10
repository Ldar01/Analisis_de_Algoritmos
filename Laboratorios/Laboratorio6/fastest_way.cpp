#include <iostream>

using namespace std;

int e1 = 2, e2 = 4, x1 =3, x2 = 2;
int a1[]= {7,9,3,4,8,4};
int a2[]= {8,5,6,4,5,7};
int t1[]= {2,1,1,2,4};
int t2[]= {2,3,2,3,1};
int const n = sizeof(a1)/sizeof(*a1);
int f1[n], f2[n];


void fastest_way(){
    f1[0] = e1 + a1[0];
    f2[0] = e2 + a2[0];

    for (int j = 1; j < n; j++){
        if (f1[j-1]+a1[j] <= f2[j-1]+t2[j-1]+ a1[j]){
            f1[j] = f1[j-1] + a1[j];
        }else{
            f1[j] = f2[j-1] + t2[j-1] + a1[j];
        }
        
        if (f2[j-1] + a2[j] <= f1[j-1]+ t1[j-1] + a2[j]){
            f2[j] = f2[j-1] + a2[j];
        }else{
            f2[j] = f1[j-1] + t1[j-1] + a2[j];
        }

        if( f1[j] <= f2[j]){
            cout<< f1[j]<<" "<<endl;
        }else{
            cout<< f2[j]<<" "<<endl;
        }
    }

    if( f1[n-1] + x1 <= f2[n-1]+ x2){
        cout<< f1[n-1]+ x1<<endl;
    }else{
        cout<< f2[n-1]+ x2<<endl;
    }
    
}

int main(int argc, char const *argv[])
{
    fastest_way();

    return 0;
}


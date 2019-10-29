#include <iostream>

using namespace std;

int memoized_cut_rod_aux(int p[], int n, int r[]){
    int q;
    if(r[n]>= 0){
        return r[n];
    }
    if (n == 0){
        q = 0;
    }else{
        q = -1;
        for (int i = 1; i <=n; i++) {
            for(int j=0;j<i;j++)
                q = max(q, p[i]+ memoized_cut_rod_aux(p,n-1,r));
                r[n] = q;
        }
        
    }
    
    return q;
}


int memoized_cut_rod(int p[], int n){
    int lista[n];

    for(int i=0; i<n; i++){
        lista[i] = -1;
        //cout<<"Aqui esta la lista :v :"<<lista[i]<<endl;
    }
    return memoized_cut_rod_aux(p,n,lista);
}


int main(int argc, char const *argv[])
{
    int longitud[] = {0,1,2,3,4,5,6,7,8,9,10} ;
    int precio[] = {1,5,8,9,10,17,17,20,24,30};

    cout<<memoized_cut_rod(precio, 4)<<endl;
    

    return 0;
}

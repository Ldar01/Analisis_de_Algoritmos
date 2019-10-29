#include <iostream>

using namespace std;

struct activity{
    int start;
    int finish;
};

activity jobs[11] = {
    {0,6}, {1,4}, {2,13}, {3,5}, {3,8}, 
    {5,7}, {5,9}, {6,10}, {8,11}, {8,12}, 
    {12,14}
};

int L[11] = {0,0,0,0,0,0,0,0,0,0,0};

int main(int argc, char const *argv[]){
    
    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 11; j++){
            if (jobs[j].finish < jobs[i].start && L[i] < L[j] ){
                L[i] = L[j];
            }
            
        }
        L[i]++;
        
    }
    
    cout<< L[10]<<endl;

    return 0;
}

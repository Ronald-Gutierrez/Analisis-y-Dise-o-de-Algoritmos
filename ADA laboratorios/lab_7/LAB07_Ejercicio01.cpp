#include <iostream>
#include <climits>
#include <time.h>
#include <chrono>
using namespace std;

bool *visited;
int *men;

int solve(int peso, int *kilos, int n){
    
    if(peso < 0){
        return INT_MAX;
    }
    
    if(peso == 0) { return 0; }
    
    if(visited[peso]){
        return men[peso];
    }
    
    int best = INT_MAX;
    for(int i=0;i<n;i++){
        int cal = solve(peso - kilos[i], kilos, n);
        if(cal != INT_MAX){
            if(cal+1 < best){ // un paquete adicionado
                best = cal+1;
            }
        }
    }
    
    visited[peso] = true;
    men[peso] = best;
    return men[peso];
}

int main()
{
    // int N = 10, n = 3;
    // int kilos[] = {1,3,4};
    
    int N =43000 ;
    int kilos[] = {1 , 2 , 5 , 7 , 11 , 13};
    int n = sizeof(kilos)/sizeof(kilos[0]);
    int *pk = kilos;
    
    visited = new bool[N+1];
    men = new int[N+1];
    
    for(int i= 0; i<N+1; i++){
        visited[i] = false;
        men[i] = 0;
    }
    
    for(int i=0;i<n; i++){
        visited[kilos[i]] = true;
        men[kilos[i]] = 1;
    }

    auto start = std::chrono::high_resolution_clock::now();
    cout<<solve(N,pk, n)<<endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout<< duration.count() << " microseg" << std::endl;
    return 0;
}
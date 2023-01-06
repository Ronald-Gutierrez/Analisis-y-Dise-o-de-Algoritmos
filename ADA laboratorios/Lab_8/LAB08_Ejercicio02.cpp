#include <iostream>
#include <climits>
#include <time.h>
#include <chrono>
using namespace std;

bool *visited;
int *men;

int solve(int tiempo, int *tipos, int n)
{
    int men[tiempo + 1];
    if (visited[tiempo])
    {
        return men[tiempo];
    }
    men[0] = 0;

    for (int k = 1; k <= tiempo; k++)
        men[k] = INT_MIN;

    for (int j = 1; j <= tiempo; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (tipos[i] <= j)
            {
                int cal = men[j - tipos[i]];
                if (cal != INT_MIN && cal + 1 > men[j])
                { // un paquete adicionado
                    men[j] = cal + 1;
                    visited[tiempo] = true;
                    //men[tiempo] = men[j];
                }
            }
        }
    }
    return men[tiempo];
}

int main()
{

    // int N = 54;
    // int tipos[] = {3,5};
    // int n = sizeof(tipos)/sizeof(tipos[0]);

    int N = 10000;
    int tipos[] = {3,5};
    int n = sizeof(tipos)/sizeof(tipos[0]);
    int *pk = tipos;
    
    visited = new bool[N+1];
    men = new int[N+1];
    
    for(int i= 0; i<N+1; i++){
        visited[i] = false;
        men[i] = 0;
    }
    
    for(int i=0;i<n; i++){
        visited[tipos[i]] = true;
        men[tipos[i]] = 1;
    }

    auto start = std::chrono::high_resolution_clock::now();
    cout<<solve(N,pk, n)<<endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout<< duration.count() << " microseg" << std::endl;
    return 0;
}
    
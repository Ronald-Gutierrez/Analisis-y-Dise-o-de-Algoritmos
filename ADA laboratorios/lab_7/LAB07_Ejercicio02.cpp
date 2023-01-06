#include <iostream>
#include <climits>
#include <time.h>
#include <chrono>
using namespace std;

bool *visited;
int *men;

int solve(int peso, int *kilos, int n)
{
    int men[peso + 1];
    if (visited[peso])
    {
        return men[peso];
    }
    men[0] = 0;

    for (int k = 1; k <= peso; k++)
        men[k] = INT_MAX;

    for (int j = 1; j <= peso; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (kilos[i] <= j)
            {
                int cal = men[j - kilos[i]];
                if (cal != INT_MAX && cal + 1 < men[j])
                { // un paquete adicionado
                    men[j] = cal + 1;
                    visited[peso] = true;
                    //men[peso] = men[j];
                }
            }
        }
    }
    return men[peso];
}

int main()
{
    // int N = 360;
    // int kilos[] = {1, 2, 5, 7, 11, 13};
    // int n = sizeof(kilos) / sizeof(kilos[0]);

    int N = 520000;
    int kilos[] = {1,2,5,7,11,13};
    int n = sizeof(kilos)/sizeof(kilos[0]);
    int *pk = kilos;

    visited = new bool[N + 1];
    men = new int[N + 1];

    for (int i = 0; i < N + 1; i++)
    {
        visited[i] = false;
        men[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        visited[kilos[i]] = true;
        men[kilos[i]] = 1;
    }

    auto start = std::chrono::high_resolution_clock::now();
    cout << solve(N, pk, n) << endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << duration.count() << " microseg" << std::endl;
    return 0;
}
    
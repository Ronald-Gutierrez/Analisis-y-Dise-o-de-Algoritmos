#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void mostrar(std::vector<int> A)
{
    for (int value : A)
    {
        cout << value << " ";
    }
    cout << endl;
}
int Partition(std::vector<int> &A, int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (A[j] <= x)
        {
            i = i + 1;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i + 1], A[r]);
    return i + 1;
}
void Quicksort(std::vector<int> &A, int p, int r)
{
    if (p < r)
    {
        int q = Partition(A, p, r);
        Quicksort(A, p, q - 1);
        Quicksort(A, q + 1, r);
    }
}

int main()
{
    srand(time(0));
    std::vector<int> A;
    int cant = 10;
    for (int n = 0; n < 7; n++)
    {
        for (int i = 1; i <= cant; i++)
        {
            A.push_back(rand() % 60);
        }
        cout << "Elementos: " << cant << endl;
        //mostrar(A);
        auto start = std::chrono::system_clock::now();
        Quicksort(A, 0, A.size() - 1);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<float, std::milli> duration = end - start;
        cout << "Arreglo ordenado --QuickSort-- \n";
        //mostrar(A);
        cout << "Tiempo de ejecucion: " << duration.count() << " ms" << std::endl;
        cout << endl;
        A.clear();
        cant *= 10;
    }
}

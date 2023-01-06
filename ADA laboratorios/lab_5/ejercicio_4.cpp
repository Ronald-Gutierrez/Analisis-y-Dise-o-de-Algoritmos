#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
void mostrar(std::vector<int> A)
{
    for (int value : A)
    {
        cout << value << " ";
    }
    cout << endl;
}
void partition3(std::vector<int> &A, int low, int high, int *i, int *j)
{
    if (high - low <= 1)
    {
        if (A[high] < A[low])
        {
            std::swap(A[high], A[low]);
        }
        *i = low;
        *j = high;
        return;
    }
    int mid = low;
    int pivot = A[high];
    while (mid <= high)
    {
        if (A[mid] < pivot)
        {
            std::swap(A[low++], A[mid++]);
        }
        else if (A[mid] == pivot)
        {
            mid++;
        }
        else if (A[mid] > pivot)
        {
            std::swap(A[mid], A[high--]);
        }
    }

    // update i and j
    *i = low - 1;
    *j = mid; // or high-1
}
void Quicksort3(std::vector<int> &A, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int i = 0, j = 0;
    partition3(A, low, high, &i, &j);

    Quicksort3(A, low, i);
    Quicksort3(A, j, high);
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
            A.push_back(rand() % 50);
        }
        cout << cant << endl;
        auto start = std::chrono::system_clock::now();
        Quicksort3(A, 0, A.size() - 1);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<float, std::milli> duration = end - start;
        cout << "Arreglo ordenado --QuickSort-- \n";
        cout << "Tiempo de ejecucion: " << duration.count() << " ms" << std::endl;
        cout << endl;
        A.clear();
        cant *= 10;
    }
}

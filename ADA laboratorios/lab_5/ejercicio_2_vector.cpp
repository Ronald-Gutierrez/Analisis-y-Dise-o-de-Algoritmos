#include <iostream>
#include <time.h>
#include <chrono>
#include <vector>
using namespace std;

bool comprobacion(vector<int> array)
{
    int i = 0, tmp = false;
    while (i < array.size() - 1 && tmp == false)
    {
        if (array[i] > array[i + 1])
            tmp = true;
        else
            i++;
    }
    return tmp;
}

int particion(vector<int> &array, int inicio, int fin)
{
    int pivote = array[fin];
    int i = inicio - 1;
    for (int j = inicio; j <= fin - 1; j++)
    {
        if (array[j] <= pivote)
        {
            i = i + 1;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[fin]);

    return i + 1;
}
void quicksort(vector<int> &array, int inicio, int fin)
{
    if (comprobacion(array) == true && (inicio < fin))
    {
        int q = particion(array, inicio, fin);
        quicksort(array, inicio, q - 1);
        quicksort(array, q + 1, fin);
    }
}

void mostrar(vector<int> array, int n)
{
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    srand(time(NULL));
    int n = 100000;
    vector<int> arr;
    for (int i = 0; i < n; i++)
        arr.push_back(rand() % 60);
    cout << "Arreglo inicial \n";
   //mostrar(arr, n);
    cout << "--> " << comprobacion(arr) << endl;
    auto start = chrono::system_clock::now();
    quicksort(arr, 0, arr.size() - 1);
    auto end = chrono::system_clock::now();
    chrono::duration<float, milli> duration = end - start;
    cout << "Arreglo ordenado --QuickSort-- \n";
    //mostrar(arr, n);
    cout << "Tiempo de ejecucion: " << duration.count() << " ms" << endl;
    return 0;
}

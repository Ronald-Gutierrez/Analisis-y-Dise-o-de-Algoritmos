#include <iostream>
#include <time.h>
using namespace std;

void imprimir (int lista[],int tam);
void insertionSort(int lista[], int tam);
int binarySearch(int a[], int x, int low, int high);

int main()
{   
    int n=5;
    int lista[n];
    srand(time(NULL));
    for(int i=0;i< n;i++)
        lista[i]=rand()%10;

    insertionSort(lista,n);
    imprimir(lista,n);
    return 0;
}
void insertionSort(int lista[], int tam)
{
    for (int i = 1; i < tam; i++) {
        int key = lista[i];
        int j = i - 1;
        int pos = binarySearch(lista, key, 0, j);
        while (j >= pos) 
        {
            lista[j + 1] = lista[j];
            j--;
        }
        lista[j + 1] = key;
    }
}
int binarySearch(int a[], int x, int low, int high)
{
    if (high <= low)
        return (x > a[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;
    if (x == a[mid])
        return mid + 1;

    if (x > a[mid])
        return binarySearch(a, x,mid + 1, high);

    return binarySearch(a, x, low,mid - 1);
}
void imprimir (int lista[],int tam)
{
	for (int i=0;i < tam;i++)
	    cout<<lista[i]<<" ";
}
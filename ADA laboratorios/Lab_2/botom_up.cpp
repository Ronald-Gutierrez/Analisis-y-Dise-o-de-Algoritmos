#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <cmath>
using namespace std;
void merge(int A[], int temp[], int from, int mid, int to)
{
    int k = from, i = from, j = mid + 1;
    while (i <= mid && j <= to)
    {
        if (A[i] < A[j])
            temp[k++] = A[i++];
        else 
            temp[k++] = A[j++];
    }
    while (i < to && i <= mid) 
        temp[k++] = A[i++];

    for (int i = from; i <= to; i++) 
        A[i] = temp[i];
}
 
// Iteratively sort subarray `A[low…high]` using a temporary array
void mergesort(int A[], int temp[], int low, int high)
{

    for (int m = 1; m <= high - low; m = 2*m)
    {
        for (int i = low; i < high; i += 2*m)
        {
            int from = i;
            int mid = i + m - 1;
            int to = min(i + 2*m - 1, high);
            merge(A, temp, from, mid, to);
        }
    }
}
 
void imprimir (int lista[],int tam){
	for (int i=0;i < tam;i++)
	    cout<<lista[i]<<" ";
    cout<<"\n";
}
 
int main()
{
    cout<<"Cantidad"<<"  "<<" Tiempo"<<endl;
    for(int i=0;i<10;i++)
    {
        int n=10000+i*10000;
        int lista[n];
        int lista_aux[n];
        srand(time(NULL));
        for(int i=0;i< n;i++) 
            lista[i]=lista_aux[i]=rand()%10;

        auto start = std::chrono::system_clock::now();
        mergesort(lista, lista_aux, 0, n - 1);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration <float, std::milli> duration = end - start;
        cout<<n<<"    --> "<<duration.count()<<" ms"<<std::endl;
        //imprimir(lista,n);
    }
	return 0;

    return 0;
}
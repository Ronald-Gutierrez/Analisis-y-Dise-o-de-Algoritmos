#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <cmath>
using namespace std;

void CopiarArr(int arr_2[],int  arr_1[],int n)
{
    for (int i = 0; i < n; i++)
        arr_1[i] = arr_2[i];
}

void BottomUpMerge(int arr_1[],int  arr_2[], int p,int  q,int  r)
{
    int i = p;
    int j = q;
    for (int k = p; k < r; k++) {
        if (i < q && (j >= r || arr_1[i] <= arr_1[j])) {
            arr_2[k] = arr_1[i];
            i = i + 1;
        } else {
            arr_2[k] = arr_1[j];
            j = j + 1;    
        }
    } 
}
void BottomUpMergeSort(int arr_1[],int  arr_2[],int  n)
{
    for (int j = 1; j < n; j = 2 * j)
    {
        for (int i = 0; i < n; i = i + 2 * j)
            BottomUpMerge(arr_1,arr_2, i, min(i+j, n), min(i+2*j, n));

        CopiarArr(arr_2, arr_1, n);
    }
}

void imprimir (int lista[],int tam){
	for (int i=0;i < tam;i++)
	    cout<<lista[i]<<" ";
    cout<<"\n";
}

int main()
{   
    cout<<"Bottom-Up  Merge Sort "<<endl;
    cout<<"Cantidad"<<"  "<<" Tiempo"<<endl;
    for(int i=0;i<10;i++)
    {
        int n=10000+i*10000;
        int lista[n];
        int lista_aux[n];
        srand(time(NULL));
        for(int i=0;i< n;i++) 
            lista[i]=rand()%10;
        auto start = std::chrono::system_clock::now();
        BottomUpMergeSort(lista,lista_aux,n);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration <float, std::milli> duration = end - start;
        cout<<n<<"    --> "<<duration.count()<<" ms"<<std::endl;
        //imprimir(lista,n);
    }

    return 0;
}
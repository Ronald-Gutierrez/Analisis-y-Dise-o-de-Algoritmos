#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <cmath>
using namespace std;

void merge(int arr[], int p, int q, int r) {
	
    int n1 = q - p + 1;
    int n2 = r - q;
    int i, j, k;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    i = 0;
    j = 0;
    k = p;
    for (k = p; k < r + 1; k++)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i = i + 1;
        }
        else
        {
            arr[k] = R[j];
            j = j + 1;
        }
    }
}
void merge_sort(int array[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r)/2;
        merge_sort(array, p, q);
        merge_sort(array, q + 1, r);
        merge(array, p, q, r);
    }
}
void imprimir (int lista[],int tam){
	for (int i=0;i < tam;i++)
	    cout<<lista[i]<<" ";
    cout<<"\n";
}
int main(){
    cout<<"Top-Down Merge Sort "<<endl;
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
        merge_sort(lista,0,n);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration <float, std::milli> duration = end - start;
        cout<<n<<"    --> "<<duration.count()<<" ms"<<std::endl;
        //imprimir(lista,n);
        
    }
    

}

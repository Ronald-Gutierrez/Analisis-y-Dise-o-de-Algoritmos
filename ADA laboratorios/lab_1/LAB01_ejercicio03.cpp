#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <fstream>
using namespace std;

void imprimir (int lista[],int tam);
void insertionSort(int lista[], int tam);

int main()
{   
    srand(time(NULL));
    for(int i=0;i<10;i++)
    {
        int n=1000+i*100;
        int lista[n];
        for(int i=0;i< n;i++)
        {
            lista[i]=rand()%100;
        }
        
        ofstream archivo("parametros_3.txt");
        auto start = std::chrono::system_clock::now();
        insertionSort(lista,n);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration <float, std::milli> duration = end - start;
        archivo<<duration.count()<<" ms"<<std::endl;
        cout<<n<<" "<<duration.count()<<" ms"<<std::endl;

        //cout<< "Arreglo Ordenado: \n";
        //imprimir(lista,n);
    }
    return 0;
}
void insertionSort(int lista[], int tam)
{
    
    for (int i = 1; i < tam; i++) {
        int key = lista[i];
        int j = i - 1;
        while (j >= 0 && lista[j] > key) {
            lista[j + 1] = lista[j]; 
            j--;
        }
        lista[j + 1] = key;
    }
}

void imprimir (int lista[],int tam){
	for (int i=0;i < tam;i++)
	    cout<<lista[i]<<" ";
}
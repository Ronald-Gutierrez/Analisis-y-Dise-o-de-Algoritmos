#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <fstream>
using namespace std;

void bubbleSort(int list[], int n);
void Imprimir(int list[], int n);

int main()
{
    
    srand(time(NULL));
    for(int i=0;i<10;i++)
    {
        int n=1000+i*100;
    int lista1[n];
        for(int i=0;i < n; i++)
            lista1[i]=rand()%100;

        ofstream archivo("parametros_4.txt");
        auto start = std::chrono::system_clock::now();
        bubbleSort(lista1, n);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration <float, std::milli> duration = end - start;
        archivo<<duration.count()<<" ms"<<std::endl;
        cout<<n<<" "<<duration.count()<<" ms"<<std::endl;
        //cout<< "Arreglo Ordenado: \n";
    }
        //Imprimir(lista1, n);
    return 0;
}

void bubbleSort(int list[], int n)
{
    for (int i =0; i <n - 1; i++){
        for (int j =0; j <n - i - 1; j++){
            if (list[j] > list[j + 1])
                swap(list[j], list[j + 1]);
        }
    }
}

void Imprimir(int list[], int n)
{
    for (int i = 0; i <n; i++)
        cout<<list[i] << " ";
    cout<<endl;
}

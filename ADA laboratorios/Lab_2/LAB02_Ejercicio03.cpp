#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <cmath>

using namespace std;

void merge(int array[], int p, int mid_1, int mid_2, int r, int Auxarray[]);
void merge_sort(int array[], int p, int r, int Auxarray[]);
void merge_sort_copy(int gArray[], int n);
void imprimir (int lista[],int tam);

int main()
{
	cout<<"Top-Down Merge Sort con 3 particiones"<<endl;
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
        merge_sort_copy(lista,n);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration <float, std::milli> duration = end - start;
        cout<<n<<"    --> "<<duration.count()<<" ms"<<std::endl;
        //imprimir(lista,n);
    }
	return 0;
}

void merge(int array[], int p, int mid_1, int mid_2, int r, int Auxarray[])
{
	int i = p, j = mid_1, k = mid_2, l = p;
    //Elegimos
	while ((i < mid_1) && (j < mid_2) && (k < r))
	{
		if(array[i] < array[j])
		{
			if(array[i] < array[k])
				Auxarray[l++] = array[i++];
			else
				Auxarray[l++] = array[k++];
		}
		else
		{
			if(array[j] < array[k])
				Auxarray[l++] = array[j++];
			else
				Auxarray[l++] = array[k++];
		}
	}

	while ((i < mid_1) && (j < mid_2))
	{
		if(array[i] < array[j])
			Auxarray[l++] = array[i++];
		else
			Auxarray[l++] = array[j++];
	}

	while ((j < mid_2) && (k < r))
	{
		if(array[j] < array[k])
			Auxarray[l++] = array[j++];
		else
			Auxarray[l++] = array[k++];
	}

	while ((i < mid_1) && (k < r))
	{
		if(array[i] < array[k])
			Auxarray[l++] = array[i++];
		else
			Auxarray[l++] = array[k++];
	}

	while (i < mid_1)
		Auxarray[l++] = array[i++];

	while (j < mid_2)
		Auxarray[l++] = array[j++];

	while (k < r)
		Auxarray[l++] = array[k++];
}

void merge_sort(int array[], int p, int r, int Auxarray[])
{
	if (r - p < 2)
		return;

	int mid_1 = p + ((r - p) / 3);
	int mid_2 = p + 2 * ((r - p) / 3) + 1;

	merge_sort(Auxarray, p, mid_1, array);
	merge_sort(Auxarray, mid_1, mid_2, array);
	merge_sort(Auxarray, mid_2, r, array);
	merge(Auxarray, p, mid_1, mid_2, r, array);
}
void merge_sort_copy(int gArray[], int n)
{
    if (n == 0)
        return;

    int fArray[n];
    for (int i = 0; i < n; i++)
        fArray[i] = gArray[i];
    merge_sort(fArray, 0, n, gArray);
    for (int i = 0; i < n; i++)
        gArray[i] = fArray[i];
}
void imprimir (int lista[],int tam){
	for (int i=0;i < tam;i++)
	    cout<<lista[i]<<" ";
}


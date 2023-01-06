#include <iostream>	
#include <time.h>
using namespace std;

int particion(int array[], int inicio, int fin)
{
    int pivote=array[fin];
    int i= inicio-1;
    for(int j=inicio;j<=fin-1;j++)
    {
        if(array[j]<=pivote)
        {
            i++;
            swap(array[i],array[j]);
        }
    }
    swap(array[i+1],array[fin]);

    return i+1;
}
void quicksort(int array[], int inicio, int fin)
{
  int q;
  if(inicio < fin)
  {
    q = particion(array, inicio, fin );
    quicksort(array, inicio, q-1 );
    quicksort(array, q+1, fin );
  }
}
void mostrar(int array[],int n)
{
    for (int i=0; i<n; i++) 
        cout<<array[i]<<" ";
    cout<<endl;
}

int main()
{
    srand(time(NULL));
    int n = 10;
    int arr[n];

    for(int i=0;i<n;i++)
        arr[i]=rand()%10;

    cout<<"Arreglo inicial \n";
    mostrar(arr,n);
    quicksort(arr, 0, n-1);
    cout<<"Arreglo ordenado --QuickSort-- \n";
    mostrar(arr,n);
    return 0;
}


#include <iostream>	
#include <time.h>
#include <chrono>
using namespace std;

bool comprobacion(int array[],int n);

int particion(int array[], int inicio, int fin)
{
    int pivote=array[fin];
    int i= inicio-1;
    for(int j=inicio;j<fin;j++)
    {
        if(array[j]<=pivote)
        {
            i=i+1;
            swap(array[i],array[j]);
        }
    }
    swap(array[i+1],array[fin]);

    return i+1;
}
void quicksort(int array[], int inicio, int fin)
{
  if(comprobacion(array,fin)==true && (inicio < fin))
  {
    int q = particion(array, inicio, fin );
    quicksort(array, inicio, q-1 );
    quicksort(array, q+1, fin );
  }
}   

bool comprobacion(int array[],int n)
{
    int i=0,tmp=false;
    while(i<(n-1) && tmp== false)
    {
        if(array[i] > array[i+1])
          tmp=true;
        else
            i++;
    }
    return tmp;
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
  int n = 10000;
  int arr[n];

  for(int i=0;i<n;i++)
      arr[i]=i;
  cout<<endl;

  cout<<"Arreglo inicial \n";
  //mostrar(arr,n);
  cout<<"--> "<<comprobacion(arr,n)<<endl;
  auto start = std::chrono::system_clock::now();
  quicksort(arr, 0, n-1);
  auto end = std::chrono::system_clock::now();
  std::chrono::duration <float, std::milli> duration = end - start;
  cout<<"Arreglo ordenado --QuickSort-- \n";
  //mostrar(arr,n);
  cout<<"Tiempo de ejecucion: "<<duration.count()<<" ms"<<std::endl;

    
    return 0;
}
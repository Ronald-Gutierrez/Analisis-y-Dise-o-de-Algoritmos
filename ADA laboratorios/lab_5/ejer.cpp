#include <iostream>	
#include <time.h>
#include <chrono>
using namespace std;

bool comprobacion(int array[],int n);

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
  int n = 10;
  int arr[n];

  for(int i=0;i<n;i++)
      arr[i]=rand()%10;
  cout<<endl;

  cout<<"Arreglo inicial \n";
  mostrar(arr,n);
  cout<<"--> "<<comprobacion(arr,n)<<endl;
  
  return 0;
}

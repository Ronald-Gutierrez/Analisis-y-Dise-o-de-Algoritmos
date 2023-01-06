#include <iostream>
using namespace std;

void retirar(int arr[],int tam)
{   
    int x=0;
    //CALCULO DE LA X
    for(int i=0;i<tam;i++)
    {   
        if(i+1 < tam){
            if(arr[i]+x < arr[i+1]) x=arr[i]+x; 
            else x=arr[i]+x-arr[i+1];
        }
        else if(i==tam-1) x=arr[i]+x;
        else break;
        
    }
    cout<<"El valor de mi x es: "<< x <<endl;
    //CALCULO DE LAS MAYOR VARIEDAD DE MONEDAS
    int suma=0;
    int count=0;
    for(int i=0; i<tam ;i++)
    {   
        suma=arr[i]+suma;
        if(suma<=x) count++;
        else break;
    }
    cout<<count<<endl;
}
int main()
{   
    int tam=6;
    //int list[tam]={1,2,4,8,16,32};
    int list[tam]={1,3,6,8,15,20};
    retirar(list,tam);
   
    return 0;
}
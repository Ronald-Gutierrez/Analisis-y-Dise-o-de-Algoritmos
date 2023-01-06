#include <iostream>
#include <cmath>
using namespace std;
void ordenar(int v[], int n) {

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v[i] > v[j])
                swap(v[i],v[j]);
        }
    }
}
void mostrar_salida(int *arr,int n_c,int n_e)
{
    for(int i=0;i<n_c;i++)
    {
        cout<<i<<": "<<arr[i]<<" "<<arr[(n_c*2)-1-i]<<endl;
    }
}
float desbalance(int *arr,int n_c,int n_e)
{
    float desbalance;
    float suma_total=0;
    float suma_gen=0;
    float n_especi2=n_e;
    for(int i=n_e;i<n_c*2;i++)
        arr[i]=0;

    for(int j=0;j<n_e; j++)
        suma_total=suma_total+arr[j];

    suma_gen=suma_total/n_c;
    //cout<<suma_gen<<endl;
    for(int i=n_e;i<n_c*2;i++)
        arr[i]=0;

    for(int j=0;j<n_c; j++)
    {
        desbalance=desbalance+abs(arr[j]+arr[(n_c*2-1)-j]-suma_gen);
    }
    return desbalance;
}
int main()
{
    // int n_camaras=3;
    // int n_especi=5;
    // int espe[n_especi]={51,19,27,14,33};

    // int n_camaras=2;
    // int n_especi=3;
    // int espe[n_especi]={6,3,8};

    // int n_camaras=5;
    // int n_especi=9;
    // int espe[n_especi]={1,2,3,5,7,11,13,17,19};

    int n_camaras=4;
    int n_especi=6;
    int espe[n_especi]={99,3,45,67,88,1000};

    ordenar(espe,n_especi);
    //MOSTRAR SALIDA

    mostrar_salida(espe,n_camaras,n_especi);
    cout<<"DESBALANCE = "<<desbalance(espe,n_camaras,n_especi);
    return 0;
}
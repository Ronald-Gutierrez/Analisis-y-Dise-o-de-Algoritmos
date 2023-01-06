#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int K=15;
    int tam=5;
    int lista_val[tam];
    int i=0;
    int count=0;
    while(K>0)
    {
        lista_val[i]=K%10;
        K=K/10;
        i++;
    }
    // for(int j=i-1;j >=0;j--)
    //     cout<<lista_val[j]<<endl;
    
    for(int j=0;j;j--)
    {
        K=lista_val[j];
        count++;
        int a=0;
        while(K>0)
        {
            lista_val[a]=K%10;
            K=K/10;
            a++;
        }
        count++;
    }
    cout<<count<<endl;
}

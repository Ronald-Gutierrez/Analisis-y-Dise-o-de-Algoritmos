#include <iostream>
#include <time.h>
using namespace std;

int main()
{   
    int n=2;
    int A[n][n];
    srand(time(NULL));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            A[i][j]=rand()%10;
    }

    cout << "Matriz A" <<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}


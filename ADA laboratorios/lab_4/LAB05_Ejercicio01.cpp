#include <iostream>
#include <time.h>
#include <chrono>
#define n 512

using namespace std;

int producto_matrices(int A[n][n], int B[n][n],int C[n][n]);
void mostrar_matriz(int A[n][n],int N);
void rellenar_matriz(int A[n][n],int N);

int main()
{   

    int A[n][n];
    int B[n][n];
    int C[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            C[i][j]=0;
    }
    rellenar_matriz(A,n);
    rellenar_matriz(B,n);
    

    // cout << "Matriz A" <<endl;
    // mostrar_matriz(A,n);
    // cout << "Matriz B" <<endl;
    // mostrar_matriz(B,n);
    // cout << "Matriz C" <<endl;
    // mostrar_matriz(C,n);

    auto start = std::chrono::system_clock::now();
    producto_matrices(A,B,C);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration <float, std::milli> duration = end - start;
    cout<<" "<<duration.count()<<" ms"<<std::endl;
    return 0;
}
int producto_matrices(int A[n][n], int B[n][n],int C[n][n])
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++)
                C[i][j] += A[i][k] * B[k][j];    
}
void mostrar_matriz(int A[n][n],int N)
{
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
}
void rellenar_matriz(int A[n][n],int N)
{
    srand(time(NULL));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            A[i][j]=rand()%10;
    }
}